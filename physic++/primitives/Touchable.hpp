#pragma once

#include "utils/Mass.hpp"
#include "utils/Material.hpp"

namespace physic
{
struct Box
{
	math::Vector<2> min;
	math::Vector<2> max;
};

class Touchable
{
  protected:
	double volume;
	Box box;
	Mass mass;
	Material material;

  public:
	virtual ~Touchable() = default;

	virtual double getVolume() { return volume; }
	virtual const Box & getBox() { return box; };
	virtual const Mass & getMass() { return mass; };
	virtual const Material & getMaterial() { return material; };

	virtual void setVolume(double i_volume) { volume = i_volume; }
	virtual void setBox(const Box & i_box) { box = i_box; };
	virtual void setMaterial(const Material & i_material)
	{
		material = i_material;
		mass     = Mass(volume * material.m_density);
	};

	virtual void update(double dt) = 0;
};

} // namespace physic