/*===========================================================================
    C++ class definitions exported from UnrealScript.
    This is automatically generated by the tools.
    DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/

#include "../inc/ModClasses.h"

IMPLEMENT_PACKAGE(Mod)

IMPLEMENT_CLASS(UModGameEngine)
IMPLEMENT_CLASS(UModRenderDevice)

UBOOL UModGameEngine::Exec(const char* Cmd, FOutputDevice& Ar){
	UBOOL handledCmd = 0;	//True if the command was recognized

	float FloatParam;

	if(GIsClient && Parse(Cmd, "SetCustomTickRate", FloatParam)){
		if(FloatParam <= 0.0f){
			GLog->Logf("%f is not a valid tick rate", FloatParam);
		}else{
			CustomTickRate = FloatParam;
			SaveConfig();
		}

		handledCmd = 1;
	}

	return Super::Exec(Cmd, Ar) || handledCmd;
}

void UModGameEngine::Tick(float DeltaTime){
	//Could be changed to a class member which would be safer but realistically
	//there will never be more than one instance of ModGameEngine at a time
	static DOUBLE OldTime = appSeconds();

	Super::Tick(DeltaTime);

	//Enforce custom maximum tick rate but only if client
	if(GIsClient && CustomTickRate > 0.0){
		double Delta = static_cast<float>((1.0 / CustomTickRate) - (appSeconds() - OldTime));

		appSleep(Delta > 0.0 ? Delta : 0.0);
	}

	OldTime = appSeconds();
}

FLOAT UModGameEngine::GetMaxTickRate(){
	if(GIsClient)
		return CustomTickRate;

	return Super::GetMaxTickRate();
}