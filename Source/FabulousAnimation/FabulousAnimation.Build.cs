using UnrealBuildTool;

public class FabulousAnimation : ModuleRules
{
	public FabulousAnimation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		bEnableNonInlinedGenCppWarnings = true;
		// UnsafeTypeCastWarningLevel = WarningLevel.Warning;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"GameplayTags", "GameplayAbilities", "FabulousUtility", "FabulousAbilitySystem"
		});
	}
}
