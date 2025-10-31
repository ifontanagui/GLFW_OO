#include "Closet.h"
#include "Cube.h"

extern unsigned int woodTexture1;
extern unsigned int woodTexture2;

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
        glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
        glm::vec3(3.0f, 3.0f, 1.0f),      // escala
        a // Angulo
    ));

    if (angle == 0.0) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.75f, 0.0f, 0.55f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.45f, 2.8f, 0.1f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.75f, 0.0f, 0.5f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.45f, 2.8f, 0.1f),      // escala
            0   // Angulo
        ));
    }
    else if (angle == 1.0) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.55f, 0.0f, 0.75f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.45f, 2.8f, 0.1f),      // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.55f, 0.0f, -0.75f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.45f, 2.8f, 0.1f),      // escala
            90   // Angulo
        ));
    }
    else if (angle == 2.0) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.75f, 0.0f, -0.55f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.45f, 2.8f, 0.1f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.75f, 0.0f, -0.55f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.45f, 2.8f, 0.1f),      // escala
            0   // Angulo
        ));
    }
    else if (angle == 3.0) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.55f, 0.0f, 0.75f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.45f, 2.8f, 0.1f),      // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.55f, 0.0f, -0.75f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.45f, 2.8f, 0.1f),      // escala
            90   // Angulo
        ));
    }
}

void Closet::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, woodTexture2);
    parts[0]->draw(shader, model);
    glBindTexture(GL_TEXTURE_2D, woodTexture1);
    parts[1]->draw(shader, model);
    parts[2]->draw(shader, model);
}
