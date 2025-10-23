#include "Cylinder.h"
#include <vector>
#include <cmath>
#include <glm/gtc/constants.hpp>
#include <iostream>

const float CYLINDER_RADIUS = 0.5f;
const float CYLINDER_HEIGHT = 1.0f;
const int SECTOR_COUNT = 30;

std::vector<float> cylinderVertices;
int cylinderDrawCount = 0;

void generateCylinderVertices() {
    cylinderVertices.clear();

    const float PI = glm::pi<float>();
    float sectorStep = 2 * PI / SECTOR_COUNT;
    float halfHeight = CYLINDER_HEIGHT / 2.0f;

    //Laterais (ao longo do eixo Y)
    for (int i = 0; i < SECTOR_COUNT; ++i) {
        float angle1 = i * sectorStep;
        float angle2 = (i + 1) * sectorStep;

        float x1 = CYLINDER_RADIUS * cosf(angle1);
        float z1 = CYLINDER_RADIUS * sinf(angle1);
        float x2 = CYLINDER_RADIUS * cosf(angle2);
        float z2 = CYLINDER_RADIUS * sinf(angle2);

        float u1 = (float)i / SECTOR_COUNT;
        float u2 = (float)(i + 1) / SECTOR_COUNT;
        float v_top = 1.0f;
        float v_bottom = 0.0f;

        glm::vec3 p1(x1, halfHeight, z1);
        glm::vec3 p2(x2, halfHeight, z2);
        glm::vec3 p3(x1, -halfHeight, z1);
        glm::vec3 p4(x2, -halfHeight, z2);

        // Tri�ngulo 1 (CCW)
        cylinderVertices.insert(cylinderVertices.end(), { p1.x, p1.y, p1.z, u1, v_top });    // Topo 1
        cylinderVertices.insert(cylinderVertices.end(), { p4.x, p4.y, p4.z, u2, v_bottom }); // Base 2
        cylinderVertices.insert(cylinderVertices.end(), { p3.x, p3.y, p3.z, u1, v_bottom }); // Base 1

        // Tri�ngulo 2 (CCW)
        cylinderVertices.insert(cylinderVertices.end(), { p1.x, p1.y, p1.z, u1, v_top });    // Topo 1
        cylinderVertices.insert(cylinderVertices.end(), { p2.x, p2.y, p2.z, u2, v_top });    // Topo 2
        cylinderVertices.insert(cylinderVertices.end(), { p4.x, p4.y, p4.z, u2, v_bottom }); // Base 2
    }

    // Base Superior (y = +halfHeight)
    glm::vec3 center_top(0.0f, halfHeight, 0.0f);
    float u_center = 0.5f;
    float v_center = 0.5f;

    for (int i = 0; i < SECTOR_COUNT; ++i) {
        float angle1 = i * sectorStep;
        float angle2 = (i + 1) * sectorStep;

        float x1 = CYLINDER_RADIUS * cosf(angle1);
        float z1 = CYLINDER_RADIUS * sinf(angle1);
        float x2 = CYLINDER_RADIUS * cosf(angle2);
        float z2 = CYLINDER_RADIUS * sinf(angle2);

        float u1 = (x1 / (2 * CYLINDER_RADIUS)) + 0.5f;
        float v1 = (z1 / (2 * CYLINDER_RADIUS)) + 0.5f;
        float u2 = (x2 / (2 * CYLINDER_RADIUS)) + 0.5f;
        float v2 = (z2 / (2 * CYLINDER_RADIUS)) + 0.5f;

        // Tri�ngulo Topo (Centro -> Ponto 1 -> Ponto 2) - CCW
        cylinderVertices.insert(cylinderVertices.end(), { center_top.x, center_top.y, center_top.z, u_center, v_center });
        cylinderVertices.insert(cylinderVertices.end(), { x1, center_top.y, z1, u1, v1 });
        cylinderVertices.insert(cylinderVertices.end(), { x2, center_top.y, z2, u2, v2 });
    }

    // Base Inferior (y = -halfHeight)
    glm::vec3 center_bottom(0.0f, -halfHeight, 0.0f);

    for (int i = 0; i < SECTOR_COUNT; ++i) {
        float angle1 = i * sectorStep;
        float angle2 = (i + 1) * sectorStep;

        float x1 = CYLINDER_RADIUS * cosf(angle1);
        float z1 = CYLINDER_RADIUS * sinf(angle1);
        float x2 = CYLINDER_RADIUS * cosf(angle2);
        float z2 = CYLINDER_RADIUS * sinf(angle2);

        float u1 = (x1 / (2 * CYLINDER_RADIUS)) + 0.5f;
        float v1 = (z1 / (2 * CYLINDER_RADIUS)) + 0.5f;
        float u2 = (x2 / (2 * CYLINDER_RADIUS)) + 0.5f;
        float v2 = (z2 / (2 * CYLINDER_RADIUS)) + 0.5f;

        // Tri�ngulo Base (Centro -> Ponto 2 -> Ponto 1) - CW para face down
        cylinderVertices.insert(cylinderVertices.end(), { center_bottom.x, center_bottom.y, center_bottom.z, u_center, v_center });
        cylinderVertices.insert(cylinderVertices.end(), { x2, center_bottom.y, z2, u2, v2 });
        cylinderVertices.insert(cylinderVertices.end(), { x1, center_bottom.y, z1, u1, v1 });
    }

    cylinderDrawCount = cylinderVertices.size() / 5; // 5 floats por v�rtice
}

Cylinder::Cylinder(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float ang)
    : position(pos), rotation(rot), scale(scl), angle(ang) {

    generateCylinderVertices();
    init();
}

void Cylinder::init() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, cylinderVertices.size() * sizeof(float), cylinderVertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Cylinder::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);

    if (glm::length(rotation) > 0.0f)
        model = glm::rotate(model, glm::radians(angle), glm::normalize(rotation));

    model = glm::scale(model, scale);

    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, cylinderDrawCount);
    glBindVertexArray(0);
}
