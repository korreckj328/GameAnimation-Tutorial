//
// Created by Jeremiah Korreck on 4/22/21.
//
#include <string.h>
#include <iostream>
#include "GLTFLoader.h"

cgltf_data *LoadGLTFFile(const char *path) {
    cgltf_options options;
    memset(&options, 0, sizeof(cgltf_options));
    cgltf_data  *data = nullptr;
    cgltf_result result = cgltf_parse_file(&options, path, &data);
    if (result != cgltf_result_success) {
        std::cout << "Could not Load: " << path << std::endl;
        return nullptr;
    }
    result = cgltf_validate(data);
    if (result != cgltf_result_success) {
        cgltf_free(data);
        std::cout << "Invalid file: " << path << std::endl;
        return nullptr;
    }
    return data;
}

void FreeGLTFFile(cgltf_data *data) {
    if (data == nullptr) {
        std::cout << "Warning can't free nullptr for gltf data" << std::endl;
    } else {
        cgltf_free(data);
    }
}
