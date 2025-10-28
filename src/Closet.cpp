#include "Closet.h"
#include "Cube.h"

Closet::Closet(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave será um "sub-modelo"

    init();
}

Closet::Closet(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Closet::init() {
    float a = 0.0f;
    switch ((int)angle) {
    case 1:
        a = 90.0f;
        break;
    case 2:
        a = 180.0f;
        break;
    case 3:
        a = 270.0f;
        break;
    }

    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 1.0f),      // rotação (eixo)
        glm::vec3(0.8f, 2.0f, 3.0f),      // escala
        a // Angulo
    ));
}

void Closet::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    for (auto &part : parts) {
        part->draw(shader, model);
    }
}
