#pragma once
#include "TransitionScene.h"
class FadeInOut :
    public TransitionScene
{
public:
    FadeInOut(std::unique_ptr<BaseScene> beforScene, std::unique_ptr<BaseScene> afterScene, const double& limitTime = 3.0);
    virtual ~FadeInOut()override final;
private:
    double limitTime_;

    bool UpdateTransition(const float& delta);
    void DrawOwnScreen(void)override final;

};

