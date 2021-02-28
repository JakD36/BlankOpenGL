#define GLEW_STATIC

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace std;

int main()
{
    const struct aiScene* scene = aiImportFile("Torch.obj",aiProcess_Triangulate | aiProcess_CalcTangentSpace);

    cout << "Hello World" << endl;

    glfwInit();

#ifdef __APPLE__
    // Following two lines are required for running on mac
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1 );

    auto* window = glfwCreateWindow(400,400,"Test", nullptr, nullptr);
    if(!window)
    {
        cout << "Failed to create window" << endl;
        exit(2);
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    auto status = glewInit();

    glfwSwapInterval(1);
    glfwWindowHint(GLFW_SAMPLES,32);
    glfwWindowHint(GLFW_STEREO, GL_FALSE);

    while(glfwGetTime() < 5)
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    return 0;
}
