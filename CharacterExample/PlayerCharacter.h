



//How to set charactermovement
//在Input设置按键进行绑定
//MoveForward:绑定W和S键,值设定为1.0和-1.0
//MoveRight:绑定A和D键,值设定为-1.0和1.0
//Jump:设定为空格键
//Turn:绑定MouseX
//LookUp:绑定MouseY


UCLASS(config=Game)
class APlayerCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;
	
	
	
	
private:	
	void MoveForward(float Axis);
	
	void MoveRight(float Axis);
	
	void Turn(float Rote);
	
	void LookUp(float Rote);
	
public:
	UPROPERTY(VisibleAnywhere, Category="Camera")
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere, Category="Camera")
	class UCameraComponent* FollowCamera;
	
	UPROPERTY(EditAnywhere, Category="Atribute")
	float BaseTurnRote;
	
	UPROPERTY(EditAnywhere, Category="Atribute")
	float BaseLookUpRote;
	
	
}






