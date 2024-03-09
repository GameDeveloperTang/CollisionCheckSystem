#include "CollisionCheckSysTypes.h"
#include "Kismet/KismetSystemLibrary.h"


void FCollisionCheckAction_LineTrace::Trace(UWorld* World, FHitResult& OutHit)
{
	if (!World || LineLength <= 0 || bMulti)
	{
		return;
	}

	OutHit.Init();

	//UKismetSystemLibrary::LineTraceSingle(World,)
}

void FCollisionCheckAction_LineTrace::Trace(UWorld* World, TArray<FHitResult>& OutHits)
{
	if (!World || LineLength <= 0 || !bMulti)
	{
		return;
	}

	OutHits.Empty();
}
