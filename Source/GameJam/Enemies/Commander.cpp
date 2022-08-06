// Fill out your copyright notice in the Description page of Project Settings.


#include "GameJam/Enemies/Commander.h"
#include "Components/WidgetComponent.h"


ACommander::ACommander()
{
	AssimillitionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget Component for assimillition"));
	AssimillitionWidget->SetupAttachment(RootComponent);

	InfoWidgetForSkills = CreateDefaultSubobject<UWidgetComponent>(TEXT("The Info Widget"));
	InfoWidgetForSkills->SetupAttachment(RootComponent);
}

void ACommander::BeginPlay()
{
	Super::BeginPlay();

	AssimillitionWidget->SetVisibility(false);
	InfoWidgetForSkills->SetVisibility(false);
}

void ACommander::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

