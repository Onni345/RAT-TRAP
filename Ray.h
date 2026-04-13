//
// Created by ZhiquanWang on 2018/7/12.
//

#ifndef RAY_TRACING_ENGINE_RAY_H
#define RAY_TRACING_ENGINE_RAY_H
#include "Vector3.h"

class Ray {
private:
    Vector3 pos;
    Vector3 dir;
    double time;
public:
    Ray() = default;

    Ray(double _p0,double _p1,double _p2,double _d0,double _d1,double _d2,double _time){
        pos.setVector(_p0,_p1,_p2);
        dir.setVector(_d0,_d1,_d2);
        this->dir = this->dir.normalize();
        this->time = _time;
    }
    Ray(const Vector3 & _p,const Vector3 & _d,const double & _time):time(_time){
        pos = _p;
        this->dir = _d.normalize();
    }

    Vector3 origin()  const{
        return pos;
    }

    Vector3 direction() const{
        return dir;
    }

    Vector3 targetPos(double _t) const{
        return pos + _t * dir;
    }

    double get_time() const{
        return this->time;
    }
};


#endif //RAY_TRACING_ENGINE_RAY_H
