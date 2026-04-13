//
// Created by mySab on 2018/9/21.
//

#ifndef RAY_TRACING_ENGINE_SCENE_H
#define RAY_TRACING_ENGINE_SCENE_H


#include "Object.h"
#include "HitInfo.h"
#include <vector>

class Scene : public Object {
private:
    std::vector<Object *> object_list;
    int object_num;
public:
    Scene();

    bool addObject(Object *);

    bool hit(const Ray &, double, double, HitInfo &) const override;

    void dispInfo() override;

    void clear();
};


#endif //RAY_TRACING_ENGINE_SCENE_H
