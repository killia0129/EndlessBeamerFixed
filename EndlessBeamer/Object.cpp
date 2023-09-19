#include "Object.h"

ObjectType Object::TypeGetter()
{
    return type;
}

bool Object::IsEnd()
{
    return deadFlag;
}

VECTOR Object::PosGetter()
{
    return pos;
}

void Object::GivenDmg(float dmg)
{
    hp -= dmg;
}
