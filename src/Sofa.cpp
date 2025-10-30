#include "Sofa.h"
#include "Cube.h"
#include "Cylinder.h"

extern unsigned int steelTexture;
extern unsigned int fabricTexture;

Sofa::Sofa(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

Sofa::Sofa(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Sofa::init() {

    if (angle == 0.0f || angle == 2.0f) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.0f, 0.0f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(3.0f, 0.6f, 1.3f),      // escala
            90   // Angulo
        ));
        if (angle == 0.0f) {
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(0.0f, 0.5f, 0.5f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
                glm::vec3(3.0f, 1.1f, 0.3f),      // escala
                90   // Angulo
            ));
        }
        else {
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(0.0f, -0.5f, 0.5f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
                glm::vec3(3.0f, 1.1f, 0.3f),      // escala
                90   // Angulo
            ));
        }
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(1.35f, 0.0f, 0.5f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.3f, 1.1f, 1.3f),      // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(-1.35f, 0.0f, 0.5f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.3f, 1.1f, 1.3f),      // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(1.3f, 0.45f, -0.4f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            90  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-1.3f, 0.45f, -0.4f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            90  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(1.3f, -0.45f, -0.4f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            90  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-1.3f, -0.45f, -0.4f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            90  // Angulo
        ));
    }
    else if (angle == 1.0f || angle == 3.0f) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.0f, 0.0f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(1.3f, 0.6f, 3.0f),      // escala
            90   // Angulo
        ));
        if (angle == 1.0f) {
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(0.5f, 0.0f, 0.5f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
                glm::vec3(0.3f, 1.1f, 3.0f),      // escala
                90   // Angulo
            ));
        }
        else {
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(-0.5f, 0.0f, 0.5f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
                glm::vec3(0.3f, 1.1f, 3.0f),      // escala
                90   // Angulo
            ));
        }
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 1.35f, 0.5f),     // posi��o
            glm::vec3(0.0f, 0.0f, 1.0f),      // rotação (eixo)
            glm::vec3(0.3f, 1.3f, 1.1f),      // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, -1.35f, 0.5f),     // posi��o
            glm::vec3(0.0f, 0.0f, 1.0f),      // rotação (eixo)
            glm::vec3(0.3f, 1.3f, 1.1f),      // escala
            90   // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.45f, 1.3f, -0.4f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            90  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.45f, -1.3f, -0.4f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            90  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.45f, 1.3f, -0.4f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            90  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.45f, -1.3f, -0.4f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rotação (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            90  // Angulo
        ));
    }
}

void Sofa::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, fabricTexture);
    for (int i = 0; i < 4; i ++)
        parts[i]->draw(shader, model);

    glBindTexture(GL_TEXTURE_2D, steelTexture);
    for (int i = 4; i < 8; i ++)
        parts[i]->draw(shader, model);
}

