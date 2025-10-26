#include "Sofa.h"
#include "Cube.h"
#include "Cylinder.h"

Sofa::Sofa(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave será um "sub-modelo"

    init();
}

Sofa::Sofa(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Sofa::init() {
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(3.0f, 0.6f, 1.3f),      // escala
        0   // Angulo
    ));
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.4f, 0.5f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(3.0f, 1.1f, 0.3f),      // escala
        0   // Angulo
    ));
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(1.35f, 0.4f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.3f, 1.1f, 1.3f),      // escala
        0   // Angulo
    ));
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(-1.35f, 0.4f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.3f, 1.1f, 1.3f),      // escala
        0   // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(1.3f, -0.4f, 0.45f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.2f, 0.3f, 0.2f),      // escala
        0  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(-1.3f, -0.4f, 0.45f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.2f, 0.3f, 0.2f),      // escala
        0  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(1.3f, -0.4f, -0.45f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.2f, 0.3f, 0.2f),      // escala
        0  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(-1.3f, -0.4f, -0.45f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.2f, 0.3f, 0.2f),      // escala
        0  // Angulo
    ));
}

void Sofa::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    for (auto &part : parts) {
        part->draw(shader, model);
    }
}

