//
// Created by mySab on 2018/9/22.
//

#ifndef RAY_TRACING_ENGINE_SPHERE_H
#define RAY_TRACING_ENGINE_SPHERE_H

#include "Object.h"
#include "Movement.h"

class Sphere : public Object, public Movement {
private:
    Vector3 center;
    double radius;
public:
    Sphere();

    Sphere(const Vector3 &, double, Material *);

    bool hit(const Ray &, double, double, HitInfo &) const override;

    bool displacement(const double &_time, Vector3 &_target_pos) const override;

    void dispInfo() override;

    Material *get_material() const;
};


#endif //RAY_TRACING_ENGINE_SPHERE_H

/*
 *
 */