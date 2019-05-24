#include "../../include/core/MainRenderer.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace core {

    MainRenderer::MainRenderer(VaoLoader *vaoLoader, FpsData *fpsData) {
        this->fpsData = fpsData;
        enableCulling();
        this->shader = new Shader(VERTEX_FILE, FRAGMENT_FILE);
        this->renderer = new Render(shader);
        this->terrainShader = new TerrainShader(TERRAIN_VERTEX_FILE, TERRAIN_FRAGMENT_FILE);
        this->terrainRenderer = new TerrainRenderer(terrainShader);
        this->skyboxRenderer = new SkyboxRenderer(vaoLoader);
        this->animatedModelShader = new AnimatedModelShader(ANIMATED_MODEL_VERTEX_FILE, ANIMATED_MODEL_FRAGMENT_FILE);
        this->animatedModelRenderer = new AnimatedModelRenderer(animatedModelShader);
    }

    MainRenderer::~MainRenderer() {

    }

    void MainRenderer::render(Light *light, Camera *camera) {

        prepare();
        this->shader->start();
        this->shader->loadSkyColour(R,G,B);
        this->shader->loadLight(light);
        this->shader->loadViewMatrix(camera);
        this->renderer->render(this->modelEntities);
        this->shader->stop();
        this->modelEntities.clear();

        this->animatedModelShader->start();
        this->animatedModelShader->loadSkyColour(R,G,B);
        this->animatedModelShader->loadLight(light);
        this->animatedModelShader->loadViewMatrix(camera);
        this->animatedModelRenderer->render(this->animatedModelEntities);
        this->animatedModelShader->stop();
        this->animatedModelEntities.clear();

        this->terrainShader->start();
        terrainShader->loadSkyColour(R,G,B);
        this->terrainShader->loadLight(light);
        this->terrainShader->loadViewMatrix(camera);
        this->terrainRenderer->render(this->terrains);
        this->terrainShader->stop();
        this->terrains.clear();

        this->skyboxRenderer->render(camera, R, G, B, this->fpsData);
    }


    void MainRenderer::processTerrain(Terrain *terrain) {

        this->terrains.push_back(terrain);
    }

    void MainRenderer::processEntity(Entity *entity) {

        TexturedModel *entityModel = entity->getModel();
        list<Entity *> batch;
        if (this->modelEntities.find(entityModel) != modelEntities.end()) {
            this->modelEntities.find(entityModel)->second.push_back(entity);
        } else {
            list<Entity *> newBatch = {entity};
            this->modelEntities.insert(pair<TexturedModel *, list<Entity *>>(entityModel, newBatch));
        }

    }

    void MainRenderer::processAnimatedEntity(AnimatedEntity *entity) {

      AnimatedModel *entityModel = entity->getModel();
      list<AnimatedEntity *> batch;
      if (this->animatedModelEntities.find(entityModel) != animatedModelEntities.end()) {
          this->animatedModelEntities.find(entityModel)->second.push_back(entity);
      } else {
          list<AnimatedEntity *> newBatch = {entity};
          this->animatedModelEntities.insert(pair<AnimatedModel *, list<AnimatedEntity *>>(entityModel, newBatch));
      }
    }

    void MainRenderer::prepare(void) {

        glEnable(GL_DEPTH_TEST);
        glClearColor(R, G, B, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        return;
    }

    void MainRenderer::enableCulling() {

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }

    void MainRenderer::disableCulling() {

        glDisable(GL_CULL_FACE);
    }

    void MainRenderer::cleanUp() {

        this->shader->cleanUp();
        this->terrainShader->cleanUp();
        this->animatedModelShader->cleanUp();
    }

}
