#include "Chair.h"
#include "Cube.h"
#include "Cylinder.h"

extern unsigned int woodTexture;
extern unsigned int steelTexture;

Chair::Chair(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

Chair::Chair(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Chair::init() {
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.8f, 0.0f),     // posição
        glm::vec3(1.0f, 1.0f, 1.0f),      // rotação (eixo)
        glm::vec3(2.0f, 0.2f, 2.0f),      // escala
        0   // Angulo
    ));

    if  (angle == 0.0) {
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.75f, 1.1f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 3.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.75f, 1.1f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 3.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.75f, 0.0f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 1.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.75f, 0.0f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 1.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 2.5f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.0f, 0.2f, 1.0f),      // escala
            90   // Angulo
        ));
    }
    else if (angle == 1.0) {
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.75f, 1.1f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 3.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.75f, 0.0f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 1.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.75f, 1.1f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 3.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.75f, 0.0f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 1.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.75f, 2.5f, 0.0f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 2.0f, 1.0f),      // escala
            90   // Angulo
        ));
    }
    else if (angle == 2.0) {
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.75f, 0.0f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 1.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.75f, 0.0f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 1.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.75f, 1.1f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 3.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.75f, 1.1f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 3.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 2.5f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.0f, 0.2f, 1.0f),      // escala
            90   // Angulo
        ));
    }
    else if (angle == 3.0) {
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.75f, 0.0f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 1.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.75f, 1.1f, 0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 3.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.75f, 0.0f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 1.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.75f, 1.1f, -0.75f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 3.5f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.75f, 2.5f, 0.0f),     // posição
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 2.0f, 1.0f),      // escala
            90   // Angulo
        ));
    }
}

void Chair::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, woodTexture);
    parts[0]->draw(shader, model);
    parts[5]->draw(shader, model);

    glBindTexture(GL_TEXTURE_2D, steelTexture);
    for (int i = 1; i < 5; i ++)
        parts[i]->draw(shader, model);
}

