#include "Sink.h"
#include "Cube.h"
#include "Cylinder.h"

extern unsigned int woodTexture1;
extern unsigned int woodTexture2;
extern unsigned int ceramicsTexture;

Sink::Sink(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave será um "sub-modelo"

    init();
}

Sink::Sink(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Sink::init() {
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
        glm::vec3(0.0f, 0.1f, 0.0f),      // rotação (eixo)
        glm::vec3(1.6f, 1.0f, 1.0f),      // escala
        a  // Angulo
    ));
    parts.push_back(std::make_unique<Cylinder>(
        glm::vec3(0.0f, 0.5f, 0.0f),     // posição
        glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
        glm::vec3(0.8f, 0.4f, 0.8f),      // escala
        0   // Angulo
    ));


    if (angle == 0.0) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.0f, 0.5f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.3f, 0.8f, 0.1f),      // escala
            0   // Angulo
        ));
    }
    else if (angle == 1.0) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.5f, 0.0f, 0.0f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.1f, 0.8f, 1.3f),      // escala
            0   // Angulo
        ));
    }
    else if (angle == 2.0) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.0f, -0.5f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.3f, 0.8f, 0.1f),      // escala
            0   // Angulo
        ));
    }
    else if (angle == 3.0) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.5f, 0.0f, 0.0f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.1f, 0.8f, 1.3f),      // escala
            0   // Angulo
        ));
    }
}

void Sink::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, woodTexture2);
    parts[0]->draw(shader, model);
    glBindTexture(GL_TEXTURE_2D, ceramicsTexture);
    parts[1]->draw(shader, model);
    glBindTexture(GL_TEXTURE_2D, woodTexture1);
    parts[2]->draw(shader, model);
}
