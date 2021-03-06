#pragma once

#include "utils/Mass.hpp"
#include "utils/Material.hpp"
#include "utils/Matrix.hpp"

namespace physic
{
struct Box
{
	utils::Vector<2> min;
	utils::Vector<2> max;
};

namespace primitives
{
class Touchable
{
  protected:
	double volume;
	Box box;
	utils::Mass mass;
	utils::Material material;

  public:
	virtual ~Touchable() = default;

	virtual double getVolume() { return volume; }
	virtual const Box & getBox() { return box; };
	virtual const utils::Mass & getMass() { return mass; };
	virtual const utils::Material & getMaterial() { return material; };

	virtual void setVolume(double i_volume) { volume = i_volume; }
	virtual void setBox(const Box & i_box) { box = i_box; };
	virtual void setMaterial(const utils::Material & i_material)
	{
		material = i_material;
		mass     = utils::Mass(volume * material.m_density);
	};

	virtual void update(double dt) = 0;
};
} // namespace primitives
} // namespace physic