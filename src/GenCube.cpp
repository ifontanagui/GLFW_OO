#include "GenCube.h"
#include "Cube.h"

GenCube::GenCube(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

GenCube::GenCube(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void GenCube::init() {
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posi��o
        glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
        glm::vec3(1.0f, 1.0f, 1.0f),      // escala
        angle
    ));
}

void GenCube::draw(Shader &shader, glm::mat4 model, unsigned int tetxure) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, tetxure);
    parts[0]->draw(shader, model);
}
