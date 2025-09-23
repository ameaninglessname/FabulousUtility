#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FuCoordinateSpaceUtility.generated.h"

// https://dev.epicgames.com/documentation/unreal-engine/coordinate-space-terminology-in-unreal-engine?application_version=5.3

UCLASS()
class FABULOUSUTILITY_API UFuCoordinateSpaceUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		DisplayName = "Try Transform World to Clip Location (Local Player)",
		Meta = (ExpandBoolAsExecs = "ReturnValue", AutoCreateRefTerm = "WorldLocation"))
	static bool TryTransformWorldToClipLocationLocalPlayer(const ULocalPlayer* LocalPlayer,
	                                                       const FVector& WorldLocation, FVector4& ClipLocation);

	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		DisplayName = "Try Transform World to Clip Location (Player Controller)",
		Meta = (DefaultToSelf = "Player", ExpandBoolAsExecs = "ReturnValue", AutoCreateRefTerm = "WorldLocation"))
	static bool TryTransformWorldToClipLocation(const APlayerController* Player, const FVector& WorldLocation, FVector4& ClipLocation);

	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		DisplayName = "Try Transform World to Screen Location (Local Player)",
		Meta = (ExpandBoolAsExecs = "ReturnValue", AutoCreateRefTerm = "WorldLocation"))
	static bool TryTransformWorldToScreenLocationLocalPlayer(const ULocalPlayer* LocalPlayer,
	                                                         const FVector& WorldLocation, FVector2f& ScreenLocation,
	                                                         bool bCalculateOutsideScreenLocation = true);

	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		DisplayName = "Try Transform World to Screen Location (Player Controller)",
		Meta = (DefaultToSelf = "Player", ExpandBoolAsExecs = "ReturnValue", AutoCreateRefTerm = "WorldLocation"))
	static bool TryTransformWorldToScreenLocation(const APlayerController* Player, const FVector& WorldLocation,
	                                              FVector2f& ScreenLocation, bool bCalculateOutsideScreenLocation = true);

	// Same as UGameplayStatics::ProjectWorldToScreen() but simplified.
	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		DisplayName = "Try Transform World to Viewport Location (Local Player)",
		Meta = (ExpandBoolAsExecs = "ReturnValue", AutoCreateRefTerm = "WorldLocation"))
	static bool TryTransformWorldToViewportLocationLocalPlayer(const ULocalPlayer* LocalPlayer, const FVector& WorldLocation,
	                                                           FVector2f& ViewportLocation, bool bPlayerViewportRelative,
	                                                           bool bCalculateOutsideScreenLocation = true);

	// Same as UGameplayStatics::ProjectWorldToScreen() but simplified.
	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		DisplayName = "Try Transform World to Viewport Location (Player Controller)",
		Meta = (DefaultToSelf = "Player", ExpandBoolAsExecs = "ReturnValue", AutoCreateRefTerm = "WorldLocation"))
	static bool TryTransformWorldToViewportLocation(const APlayerController* Player, const FVector& WorldLocation,
	                                                FVector2f& ViewportLocation, bool bPlayerViewportRelative,
	                                                bool bCalculateOutsideScreenLocation = true);

	// Same as UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition() or UGameplayStatics::ProjectWorldToScreen()
	// with USlateBlueprintLibrary::ScreenToViewport(), but simplified and without rounding.
	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		DisplayName = "Try Transform World to Viewport Widget Location (Local Player)",
		Meta = (xpandBoolAsExecs = "ReturnValue", AutoCreateRefTerm = "WorldLocation"))
	static bool TryTransformWorldToViewportWidgetLocationLocalPlayer(const ULocalPlayer* LocalPlayer, const FVector& WorldLocation,
	                                                                 FVector2f& ViewportWidgetLocation, bool bPlayerViewportRelative,
	                                                                 bool bCalculateOutsideScreenLocation = true);

	// Same as UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition() or UGameplayStatics::ProjectWorldToScreen()
	// with USlateBlueprintLibrary::ScreenToViewport(), but simplified and without rounding.
	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		DisplayName = "Try Transform World to Viewport Widget Location (Player Controller)",
		Meta = (DefaultToSelf = "Player", ExpandBoolAsExecs = "ReturnValue", AutoCreateRefTerm = "WorldLocation"))
	static bool TryTransformWorldToViewportWidgetLocation(const APlayerController* Player, const FVector& WorldLocation,
	                                                      FVector2f& ViewportWidgetLocation, bool bPlayerViewportRelative,
	                                                      bool bCalculateOutsideScreenLocation = true);

	UFUNCTION(BlueprintCallable, Category = "Fabulous Utility|Coordinate Space Utility",
		Meta = (WorldContext = "WorldContext", ExpandBoolAsExecs = "ReturnValue"))
	static bool TryGetViewportWidgetSize(const UObject* WorldContext, FVector2f& ViewportWidgetSize);
};
