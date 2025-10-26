#include "Table.h"
#include "Cube.h"
#include "Cylinder.h"

Table::Table(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

Table::Table(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Table::init() {
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.0f, 0.75f),     // posi��o
        glm::vec3(1.0f, 1.0f, 1.0f),      // rota��o (eixo)
        glm::vec3(2.0f, 2.0f, 0.2f),      // escala
        0   // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(0.75f, 0.75f, 0.0f),     // posi��o
        glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
        glm::vec3(0.2f, 1.5f, 0.2f),      // escala
        90  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(-0.75f, 0.75f, 0.0f),     // posi��o
        glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
        glm::vec3(0.2f, 1.5f, 0.2f),      // escala
        90  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(0.75f, -0.75f, 0.0f),     // posi��o
        glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
        glm::vec3(0.2f, 1.5f, 0.2f),      // escala
        90  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(-0.75f, -0.75f, 0.0f),     // posi��o
        glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
        glm::vec3(0.2f, 1.5f, 0.2f),      // escala
        90  // Angulo
    ));
}

void Table::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    for (auto &part : parts) {
        part->draw(shader, model);
    }
}

