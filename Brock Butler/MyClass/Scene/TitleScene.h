#pragma once
#include "BaseScene.h"

class TitleScene :
    public BaseScene
{
public:
    TitleScene();
    ~TitleScene();
private:
	virtual bool Init(void);
	virtual std::unique_ptr<BaseScene> Update(std::unique_ptr<BaseScene> ownScene);

	virtual void DrawOwnScreen(void);
	virtual void DebugDraw(void);


};

