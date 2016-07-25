//
// Created by ld016 on 16-7-20.
//

#include "Docment.h"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

Docment::Docment():mScene(nullptr)
{

}

void Docment::load(const char* path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return;
    }


}