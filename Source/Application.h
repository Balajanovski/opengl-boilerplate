#ifndef OPENGL_BOILERPLATE_APPLICATION_H
#define OPENGL_BOILERPLATE_APPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application {
public:
    Application();
    ~Application();
    void run_loop();
private:
    GLFWwindow* window;

    constexpr static int WINDOW_WIDTH = 800;
    constexpr static int WINDOW_HEIGHT = 600;
    constexpr static int MS_PER_UPDATE = 2;
};


#endif //OPENGL_BOILERPLATE_APPLICATION_H
