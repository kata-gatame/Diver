#pragma once

UENUM(BlueprintType)
enum class EDiverState : uint8
{
	EDS_UnSet UMETA(DisplayName = "UnSet"),
	EDS_Set UMETA(DisplayName = "Set"),

	EDS_MAX UMETA(DisplayName = "DefaultMAX")
};