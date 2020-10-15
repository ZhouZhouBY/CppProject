// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawn.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemySpawn::AEnemySpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
	RootComponent = SpawnArea;
	SpawnArea->SetBoxExtent(FVector(10000.0f, 10000.0f, 100.0f));

}

void AEnemySpawn::SpawnEnemy()
{
	FVector Origin;
	FVector Extends;
	GetActorBounds(false, Origin, Extends);
	FVector SpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extends);
	GetWorld()->SpawnActor<AEnemy>(EnemyType, SpawnPoint, FRotator::ZeroRotator);
}

// Called when the game starts or when spawned
void AEnemySpawn::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(SpawnHandle, this, &AEnemySpawn::SpawnEnemy, 1.0f, true);
}

// Called every frame
void AEnemySpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

