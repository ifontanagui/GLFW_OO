#include "Toilet.h"
#include "Cylinder.h"
#include "Cube.h"

extern unsigned int ceramicsTexture;

Toilet::Toilet(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

Toilet::Toilet(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Toilet::init() {
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posi��o
        glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
        glm::vec3(1.1f, 1.0f, 1.1f),      // escala
        90   // Angulo
    ));

    if (angle == 0.0f)
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.5f, 0.8f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(1.1f, 1.1f, 0.5f),      // escala
            90   // Angulo
        ));
}

void Toilet::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, ceramicsTexture);
    for (auto &part : parts) {
        part->draw(shader, model);
    }
}
