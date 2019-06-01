#include "../../include/shader/ParticleShader.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace shader {

  ParticleShader::ParticleShader(const char *vertexShaderFile, const char *fragmentShaderFile) {

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

  ParticleShader::~ParticleShader() {

  }

  void ParticleShader::bindAttribute(int index, const char *variableName) {

    glBindAttribLocation(programID, index, variableName);

    return;
  }

  void ParticleShader::start(void) {

    glUseProgram(programID);

    return;
  }

  void ParticleShader::stop(void) {

    glUseProgram(0);

    return;
  }

  void ParticleShader::cleanUp(void) {

    stop();
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDeleteProgram(programID);

    return;
  }

  int ParticleShader::getUniformLocation(const char *uniformName) {

    return glGetUniformLocation(this->programID, uniformName);
  }

  void ParticleShader::getAllUniformLocations(void) {

    this->locationProjectionMatrix = getUniformLocation("projectionMatrix");
    this->locationModelViewMatrix = getUniformLocation("modelViewMatrix");
  }

  void ParticleShader::loadFloat(int uniformLocation, float value) {

    glUniform1f(uniformLocation, value);
  }

  void ParticleShader::loadFloatVertex(int uniformLocation, vec3 vertex) {

    glUniform3f(uniformLocation, vertex.x, vertex.y, vertex.z);
  }

  void ParticleShader::loadBoolean(int uniformLocation, bool value) {

    int variable =  0;
    if (value) {
      variable = 1;
    }
    glUniform1f(uniformLocation, variable);
  }

  void ParticleShader::loadMatrix(int uniformLocation, mat4 matrix) {

    float *matrixBuffer = (float *)value_ptr(matrix);
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, matrixBuffer);

    return;
  }

  void ParticleShader::loadProjectionMatrix(mat4 matrix) {
    loadMatrix(locationProjectionMatrix, matrix);
  }

  void ParticleShader::loadModelViewMatrix(mat4 matrix) {
    loadMatrix(locationModelViewMatrix, matrix);
  }

  int ParticleShader::loadShader(const char *fileName, GLenum type) {

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

  void ParticleShader::bindAttributes(void) {

    bindAttribute(0, "position");
    return;
  }

} // shader
