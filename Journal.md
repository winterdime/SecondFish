10/10

installed OpenGL, GLFW, GLEW using Homebrew, decided glew was bad and wanted to get glad. 
getting glad was a pain in the ass. - apparently its more modern and better, but cant just link to it, 
had to place it into my directory, and then link to it

Seems like CMAKELISTS.txt is a file that CMAKE refers to when building your program and you must link everything you
want to use when you begin, its confusing and doesnt teach me much.  for now, i got the cmakelists template off of 
an LLM. and it seems to work. maybe ill be able to remmeber this stuff one day. ive tagged it up with comments so
i understand roughly whats happening

in terms of project tree:

3rd party - a file i had to make to hold the GLAD files

cmake-build-debug - CMAKE made this, i probably dont ever touch it

CMakeLists.txt - Cmake uses this to link thinks and almost like an init file, a config file to see what parameters 
are used for things  (i have no idea what im talking about)

main.cpp - main program file.

External libraries:
his section lists all the header files, SDKs, and pre-compiled libraries that your project depends on (LLM)

Scratches and Consoles: 

A built-in scratchpad area in JetBrains IDEs where you can quickly write, test, or experiment with temporary code 
snippets, SQL queries, or text notes without adding them to any specific project folder.


I will try to be able to spawn an instance of a window.

12/10

glfwDestroyWindow(window); is used when you want to quit program. save for later

what i did:
got window to work, required me to reorder some of the code to properly name window and instanciate it
added if !window for if it doesnt open 

added error callback

16/10

not really sure what to do now, will try to find documentation on 2d games using OPENGl
