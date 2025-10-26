#include "Bed.h"
#include "Cube.h"
#include "Cylinder.h"

Bed::Bed(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave será um "sub-modelo"

    init();
}

Bed::Bed(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Bed::init() {
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(3.0f, 1.0f, 2.2f),      // escala
        0   // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(1.3f, -0.55f, 0.9f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.2f, 0.3f, 0.2f),      // escala
        0  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(-1.3f, -0.55f, 0.9f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.2f, 0.3f, 0.2f),      // escala
        0  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(1.3f, -0.55f, -0.9f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.2f, 0.3f, 0.2f),      // escala
        0  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(-1.3f, -0.55f, -0.9f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.2f, 0.3f, 0.2f),      // escala
        0  // Angulo
    ));
}

void Bed::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    for (auto &part : parts) {
        part->draw(shader, model);
    }
}

