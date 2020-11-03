



#include "MobaGameViewportCamera.Generator.h"


UCLASS(config=Game)
class PROJECTNAME_API AMobaGameViewportCamera : public APawn
{
    GENERATED_BODY()
public:
    AMobaGameViewportCamera();

    virtual void BeginPlay()override;
    

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
    class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
    class UCameraComponent* FollowCamera;
    //碰撞盒
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
        class UBoxComponent* MarkBox;
    
    
};

