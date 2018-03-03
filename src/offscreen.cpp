#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    // Set the error callback before any other GLFW calls so we get proper error reporting
    glfwSetErrorCallback([](int error, const char *description) {
        std::cerr << "ERROR: (" << error << ") " << description << std::endl;
    });

    if (glfwInit() == 0) {
        std::cerr << "GLFW init failed" << std::endl;
        return EXIT_FAILURE;
    }

    // can only do OpenGL 2.1 with default linux OS Mesa install
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    int width = 640;
    int height = 480;

    GLFWwindow *window = glfwCreateWindow(width, height, "", nullptr, nullptr);

    if (window == nullptr) {
        glfwTerminate();
        std::cerr << "GLFW window creation failed" << std::endl;
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)) == 0) {
        glfwDestroyWindow(window);
        glfwTerminate();
        std::cerr << "Failed load OpenGL" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "\nOpenGL version " << GLVersion.major << "." << GLVersion.minor << " loaded.\n" << std::endl;

    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}
