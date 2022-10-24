#pragma once
#include <memory>


class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();

	virtual bool Init(void) = 0;
	virtual std::unique_ptr<BaseScene> Update(std::unique_ptr<BaseScene> ownScene) = 0;

	virtual void Draw(void);
	virtual void DrawOwnScreen(void) = 0;
	virtual void DebugDraw(void) = 0;

private:
protected:
	int screenID_;
};