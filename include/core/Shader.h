#ifndef GLFW_CLIENT_SHADER_H
#define GLFW_CLIENT_SHADER_H
#include "../incs.h"

class Shader {
private:
    int shaderProgrammID;
    bool beeingUsed;

    const char* vertexSources;
    const char* fragmentSources;
    const char* filePath;

public:
    Shader(const char* filePath);
    void compile();
    void use();
    void detach();

    void uploadMat4f(const char* varName, glm::mat4 mat4);
    void uploadMat3f(const char* varName, glm::mat3 mat3);
    void uploadVec4f(const char* varName, glm::vec4 vec4);
    void uploadVec3f(const char* varName, glm::vec3 vec3);
    void uploadVec2f(const char* varName, glm::vec2 vec2);
    void uploadFloat(const char* varName, float value);
    void uploadInt(const char* varName, int value);
    void uploadIntArray(const char* varName, int array[]);
    void uploadTexture(const char* varName, int slot);



};


#endif
