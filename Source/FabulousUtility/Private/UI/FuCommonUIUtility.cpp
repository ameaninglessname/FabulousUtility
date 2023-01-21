#include "UI/FuCommonUIUtility.h"

#include "CommonInputSubsystem.h"

ECommonInputType UFuCommonUIUtility::GetInputTypeForKey(const FKey& Key)
{
	// Based on FCommonInputPreprocessor::GetInputType().

	return !Key.IsGamepadKey()
		       ? ECommonInputType::MouseAndKeyboard
		       : !UCommonInputSubsystem::IsMobileGamepadKey(Key)
		       ? ECommonInputType::Gamepad
		       : ECommonInputType::Touch;
}

UUserWidget* UFuCommonUIUtility::FindRootUserWidgetOfClass(const UWidget* Widget, TSubclassOf<UUserWidget> UserWidgetClass)
{
	if (!IsValid(UserWidgetClass))
	{
		UserWidgetClass = UUserWidget::StaticClass();
	}

	UUserWidget* ResultUserWidget{nullptr};

	while (IsValid(Widget))
	{
		// The outer of every widget is the UWidgetTree it's in, and the outer of every UWidgetTree is the UUserWidget that owns it.

		const UWidgetTree* WidgetTree{Cast<UWidgetTree>(Widget->GetOuter())};
		if (!IsValid(WidgetTree))
		{
			break;
		}

		auto* UserWidget{Cast<UUserWidget>(WidgetTree->GetOuter())};
		if (IsValid(UserWidget) && UserWidget->IsA(UserWidgetClass))
		{
			ResultUserWidget = UserWidget;
		}

		Widget = UserWidget;
	}

	return ResultUserWidget;
}