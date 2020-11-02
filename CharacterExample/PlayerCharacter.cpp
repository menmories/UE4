



//How to set charactermovement
//在Input设置按键进行绑定
//MoveForward:绑定W和S键,值设定为1.0和-1.0
//MoveRight:绑定A和D键,值设定为-1.0和1.0
//Jump:设定为空格键
//Turn:绑定MouseX
//LookUp:绑定MouseY


#include "PlayerCharacter.h"
#include "UObject/ConstrctorHelpers.h"

APlayerCharacter::APlayerCharacter()
{
	BaseTurnRote = 45.0f;
	BaseLookUpRote = 45.0f;
	//设置胶囊体大小
	GetCapsuleComponent()->InitCapsuleSize(35.0f, 90.0f);
	//设置控制器不受旋转影响
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	static ConstrctorHelpers::FObjectFinder<USkeletalMesh> PlayerPawnSkeletalMesh(TEXT("Your skeletalMesh folder"));
	if(PlayerPawnSkeletalMesh.IsSuccessed())
	{
		GetMesh()->SetSkeletalMesh(PlayerPawnSkeletalMesh.Object);
		GetMesh()->SetRelativeLotation(FVector(0.0f, 0.0f, -90.0f));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	}
	
	//创建自拍杆,并将自拍杆附加到角色上
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->AttachTo(RootComponent);
	SpringArm->TargetArmLength = 260.0f;		//设置自拍杆与角色之间的间距为260cm
	SpringArm->bUsePawnControlRotation = true;
	//创建相机并把相机附加到自拍杆上
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->AttachTo(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	
	//设置控制器在移动时可以旋转
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->VelocityZOrder = 600.0f;		//跳跃高度
	GetCharacterMovement()->SetMaxWalkSpeed(300.0f);
}

void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	
	PlayerInputComponent->BindAction("Jump", this, IE_Pressed, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", this, IE_Released, &ACharacter::StopJumping);
}

void APlayerCharacter::MoveForward(float Axis)
{
	const FRotator Rotator = GetController()->GetControlRotation();
	const FRotator YawRotation = FRotator(0.0f, Rotator.Yaw, 0.0f);
	
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Axis);
}

void APlayerCharacter::MoveRight(float Axis)
{
	const FRotator Rotator = GetController()->GetControlRotation();
	const FRotator YawRotation = FRotator(0.0f, Rotator.Yaw, 0.0f);
	
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Axis);
}

void APlayerCharacter::Turn(float Rote)
{
	AddControllerYawInput(Rote * BaseTurnRote * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::LookUp(float Rote)
{
	AddControllerPitchInput(Rote * BaseLookUpRote * GetWorld()->GetDeltaSeconds());
}




