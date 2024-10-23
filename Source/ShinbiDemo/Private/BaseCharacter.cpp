// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "AttributeSets/BasicAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	UAbilitySystemComponent* MyASC = this->FindComponentByClass<UAbilitySystemComponent>();
	if (MyASC)
	{
		// 通过ASC获取改变数值的属性，并绑定委托函数
		MyASC->GetGameplayAttributeValueChangeDelegate(UBasicAttributeSet::GetHPAttribute()).AddUObject(this, &ABaseCharacter::OnHealthAttributeChanged);
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	// 将属性值改变的情况进行广播处理
	HPChangeEvent.Broadcast(Data.NewValue);
}

