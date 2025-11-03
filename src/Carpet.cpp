#include "Carpet.h"
#include "Cube.h"

extern unsigned int carpetTexture;

Carpet::Carpet(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

Carpet::Carpet(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Carpet::init() {
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posi��o
        glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
        glm::vec3(1.0f, 1.0f, 1.0f),      // escala
        angle
    ));
}

void Carpet::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, carpetTexture);
    parts[0]->draw(shader, model);
}
