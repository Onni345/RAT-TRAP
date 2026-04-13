//
// Created by mySab on 2018/10/1.
//

#ifndef RAY_TRACING_ENGINE_MOVEMENT_H
#define RAY_TRACING_ENGINE_MOVEMENT_H

#include <vector>
#include "Vector3.h"
#include "Object.h"

class MovementNode {
public:
    Vector3 pos;
    double time;

    MovementNode() = default;
    MovementNode(const Vector3 &_pos, const double &_time) {
        pos = _pos;
        time = _time;
    }
};

class Movement {
protected:
    std::vector<MovementNode> node_list;
public:
    Movement() = default;

    Movement(const std::vector<MovementNode> &_node_list);

    void add_node(const Vector3 &_pos, const double &_time);

    virtual bool displacement(const double &_time, Vector3 &_target_pos) const = 0;
};


#endif //RAY_TRACING_ENGINE_MOVEMENT_H
