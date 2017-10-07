#include "Application.h"

#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Application::Application() {
// Initialise GLFW
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

// Create GLFW window
        window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", NULL, NULL);
        if (window == NULL) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }
        glfwMakeContextCurrent(window);

// Initialise GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD");
        }

// Set the viewport size and resize function
        glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
        glfwSetFramebufferSizeCallback(window,
        [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });

}

void Application::run_loop() {
    // Game loop
    int last_ticks = 0,
            lag = 0;
    while (/* TODO: Game not ended */) {
        // TODO: Take controls

        int current_ticks = glfwGetTime();
        int elapsed = current_ticks - last_ticks;
        last_ticks = current_ticks;
        lag += elapsed;

        // While the game is lagging
        while (lag >= MS_PER_UPDATE) {
            // Update the game's internal state
            lag -= MS_PER_UPDATE;
        }

        // TODO: Draw to window
    }
}