

/*
* Slate样式注册单例
*/

#include "CoreMinimal.h"
#include "SlateBasics.h"

class FSlateStyleRegSingleton
{
public:
    static void Initialize();

    static void Shutdown();

    static FName GetStyleName();

private:
    static TSharedRef<class FSlateStyleSet> Create();

    static TSharedPtr<class FSlateStyleSet> StyleRegInstance;
};




