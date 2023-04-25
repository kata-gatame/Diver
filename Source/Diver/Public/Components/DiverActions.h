// kata.codes
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiverActions.generated.h"

class ADiverCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIVER_API UDiverActions : public UActorComponent
{
	GENERATED_BODY()

	ADiverCharacter* Diver;

	UPROPERTY(EditAnywhere)
	float BaseWalkSpeed;

	bool bDiverSet;

protected:
	virtual void BeginPlay() override;

	void SetButtonPressed();
	void DiveButtonPressed();
	
	void SetDiver(bool bIsSet);
	void Dive();

public:	
	UDiverActions();

	friend class ADiverCharacter;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
