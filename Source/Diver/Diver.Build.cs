// kata.codes

using UnrealBuildTool;

public class Diver : ModuleRules
{
	public Diver(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"EnhancedInput",
			"Engine",
			"InputCore",
			"Niagara",
			"UMG"
		});
	}
}
