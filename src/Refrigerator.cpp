#include "Refrigerator.h"
#include "Cube.h"

extern unsigned int steelTexture1;

Refrigerator::Refrigerator(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

Refrigerator::Refrigerator(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Refrigerator::init() {
    float a = 0.0f;
    if (angle  == 1.0f || angle == 3.0f)
        a = 90.0f;

    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.0f, 0.0f),      // posição
        glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
        glm::vec3(1.2f, 2.2f, 0.8),       // escala
        a   // Angulo
    ));

    if (angle == 0.0f) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, -0.7f, 0.4f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.15f, 0.7f, 0.05f),    // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.4f, 0.4f),       // posição
            glm::vec3(0.0f, 1.0f, 0.0f),       // rotação (eixo)
            glm::vec3(1.15f, 1.4f, 0.05f),     // escala
            0   // Angulo
        ));
    }
    else if (angle == 1.0f) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.4f, -0.7f, 0.0f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.15f, 0.7f, 0.05f),    // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.4f, 0.4f, 0.0f),       // posição
            glm::vec3(0.0f, 1.0f, 0.0f),       // rotação (eixo)
            glm::vec3(1.15f, 1.4f, 0.05f),     // escala
            90  // Angulo
        ));
    }
    else if (angle == 2.0f) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, -0.7f, -0.4f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.15f, 0.7f, 0.05f),    // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.4f, -0.4f),       // posição
            glm::vec3(0.0f, 1.0f, 0.0f),       // rotação (eixo)
            glm::vec3(1.15f, 1.4f, 0.05f),     // escala
            0   // Angulo
        ));
    }
    else if (angle == 3.0f) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.4f, -0.7f, 0.0f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.15f, 0.7f, 0.05f),    // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.4f, 0.4f, 0.0f),       // posição
            glm::vec3(0.0f, 1.0f, 0.0f),       // rotação (eixo)
            glm::vec3(1.15f, 1.4f, 0.05f),     // escala
            90  // Angulo
        ));
    }
}

void Refrigerator::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, steelTexture1);
    for (int i = 0; i < 3; i ++)
        parts[i]->draw(shader, model);
}
