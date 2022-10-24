#pragma once
#include "../BaseScene.h"

enum class Transition
{
    CrossFade,
    FadeInOut,
    Slide,
    Max,
};

class TransitionScene :
    public BaseScene
{
public:
    TransitionScene(std::unique_ptr<BaseScene> beforScene, std::unique_ptr<BaseScene> afterScene);
    virtual ~TransitionScene();
private:
    virtual bool UpdateTransition(const float& delta) = 0;
    bool Init(void)override;
    std::unique_ptr<BaseScene> Update(std::unique_ptr<BaseScene> ownScene)override final;
    virtual void DebugDraw(void);
protected:
    std::unique_ptr<BaseScene> beforScene_;
    std::unique_ptr<BaseScene> afterScene_;

    double count_;
    static constexpr int EIGHTBITS_NUM = 255;
    static constexpr float EIGHTBITS_NUM_F = 255;
};

