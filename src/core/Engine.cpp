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

  ModelTexture *texture;

  TexturedModel *texturedModel;

  Entity *entity;

  Shader *shader;

  Camera *camera;

  Light *light;

  ObjLoader objLoader;

  Terrain *terrain;

  Player *player;

  FpsData *fpsData;

  vector<HudTexture*> huds;

  HudRenderer *hudRenderer;

  Font *font;

  FontRenderer *fontRenderer;

  Text *text;

  int screenWidth;

  int screenHeight;

  const char *screenTitle = "VitezRedaZmaja";




  Engine::Engine() {

  }

  Engine::~Engine() {
    mainRenderer->cleanUp();
    hudRenderer->cleanUp();
    vaoLoader->cleanUp();
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

    vaoLoader = new VaoLoader;

    model = objLoader.loadObjModel("res/character.obj", vaoLoader);
    texture = new ModelTexture(vaoLoader->loadTexture("res/characterTexture.png"));
    texture->setShine(200);
    texture->setReflectivity(0.1);
    texturedModel = new TexturedModel(model, texture);

    TerrainTexture *backgroundTexture = new TerrainTexture(vaoLoader->loadTexture("res/grassy.png"));
    TerrainTexture *rTexture = new TerrainTexture(vaoLoader->loadTexture("res/mud.png"));
    TerrainTexture *gTexture = new TerrainTexture(vaoLoader->loadTexture("res/grassFlowers.png"));
    TerrainTexture *bTexture = new TerrainTexture(vaoLoader->loadTexture("res/path.png"));

    TerrainTexturePack *texturePack = new TerrainTexturePack(backgroundTexture, rTexture, gTexture, bTexture);
    TerrainTexture *blendMap = new TerrainTexture(vaoLoader->loadTexture("res/blendMap.png"));

    terrain = new Terrain(0, -1, vaoLoader, texturePack, blendMap, "res/heightmap.png");

    fpsData = new FpsData();

    mainRenderer = new MainRenderer(vaoLoader, fpsData);

    vec3 position(260, 5, -260);
    vec3 rotation(0, 180, 0);
    float scale = 1;
    player = new Player(texturedModel, position, rotation, scale, terrain);

    HudTexture *hud = new HudTexture(vaoLoader->loadTexture("res/hud.png"), vec2(-0.9, -0.8), vec2(100/(float)glutGet(GLUT_WINDOW_WIDTH),100/(float)glutGet(GLUT_WINDOW_HEIGHT)), 180);
    huds.push_back(hud);
    hudRenderer = new HudRenderer(vaoLoader);

    font = new Font("res/CalibriRegular.ttf", 48);
    fontRenderer = new FontRenderer();
    text = new Text(font, " ", vec2(-0.95, 0.9), vec2(1,1), 0, vec3(1, 1, 1));

    camera = new Camera(player);
    light = new Light(vec3 (2000, 2000, 2000), vec3 (1, 1, 1));



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

    mainRenderer->processTerrain(terrain);
    player->move(fpsData);
    mainRenderer->processEntity(player);
    camera->move();
    mainRenderer->render(light, camera);
    hudRenderer->render(huds);
    text->setText(string("FPS: " + to_string(fpsData->getFpsCount())));
    fontRenderer->render(text);
    glutSwapBuffers();
    fpsData->update();

    return;
  }

  void onKeyboard(unsigned char key, int x, int y) {
    if (key == ESC) {
      glutLeaveMainLoop();
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
