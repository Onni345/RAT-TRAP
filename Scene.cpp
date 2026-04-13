//
// Created by mySab on 2018/9/21.
//

#include "Scene.h"


Scene::Scene() :object_num(0) {

}

bool Scene::addObject(Object * _obj) {
	this->object_list.push_back(_obj);
	++object_num;
	return true;
}

bool Scene::hit(const Ray & _r, double _min, double _max, HitInfo & _info) const {
    double tmp_min = _max;
    HitInfo tmp_info;
    bool is_hit = false;
    for(auto obj:this->object_list){
        if (obj->hit(_r,_min,tmp_min,tmp_info)){
            is_hit = true;
            tmp_min = tmp_info.t;
            _info = tmp_info;
        }
    }
    return is_hit;
}

void Scene::dispInfo() {
    std::cout << "Scene:"<< std::endl;
    for(auto obj:this->object_list){
        obj->dispInfo();
    }
}

void Scene::clear() {
    this->object_list.clear();
}

