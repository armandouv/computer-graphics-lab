#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow *window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
    glfwInit();
    //Verificación de compatibilidad
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL);
    glfwSetFramebufferSizeCallback(window, resize);

    //Verificación de errores de creacion  ventana
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    //Verificación de errores de inicialización de glew

    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialise GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    // Imprimimos informacin de OpenGL del sistema
    std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    std::string base_path{"/home/armandouv/Documents/Projects/computer-graphics-lab/P1/ejercicio/Shader/"};
    Shader OurShader(base_path + "core.vs", base_path + "core.frag");


    // Set up vertex data (and buffer(s)) and attribute pointers
    float vertices[] = {
            // Primera figura
            -0.8f, 0.5f, 0.0f, 0.25f, 0.16f, 0.48f,
            -0.7f, 0.5f, 0.0f, 0.25f, 0.16f, 0.48f,
            -0.7f, 0.4f, 0.0f, 0.25f, 0.16f, 0.48f,

            -0.7f, 0.4f, 0.0f, 0.25f, 0.16f, 0.48f,
            -0.6f, 0.4f, 0.0f, 0.25f, 0.16f, 0.48f,
            -0.7f, 0.5f, 0.0f, 0.25f, 0.16f, 0.48f,

            -0.7f, 0.5f, 0.0f, 0.0f, 0.56f, 0.81f,
            -0.6f, 0.5f, 0.0f, 0.0f, 0.56f, 0.81f,
            -0.6f, 0.4f, 0.0f, 0.0f, 0.56f, 0.81f,

            -0.6f, 0.4f, 0.0f, 1.0f, 0.81f, 0.2f,
            -0.6f, 0.6f, 0.0f, 1.0f, 0.81f, 0.2f,
            -0.4f, 0.4f, 0.0f, 1.0f, 0.81f, 0.2f,

            -0.6f, 0.6f, 0.0f, 1.0f, 0.1f, 0.14f,
            -0.4f, 0.6f, 0.0f, 1.0f, 0.1f, 0.14f,
            -0.4f, 0.4f, 0.0f, 1.0f, 0.1f, 0.14f,

            -0.4f, 0.4f, 0.0f, 0.0f, 0.67f, 0.24f,
            -0.3f, 0.4f, 0.0f, 0.0f, 0.67f, 0.24f,
            -0.3f, 0.5f, 0.0f, 0.0f, 0.67f, 0.24f,
            -0.4f, 0.5f, 0.0f, 0.0f, 0.67f, 0.24f,

            -0.3f, 0.4f, 0.0f, 1.0f, 0.03f, 0.46f,
            -0.3f, 0.5f, 0.0f, 1.0f, 0.03f, 0.46f,
            -0.2f, 0.4f, 0.0f, 1.0f, 0.03f, 0.46f,

            -0.3f, 0.5f, 0.0f, 1.0f, 0.49f, 0.29f,
            -0.2f, 0.4f, 0.0f, 1.0f, 0.49f, 0.29f,
            -0.1f, 0.5f, 0.0f, 1.0f, 0.49f, 0.29f,

            // Segunda figura
            0.5f, -0.7f, 0.0f, 1.0f, 0.81f, 0.2f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.81f, 0.2f,
            0.3f, -0.5f, 0.0f, 1.0f, 0.81f, 0.2f,

            0.5f, -0.7f, 0.0f, 1.0f, 0.1f, 0.14f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.1f, 0.14f,
            0.7f, -0.5f, 0.0f, 1.0f, 0.1f, 0.14f,

            0.5f, -0.5f, 0.0f, 1.0f, 0.49f, 0.29f,
            0.5f, -0.4f, 0.0f, 1.0f, 0.49f, 0.29f,
            0.6f, -0.4f, 0.0f, 1.0f, 0.49f, 0.29f,

            0.5f, -0.5f, 0.0f, 0.25f, 0.16f, 0.48f,
            0.5f, -0.4f, 0.0f, 0.25f, 0.16f, 0.48f,
            0.45f, -0.45f, 0.0f, 0.25f, 0.16f, 0.48f,

            0.5f, -0.4f, 0.0f, 0.25f, 0.16f, 0.48f,
            0.45f, -0.45f, 0.0f, 0.25f, 0.16f, 0.48f,
            0.45f, -0.35f, 0.0f, 0.25f, 0.16f, 0.48f,

            0.45f, -0.35f, 0.0f, 0.0f, 0.56f, 0.81f,
            0.45f, -0.45f, 0.0f, 0.0f, 0.56f, 0.81f,
            0.4f, -0.4f, 0.0f, 0.0f, 0.56f, 0.81f,

            0.5f, -0.4f, 0.0f, 1.0f, 0.03f, 0.46f,
            0.6f, -0.4f, 0.0f, 1.0f, 0.03f, 0.46f,
            0.55f, -0.35f, 0.0f, 1.0f, 0.03f, 0.46f,

            0.5f, -0.4f, 0.0f, 0.0f, 0.67f, 0.24f,
            0.55f, -0.35f, 0.0f, 0.0f, 0.67f, 0.24f,
            0.5f, -0.3f, 0.0f, 0.0f, 0.67f, 0.24f,
            0.45f, -0.35f, 0.0f, 0.0f, 0.67f, 0.24f
    };
    unsigned int indices[] = {  // note that we start from 0!
            // 0,2,1
    };


    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Enlazar  Vertex Array Object
    glBindVertexArray(VAO);

    //2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 4. Despues colocamos las caracteristicas de los vertices

    //Posicion
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) 0);
    glEnableVertexAttribArray(0);

    //Color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) (3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);


    glBindVertexArray(0); // Desenlazamos de memoria el VAO



    while (!glfwWindowShouldClose(window)) {
        // Checa si un eveneto ha sido activado y manda a llamar al callback correspondiente
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // Dibujar aquí
        OurShader.Use();
        glBindVertexArray(VAO);
        glPointSize(20);
        //glDrawElements(GL_TRIANGLES,3, GL_UNSIGNED_INT, (GLvoid*)(3*sizeof(GLfloat)));
        glDrawArrays(GL_TRIANGLES, 0, 15);
        glDrawArrays(GL_TRIANGLE_FAN, 15, 4);
        glDrawArrays(GL_TRIANGLES, 19, 27);
        glDrawArrays(GL_TRIANGLE_FAN, 46, 4);

        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return EXIT_SUCCESS;
}

void resize(GLFWwindow *window, int width, int height) {
    // Set the Viewport to the size of the created window
    glViewport(0, 0, width, height);
    //glViewport(0, 0, screenWidth, screenHeight);
}