#ifndef COUNTERTOP_H
#define COUNTERTOP_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Object.h"
#include "Shader.h"
#include <vector>
#include <memory>

class Countertop : public Object {
public:
    Countertop(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float ang);
    Countertop(glm::vec3 pos, float ang = 0.0f);

    void init();
    void draw(Shader &shader, glm::mat4 model);

private:
    std::vector<std::unique_ptr<Object>> parts;
};

#endif
