// kata.codes

using UnrealBuildTool;

public class DiverTarget : TargetRules
{
	public DiverTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("Diver");
	}
}
