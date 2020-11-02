



#include "PlayerGameMode.h"
#include "UObject/ConstrctorHelpers.h"

void PlayerGameMode::PlayerGameMode()
{
	static ConstrctorHelpers::FClassFinder<APawn> PlayerCharacter(TEXT("Your character blueprint path"));
	if(PlayerCharacter.Class != NULL)
	{
		DefaultPawn = PlayerCharacter.Class;
	}
	//failed to load character blueprint.
	
	//HUD
	//HUDClass = XXXX::StaticClass();
}




