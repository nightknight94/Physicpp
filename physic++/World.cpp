#include "World.hpp"

#include "Collision.hpp"
#include "Object.hpp"

namespace physic
{
    void World::setGravity(math::Vector<2> g)
    {
        gravity = g;
    }

    void World::addObject(Object &o)
    {
        objects.push_back(&o);
    }

    void World::update(double dt)
    {
        for(auto &object : objects)
        {
            for(auto &object2 : objects)
            {
                physic::Collision((*object), (*object2));
            }
            object->force += (gravity * object->mass);
            object->update(dt);
        }
    }
} // namespace physic