using UnrealBuildTool;

public class FabulousAbilitySystem : ModuleRules
{
	public FabulousAbilitySystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		bEnableNonInlinedGenCppWarnings = true;
		// UnsafeTypeCastWarningLevel = WarningLevel.Warning;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "GameplayTags", "GameplayAbilities", "FabulousUtility"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"EnhancedInput", "NetCore", "GameplayTasks", "NavigationSystem"
		});

		SetupIrisSupport(Target);
	}
}
