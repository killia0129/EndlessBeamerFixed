#include "ObjectController.h"

ObjectController::ObjectController()
{
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
