// Copyright 2018

#include "Body.hpp"

#include "Material.hpp"
#include "Shape.hpp"

namespace physic {
void Body::setShape(const Shape &s) { shape = &s; }

void Body::setMaterial(const Material &m) {
  material = &m;

  const double volume = shape->getVolume();
  mass = Mass(volume * material->m_density);
}

void Body::update(double dt) { resolvePhysics(dt); }

}  // namespace physic
