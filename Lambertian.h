//
// Created by mySab on 2018/9/27.
//

#ifndef RAY_TRACING_ENGINE_LAMBERTIAN_H
#define RAY_TRACING_ENGINE_LAMBERTIAN_H


#include "Vector3.h"
#include "Ray.h"
#include "HitInfo.h"

class Lambertian : public Material {
private:
    Vector3 albedo;
public:
    explicit Lambertian(const Vector3 &);

    bool scatter(const Ray &, const HitInfo &, Vector3 &, Ray &) const override;

};


#endif //RAY_TRACING_ENGINE_LAMBERTIAN_H
