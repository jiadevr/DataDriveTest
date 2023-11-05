// Fill out your copyright notice in the Description page of Project Settings.


#include "DataDriveLogic/Public/WebBrowserHUD.h"

#include "URLData.h"
#include "WebBrowserWorldData.h"

void AWebBrowserHUD::BeginPlay()
{
	InitialURL();
	Super::BeginPlay();
}

void AWebBrowserHUD::InitialURL()
{
	AWorldSettings* CustomWorldSetting= GetWorldSettings();
	if (nullptr==CustomWorldSetting)
	{
		UE_LOG(LogTemp,Error,TEXT("Get NUll World Settings"));
		return;
	}
	AWebBrowserWorldData* URLSettings=Cast<AWebBrowserWorldData>(CustomWorldSetting);
	if (nullptr==URLSettings)
	{
		UE_LOG(LogTemp,Error,TEXT("Get World Settings,But Not Match AWebBrowserWorldData"));
		return;
	}
	if (!URLSettings->URLDataForCurrentWorld)
	{
		UE_LOG(LogTemp,Error,TEXT("AWebBrowserWorldData Define None URLData"));
	}
	URLSettings->URLDataForCurrentWorld->GetURLMap(URLMap);
	URLSettings->URLDataForCurrentWorld->GetDefaultName(DefaultURLName);
	if (!URLMap.Contains(DefaultURLName))
	{
		UE_LOG(LogTemp,Error,TEXT("Find Null URL Data Named:%s"),*DefaultURLName.ToString());
		return;
	}
	
}
