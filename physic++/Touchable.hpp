#pragma once

#include "Mass.hpp"
#include "Material.hpp"
#include "Shape.hpp"

namespace physic
{

class Touchable
{
  protected:
    Mass mass{};
    Shape shape{};
    Material material{};

  public:
    virtual ~Touchable() = default;

    virtual const Mass &getMass() { return mass; };
    virtual const Shape &getShape() { return shape; };
    virtual const Material &getMaterial() { return material; };

    virtual void setShape(const Shape &i_shape) { shape = i_shape; };
    virtual void setMaterial(const Material &i_material)
    {
        material = i_material;
        mass = Mass(shape.getVolume() * material.m_density);
    };

    virtual void update(double dt) = 0;
};

} // namespace physic