//
// Created by mySab on 2018/9/22.
//

#include "Sphere.h"


Sphere::Sphere() = default;

Sphere::Sphere(const Vector3 &_c, double _r, Material *_m) : center(_c), radius(_r) {
    material_ptr = _m;
}

bool Sphere::hit(const Ray &_r, double _min, double _max, HitInfo &_info) const {
    Vector3 center_t;
    if (!this->displacement(_r.get_time(), center_t)) {
        center_t = this->center;
    }
    Vector3 oc = _r.origin() - center_t;
    double a = dot(_r.direction(), _r.direction());
    double b = dot(oc, _r.direction());
    double c = dot(oc, oc) - this->radius * this->radius;
    double discriminant = b * b - a * c;
    if (discriminant > 0.0) {
        double tmp = (-b - sqrt(discriminant)) / a;
        if (tmp > _min && tmp < _max) {
            _info.t = tmp;
            _info.pos = _r.targetPos(tmp);
            if (_info.pos[1] < center[1]){
                return false;
            }
            _info.normal = (_info.pos - center_t) / this->radius;
            _info.material_ptr = this->material_ptr;
            return true;
        }
        tmp = (-b + sqrt(discriminant)) / a;
        if (tmp > _min && tmp < _max) {
            _info.t = tmp;
            _info.pos = _r.targetPos(_info.t);
            if (_info.pos[1] < center[1]){
                return false;
            }
            _info.normal = (_info.pos - center_t) / this->radius;
            _info.material_ptr = this->material_ptr;
            return true;
        }
    }
    return false;
}

void Sphere::dispInfo() {
    std::cout << "Sphere-center";
    std::cout << this->center;
    std::cout << "-radius:" << this->radius << std::endl;
}

Material *Sphere::get_material() const {
    return this->material_ptr;
}

bool Sphere::displacement(const double &_time, Vector3 &_target_pos) const {
    if(this->node_list.empty()){
        return false;
    }
    MovementNode pre_node = this->node_list.front();
    for (auto node_itor = Movement::node_list.begin();
         node_itor != this->node_list.end(); ++node_itor) {
        if (pre_node.time <= _time && _time <= node_itor->time) {
            _target_pos = pre_node.pos +
                          (_time - pre_node.time) / (node_itor->time - pre_node.time) * (node_itor->pos - pre_node.pos);
            return true;
        } else {
            pre_node = *node_itor;
        }
    }
    return false;

}
