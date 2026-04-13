//
// Created by mySab on 2018/9/23.
//

#include "Vector3.h"

Vector3::Vector3() = default;

Vector3::Vector3(const Vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] = _v[i];
    }
}

Vector3::Vector3(double _n0, double _n1, double _n2) {
    this->vec3[0] = _n0;
    this->vec3[1] = _n1;
    this->vec3[2] = _n2;
}
