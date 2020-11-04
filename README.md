# UE4

虚幻四引擎笔记与经验记录


How to set charactermovement


How to use Slate UI and UMG in c++

# UE4部分类介绍
AActor:
Actor在UE4中是不会被渲染的,除非给它挂载了需要渲染的组件

AHUD:
HUD是一个抬头显示器,能够绘制线条、贴图等基本元素

TSubClassOf<UMyUserWidget> MyUserWidgetClass;
UMyUserWidget* MyUserWidget;

void BeginPlay()
{
    Super::BeginPlay();
    APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    MyUserWidget = CreateWidget<UMyUserWidget>(Controller, MyUserWidgetClass);  //MyUserWidgetClass这个需要在蓝图中挂载
    if(MyUserWidget)
    {
        MyUserWidget->AddToViewport();
    }
}

# 游戏模式

AGameModeBase:UE4新版本新增的,开销小内容精简

AGameMode:UE4版本刚出就有的,新版本继承于AGameModeBase

如果想要关卡加载游戏模式,只需要打开该关卡,选择World Setting,然后将里面的GameMode更改为你的GameMode



# UE4 GUID生成：
FGuid NewGuid = FGuid::NewGuid();





# C++与蓝图互交互


如果想要把成员变量暴露给蓝图,并且可读写

UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="YourCategory")
float Speed;

成员变量暴露给蓝图,但是只允许蓝图读取

UPROPERTY(VisibleAnywhere, BluprintReadOnly, Category="YourCategory")
float Speed

成员变量暴露给蓝图,但是蓝图不可读写

UPROPERTY(VisibleAnywhere, Category="YourCategory")
float Speed;


