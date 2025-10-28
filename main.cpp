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
//
#include <Sofa.h>               //01
#include <Lighting.h>           //02
#include <Countertop.h>         //03
#include <Table.h>              //04
#include <Chair.h>              //05
#include <Refrigerator.h>       //06
#include <Closet.h>             //07
#include <Bed.h>                //08
#include <Toilet.h>             //09
#include <Sink.h>               //10
#include <Shower.h>             //11


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

    // Paredes
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
    Cube cube11(glm::vec3(4.75f, -1.8f, -3.3f));

    // Sala
    Sofa sofa1(glm::vec3(0.0f, 1.0f, -4.0f), 2.0f);
    Sofa sofa2(glm::vec3(2.5f, 1.0f, -4.0f), 2.0f);
    Sofa sofa3(glm::vec3(1.0f, 4.9f, -4.0f), 0.0f);
    Lighting ligh1(glm::vec3(1.3f, 1.0f, -3.5f));

    // Cozinha
    Countertop ctop1(glm::vec3(-6.55f, 2.5f, -3.9f), 1.0f);
    Table table1(glm::vec3(-3.5f, 3.0f, -3.8f));
    Chair chair1(glm::vec3(-4.0f, 3.8f, -4.0f), 0.0f);
    Chair chair2(glm::vec3(-3.0f, 3.8f, -4.0f), 0.0f);
    Chair chair3(glm::vec3(-3.0f, 2.25f, -4.0f), 2.0f);
    Chair chair4(glm::vec3(-4.0f, 2.25f, -4.0f), 2.0f);
    Refrigerator ref1(glm::vec3(-6.55f, 4.8f, -3.5f), 1.0f);
    Closet closet1(glm::vec3(-6.55f, 2.2f, -2.3f), 0.0f);

    //Quarto
    Bed bed1(glm::vec3(-5.55f, -2.5f, -4.2f), 0.0f);
    Lighting ligh2(glm::vec3(-6.5f, -1.3f, -3.5f));
    Lighting ligh3(glm::vec3(-6.5f, -3.7f, -3.5f));
    Table table2(glm::vec3(0.0, -3.8f, -3.8f));
    Chair chair5(glm::vec3(0.0f, -3.2f, -4.0f), 0.0f);
    Closet closet2(glm::vec3(0.3f, -0.2f, -2.9f), 1.0f);

    //Banheiro
    Toilet toilet1(glm::vec3(3.0f, 0.0f, -4.0f), 0.0f);
    Sink sink1(glm::vec3(3.0f, -4.1f, -3.95f), 0.0f);
    Shower shower1(glm::vec3(6.7f, -1.7f, -1.7f), 0.0f);

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


        // Paredes
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
        cube11.scale = glm::vec3(0.15f, 2.5f, 2.0f);

        // Sala
        sofa1.scale = glm::vec3(0.5f, 0.5f, 0.5f);
        sofa2.scale = glm::vec3(0.5f, 0.5f, 0.5f);
        sofa3.scale = glm::vec3(1.5f, 0.5f, 0.5f);
        ligh1.scale = glm::vec3(0.4f, 0.4f, 0.4f);

        // Cozinha
        ctop1.scale = glm::vec3(0.7f, 1.2f, 0.6f);
        table1.scale = glm::vec3(1.2f, 0.5f, 0.6f);
        chair1.scale = glm::vec3(0.3f, 0.3f, 0.3f);
        chair2.scale = glm::vec3(0.3f, 0.3f, 0.3f);
        chair3.scale = glm::vec3(0.3f, 0.3f, 0.3f);
        chair4.scale = glm::vec3(0.3f, 0.3f, 0.3f);
        ref1.scale = glm::vec3(0.7f, 0.7f, 0.7f);
        closet1.scale = glm::vec3(0.5f, 1.4f, 0.2f);

        // Quarto
        bed1.scale = glm::vec3(0.8f, 0.8f, 0.6f);
        ligh2.scale = glm::vec3(0.4f, 0.4f, 0.4f);
        ligh3.scale = glm::vec3(0.4f, 0.4f, 0.4f);
        table2.scale = glm::vec3(0.5f, 0.4f, 0.6f);
        chair5.scale = glm::vec3(0.3f, 0.3f, 0.3f);
        closet2.scale = glm::vec3(1.5f, 1.2f, 0.9f);

        //Banheiro
        toilet1.scale = glm::vec3(0.4f, 0.4f, 0.4f);
        sink1.scale = glm::vec3(0.4f, 0.4f, 0.4f);
        shower1.scale = glm::vec3(0.8f, 0.8f, 0.8f);


        shader.setMat4("model", model);

        // Paredes
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
        cube11.draw(shader, model);

        // Sala
        sofa1.draw(shader, model);
        sofa2.draw(shader, model);
        sofa3.draw(shader, model);
        ligh1.draw(shader, model);

        // Cozinha
        ctop1.draw(shader, model);
        table1.draw(shader, model);
        chair1.draw(shader, model);
        chair2.draw(shader, model);
        chair3.draw(shader, model);
        chair4.draw(shader, model);
        ref1.draw(shader, model);
        closet1.draw(shader, model);

        // Quarto
        bed1.draw(shader, model);
        ligh2.draw(shader, model);
        ligh3.draw(shader, model);
        table2.draw(shader, model);
        chair5.draw(shader, model);
        closet2.draw(shader, model);

        //Banheiro
        toilet1.draw(shader, model);
        sink1.draw(shader, model);
        shower1.draw(shader, model);


        // Swap buffers e eventos
        glfwSwapBuffers(app.getWindow());
        glfwPollEvents();
    }

    return 0;
}
