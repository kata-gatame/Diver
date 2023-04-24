// kata.codes

#include "Components/DiveComponent.h"
#include "Character/DiverCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UDiveComponent::UDiveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	BaseWalkSpeed = 600.f;
}

void UDiveComponent::BeginPlay()
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

void UDiveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDiveComponent::SetButtonPressed()
{
	if (Diver) SetDiver(bDiverSet ? false : true);
}

void UDiveComponent::SetDiver(bool bIsSetting)
{
	Diver->GetCharacterMovement()->SetMovementMode(bIsSetting ? MOVE_None : MOVE_Walking);
	bDiverSet = bIsSetting;
}

void UDiveComponent::DiveButtonPressed()
{
	if (bDiverSet) Dive();
}

void UDiveComponent::Dive()
{
	Diver->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	bDiverSet = false;
}
