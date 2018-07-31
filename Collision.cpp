#include "Collision.hpp"
#include "Body.hpp"

namespace
{
    struct CollisionInfo
    {
        physic::Body &A;
        physic::Body &B;
        const math::Vector<2> collisionNormal;
        const double depth;
        const math::Vector<2> relativeVelocity;
        const double velocityNormal;
    };

    CollisionInfo getCollisionInfo(physic::Body &A, physic::Body &B)
    {
        const double minPossibleDist = B.m_shape.getRadius() + A.m_shape.getRadius();
        const auto distaceBetweenBodies = math::norm(B.m_position - A.m_position);

        const double collisionDepth = distaceBetweenBodies - minPossibleDist;
        const auto collisionNormal = (B.m_position - A.m_position) / distaceBetweenBodies;

        const auto relativeVelocity = B.m_velocity - A.m_velocity;
        const double velocityNormal = math::dotProduct(relativeVelocity, collisionNormal);

        return CollisionInfo{
            .A = A,
            .B = B,
            .collisionNormal = collisionNormal,
            .depth = collisionDepth,
            .relativeVelocity = relativeVelocity,
            .velocityNormal = velocityNormal,
        };
    }

    bool collisionDetected(const CollisionInfo &info)
    {
        return info.depth < 0;
    }

    void resolveCollision(CollisionInfo &info)
    {
        double e = std::min(info.A.m_material.m_restitution, info.B.m_material.m_restitution);

        double impulseSkalar = -(1 + e) * info.velocityNormal;
        impulseSkalar /= (1 / info.A.m_mass + 1 / info.B.m_mass);

        auto impulse = info.collisionNormal * impulseSkalar;

        info.A.m_velocity -= (impulse * (1 / info.A.m_mass));
        info.B.m_velocity += (impulse * (1 / info.B.m_mass));
    }

    void positionCorrection(CollisionInfo &info)
    {
        double percent = 0.2;
        math::Vector<2> correction = -info.depth * percent * info.collisionNormal / (1 / info.A.m_mass + 1 / info.B.m_mass);
        info.A.m_position -= correction / info.A.m_mass;
        info.B.m_position += correction / info.B.m_mass;
    }
} // namespace

namespace physic
{
    void collision(Body &a, Body &b)
    {
        auto info = getCollisionInfo(a, b);

        // Break if bodies don't collide
        if(not collisionDetected(info))
        {
            return;
        }

        // Break if velocities are separating
        if(info.velocityNormal < 0)
        {
            resolveCollision(info);
            positionCorrection(info);
        }
    }
} // namespace physic