#pragma once

namespace physic
{
class Shape
{
	public:
	virtual ~Shape() = default;

	virtual double getDistanceToCenter() const { return 5; };
	virtual double getVolume() const { return 3.1415 * 5 * 5; };
};

} // namespace physic