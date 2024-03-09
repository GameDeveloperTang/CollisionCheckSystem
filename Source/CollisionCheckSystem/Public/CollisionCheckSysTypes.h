#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/HitResult.h"
#include "Engine/EngineTypes.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/ObjectMacros.h"
#include "CollisionCheckSysTypes.generated.h"

// Collision Check Pipline

USTRUCT(BlueprintType, meta = (Abstract))
struct FCollisionCheckPipline_Base
{
	GENERATED_BODY()

public:
	FCollisionCheckPipline_Base() {};

	virtual ~FCollisionCheckPipline_Base() {};

	virtual void DoTracePipline(UWorld* World) {};
};


// CollisionCheck Type Action

USTRUCT(BlueprintType, meta = (Abstract))
struct FCollisionCheckAction_Base
{
	GENERATED_BODY()

public:
	FCollisionCheckAction_Base() {};

	virtual ~FCollisionCheckAction_Base() {};

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FVector Start;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FVector End;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	TEnumAsByte<ETraceTypeQuery> TraceChannel;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	bool bMulti = false;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	bool bTraceComplex = false;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	TEnumAsByte<EDrawDebugTrace::Type> DebugDrawType;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	float DebugDrawDuration = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FLinearColor TraceColor= FLinearColor::Red;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FLinearColor HitResultColor = FLinearColor::Green;

// 	UPROPERTY(EditDefaultsOnly, Category = "Config")
// 	TArray<FInstancedStruct> CollisionParamsPrepares;

	virtual void Trace(UWorld* World, FHitResult& OutHit) {};

	virtual void Trace(UWorld* World, TArray<FHitResult>& OutHits) {};
};

USTRUCT(BlueprintType)
struct FCollisionCheckAction_LineTrace : public FCollisionCheckAction_Base
{
	GENERATED_BODY()

public:
	FCollisionCheckAction_LineTrace() {};

	virtual ~FCollisionCheckAction_LineTrace() override {};

	UPROPERTY(EditDefaultsOnly, Category = "Config", meta = (DisplayPriority = 1))
	float LineLength;

	virtual void Trace(UWorld* World, FHitResult& OutHit) override;

	virtual void Trace(UWorld* World, TArray<FHitResult>& OutHits) override;
};

USTRUCT(BlueprintType)
struct FCollisionCheckAction_ShapeTrace : public FCollisionCheckAction_Base
{
	GENERATED_BODY()

public:
	FCollisionCheckAction_ShapeTrace() {};

	virtual ~FCollisionCheckAction_ShapeTrace() override {};

	//virtual void Trace(UWorld* World, FHitResult& Output) override;
};

USTRUCT(BlueprintType)
struct FCollisionCheckAction_ShapeOverlap : public FCollisionCheckAction_Base
{
	GENERATED_BODY()

public:
	FCollisionCheckAction_ShapeOverlap() {};

	virtual ~FCollisionCheckAction_ShapeOverlap() override {};
};


// HitResult Filter Struct

USTRUCT(BlueprintType, meta = (Abstract))
struct FCollisionCheckFilter_Base
{
	GENERATED_BODY()

public:
	FCollisionCheckFilter_Base() {};

	virtual ~FCollisionCheckFilter_Base() {};

	virtual void Filter(TArray<FHitResult>& OutHits) {};

	virtual void Filter(FHitResult& OutHit) {};
};

// CollisionPrepare Stuct