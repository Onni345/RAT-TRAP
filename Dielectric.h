//
// Created by mySab on 2018/9/27.
//

#ifndef RAY_TRACING_ENGINE_DIELECTRIC_H
#define RAY_TRACING_ENGINE_DIELECTRIC_H


#include "Material.h"

class Dielectric: public Material {
private:
    double refractive_index;
public:
    Dielectric(double _ref_index);
    bool scatter(const Ray &_in_ray, const HitInfo &_hit_info, Vector3 &_attenuation, Ray &_scattered_ray) const override;
};


#endif //RAY_TRACING_ENGINE_DIELECTRIC_H
