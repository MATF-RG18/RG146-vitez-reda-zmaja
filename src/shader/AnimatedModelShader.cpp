#include "../../include/shader/AnimatedModelShader.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace shader {

  AnimatedModelShader::AnimatedModelShader(const char *vertexShaderFile, const char *fragmentShaderFile) {

    this->vertexShaderID = loadShader(vertexShaderFile, GL_VERTEX_SHADER);
    this->fragmentShaderID = loadShader(fragmentShaderFile, GL_FRAGMENT_SHADER);
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

  AnimatedModelShader::~AnimatedModelShader() {

  }

  void AnimatedModelShader::bindAttribute(int index, const char *variableName) {

    glBindAttribLocation(programID, index, variableName);

    return;
  }

  void AnimatedModelShader::start(void) {

    glUseProgram(programID);

    return;
  }

  void AnimatedModelShader::stop(void) {

    glUseProgram(0);

    return;
  }

  void AnimatedModelShader::cleanUp(void) {

    stop();
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDeleteProgram(programID);

    return;
  }

  int AnimatedModelShader::getUniformLocation(const char *uniformName) {

    return glGetUniformLocation(this->programID, uniformName);
  }

  void AnimatedModelShader::getAllUniformLocations(void) {

    this->locationTransformationMatrix = getUniformLocation("transformationMatrix");
    this->locationProjectionMatrix = getUniformLocation("projectionMatrix");
    this->locationViewMatrix = getUniformLocation("viewMatrix");
    this->locationLightPosition = getUniformLocation("lightPosition");
    this->locationLightColour = getUniformLocation("lightColour");
    this->locationShine = getUniformLocation("shine");
    this->locationReflectivity = getUniformLocation("reflectivity");
    this->locationSkyColour = getUniformLocation("skyColour");
    this->locationUseFakeLightning = getUniformLocation("useFakeLightning");
    this->locationBoneTransforms = getUniformLocation("boneTransforms");
  }

  void AnimatedModelShader::loadFloat(int uniformLocation, float value) {

    glUniform1f(uniformLocation, value);
  }

  void AnimatedModelShader::loadFloatVertex(int uniformLocation, vec3 vertex) {

    glUniform3f(uniformLocation, vertex.x, vertex.y, vertex.z);
  }

  void AnimatedModelShader::loadBoolean(int uniformLocation, bool value) {

    int variable =  0;
    if (value) {
      variable = 1;
    }
    glUniform1f(uniformLocation, variable);
  }

  void AnimatedModelShader::loadMatrix(int uniformLocation, mat4 matrix) {

    float *matrixBuffer = (float *)value_ptr(matrix);
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, matrixBuffer);

    return;
  }

  void AnimatedModelShader::loadMatrixArray(int uniformLocation, mat4 *matArray, int size) {

    float *matrixBuffer = (float *)value_ptr(matArray[0]);
    glUniformMatrix4fv(uniformLocation, size, GL_FALSE, matrixBuffer);
  }

  void AnimatedModelShader::loadTransformationMatrix(mat4 matrix) {
    loadMatrix(locationTransformationMatrix, matrix);
  }

  void AnimatedModelShader::loadProjectionMatrix(mat4 matrix) {
    loadMatrix(locationProjectionMatrix, matrix);
  }

  void AnimatedModelShader::loadViewMatrix(Camera *camera) {
    mat4 viewMatrix = createViewMatrix(camera->getPosition(), camera->getPich(), camera->getYaw());
    loadMatrix(locationViewMatrix, viewMatrix);
  }

  void AnimatedModelShader::loadBoneTransforms(mat4 *boneTransforms, int size) {
    loadMatrixArray(locationBoneTransforms, boneTransforms, size);
  }

  void AnimatedModelShader::loadLight(Light *light) {
    loadFloatVertex(locationLightPosition, light->getPosition());
    loadFloatVertex(locationLightColour, light->getColour());
  }

  void AnimatedModelShader::loadShineVariables(float shine, float reflectivity) {

    loadFloat(locationShine, shine);
    loadFloat(locationReflectivity, reflectivity);
  }

  void AnimatedModelShader::loadSkyColour(float r, float g, float b) {

    loadFloatVertex(locationSkyColour, vec3(r,g,b));
  }

  void AnimatedModelShader::loadFakeLightning(bool useFakeLightning) {

    loadBoolean(locationUseFakeLightning, useFakeLightning);
  }

  int AnimatedModelShader::loadShader(const char *fileName, GLenum type) {

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

  void AnimatedModelShader::bindAttributes(void) {

    bindAttribute(0, "position");
    bindAttribute(1, "textureCoords");
    bindAttribute(2, "normal");
    bindAttribute(3, "boneIndices");
    bindAttribute(4, "weights");

    return;
  }

} // shader
