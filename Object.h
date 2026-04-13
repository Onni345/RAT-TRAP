//
// Created by Zhiquan on 2018/9/20.
//

#ifndef RAY_TRACING_ENGINE_OBJECT_H
#define RAY_TRACING_ENGINE_OBJECT_H

#include <iostream>
#include "Ray.h"
#include "Material.h"
#include "HitInfo.h"

class Object {
protected:
    Material *material_ptr;
public:
    virtual bool hit(const Ray &, double, double, HitInfo &) const = 0;

    virtual void dispInfo() = 0;


};


#endif //RAY_TRACING_ENGINE_OBJECT_H
