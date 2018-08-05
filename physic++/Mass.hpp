#pragma once

namespace physic
{
    class Mass
    {
      private:
        template <typename T>
        friend T operator*(const T &left, const Mass &right);

        template <typename T>
        friend T operator/(const T &left, const Mass &right);

        double mass;
        double massInv;

      public:
        explicit Mass(double t_mass)
            : mass(t_mass)
            , massInv((mass == 0) ? 0 : 1 / mass)
        {}
    };

    template <typename T>
    T operator*(const T &left, const Mass &right)
    {
        return left * right.mass;
    }

    template <typename T>
    T operator/(const T &left, const Mass &right)
    {
        return left * right.massInv;
    }

} // namespace physic