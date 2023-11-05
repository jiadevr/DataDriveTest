// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WebBrowserHUD.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVELOGIC_API AWebBrowserHUD : public AHUD
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable,Category="WebURL")
	void InitialURL();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WebURL")
	TMap<FName,FString> URLMap;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WebURL")
	FName DefaultURLName;
};
