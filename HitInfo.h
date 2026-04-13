//
// Created by mySab on 2018/9/26.
//

#ifndef RAY_TRACING_ENGINE_HITINFO_H
#define RAY_TRACING_ENGINE_HITINFO_H

#include "Vector3.h"
#include "Material.h"

class HitInfo {
public:
    double t;
    Vector3 pos;
    Vector3 normal;
    Material *material_ptr;

    HitInfo()= default;

};


#endif //RAY_TRACING_ENGINE_HITINFO_H
