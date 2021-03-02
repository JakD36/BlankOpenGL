#define GLEW_STATIC

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define IMGUI_IMPL_OPENGL_LOADER_GLEW
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#include <imgui.cpp>
#include <imgui_demo.cpp>
#include <imgui_draw.cpp>
#include <imgui_tables.cpp>
#include <imgui_widgets.cpp>
#include <backends/imgui_impl_opengl3.cpp>
#include <backends/imgui_impl_glfw.cpp>

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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410 core");

    while(glfwGetTime() < 5)
    {
        glfwPollEvents();
        glfwSwapBuffers(window);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Render();
    }

    glfwDestroyWindow(window);

    return 0;
}
