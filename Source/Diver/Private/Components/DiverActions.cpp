// kata.codes

#include "Components/DiverActions.h"
#include "Character/DiverCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UDiverActions::UDiverActions()
{
	PrimaryComponentTick.bCanEverTick = true;

	BaseWalkSpeed = 600.f;
}

void UDiverActions::BeginPlay()
{
	Super::BeginPlay();
	if (Diver)
	{
		Diver->GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
		Diver->GetCharacterMovement()->JumpZVelocity = 700.f;
		Diver->GetCharacterMovement()->AirControl = 0.35f;
		Diver->GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
		Diver->GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	}
}

void UDiverActions::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDiverActions::SetButtonPressed()
{
	if (Diver) SetDiver(bDiverSet ? false : true);
}

void UDiverActions::SetDiver(bool bIsSetting)
{
	Diver->GetCharacterMovement()->SetMovementMode(bIsSetting ? MOVE_None : MOVE_Walking);
	bDiverSet = bIsSetting;
}

void UDiverActions::DiveButtonPressed()
{
	if (bDiverSet) Dive();
}

void UDiverActions::Dive()
{
	Diver->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	bDiverSet = false;
}
