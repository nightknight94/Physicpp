#pragma once

namespace physic
{
struct Material
{
    double m_density{};
    double m_restitution{};
};
} // namespace physic

namespace materials
{
constexpr physic::Material Rock{
    .m_density = 0.6,
    .m_restitution = 0.1,
};

constexpr physic::Material Wood{
    .m_density = 0.3,
    .m_restitution = 0.2,
};

constexpr physic::Material Metal{
    .m_density = 1.2,
    .m_restitution = 0.05,
};

constexpr physic::Material Bouncy{
    .m_density = 0.3,
    .m_restitution = 0.8,
};

constexpr physic::Material SuperBouncy{
    .m_density = 0.3,
    .m_restitution = 0.95,
};

constexpr physic::Material Pillow{
    .m_density = 0.1,
    .m_restitution = 0.2,
};

constexpr physic::Material Static{
    .m_density = 0.0,
    .m_restitution = 0.4,
};
} // namespace materials