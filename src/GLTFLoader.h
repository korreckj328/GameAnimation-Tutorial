//
// Created by Jeremiah Korreck on 4/22/21.
//

#ifndef GAMEANIMATION_TUT_GLTFLOADER_H
#define GAMEANIMATION_TUT_GLTFLOADER_H

#include <cgltf.h>


cgltf_data *LoadGLTFFile(const char* path);
void FreeGLTFFile(cgltf_data *data);



#endif //GAMEANIMATION_TUT_GLTFLOADER_H
