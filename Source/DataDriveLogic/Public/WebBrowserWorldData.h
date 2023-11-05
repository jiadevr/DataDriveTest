// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "WebBrowserWorldData.generated.h"

class UURLData;
/**
 * 
 */
UCLASS()
class DATADRIVELOGIC_API AWebBrowserWorldData : public AWorldSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="CurrentWorldData")
	UURLData* URLDataForCurrentWorld;
};
