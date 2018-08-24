#pragma once

namespace physic
{
namespace utils
{
struct Material
{
	double m_density{};
	double m_restitution{};
};
} // namespace utils
} // namespace physic

namespace materials
{
constexpr physic::utils::Material Rock{
    .m_density     = 0.6,
    .m_restitution = 0.1,
};

constexpr physic::utils::Material Wood{
    .m_density     = 0.3,
    .m_restitution = 0.2,
};

constexpr physic::utils::Material Metal{
    .m_density     = 1.2,
    .m_restitution = 0.05,
};

constexpr physic::utils::Material Bouncy{
    .m_density     = 0.3,
    .m_restitution = 0.8,
};

constexpr physic::utils::Material SuperBouncy{
    .m_density     = 0.3,
    .m_restitution = 0.95,
};

constexpr physic::utils::Material Pillow{
    .m_density     = 0.1,
    .m_restitution = 0.2,
};

constexpr physic::utils::Material Static{
    .m_density     = 0.0,
    .m_restitution = 0.4,
};
} // namespace materials