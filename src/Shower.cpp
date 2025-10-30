#include "Shower.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"

extern unsigned int steelTexture;

Shower::Shower(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave será um "sub-modelo"

    init();
}

Shower::Shower(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Shower::init() {
    if (angle == 0.0f)
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.0f, 0.2f, 0.0f),     // posição
            glm::vec3(2.0f, 0.0f, 0.0f),    // rotação (eixo)
            glm::vec3(0.05f, 0.6, 0.05f),     // escala
            45  // Angulo
        ));
    else if (angle == 1.0f)
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.0f, 0.2f, 0.0f),     // posição
            glm::vec3(0.0f, 0.0f, 2.0f),    // rotação (eixo)
            glm::vec3(0.05f, 0.6, 0.05f),     // escala
            45  // Angulo
        ));
    else if (angle == 2.0f)
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.0f, 0.2f, 0.0f),     // posição
            glm::vec3(-2.0f, 0.0f, 0.0f),    // rotação (eixo)
            glm::vec3(0.05f, 0.6, 0.05f),     // escala
            45  // Angulo
        ));
    else if (angle == 3.0f)
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.0f, 0.2f, 0.0f),     // posição
            glm::vec3(0.0f, 0.0f, -2.0f),    // rotação (eixo)
            glm::vec3(0.05f, 0.6, 0.05f),     // escala
            45  // Angulo
        ));
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0, 0.0f, 0.0),     // posição
        glm::vec3(0.0f, 0.0f, 0.0),    // rotação (eixo)
        glm::vec3(0.5f, 0.1f, 0.5f),      // escala
        0  // Angulo
    ));
}

void Shower::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, steelTexture);
    for (auto &part : parts) {
        part->draw(shader, model);
    }
}
