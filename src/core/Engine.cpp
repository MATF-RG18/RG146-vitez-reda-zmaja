#include "../../include/core/Engine.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// kao i vezbi iz racunarske grafike.

// Prostor imena core
namespace core {

  VaoLoader *vaoLoader;

  Render *renderer;

  MainRenderer *mainRenderer;

  RawModel *model;

  Texture *texture;

  TexturedModel *texturedModel;

  Entity *entity;

  Shader *shader;

  Camera *camera;

  Light *light;

  Terrain *terrain;

  Player *player;

  FpsData *fpsData;

  vector<HudTexture*> huds;

  HudRenderer *hudRenderer;

  Font *font;

  FontRenderer *fontRenderer;

  AnimatedModel *animatedModel;

  AnimatedModelRenderer *animatedModelRenderer;

  vector<Entity *> trees;

  Loader *loader;

  Text *text;

  Animator *animator;

  Animation *animation;

  ParticleHandler *particleHandler;

  WeatherSystem *weatherSystem;

  int screenWidth;

  int screenHeight;

  Texture *snowTexture;
  Texture *rainTexture;
  bool weather = false;

  const char *screenTitle = "VitezRedaZmaja";




  Engine::Engine() {

  }

  Engine::~Engine() {
    mainRenderer->cleanUp();
    hudRenderer->cleanUp();
    vaoLoader->cleanUp();
    particleHandler->cleanUp();
  }

  void Engine::start(int *argcp, char **argv) {

    // Inicijalizuje se glut
    initGlut(argcp, argv);

    // Kreira se prozor
    createWindow();

    // Inicijalizuje se OpenGL
    initGl();

    // Registruju se callback funkcije
    registerCallbackFunctions();

    // Pokretanje glavne petlje programa
    glutMainLoop();

    return;
  }

  void Engine::initGlut(int *argcp, char **argv) {

    // Omogucavanje core profila GLSL sejder programa za mogucnost funkcionisanja na AMD grafickim procesorima
    glutInitContextVersion(4, 0);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutInit(argcp, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    return;
  }

  void Engine::createWindow(void) {

    screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(screenTitle);

    // if (glutGameModeGet (GLUT_GAME_MODE_POSSIBLE)) {
    //   glutEnterGameMode();
    // }

    return;
  }

  void Engine::initGl(void) {

    glClearColor(1, 1, 1, 0);
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, screenWidth, screenHeight);

    vaoLoader = new VaoLoader();
    loader = new Loader();

    texturedModel = loader->loadTexturedModel("res/tree.dae", vaoLoader);
    animatedModel = loader->loadAnimatedModel("res/model.dae", vaoLoader);
    TerrainTexture *backgroundTexture = new TerrainTexture(vaoLoader->loadTexture("res/grassy.png"));
    TerrainTexture *rTexture = new TerrainTexture(vaoLoader->loadTexture("res/mud.png"));
    TerrainTexture *gTexture = new TerrainTexture(vaoLoader->loadTexture("res/grassFlowers.png"));
    TerrainTexture *bTexture = new TerrainTexture(vaoLoader->loadTexture("res/path.png"));

    TerrainTexturePack *texturePack = new TerrainTexturePack(backgroundTexture, rTexture, gTexture, bTexture);
    TerrainTexture *blendMap = new TerrainTexture(vaoLoader->loadTexture("res/blendMap.png"));

    terrain = new Terrain(0, -1, vaoLoader, texturePack, blendMap, "res/heightmap.png");

    fpsData = new FpsData();

    mainRenderer = new MainRenderer(vaoLoader, fpsData);

    animator = new Animator(animatedModel, fpsData);

    vec3 position(260, 5, -260);
    vec3 rotation(-90, 0, 0);
    float scale = 1;
    player = new Player(animatedModel, position, rotation, scale, terrain, fpsData, animator);

    for (size_t i = 0; i < 250; i++) {
      float posX = rand()%1000;
      float posZ = -(rand()%1000);
      vec3 tposition(posX, terrain->getHeightOfTerrain(posX, posZ), posZ);
      vec3 trotation(0, 0, 0);
      float tscale = 5;
      entity = new Entity(texturedModel, tposition, trotation, tscale);
      trees.push_back(entity);
    }
    vec3 tposition(250, terrain->getHeightOfTerrain(250,-250), -250);
    vec3 trotation(0, 0, 0);
    float tscale = 5;
    entity = new Entity(texturedModel, tposition, trotation, tscale);

    HudTexture *hud = new HudTexture(vaoLoader->loadTexture("res/hud.png"), vec2(-0.9, -0.8), vec2(100/(float)glutGet(GLUT_WINDOW_WIDTH),100/(float)glutGet(GLUT_WINDOW_HEIGHT)), 180);
    huds.push_back(hud);
    hudRenderer = new HudRenderer(vaoLoader);

    font = new Font("res/CalibriRegular.ttf", 48);
    fontRenderer = new FontRenderer();
    text = new Text(font, " ", vec2(-0.95, 0.9), vec2(1,1), 0, vec3(1, 1, 1));

    camera = new Camera(player);
    light = new Light(vec3 (2000, 2000, 2000), vec3 (1, 1, 1));

    particleHandler = new ParticleHandler(vaoLoader);
    snowTexture = new Texture(vaoLoader->loadTexture("res/snowflake.png"));
    rainTexture = new Texture(vaoLoader->loadTexture("res/raindrop.png"));
    weatherSystem = new WeatherSystem(400, 6, 3, 60, fpsData, snowTexture);


    fpsData->update();
    return;
  }

  void Engine::registerCallbackFunctions(void) {

    glutKeyboardFunc(onKeyboard);
    glutMouseFunc(onMouse);
    glutSpecialFunc(onSpecialDown);
    glutSpecialUpFunc(onSpecialUp);
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    return;
  }

  void renderScene(void) {

    fpsData->update();
    mainRenderer->processTerrain(terrain);
    player->move();
    mainRenderer->processAnimatedEntity(player);
    for (Entity *e : trees) {
      mainRenderer->processEntity(e);
    }
    camera->move();
    mainRenderer->render(light, camera);

    float posX = camera->getPosition().x;
    float posZ = camera->getPosition().z;
    float posY = camera->getPosition().y+10;

    if (weather) {
      weatherSystem->generateParticles(particleHandler, vec3(posX, posY, posZ));
      particleHandler->update();
      particleHandler->renderParticles(camera, weatherSystem->getTexture());
    }

    hudRenderer->render(huds);
    text->setText(string("FPS: " + to_string(fpsData->getFpsCount())));
    fontRenderer->render(text);
    glutSwapBuffers();

    return;
  }

  void onKeyboard(unsigned char key, int x, int y) {
    if (key == ESC) {
      glutLeaveMainLoop();
    }
    if (key == '1') {

      weather = false;
    }
    else if (key == '2') {

      weather = true;
      weatherSystem->setTexture(snowTexture);
    }
    else if (key == '3') {
      weather = true;
      weatherSystem->setTexture(rainTexture);
    }
    camera->move();
    camera->handleKeyboardInput(key);
  }

  void onMouse(int button, int state, int x, int y) {

    camera->handleMouseInput(button, state, x, y);
  }

  void onSpecialDown(int key, int x, int y) {

    player->handleKeyDown(key);
  }

  void onSpecialUp(int key, int x, int y) {

    player->handleKeyUp(key);
  }

} // core
