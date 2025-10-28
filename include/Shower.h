#ifndef SHOWER_H
#define SHOWER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Object.h"
#include "Shader.h"
#include <vector>
#include <memory>

class Shower : public Object {
public:
    Shower(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float ang);
    Shower(glm::vec3 pos, float ang = 0.0f);

    void init();
    void draw(Shader &shader, glm::mat4 model);

private:
    std::vector<std::unique_ptr<Object>> parts;
};

#endif
