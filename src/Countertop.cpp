#include "Countertop.h"
#include "Cube.h"
#include "Cylinder.h"

extern unsigned int woodTexture1;
extern unsigned int woodTexture2;
extern unsigned int ceramicsTexture;
extern unsigned int steelTexture1;

Countertop::Countertop(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

Countertop::Countertop(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Countertop::init() {
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
        glm::vec3(5.0f, 1.2f, 0.8f),      // escala
        a   // Angulo
    ));

    if (angle == 0.0) {
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.6f, 0.5f, 0.0f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.1f, 0.4f, 0.6f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(1.7f, 0.45f, 0.0f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.75f, 0.4f, 0.75f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(1.2f, 0.0f, 0.4f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.3f, 1.0f, 0.1f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-1.2f, 0.0f, 0.4f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.3f, 1.0f, 0.1f),      // escala
            0   // Angulo
        ));
    }
    else if (angle == 1.0) {
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.0f, 0.5f, -0.6f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.6f, 0.4f, 1.1f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.45f, 1.7f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.75f, 0.4f, 0.75f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.4f, 0.0f, 1.2f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.3f, 1.0f, 0.1f),      // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.4f, 0.0f, -1.2f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.3f, 1.0f, 0.1f),      // escala
            90   // Angulo
        ));
    }
    else if (angle == 2.0) {
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.6f, 0.5f, 0.0f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.1f, 0.4f, 0.6f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-1.7f, 0.45f, 0.0f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.75f, 0.4f, 0.75f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(1.2f, 0.0f, -0.4f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.3f, 1.0f, 0.1f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-1.2f, 0.0f, -0.4f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.3f, 1.0f, 0.1f),      // escala
            0   // Angulo
        ));
    }
    else if (angle == 3.0) {
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.0f, 0.5f, 0.6f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.6f, 0.4f, 1.1f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.45f, -1.7f),     // posição
            glm::vec3(0.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.75f, 0.4f, 0.75f),      // escala
            0   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.4f, 0.0f, 1.2f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.3f, 1.0f, 0.1f),      // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-0.4f, 0.0f, 1.2f),     // posição
            glm::vec3(0.0f, 1.0f, 0.0f),      // rotação (eixo)
            glm::vec3(2.3f, 1.0f, 0.1f),      // escala
            90   // Angulo
        ));
    }
}

void Countertop::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, woodTexture2);
    parts[0]->draw(shader, model);
    glBindTexture(GL_TEXTURE_2D, ceramicsTexture);
    parts[1]->draw(shader, model);
    glBindTexture(GL_TEXTURE_2D, steelTexture1);
    parts[2]->draw(shader, model);
    glBindTexture(GL_TEXTURE_2D, woodTexture1);
    parts[3]->draw(shader, model);
    parts[4]->draw(shader, model);
}
