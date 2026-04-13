//
// Created by mySab on 2018/9/27.
//

#include "Lambertian.h"


Lambertian::Lambertian(const Vector3 & _a) :albedo(_a){

}

bool Lambertian::scatter(const Ray & _r, const HitInfo & _i, Vector3 & _a, Ray & _s) const {
    Vector3 target_pos = _i.pos + _i.normal + random_in_unit_sphere();
    _s = Ray(_i.pos,target_pos-_i.pos,_r.get_time());
    _a = albedo;
    return true;
}

