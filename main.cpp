#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Shader.h>
#include <Application.h>
#include <Texture.h>
#include <iostream>
#include <Cube.h>
#include <Sofa.h>
#include <Lighting.h>
#include <Countertop.h>


int main() {
    // Cria janela e inicializa OpenGL
    Application app(1024, 768, "Cubos OOP");
    if (!app.init()) return -1;

    // Shader
    Shader shader("vertex.glsl", "fragment.glsl");
    shader.use();

    // Carrega texturas
    Texture tex1("quadri.jpg");
    //Texture tex2("opengl.png");  // logo OpenGL com alpha

    shader.setInt("texture1", 0);
    //shader.setInt("texture2", 1);

    // Paredes da Casa
    Cube cube1(glm::vec3(6.9f, -2.0f, -2.5f));
    Cube cube2(glm::vec3(2.5f, 0.5f, -2.5f));
    Cube cube3(glm::vec3(0.0f, -4.5f, -2.5f));
    Cube cube4(glm::vec3(2.0f, -3.25f, -2.5f));
    Cube cube5(glm::vec3(2.0f, -0.25f, -2.5f));
    Cube cube6(glm::vec3(-7.0f, 0.4f, -2.5f));
    Cube cube7(glm::vec3(-1.1f, 5.5f, -2.5f));
    Cube cube8(glm::vec3(4.75f,4.5f, -2.5f));
    Cube cube9(glm::vec3(4.75f, 1.25f, -2.5f));
    Cube cube10(glm::vec3(-5.5f, 0.5f, -2.5f));

    Sofa sofa1(glm::vec3(0.0f, 1.0f, -4.0f), 2.0f);
    Sofa sofa2(glm::vec3(2.5f, 1.0f, -4.0f), 2.0f);
    Sofa sofa3(glm::vec3(1.0f, 5.0f, -4.0f), 0.0f);
    Lighting ligh1(glm::vec3(1.3f, 1.0f, -3.5f));

    Countertop ctop1(glm::vec3(-6.6f, 1.5f, -3.9f), 1.0f);


    // Ativa depth test
    glEnable(GL_DEPTH_TEST);

    // Loop principal
    while (!glfwWindowShouldClose(app.getWindow())) {
        // Processa input
        if (glfwGetKey(app.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(app.getWindow(), true);

        // Limpa tela e depth buffer
        //glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClearColor(0.7f, 0.5f, 0.1f, 1.0f);
        //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();

        // Configura view e projection
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                800.0f / 600.0f,
                                                0.1f, 100.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.0f, -15.0f));
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);

        // Bind texturas
        tex1.bind(0);
        //tex2.bind(1);


        float angle = 15.6f;
        glm::mat4 model = glm::mat4(2.0f);
        model = glm::rotate(model, (angle * (float) glfwGetTime()) / 20, glm::vec3(3.5f, -3.25f, 0.75f));


        cube1.scale = glm::vec3(0.25f, 5.0f, 3.5f);
        cube2.scale = glm::vec3(9.0f, 0.25f, 3.5f);
        cube3.scale = glm::vec3(14.0f, 0.25f, 3.5f);
        cube4.scale = glm::vec3(0.25f, 2.5f, 3.5f);
        cube5.scale = glm::vec3(0.25f, 1.5f, 3.5f);
        cube6.scale = glm::vec3(0.25f, 10.0f, 3.5f);
        cube7.scale = glm::vec3(12.0f, 0.25f, 3.5f);
        cube8.scale = glm::vec3(0.25, 2.0f, 3.5f);
        cube9.scale = glm::vec3(0.25, 1.5f, 3.5f);
        cube10.scale = glm::vec3(3.0f, 0.25f, 3.5f);

        sofa1.scale = glm::vec3(0.5f, 0.5f, 0.5f);
        sofa2.scale = glm::vec3(0.5f, 0.5f, 0.5f);
        sofa3.scale = glm::vec3(1.5f, 0.5f, 0.5f);
        ligh1.scale = glm::vec3(0.4f, 0.4f, 0.4f);

        ctop1.scale = glm::vec3(0.6f, 0.6f, 0.6f);

        shader.setMat4("model", model);
        cube1.draw(shader, model);
        cube2.draw(shader, model);
        cube3.draw(shader, model);
        cube4.draw(shader, model);
        cube5.draw(shader, model);
        cube6.draw(shader, model);
        cube7.draw(shader, model);
        cube8.draw(shader, model);
        cube9.draw(shader, model);
        cube10.draw(shader, model);

        sofa1.draw(shader, model);
        sofa2.draw(shader, model);
        sofa3.draw(shader, model);
        ligh1.draw(shader, model);

        ctop1.draw(shader, model);


        // Swap buffers e eventos
        glfwSwapBuffers(app.getWindow());
        glfwPollEvents();
    }

    return 0;
}
