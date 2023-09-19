#include "ObjectController.h"

ObjectController::ObjectController()
{
    playerBeamPoint = 0;
    playerBeamPoint = 0;
}

ObjectController::~ObjectController()
{
}

void ObjectController::Update(float deltaTime)
{
    for (auto ptr : object)
    {
        ptr->Update(deltaTime);
    }
}

void ObjectController::DrawAll()
{
    for (auto ptr : object)
    {
        ptr->Draw();
    }
}

void ObjectController::Entry(Object* newObj)
{
    object.emplace_back(newObj);
}

void ObjectController::Delete()
{
    std::vector<Object*>deleteObj;
    for (auto ptr : object)
    {
        if (ptr->IsEnd())
        {
            deleteObj.emplace_back(ptr);
        }
    }
    for (auto ptr : deleteObj)
    {
        auto iter = std::find(object.begin(), object.end(), ptr);
        if (iter != object.end())
        {
            std::iter_swap(iter, object.end() - 1);
            object.pop_back();
        }
    }
}

void ObjectController::ClearAll()
{
    object.clear();
}

void ObjectController::HitChecker(float deltaTime)
{
    for (auto ptr : object)
    {
        if (ptr->TypeGetter() == NEEDLE || ptr->TypeGetter() == METEOR)
        {
            float ratio = ptr->PosGetter().z / object[playerBeamPoint]->PosGetter().z;
            float hitPointX = object[playerPoint]->PosGetter().x + ((object[playerBeamPoint]->PosGetter().x - object[playerPoint]->PosGetter().x) * ratio);
            float hitPointY = object[playerPoint]->PosGetter().y + ((object[playerBeamPoint]->PosGetter().y - object[playerPoint]->PosGetter().y) * ratio);
            VECTOR hitPos = VGet(hitPointX, hitPointY, ptr->PosGetter().z);
            float dis = pow((ptr->PosGetter().x - hitPos.x), 2.f) + pow((ptr->PosGetter().y - hitPos.y), 2.f);
            dis = sqrt(dis);
        }
    }
}

void ObjectController::SetPlayerAndPlayerBeam()
{
    for (int i = 0; i < object.size(); i++)
    {
        if (object[i]->TypeGetter() == PLAYER)
        {
            playerPoint = i;
        }
        if (object[i]->TypeGetter() == PLAYER_BEAM)
        {
            playerBeamPoint = i;
        }
    }
}

int ObjectController::GetSize()
{
    return object.size();
}
