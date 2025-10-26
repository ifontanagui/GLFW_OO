#include "Toilet.h"
#include "Cylinder.h"
#include "Cube.h"

Toilet::Toilet(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave será um "sub-modelo"

    init();
}

Toilet::Toilet(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Toilet::init() {
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(1.1f, 1.0f, 1.1f),      // escala
        0   // Angulo
    ));
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.8f, -0.5f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(1.1f, 1.1f, 0.4f),      // escala
        0   // Angulo
    ));
}

void Toilet::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    for (auto &part : parts) {
        part->draw(shader, model);
    }
}
