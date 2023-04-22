// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/DiveGameGameMode.h"
#include "Character/DiveGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADiveGameGameMode::ADiveGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
