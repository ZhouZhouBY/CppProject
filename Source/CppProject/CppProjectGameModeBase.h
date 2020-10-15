// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CppProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CPPPROJECT_API ACppProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 points;
};
