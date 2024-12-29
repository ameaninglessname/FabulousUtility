using UnrealBuildTool;

public class FabulousAI : ModuleRules
{
	public FabulousAI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		bEnableNonInlinedGenCppWarnings = true;
		// UnsafeTypeCastWarningLevel = WarningLevel.Warning;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "GameplayTags", "AIModule"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"GameplayAbilities", "NavigationSystem", "FabulousUtility", "FabulousAbilitySystem"
		});
	}
}
