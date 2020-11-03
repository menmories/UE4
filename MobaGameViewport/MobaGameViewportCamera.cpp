
#include "MobaGameViewportCamera.h"




AMobaGameViewportCamera::AMobaGameViewportCamera()
{
    PrimaryActorTick.bCanEverTick = false;
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

    MarkBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MarkBox"))

    CameraBoom->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

    FollowCamera->AttachToComponent(CameraBoom, FAttachmentTransformRules::KeepRelativeTransform);

    MarkBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AMobaGameViewportCamera::BeginPlay()
{
    Super::BeginPlay();
}