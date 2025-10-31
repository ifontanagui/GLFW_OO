#include "Bed.h"
#include "Cube.h"
#include "Cylinder.h"

extern unsigned int woodTexture2;
extern unsigned int fabricTexture1;
extern unsigned int fabricTexture2;

Bed::Bed(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : Object(pos, rot, scl, angle)
{
    // Cada parte da nave ser� um "sub-modelo"

    init();
}

Bed::Bed(glm::vec3 pos, float angle)
    : Object(pos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), angle)
{
    init();
}

void Bed::init() {
    if (angle == 0.0f || angle == 2.0f) {
        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.6f, 0.0f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(3.0f, 1.0f, 2.2f),      // escala
            0   // Angulo
        ));


        if (angle == 0.0f) {
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(1.2f, 1.3f, -0.55f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
                glm::vec3(0.5f, 0.4f, 1.0f),      // escala
                0   // Angulo
            ));

            parts.push_back(std::make_unique<Cube>(
                glm::vec3(1.2f, 1.3f, 0.55f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
                glm::vec3(0.5f, 0.4f, 1.0f),      // escala
                0   // Angulo
            ));
        }
        else {
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(-1.2f, 1.3f, -0.55f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
                glm::vec3(0.5f, 0.4f, 1.0f),      // escala
                0   // Angulo
            ));

            parts.push_back(std::make_unique<Cube>(
                glm::vec3(-1.2f, 1.3f, 0.55f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
                glm::vec3(0.5f, 0.4f, 1.0f),      // escala
                0   // Angulo
            ));
        }

        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(1.3f, 0.0f, 0.9f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-1.3f, 0.0f, 0.9f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(1.3f, 0.0f, -0.9f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-1.3f, 0.0f, -0.9f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            0  // Angulo
        ));
    }
    else if (angle == 1.0f || angle == 3.0f) {

        parts.push_back(std::make_unique<Cube>(
            glm::vec3(0.0f, 0.6f, 0.0f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(2.2f, 1.0f, 3.0f),      // escala
            0   // Angulo
        ));

        if (angle == 1.0f) {
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(0.8f, 1.3f, 0.75f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
                glm::vec3(0.5f, 0.4f, 1.4f),      // escala
                0   // Angulo
            ));
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(0.8f, 1.3f, -0.75f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
                glm::vec3(0.5f, 0.4f, 1.4f),      // escala
                0   // Angulo
            ));
        }
        else {
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(-0.8f, 1.3f, 0.75f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
                glm::vec3(0.5f, 0.4f, 1.4f),      // escala
                0   // Angulo
            ));
            parts.push_back(std::make_unique<Cube>(
                glm::vec3(-0.8f, 1.3f, -0.75f),     // posi��o
                glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
                glm::vec3(0.5f, 0.4f, 1.4f),      // escala
                0   // Angulo
            ));
        }

        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.9f, 0.0f, 1.3f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(0.9f, 0.0f, -1.3f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.9f, 0.0f, 1.3f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            0  // Angulo
        ));
        parts.push_back(std::make_unique<Cylinder>(
            glm::vec3(-0.9f, 0.0f, -1.3f),     // posi��o
            glm::vec3(1.0f, 0.0f, 0.0f),      // rota��o (eixo)
            glm::vec3(0.2f, 0.3f, 0.2f),      // escala
            0  // Angulo
        ));
    }
}

void Bed::draw(Shader &shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glBindTexture(GL_TEXTURE_2D, fabricTexture1);
    parts[0]->draw(shader, model);
    glBindTexture(GL_TEXTURE_2D, fabricTexture2);
    parts[1]->draw(shader, model);
    parts[2]->draw(shader, model);


    glBindTexture(GL_TEXTURE_2D, woodTexture2);
    for (int i = 3; i < 7; i ++)
        parts[i]->draw(shader, model);
}

