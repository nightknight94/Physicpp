#include "CollisionSolver.hpp"

#include <algorithm>

#include "IShape.hpp"
#include "Material.hpp"
#include "Particle.hpp"

namespace physic
{
struct CollisionInfo
{
    physic::Particle &A;
    physic::Particle &B;
    const math::Vector<2> collisionNormal;
    const double depth;
    const math::Vector<2> relativeVelocity;
    const double velocityNormal;
};

void CollisionSolver::operator()(Particle &a, Particle &b)
{
    A = &a;
    B = &b;

    // Don't resolve if a and b points to the same body
    if(&a == &b)
    {
        return;
    }

    const double minPossibleDist =
        B->getRadius() + A->getRadius();
    const auto distaceBetweenBodies = math::norm(B->position - A->position);

    depth = distaceBetweenBodies - minPossibleDist;
    collisionNormal = (B->position - A->position) / distaceBetweenBodies;

    relativeVelocity = B->velocity - A->velocity;
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

bool CollisionSolver::detected() { return depth < 0; }

void CollisionSolver::resolve()
{
    double e = std::min(A->material->m_restitution, B->material->m_restitution);

    double impulseSkalar = -(1 + e) * velocityNormal;
    impulseSkalar /= (1 / A->mass + 1 / B->mass);

    auto impulse = collisionNormal * impulseSkalar;

    A->velocity -= (impulse * (1 / A->mass));
    B->velocity += (impulse * (1 / B->mass));
}

void CollisionSolver::correctPosition()
{
    double percent = 0.2;
    math::Vector<2> correction = -depth * percent * collisionNormal / (1 / A->mass + 1 / B->mass);
    A->position -= correction / A->mass;
    B->position += correction / B->mass;
}

} // namespace physic
