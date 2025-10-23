#include "Sphere.h"
#include <vector>
#include <cmath>
#include <glm/gtc/constants.hpp>
#include <iostream>

const float SPHERE_RADIUS = 0.5f;
const int SECTOR_COUNT = 36; // Divisões ao redor do eixo Y (Longitude)
const int STACK_COUNT = 18;  // Divisões ao longo do eixo Y (Latitude)

// Vetor para armazenar os vértices (Simulando o membro 'vertices')
std::vector<float> sphereVertices;
// Contador de Vértices para o glDrawArrays (Simulando o membro 'drawCount')
int globalDrawCount = 0;


// ====================================================================
// Geração de Vértices
// ====================================================================

void generateSphereVertices() {
    // 1. Geração da Matriz de Pontos (Vertices + TexCoords)
    sphereVertices.clear();

    const float PI = glm::pi<float>();

    float x, y, z, xy;
    float s, t;

    float sectorStep = 2 * PI / SECTOR_COUNT;
    float stackStep = PI / STACK_COUNT;
    float sectorAngle, stackAngle;

    for (int i = 0; i <= STACK_COUNT; ++i) {
        stackAngle = PI / 2 - i * stackStep;
        xy = SPHERE_RADIUS * cosf(stackAngle);
        y = SPHERE_RADIUS * sinf(stackAngle);

        for (int j = 0; j <= SECTOR_COUNT; ++j) {
            sectorAngle = j * sectorStep;

            x = xy * cosf(sectorAngle);
            z = xy * sinf(sectorAngle);

            s = (float)j / SECTOR_COUNT;
            t = (float)i / STACK_COUNT;

            sphereVertices.push_back(x);
            sphereVertices.push_back(y);
            sphereVertices.push_back(z);

            sphereVertices.push_back(s);
            sphereVertices.push_back(t);
        }
    }

    std::vector<float> finalVertices;
    int k1, k2;

    int verticesPerStack = SECTOR_COUNT + 1;
    int stride = 5;

    for (int i = 0; i < STACK_COUNT; ++i) {
        k1 = i * verticesPerStack;
        k2 = (i + 1) * verticesPerStack;
        for (int j = 0; j < SECTOR_COUNT; ++j, ++k1, ++k2) {

            // Se não for o Pólo Norte
            if (i != 0) {
                for (int m = 0; m < stride; ++m) finalVertices.push_back(sphereVertices[stride * k1 + m]);
                for (int m = 0; m < stride; ++m) finalVertices.push_back(sphereVertices[stride * k2 + m]);
                for (int m = 0; m < stride; ++m) finalVertices.push_back(sphereVertices[stride * (k1 + 1) + m]);
            }

            // Se não for o Pólo Sul
            if (i != (STACK_COUNT - 1)) {
                for (int m = 0; m < stride; ++m) finalVertices.push_back(sphereVertices[stride * (k1 + 1) + m]);
                for (int m = 0; m < stride; ++m) finalVertices.push_back(sphereVertices[stride * k2 + m]);
                for (int m = 0; m < stride; ++m) finalVertices.push_back(sphereVertices[stride * (k2 + 1) + m]);
            }
        }
    }

    sphereVertices = finalVertices;

    globalDrawCount = sphereVertices.size() / 5;
}

Sphere::Sphere(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float ang)
    : position(pos), rotation(rot), scale(scl), angle(ang) {

    generateSphereVertices();

    init();
}

void Sphere::init() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sphereVertices.size() * sizeof(float), sphereVertices.data(), GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // tex coords
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Sphere::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);

    if (glm::length(rotation) > 0.0f)
        model = glm::rotate(model, glm::radians(angle), glm::normalize(rotation));

    model = glm::scale(model, scale);

    shader.setMat4("model", model);

    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, globalDrawCount);
    glBindVertexArray(0);
}
