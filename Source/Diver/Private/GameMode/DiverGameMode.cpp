// kata.codes

#include "GameMode/DiverGameMode.h"
#include "UObject/ConstructorHelpers.h"

ADiverGameMode::ADiverGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/_Blueprints/BP_Diver"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
