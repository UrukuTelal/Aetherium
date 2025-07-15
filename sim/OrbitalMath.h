#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

inline glm::vec3 OrbitPosition(float radius, float angleRadians, const glm::vec3& center) {
    return center + glm::vec3(cos(angleRadians) * radius, 0, sin(angleRadians) * radius);
}

inline glm::mat4 RotateY(float angleRadians) {
    return glm::rotate(glm::mat4(1.0f), angleRadians, glm::vec3(0, 1, 0));
}
