#ifndef LIGHTING_H
#define LIGHTING_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Object.h"
#include "Shader.h"
#include <vector>
#include <memory>

class Lighting : public Object {
public:
    Lighting(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float ang);
    Lighting(glm::vec3 pos, float ang = 0.0f);

    void init();
    void draw(Shader &shader, glm::mat4 model);

private:
    std::vector<std::unique_ptr<Object>> parts;
};

#endif
