#include <iostream>
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// including relevant libraries/thingies idk the terminology.

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
} //from documentation, a function that allows errors to be echoed to me, needs declaring before GLFW init


int main() {

    std::cout << "main{} started"; //lowk just keeping this for error checking
    glfwInit();  // this neeeds to be first.


    if (!glfwInit()) //if program doesnt run glfwinit
    {
        return -1;
    }

    GLFWmonitor* monitor = glfwGetPrimaryMonitor(); //setting basic settings, not sure if this is nessessary.
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    //hints like these are to tell GLFW config of the window,

    glfwSetErrorCallback(error_callback); //telling glfw where to send errorcallbacks. function is for formatting.

    GLFWwindow* window=glfwCreateWindow(640,480,"SecondFish",NULL,NULL);
        glfwMakeContextCurrent(window);
        //whats being done here is a a function (glfwcreatewindow()) is used to create a window oject called GLFW window
        //for some reason, it must be called GLFWwindow. im not sure why.
        //actually i know why now: its because GLFWwindow is not the varaible name, its like a function that is used to
        //communicate with GLFW, variables called window.
        //

    if (!window) {
        std::cout << "Failed to create GLFW window" << '\n';
        glfwTerminate();
        return -1; //exit code -1 if window didnt create.
    }

    while (!glfwWindowShouldClose(window)) //if flag of glfwWindowShouldClose is untrue,
                                            // (should be open) in GLFW3 close button  or clsoing window sets
                                            // this to true
        glfwPollEvents(); //processes any input and returns it immidiately.



    glfwMakeContextCurrent(window); //creating the opengl instance and linking it to our GLFW window
    gladLoadGL(glfwGetProcAddress);


    return 0; //if all is good, process finishes with exit code 0
    }