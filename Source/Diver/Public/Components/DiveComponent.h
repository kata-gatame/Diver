// kata.codes

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiveComponent.generated.h"

class ADiverCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIVER_API UDiveComponent : public UActorComponent
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
	UDiveComponent();

	friend class ADiverCharacter;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
