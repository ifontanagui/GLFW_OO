#include "Lighting.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"

extern unsigned int lightTexture;
extern unsigned int woodTexture;

Lighting::Lighting(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave será um "sub-modelo"

    init();
}

Lighting::Lighting(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Lighting::init() {
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(0.0f, 4.2f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.8f, 1.7f, 0.8f),      // escala
        0  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(0.0f, 1.7f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.15f, 3.3f, 0.15f),      // escala
        0  // Angulo
    ));
    parts.push_back(std::make_unique<Cube>(
        glm::vec3(0.0f, 0.0f, 0.0f),     // posição
        glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.5f, 0.1f, 0.5f),      // escala
        0  // Angulo
    ));
}

void Lighting::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, lightTexture);
    parts[0]->draw(shader, model);

    glBindTexture(GL_TEXTURE_2D, woodTexture);
    parts[1]->draw(shader, model);
    parts[2]->draw(shader, model);
}

