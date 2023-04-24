// kata.codes

using UnrealBuildTool;

public class DiverEditorTarget : TargetRules
{
	public DiverEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("Diver");
	}
}
