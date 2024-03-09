// Copyright Epic Games, Inc. All Rights Reserved.

#include "CollisionCheckSystem.h"

#define LOCTEXT_NAMESPACE "FCollisionCheckSystemModule"

void FCollisionCheckSystemModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FCollisionCheckSystemModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCollisionCheckSystemModule, CollisionCheckSystem)