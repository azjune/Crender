//
// Created by ld016 on 16-7-20.
//

#ifndef APP_DOCMENT_H
#define APP_DOCMENT_H

#include <iostream>
#include <assimp/scene.h>

class Docment {
public:
    Docment();
    void load(const char* path);

private:
    aiScene* mScene;
};


#endif //APP_DOCMENT_H
