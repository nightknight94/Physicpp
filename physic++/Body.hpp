#pragma once

#include "IBody.hpp"

namespace physic
{
class IShape;

class Body : public IBody
{
  public:
    void setMaterial(const Material &m) override;
    void setShape(const IShape &s) override;

    void update(double dt) override;
};

} // namespace physic