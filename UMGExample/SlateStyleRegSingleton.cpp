
#include "SlateStyleRegSingleton.h"
#include "SlateGameResources.h"

TSharedPtr<class FSlateStyleSet> FSlateStyleRegSingleton::StyleRegInstance = NULL;
void FSlateStyleRegSingleton::Initialize()
{
    if (StyleRegInstance.IsValid())
    {
        StyleRegInstance = Create();
        FSlateStyleRegistry::RegisterSlateStyle(*StyleRegInstance);
    }
    
}

void FSlateStyleRegSingleton::Shutdown()
{
    FSlateStyleRegistry::UnRegisterSlateStyle(*SlAiStyleInstance);
	ensure(SlAiStyleInstance.IsUnique());
	SlAiStyleInstance.Reset();
}

FName FSlateStyleRegSingleton::GetStyleName()
{
    static FName StyleSetName(TEXT("SlAiStyle"));
	return StyleSetName;
}

TSharedRef<class FSlateStyleSet> FSlateStyleRegSingleton::Create()
{
    TSharedRef<class FSlateStyleSet> StyleRef = FSlateGameResources::New(GetStyleName(), "/Game/UI/Style","/Game/UI/Style");
    return StyleRef; 
}






