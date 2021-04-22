//
// Created by Jeremiah Korreck on 7/11/20.
//

#ifndef OPENGL_TUT_MESH_H
#define OPENGL_TUT_MESH_H
#include <vector>
#include <glm/glm.hpp>

enum MeshType {
    kTriangle = 0,
    kQuad = 1,
    kCube = 2,
    kSphere = 3
};

struct Vertex {
    glm::vec3 pos;
    glm::vec3 normal;
    glm::vec3 color;
    glm::vec2 texCoords;
};

class Mesh {
public:
    static void setTriData(std::vector<Vertex>& vertices,
                           std::vector<uint32_t>&indices);
    static void setQuadData(std::vector<Vertex>& vertices,
                            std::vector<uint32_t>&indices);
    static void setCubeData(std::vector<Vertex>& vertices,
                            std::vector<uint32_t>&indices);
    static void setSphereData(std::vector<Vertex>& vertices,
                              std::vector<uint32_t>&indices);
};



#endif //OPENGL_TUT_MESH_H
