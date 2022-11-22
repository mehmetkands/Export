//Playable Ball Character Class

#include "FastBowlingCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FastBowlPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"


AFastBowlingCharacter::AFastBowlingCharacter()
{
	// set our turn rate for input
	TurnRateGamepad = 50.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	StaticMeshC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCharacter"));
	StaticMeshC->SetupAttachment(RootComponent);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(StaticMeshC);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}


//Inputs

void AFastBowlingCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AFastBowlingCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AFastBowlingCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &AFastBowlingCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &AFastBowlingCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AFastBowlingCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AFastBowlingCharacter::TouchStopped);
}

void AFastBowlingCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFastBowlingCharacter::Tick(float Deltasecond)
{
	Super::Tick(Deltasecond);

	//Control ball skin in every frame.
	ChangeBallColor();
}

//Delay Destroy
void AFastBowlingCharacter::Destroyer()
{
	FTimerHandle FunctionTimer;
	GetWorldTimerManager().SetTimer(FunctionTimer, this, &AFastBowlingCharacter::StartDestroy, BallDestroyTimeDelay, false);
}

//Call "Destroy()" function in function.
void AFastBowlingCharacter::StartDestroy()
{
	Destroy();
}

//Set Ball Skin.
void AFastBowlingCharacter::ChangeBallColor()
{
	AFastBowlPlayerController* PC = Cast<AFastBowlPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PC)
	{
		//if Blue Skin is enabled, set blue skin.
		if (PC->TextureBlue == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material1, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Red Skin is enabled, set red skin.
		if (PC->TextureRed == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material2, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Green Skin is enabled, set Green skin.
		if (PC->TextureGreen == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material3, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Yellow Skin is enabled, set Yellow skin.
		if (PC->TextureYellow == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material4, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Purple Skin is enabled, set Purple skin.
		if (PC->TexturePurple == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material5, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if White Skin is enabled, set White skin.
		if (PC->TextureWhite == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material6, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Black Skin is enabled, set Black skin.
		if (PC->TextureBlack == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material7, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Golden Skin is enabled, set Golden skin.
		if (PC->TextureGolden == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material8, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Earth Skin is enabled, set Earth skin.
		if (PC->TextureEarth == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material9, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Moon Skin is enabled, set Moon skin.
		if (PC->TextureMoon == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material10, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Cloud Skin is enabled, set Cloud skin.
		if (PC->TextureCloud == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material11, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Flower Skin is enabled, set Flower skin.
		if (PC->TextureFlower == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material12, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}

		//if Cactus Skin is enabled, set Cactus skin.
		if (PC->TextureCactus == true)
		{
			UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material13, this);

			DynMaterial->SetScalarParameterValue("Parameter", 1.0f);
			StaticMeshC->SetMaterial(0, DynMaterial);
		}
	}
}

//Call Jump
void AFastBowlingCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

//Stop Jump
void AFastBowlingCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

//Set move speed
void AFastBowlingCharacter::SpeedPlus()
{
	GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed + 100;
}

//Set move speed
void AFastBowlingCharacter::SpeedNega()
{
	GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed - 100;
}

//Set TurnAtRate
void AFastBowlingCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

//Set LookUpAtRate
void AFastBowlingCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

//Set Forward and Backward movement physic.
void AFastBowlingCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FVector Route(Value * 55, 0, 0);
		StaticMeshC->AddAngularImpulseInDegrees(Route,NAME_None,true);
	}
}

//Set Left and Right movement physic.
void AFastBowlingCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		const FVector Route(Value * 15, 0, 0);
		StaticMeshC->AddImpulse(Route, NAME_None, true);

	}
}


//...