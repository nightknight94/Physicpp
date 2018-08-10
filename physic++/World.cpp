#include "World.hpp"

#include "Collision.hpp"
#include "Object.hpp"

namespace physic
{
    void World::setGravity(const math::Vector<2> &i_gravity)
    {
        gravity = i_gravity;
    }

    void World::addObject(Object &i_object)
    {
        objects.push_back(&i_object);
    }

    void World::resolveCollisions()
    {
        for(auto &object1 : objects)
        {
            for(auto &object2 : objects)
            {
                physic::Collision((*object1), (*object2));
            }
        }
    }

    void World::update(double dt)
    {
        resolveCollisions();

        for(auto &object : objects)
        {
            object->force += (gravity * object->mass);
            object->update(dt);
        }
    }
} // namespace physic