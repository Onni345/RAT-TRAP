//
// Created by mySab on 2018/9/27.
//

#include "Material.h"

Vector3 random_in_unit_sphere()
{
    Vector3 p;
    do
    {
        p = 2.0 * Vector3(drand48(), drand48(), drand48()) - Vector3(1, 1, 1);
    } while (p.length() * p.length() >= 1.0);
    return p;
}

Vector3 random_in_unit_disk()
{
    Vector3 p;
    do
    {
        p = 2.0 * Vector3(drand48(), drand48(), 0) - Vector3(1, 1, 0);
    } while (p.length() >= 1.0);
    return p;
}
Vector3 reflect(const Vector3 &_v, const Vector3 &_n)
{
    return _v - 2 * dot(_v, _n) * _n;
}

bool refract(const Vector3 &_in_vec, const Vector3 &_normal, double _eta, Vector3 &_ref_vec)
{
    //Snell's Law
    double cos_in = dot(_in_vec.normalize(), _normal);
    double discriminant = 1.0 - _eta * _eta * (1 - cos_in * cos_in);
    if (discriminant > 0)
    {
        _ref_vec = _eta * (_in_vec.normalize() - _normal * cos_in) - _normal * sqrt(discriminant);
        return true;
    }
    else
    {
        return false;
    }
}

double reflection_coefficient(double _cosine, double _ref_index)
{
    //Schlick's approximation
    double r0 = (1.0 - _ref_index) / (1.0 + _ref_index);
    r0 *= r0;
    return r0 + (1.0 - r0) * pow((1 - _cosine), 5);
}
