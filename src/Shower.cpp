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
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posição
        glm::vec3(1.0f, 0.0f, -1.5f),    // rotação (eixo)
        glm::vec3(0.05f, 0.5f, 0.05f),     // escala
        90  // Angulo
    ));
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(-0.15f, 0.0f, -0.2f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0),    // rotação (eixo)
        glm::vec3(0.5f, 0.5f, 0.1f),      // escala
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
