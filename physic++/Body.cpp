// Copyright 2018

#include "Body.hpp"

#include "IShape.hpp"
#include "Material.hpp"

namespace physic {
void Body::setShape(const IShape &s) { shape = &s; }

void Body::setMaterial(const Material &m) {
  material = &m;

  const double volume = shape->getVolume();
  mass = Mass(volume * material->m_density);
}

void Body::update(double dt) { resolvePhysics(dt); }

}  // namespace physic
