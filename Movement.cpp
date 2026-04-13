//
// Created by mySab on 2018/10/1.
//

#include "Movement.h"

Movement::Movement(const std::vector<MovementNode> &_node_list)
        : node_list(_node_list) {

}

void Movement::add_node(const Vector3 &_pos, const double &_time) {
    this->node_list.emplace_back(MovementNode(_pos, _time));
}
//
//bool Movement::placement(const double &_time, Vector3 &_target_pos) const {
//    return false;
//}
