// Copyright 2018

#include "World.hpp"

#include "Collision.hpp"
#include "IBody.hpp"

namespace physic {

void World::setGravity(const math::Vector<2> &i_gravity) {
  gravity = i_gravity;
}

void World::addObject(IBody &i_body) { bodies.push_back(&i_body); }

void World::resolveCollisions() {
  for (auto &body1 : bodies) {
    for (auto &body2 : bodies) {
      physic::Collision((*body1), (*body2));
    }
  }
}

void World::update(double dt) {
  resolveCollisions();

  for (auto &object : bodies) {
    object->force += (gravity * object->mass);
    object->update(dt);
  }
}

}  // namespace physic
