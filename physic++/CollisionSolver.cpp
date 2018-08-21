#include "CollisionSolver.hpp"

#include "Particle.hpp"

#include <algorithm>

namespace physic
{
void CollisionSolver::operator()(Particle & a, Particle & b)
{
	// Don't resolve if a and b points to the same body
	if(&a == &b)
	{
		return;
	}

	A = &a;
	B = &b;

	const double minPossibleDist    = B->getRadius() + A->getRadius();
	const auto distaceBetweenBodies = math::norm(B->getPosition() - A->getPosition());

	depth = distaceBetweenBodies - minPossibleDist;

	// Break if bodies don't collide
	if(detected())
	{
		collisionNormal  = (B->getPosition() - A->getPosition()) / distaceBetweenBodies;
		relativeVelocity = B->getVelocity() - A->getVelocity();
		velocityNormal   = math::dotProduct(relativeVelocity, collisionNormal);

		// Break if velocities are separating
		if(velocityNormal < 0)
		{
			resolve();
			correctPosition();
		}
	}
}

bool CollisionSolver::detected()
{
	return depth < 0;
}

void CollisionSolver::resolve()
{
	double e = std::min(A->getMaterial().m_restitution, B->getMaterial().m_restitution);

	double impulseSkalar = -(1 + e) * velocityNormal;
	impulseSkalar /= (1 / A->getMass() + 1 / B->getMass());

	auto impulse = collisionNormal * impulseSkalar;

	A->setVelocity(A->getVelocity() - (impulse * (1 / A->getMass())));
	B->setVelocity(B->getVelocity() + (impulse * (1 / B->getMass())));
}

void CollisionSolver::correctPosition()
{
	double percent = 0.2;
	math::Vector<2> correction =
	    -depth * percent * collisionNormal / (1 / A->getMass() + 1 / B->getMass());
	A->setPosition(A->getPosition() - correction / A->getMass());
	B->setPosition(B->getPosition() + correction / B->getMass());
}

} // namespace physic
