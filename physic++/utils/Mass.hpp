#pragma once

namespace physic
{
namespace utils
{
class Mass
{
  private:
	template <typename T>
	friend auto operator*(const T & left, const Mass & right);

	template <typename T>
	friend auto operator/(const T & left, const Mass & right);

	double mass{};
	double massInv{};

  public:
	Mass() = default;
	explicit Mass(double t_mass)
	    : mass(t_mass)
	    , massInv((mass == 0) ? 0 : 1 / mass)
	{}
};

template <typename T>
auto operator*(const T & left, const utils::Mass & right)
{
	return left * right.mass;
}

template <typename T>
auto operator/(const T & left, const utils::Mass & right)
{
	return left * right.massInv;
}

} // namespace utils
} // namespace physic