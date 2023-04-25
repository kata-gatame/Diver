// kata.codes
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "DiverCharacter.generated.h"

class UCameraComponent;
class UDiverActions;
class UInputAction;
class UInputMappingContext;
class USpringArmComponent;

UCLASS(config=Game)
class ADiverCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UDiverActions* DiverActions;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Set Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* SetAction;

	/** Dive Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* DiveAction;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay() override;

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for set input */
	void Set();

	/** Called for dive input */
	void Dive();

public:
	ADiverCharacter();
	virtual void PostInitializeComponents() override;

	bool IsSet() const;

	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
