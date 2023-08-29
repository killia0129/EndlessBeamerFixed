#include "Object.h"

ObjectType Object::TypeGetter()
{
    return type;
}

bool Object::IsEnd()
{
    return deadFlag;
}
