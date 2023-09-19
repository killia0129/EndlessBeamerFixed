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
    void HitChecker(float deltaTime);
    void SetPlayerAndPlayerBeam();
    int GetSize();
    bool PlusTimeFlag();
    int KilledNum();
    int TypeObjetNumGetter(ObjectType objName);
    VECTOR PlayerPosGetter();

private:
    vector<Object*> object;
    int playerPoint;
    int playerBeamPoint;
    bool plusTime;
    int killed;
};

