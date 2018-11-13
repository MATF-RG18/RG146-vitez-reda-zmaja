#include "../../include/core/MainRenderer.h"

namespace core {

    MainRenderer::MainRenderer(VaoLoader *vaoLoader, FpsData *fpsData) {
        this->fpsData = fpsData;
        enableCulling();
        this->shader = new Shader(VERTEX_FILE, FRAGMENT_FILE);
        this->renderer = new Render(shader);
        this->terrainShader = new TerrainShader(TERRAIN_VERTEX_FILE, TERRAIN_FRAGMENT_FILE);
        this->terrainRenderer = new TerrainRenderer(terrainShader);
        this->skyboxRenderer = new SkyboxRenderer(vaoLoader);
    }

    MainRenderer::~MainRenderer() {

    }

    void MainRenderer::render(Light *light, Camera *camera) {
        
        prepare();
        this->shader->start();
        this->shader->loadSkyColour(R,G,B);
        this->shader->loadLight(light);
        this->shader->loadViewMatrix(camera);
        this->renderer->render(this->entities);
        this->shader->stop();
        this->entities.clear();

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
        if (this->entities.find(entityModel) != entities.end()) {
            this->entities.find(entityModel)->second.push_back(entity);
        } else {
            list<Entity *> newBatch = {entity};
            this->entities.insert(pair<TexturedModel *, list<Entity *>>(entityModel, newBatch));
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
    }

}