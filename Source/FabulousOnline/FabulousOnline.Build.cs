using UnrealBuildTool;

public class FabulousOnline : ModuleRules
{
	public FabulousOnline(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnableNonInlinedGenCppWarnings = true;
		// UnsafeTypeCastWarningLevel = WarningLevel.Warning;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "OnlineSubsystemUtils"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"OnlineSubsystem", "FabulousUtility"
		});
	}
}
