#include "../../include/shader/SkyboxShader.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace shader {

  SkyboxShader::SkyboxShader() {

    this->rotation = 0.0;
    this->vertexShaderID = loadShader(VERTEX_SHADER_FILE, GL_VERTEX_SHADER);
    this->fragmentShaderID = loadShader(FRAGMENT_SHADER_FILE, GL_FRAGMENT_SHADER);
    this->programID = glCreateProgram();


    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    bindAttributes();

    glLinkProgram(programID);
    GLint isLinked = 0;
    glGetProgramiv(programID, GL_LINK_STATUS, &isLinked);
    if(isLinked == GL_FALSE)
    {
    	GLint maxLength = 0;
    	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

    	std::vector<GLchar> infoLog(maxLength);
    	glGetProgramInfoLog(programID, maxLength, &maxLength, &infoLog[0]);

    	glDeleteProgram(programID);

      for (auto i = infoLog.begin(); i != infoLog.end(); ++i)
        cout << *i << ' ';

    }
    glValidateProgram(programID);

    getAllUniformLocations();

  }

  SkyboxShader::~SkyboxShader() {

  }

  void SkyboxShader::bindAttribute(int index, const char *variableName) {

    glBindAttribLocation(programID, index, variableName);

    return;
  }

  void SkyboxShader::start(void) {

    glUseProgram(programID);

    return;
  }

  void SkyboxShader::stop(void) {

    glUseProgram(0);

    return;
  }

  void SkyboxShader::cleanUp(void) {

    stop();
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDeleteProgram(programID);

    return;
  }

  int SkyboxShader::getUniformLocation(const char *uniformName) {

    return glGetUniformLocation(this->programID, uniformName);
  }

  void SkyboxShader::getAllUniformLocations(void) {

    this->locationProjectionMatrix = getUniformLocation("projectionMatrix");
    this->locationViewMatrix = getUniformLocation("viewMatrix");
    this->locationFogColour = getUniformLocation("fogColour"); 
    this->locationCubeMap = getUniformLocation("cubeMap");
    this->locationCubeMap2 = getUniformLocation("cubeMap2");
    this->locationBlendFactor = getUniformLocation("blendFactor");
  }

  void SkyboxShader::loadFloat(int uniformLocation, float value) {

    glUniform1f(uniformLocation, value);
  }

  void SkyboxShader::loadInt(int uniformLocation, int value) {

    glUniform1i(uniformLocation, value);
  }

  void SkyboxShader::loadFloatVertex(int uniformLocation, vec3 vertex) {

    glUniform3f(uniformLocation, vertex.x, vertex.y, vertex.z);
  }

  void SkyboxShader::loadMatrix(int uniformLocation, mat4 matrix) {

    float *matrixBuffer = (float *)value_ptr(matrix);
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, matrixBuffer);

    return;
  }

  void SkyboxShader::loadProjectionMatrix(mat4 matrix) {
    loadMatrix(locationProjectionMatrix, matrix);
  }

  void SkyboxShader::loadViewMatrix(Camera *camera, FpsData *fpsData) {
    mat4 viewMatrix = createViewMatrix(camera->getPosition(), camera->getPich(), camera->getYaw());
    viewMatrix[3][0] = 0;
    viewMatrix[3][1] = 0;
    viewMatrix[3][2] = 0;
    if (fpsData->getFpsCount() != 0)
      this->rotation += SKYBOX_ROTATION_SPEED/float(fpsData->getFpsCount());
    if (this->rotation >= 360)
      this->rotation -= 360;
    viewMatrix = rotate(viewMatrix, radians(this->rotation), vec3(0,1,0));
    loadMatrix(locationViewMatrix, viewMatrix);
  }

  
  void SkyboxShader::loadFogColour(float r, float g, float b) {

    loadFloatVertex(locationFogColour, vec3(r,g,b));
  }

  void SkyboxShader::loadBlendFactor(float blendFactor) {

    loadFloat(this->locationBlendFactor, blendFactor);
  }

  void SkyboxShader::connectTextureUnits() {
    
    loadInt(this->locationCubeMap, 0);
    loadInt(this->locationCubeMap2, 1);
  }

  int SkyboxShader::loadShader(const char *fileName, GLenum type) {

      string shaderSource;
      string line;
      ifstream shaderFile(fileName);
      if (shaderFile.is_open()) {
        while (getline(shaderFile, line)) {
          shaderSource.append(line);
          shaderSource.append("\n");
        }

        shaderFile.close();
      }
      else {
        cout << "Unable to open shader file" << '\n';
      }


      int shaderID = glCreateShader(type);

      const GLchar *source = (const GLchar *)shaderSource.c_str();
      glShaderSource(shaderID, 1, &source, 0);
      glCompileShader(shaderID);

      GLint isCompiled = 0;

      glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isCompiled);
      if(isCompiled == GL_FALSE)
      {

      	GLint maxLength = 0;
      	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
        std::cout << maxLength << '\n';

      	vector<char> errorLog(maxLength);
      	glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);

      	glDeleteShader(shaderID);
        std::cout << errorLog.size() << '\n';
        for (int i = 0; i <errorLog.size(); ++i)
          cout << errorLog[i] << ' ';

      }

      return shaderID;
  }

  void SkyboxShader::bindAttributes(void) {

    bindAttribute(0, "position");
    bindAttribute(1, "textureCoords");
    bindAttribute(2, "normal");

    return;
  }

} // shader
