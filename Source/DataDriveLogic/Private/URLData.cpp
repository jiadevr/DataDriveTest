// Fill out your copyright notice in the Description page of Project Settings.


#include "DataDriveLogic/Public/URLData.h"

void UURLData::GetURLMap(TMap<FName, FString>& Receiver) const
{
	Receiver=NameToURLMap;
}

void UURLData::GetDefaultName(FName& Receiver) const
{
	Receiver=DefaultURLName;
}
