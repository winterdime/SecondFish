#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// including relevant libraries/thingies idk the terminology.


int main() {

    for (int i = 1; i <= 5; i++) {
        std::cout << "i = " << i << std::endl; //lowk just keeping this for error checking

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //hints like these are to tell GLFW config of the window
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window=glfwCreateWindow(800,500,"SecondFish",nullptr,nullptr);
        //whats being done here is a a function (glfwcreatewindow()) is used to create a window oject called GLFW window
        //for some reason, it must be called GLFWwindow. im not sure why.

        if (window==nullptr) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;

        }
        glfwMakeContextCurrent(window);



    }

    return 0;
}