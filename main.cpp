#include <iostream>
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Player.h" //including our player class header

// including relevant libraries/thingies idk the terminology.

// ---------------------------------------------Function for error calling -----------------------------------
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
} //from documentation, a function that allows errors to be echoed to me, needs declaring before GLFW init



//fish coordinates
float fishX = 0.0;
float fishY = 0.0;
//keys set to not pressed initially. Not used at the moment
bool running = true;
bool wpressed = false;
bool spressed = false;
bool apressed = false;
bool dpressed = false;

// object coordinates,, for now before main, these hold coordinates for our first object.
float vertices []={
    0.5,0.5,0,
    0.5,-0.5,0,
    -0.5,-0.5,0
}; //  a VBO (vertex bugger object) is used in OPENGL to send coordinates to the GPU all at once. VBOS can store
//loads of vertices in GPU memory which makes it really fast
//
//global for now... maybe later div into classes. for now (and to not lose my mind and quit) ill do it global;.

/*
unsigned int VBO;

glGenBuffers(1, &VBO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
*/ //interestingly,. this cant be defined outside of a function....moved to main.

//vertext shaders, for now before main,  should ideally be split into its own GLSL File.
const char* vertexshadersource = R"(
#version 330 core
layout (location = 0) in vec3 position;
void main()
{
gl_Position = vec4(position.x, position.y, position.z, 1.0);
}
)";
 // this is funky, im doingit all in string in main.cpp but could be its own glsl file, essentially  


//-------------------------------------------------main game function ---------------------------------------
int main() {


    std::cout << "main{} started"; //lowk just keeping this for error checking
    glfwInit();  // this neeeds to be first.

    if (!glfwInit()) //if program doesnt run glfwinit
    {
        std::cout << "Failed to init GLFW window" << std::endl;
        return -1;
    }

    //initialisation stuff
    GLFWmonitor* monitor = glfwGetPrimaryMonitor(); //setting basic settings, not sure if this is nessessary.
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    //hints like these are to tell GLFW config of the window,
    glfwSetErrorCallback(error_callback); //telling glfw where to send errorcallbacks. function is for formatting.
    GLFWwindow* window=glfwCreateWindow(640,480,"SecondFish",nullptr, nullptr);
    glfwMakeContextCurrent(window);
    //whats being done here is a a function (glfwcreatewindow()) is used to create a window oject called GLFW window
    //for some reason, it must be called GLFWwindow. im not sure why.
    //actually i know why now: its because GLFWwindow is not the varaible name, its like a function that is used to
    //communicate with GLFW, variables called window.
    //

    // if window doesnt create, terminate the program.
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1; //exit code -1 if window didnt create.
    }

    //open gl api: creation
    glfwMakeContextCurrent(window); //creating the opengl instance and linking it to our GLFW window
    gladLoadGL(glfwGetProcAddress); //connects glad to glfw
    glViewport(0,0,640,480); //tells opengl our boundaries for the program, first two bottom left last two TR
    //you could implement resizing gl window via learnopengl documentation, i decided not to.

    // variable time tracks time since program initalised.
    double time = glfwGetTime();


    //prototying (telling it it exists) the void keycallback function ( which is decalred i the other section)
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods); //prototype forward declaration so that main knows hat keycallback is

    //GLFW sets key callback to our new keycallback function, so it will tell you when a key is pressed
    glfwSetKeyCallback(window,key_callback);


    //shader stuff  - prototyping VBO and VAO, im not sure ill be using VAO, but VBO is  the buffer (carrier) of my vertices to the gpu
    unsigned int VBO;
    unsigned int VAO;

    //
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int vertexshader;
    vertexshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexshader, 1, &vertexshadersource, NULL);
    glCompileShader(vertexshader);


    int  success;
    char infoLog[512];
    glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &success);


    if(!success)
    {
        glGetShaderInfoLog(vertexshader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    while (!glfwWindowShouldClose(window)) //if flag of glfwWindowShouldClose is untrue, /MAIN GAME LOOP!!!!
    {

    // OPENGL.
        glClearColor(0.2f, 0.3f, 0.6f, 1.0f); //specifiying bit /  colors for GLCCOLOR (BLUE)
        glClear(GL_COLOR_BUFFER_BIT); //glClear is a function that passes bits that you previously set BACKGROUND








        // input sensing and buffer swapping.
        glfwPollEvents(); //processes any input and returns it immidiately.
        glfwSwapBuffers(window); // not sure what this does., documentation says that two buffers exist, one for display one for rednering, and this swaps them.
    }


    //end of main function
    std::cout << "\n" << time << "\n";
    return 0; //if all is good, process finishes with exit code 0

    }

// -------------------------------------------------other / helper functions -------------------------------------

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    }

    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        std::cout << "W" << std::endl;
        wpressed = true;
    }

    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        std::cout << "S" << std::endl;
        spressed = true;
    }

    if (key == GLFW_KEY_E && action == GLFW_PRESS) {
        std::cout << "A" << std::endl;
        apressed = true;
    }

    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        std::cout << "D" << std::endl;
        dpressed = true;

    }
}