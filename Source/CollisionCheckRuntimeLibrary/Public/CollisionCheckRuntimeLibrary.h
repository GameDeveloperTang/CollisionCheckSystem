// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "CollisionCheckRuntimeLibrary.generated.h"

class FCollisionCheckRuntimeLibraryModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

UCLASS()
class COLLISIONCHECKRUNTIMELIBRARY_API UCollisionCheckRuntimeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void Test();
};