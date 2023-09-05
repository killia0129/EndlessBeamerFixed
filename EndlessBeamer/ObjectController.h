#pragma once
#include<vector>
#include"Object.h"

using namespace std;

class ObjectController
{
public:
    ObjectController();
    virtual ~ObjectController();
    void Update(float deltaTime);
    void DrawAll();
    void Entry(Object* newObj);
    void Delete();
    void ClearAll();

private:
    vector<Object*> object;
};

