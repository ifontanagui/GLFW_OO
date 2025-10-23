// Cube.cpp
#include "Prisma.h"

float verticesPrisma [] = {
    // positions          // tex coords
    // back face
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

    1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, -1.0f, 1.0f, 1.0f,
    0.0f, 0.0f, -1.0f, 1.0f, 0.0f,

    1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, -1.0f, 1.0f, 1.0f,

    1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, -1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, -1.0f, 1.0f, 0.0f,

    0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, -1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

    0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, -1.0f, 1.0f, 1.0f,

    0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, -1.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f, 1.0f,

    0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
    0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
};

Prisma::Prisma(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle)
    : position(pos), rotation(rot), scale(scl), angle(angle) {
    init();
}

void Prisma::init() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPrisma), verticesPrisma, GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // tex coords
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Prisma::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);

    if (glm::length(rotation) > 0.0f)
        model = glm::rotate(model, glm::radians(angle), glm::normalize(rotation));

    model = glm::scale(model, scale);

    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 24);
    glBindVertexArray(0);
}
