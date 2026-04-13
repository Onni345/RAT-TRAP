//
// Created by mySab on 2018/9/24.
//

#include "Camera.h"
Camera::Camera() : origin(Vector3(0, 0, 0)),
                   low_left_corner(Vector3(0, 0, 0)),
                   horizontal_vec(Vector3(0, 0, 0)),
                   vertical_vec(Vector3(0, 0, 0)),
                   duration_start(0.0),
                   duration_end(0.0){
}


Ray Camera::gen_ray(double _u, double _v) {
    Vector3 random_pos = this->aperture/2 * random_in_unit_disk();
    Vector3 offset = u*random_pos.x() + v * random_pos.y();
    double tmp_time = this->duration_start + drand48() * (this->duration_end-this->duration_start);
    Ray tmp_r(origin + offset, low_left_corner + _u * horizontal_vec + _v * vertical_vec - origin - offset,tmp_time);
    return {tmp_r};
}

Camera::Camera(const Vector3 &_look_from, const Vector3 &_look_at, const Vector3 &_view_up, const double &_vfov,
               const double &_aspect, const double &_aperture, const double &_focus_dis,const double & _duration_start,const double & _duration_end) {
    //vfov top to bottom in degrees & aspect = width / height
    double theta = _vfov * M_PI / 180;
    double half_height = tan(theta / 2);
    double half_width = _aspect * half_height;
    this->origin = _look_from;
    this->w = (_look_from - _look_at).normalize();
    this->u = cross(_view_up, this->w).normalize();
    this->v = cross(w, u).normalize();
    this->aperture = _aperture;
    this->low_left_corner = origin - u * half_width * _focus_dis - v * half_height * _focus_dis - w * _focus_dis;
    this->horizontal_vec = 2 * half_width * _focus_dis * u;
    this->vertical_vec = 2 * half_height * _focus_dis * v;
    this->duration_start = _duration_start;
    this->duration_end = _duration_end;
}


