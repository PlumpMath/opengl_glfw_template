//#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <glew.h>
#include "GLFW/glfw3.h" // GLFW helper library
#include "glm/glm.hpp"
#include <iostream>
#include "loadShaders.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using namespace glm;

void glfw_init() {
    //  1. initialise the glfw
    if (!glfwInit()) {
        cerr << "Failed to inialise the glfwn";
        exit(-1);
    }

//  2. setting to make os x happy
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *createWindow() {
    GLFWwindow *window = glfwCreateWindow(1024, 768, "Jellyshen", NULL, NULL);
    if (window == NULL) {
        cerr << "Failed to open glfw window\n";
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    return window;
}

void glew_init() {
    //    3. initialise glew
    glewExperimental = true;

    if (glewInit() != GLEW_OK) {
        cerr << "Failed to inialise glew\n";
        exit(-2);
    }
}

int main() {

    glfw_init();
    GLFWwindow *window = createWindow();
    glew_init();

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

//    main loop
    do {
        //doing nothing, needing code here

        //swap buffer

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    glfwTerminate();
}