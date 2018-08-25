#pragma once

namespace physic
{
namespace utils
{
class Convert
{
  private:
	const double si2px_ratio;

  public:
	constexpr Convert(double i_si2px_ratio)
	    : si2px_ratio(i_si2px_ratio)
	{}

	template <typename T>
	constexpr auto si2px(T si) const
	{
		return si * si2px_ratio;
	}

	template <typename T>
	constexpr auto px2si(T px) const
	{
		return px / si2px_ratio;
	}
};

} // namespace utils
} // namespace physic