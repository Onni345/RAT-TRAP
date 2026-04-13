//
// Created by mySab on 2018/9/27.
//

#ifndef RAY_TRACING_ENGINE_METAL_H
#define RAY_TRACING_ENGINE_METAL_H


#include "Material.h"

class Metal : public Material {
private:
    Vector3 albedo;
    double fuzz;
public:
    Metal(const Vector3 &,const double &);

    bool scatter(const Ray &, const HitInfo &, Vector3 &, Ray &) const override;

};


#endif //RAY_TRACING_ENGINE_METAL_H
