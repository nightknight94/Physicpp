#include "Collision.hpp"
#include "Body.hpp"
#include "Shape.hpp"

namespace physic
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

    Collision::Collision(Body &a, Body &b)
        : A(a)
        , B(b)
    {
        const double minPossibleDist = B.shape.getDistanceToCenter() + A.shape.getDistanceToCenter();
        const auto distaceBetweenBodies = math::norm(B.m_position - A.m_position);

        depth = distaceBetweenBodies - minPossibleDist;
        collisionNormal = (B.m_position - A.m_position) / distaceBetweenBodies;

        relativeVelocity = B.m_velocity - A.m_velocity;
        velocityNormal = math::dotProduct(relativeVelocity, collisionNormal);

        // Break if bodies don't collide
        if(detected())
        {
            // Break if velocities are separating
            if(velocityNormal < 0)
            {
                resolve();
                correctPosition();
            }
        }
    }

    bool Collision::detected()
    {
        return depth < 0;
    }

    void Collision::resolve()
    {
        double e = std::min(A.m_material.m_restitution, B.m_material.m_restitution);

        double impulseSkalar = -(1 + e) * velocityNormal;
        impulseSkalar /= (1 / A.m_mass + 1 / B.m_mass);

        auto impulse = collisionNormal * impulseSkalar;

        A.m_velocity -= (impulse * (1 / A.m_mass));
        B.m_velocity += (impulse * (1 / B.m_mass));
    }

    void Collision::correctPosition()
    {
        double percent = 0.2;
        math::Vector<2> correction = -depth * percent * collisionNormal / (1 / A.m_mass + 1 / B.m_mass);
        A.m_position -= correction / A.m_mass;
        B.m_position += correction / B.m_mass;
    }

} // namespace physic