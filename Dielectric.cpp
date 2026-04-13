//
// Created by mySab on 2018/9/27.
//

#include "Dielectric.h"
#include "HitInfo.h"

Dielectric::Dielectric(double _ref_index) : refractive_index(_ref_index) {

}

bool Dielectric::scatter(const Ray &_in_ray, const HitInfo &_hit_info, Vector3 &_attenuation,
                         Ray &_scattered_ray) const {
    // implement your refraction here
    return true;
}
