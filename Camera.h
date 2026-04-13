//
// Created by mySab on 2018/9/24.
//

#ifndef RAY_TRACING_ENGINE_CAMERA_H
#define RAY_TRACING_ENGINE_CAMERA_H


#include "Vector3.h"
#include "Ray.h"
#include "Material.h"
#include <math.h>

class Camera {
private:
    Vector3 origin;
    Vector3 low_left_corner;
    Vector3 horizontal_vec;
    Vector3 vertical_vec;
    Vector3 u;
    Vector3 v;
    Vector3 w;
    double aperture;
    double duration_start;
    double duration_end;
public:
    Camera();

    Camera(const Vector3 &_look_from,
           const Vector3 &_look_at,
           const Vector3 &_view_up,
           const double &_vfov,
           const double &_aspect,
           const double &_aperture,
           const double &_focus_dist,
           const double &_duration_start,
           const double &_duration_end);

    Ray gen_ray(double, double);
};


#endif //RAY_TRACING_ENGINE_CAMERA_H
