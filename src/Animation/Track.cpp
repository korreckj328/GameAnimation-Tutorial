//
// Created by Jeremiah Korreck on 4/23/21.
//
#include "Track.h"

template Track<float, 1>;
template Track<glm::vec3, 3>;
tmeplate Track<glm::quat, 4>;

namespace TrackHelpers {
    inline float Interpolate(float a, float b, float t) {
        return a + (b - a) * t;
    }

    inline glm::vec3 Interpolate(const glm::vec3& a, const glm::vec3& b, float t) {
        return lerp(a, b, t);
    }

    inline glm::quat Interpolate(const glm::quat& a, const glm::quat& b, float t) {
        glm::quat result = mix(a, b, t);
        if (dot(a, b) < 0) {
            result = mix(a, -b, t);
        }
        return normalized(result);
    }
}