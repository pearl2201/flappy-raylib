#pragma once

class IGameObject
{
public:
    IGameObject();
    virtual ~IGameObject();
    virtual void Start();
    virtual void Update(float delta);
    virtual void Draw();
    virtual int GetId() {return id;}
    int id;
};