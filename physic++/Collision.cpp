#include "Collision.hpp"

#include <algorithm>

#include "IBody.hpp"
#include "IShape.hpp"
#include "Material.hpp"

namespace physic
{
struct CollisionInfo
{
    physic::IBody &A;
    physic::IBody &B;
    const math::Vector<2> collisionNormal;
    const double depth;
    const math::Vector<2> relativeVelocity;
    const double velocityNormal;
};

Collision::Collision(IBody &a, IBody &b)
    : A(a)
    , B(b)
{
    // Don't resolve if a and b points to the same body
    if(&a == &b)
    {
        return;
    }

    const double minPossibleDist =
        B.shape->getDistanceToCenter() + A.shape->getDistanceToCenter();
    const auto distaceBetweenBodies = math::norm(B.position - A.position);

    depth = distaceBetweenBodies - minPossibleDist;
    collisionNormal = (B.position - A.position) / distaceBetweenBodies;

    relativeVelocity = B.velocity - A.velocity;
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

bool Collision::detected() { return depth < 0; }

void Collision::resolve()
{
    double e = std::min(A.material->m_restitution, B.material->m_restitution);

    double impulseSkalar = -(1 + e) * velocityNormal;
    impulseSkalar /= (1 / A.mass + 1 / B.mass);

    auto impulse = collisionNormal * impulseSkalar;

    A.velocity -= (impulse * (1 / A.mass));
    B.velocity += (impulse * (1 / B.mass));
}

void Collision::correctPosition()
{
    double percent = 0.2;
    math::Vector<2> correction =
        -depth * percent * collisionNormal / (1 / A.mass + 1 / B.mass);
    A.position -= correction / A.mass;
    B.position += correction / B.mass;
}

} // namespace physic
