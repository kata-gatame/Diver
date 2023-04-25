#pragma once

UENUM(BlueprintType)
enum class EDiveGroup : uint8
{
	EDG_Forward UMETA(DisplayName = "Forward"),
	EDG_Backward UMETA(DisplayName = "Backward"),
	EDG_Reverse UMETA(DisplayName = "Reverse"),
	EDG_Inward UMETA(DisplayName = "Inward"),
	EDG_Twisting UMETA(DisplayName = "Twisting"),
	EDG_ArmStand UMETA(DisplayName = "ArmStand"),

	EDG_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class EDivePosition : uint8
{
	EDP_Straight UMETA(DisplayName = "Straight"),
	EDP_Pike UMETA(DisplayName = "Pike"),
	EDP_Tuck UMETA(DisplayName = "Tuck"),
	EDP_Free UMETA(DisplayName = "Free"),

	EDP_MAX UMETA(DisplayName = "DefaultMAX")
};
