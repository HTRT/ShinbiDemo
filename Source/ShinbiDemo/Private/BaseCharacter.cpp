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
		MyASC->GetGameplayAttributeValueChangeDelegate(UBasicAttributeSet::GetMPAttribute()).AddUObject(this, &ABaseCharacter::OnManaAttributeChanged);
		MyASC->GetGameplayAttributeValueChangeDelegate(UBasicAttributeSet::GetStrengthAttribute()).AddUObject(this, &ABaseCharacter::OnStrengthAttributeChanged);
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

void ABaseCharacter::OnManaAttributeChanged(const FOnAttributeChangeData& Data)
{
	MPChangeEvent.Broadcast(Data.NewValue);
}

void ABaseCharacter::OnStrengthAttributeChanged(const FOnAttributeChangeData& Data)
{
	StrengthChangeEvent.Broadcast(Data.NewValue);
}

FGameplayAbilityInfoClass ABaseCharacter::GetGameplayAbilityInfo(TSubclassOf<UBaseGameplayAbility> AbilityClass, int level)
{
	UAbilitySystemComponent* MyASC = this->FindComponentByClass<UAbilitySystemComponent>();
	UBaseGameplayAbility* AbilityInstance = AbilityClass->GetDefaultObject<UBaseGameplayAbility>();

	if (MyASC && AbilityInstance)
	{
		return AbilityInstance->GetAbilityInfo(level);
	}

	return FGameplayAbilityInfoClass();
}

