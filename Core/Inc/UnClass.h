/*=============================================================================
	UnClass.h: UClass definition.
	Copyright 1997-1999 Epic Games, Inc. All Rights Reserved.

	Revision history:
		* Created by Tim Sweeney.
=============================================================================*/

/*-----------------------------------------------------------------------------
	Constants
-----------------------------------------------------------------------------*/

//Boundary to align class properties on.
enum { PROPERTY_ALIGNMENT = 4 };

/*-----------------------------------------------------------------------------
	FRepRecord
-----------------------------------------------------------------------------*/

//
//Information about a property to replicate.
//
struct FRepRecord{
	UProperty* Property;
	INT Index;
	FRepRecord(UProperty* InProperty,INT InIndex) : Property(InProperty),
													Index(InIndex){}
};

/*-----------------------------------------------------------------------------
	FDependency
-----------------------------------------------------------------------------*/

//
//One dependency record, for incremental compilation.
//
class CORE_API FDependency{
public:
	//Variables.
	UClass*		Class;
	UBOOL		Deep;
	DWORD		ScriptTextCRC;

	//Functions.
	FDependency();
	FDependency(UClass* InClass, UBOOL InDeep);
	UBOOL IsUpToDate();
	CORE_API friend FArchive& operator<<(FArchive& Ar, FDependency& Dep);
};

/*-----------------------------------------------------------------------------
	FRepLink
-----------------------------------------------------------------------------*/

//
//A tagged linked list of replicatable variables.
//
class FRepLink{
public:
	UProperty*	Property;		//Replicated property.
	FRepLink*	Next;			//Next replicated link per class.
	FRepLink(UProperty* InProperty, FRepLink* InNext)
	:	Property	(InProperty)
	,	Next		(InNext)
	{}
};

/*-----------------------------------------------------------------------------
	FLabelEntry
-----------------------------------------------------------------------------*/

//
//Entry in a state's label table.
//
struct CORE_API FLabelEntry{
	//Variables.
	FName	Name;
	INT		iCode;

	//Functions.
	FLabelEntry(FName InName, INT iInCode);
	CORE_API friend FArchive& operator<<(FArchive& Ar, FLabelEntry &Label);
};

/*-----------------------------------------------------------------------------
	UField
-----------------------------------------------------------------------------*/

//
//Base class of UnrealScript language objects.
//
class CORE_API UField : public UObject{
	DECLARE_ABSTRACT_CLASS(UField,UObject,0,Core)
	NO_DEFAULT_CONSTRUCTOR(UField)

	//Constants.
	enum {HASH_COUNT = 256};

	//Variables.
	UField*			SuperField;

	//Constructors.
	UField(ENativeConstructor, UClass* InClass, const TCHAR* InName, const TCHAR* InPackageName, DWORD InFlags);
	UField(EStaticConstructor, const TCHAR* InName, const TCHAR* InPackageName, DWORD InFlags);

	//UObject interface.
	void Serialize(FArchive& Ar);
	void PostLoad();
	void Register();

	//UField interface.
	virtual void AddCppProperty(UProperty* Property);
	virtual UBOOL MergeBools();
	virtual void Bind();
	virtual UClass* GetOwnerClass();
	virtual INT GetPropertiesSize();
};

/*-----------------------------------------------------------------------------
	TFieldIterator
-----------------------------------------------------------------------------*/

//
//For iterating through a linked list of fields.
//
template <class T> class TFieldIterator{
public:
	TFieldIterator(UStruct* InStruct)
	: Struct(InStruct)
	, Field(InStruct ? InStruct->Children : NULL){
		IterateToNext();
	}

	operator UBOOL(){
		return Field != NULL;
	}

	void operator++(){
		checkSlow(Field);
		Field = Field->Next;
		IterateToNext();
	}

	T* operator*(){
		checkSlow(Field);
		return (T*)Field;
	}

	T* operator->(){
		checkSlow(Field);
		return (T*)Field;
	}

	UStruct* GetStruct(){
		return Struct;
	}
protected:
	void IterateToNext(){
		while(Struct){
			while(Field){
				if(Field->IsA(T::StaticClass()))
					return;
				Field = Field->Next;
			}

			Struct = Struct->GetInheritanceSuper();

			if(Struct)
				Field = Struct->Children;
		}
	}

	UStruct* Struct;
	UField* Field;
};

/*-----------------------------------------------------------------------------
	UStruct
-----------------------------------------------------------------------------*/

//
//An UnrealScript structure definition.
//
class CORE_API UStruct : public UField{
	DECLARE_CLASS(UStruct,UField,0,Core)
	NO_DEFAULT_CONSTRUCTOR(UStruct)
	
	//Variables.
	UTextBuffer*		ScriptText;
	UField*				Children;
	char				Pad1[8]; //Padding
	TArray<BYTE>		Defaults;
	INT					PropertiesSize;
	INT					PropertiesAlign;
	FName				FriendlyName;
	TArray<BYTE>		Script;
	INT					TextPos;
	INT					Line;
	char				Pad2[4]; //Padding
	//In memory only.
	UObjectProperty*	RefLink;
	UStructProperty*	StructLink;
	UProperty*			PropertyLink;
	UProperty*			ConfigLink;
	UProperty*			ConstructorLink;

	//Constructors.
	UStruct(ENativeConstructor, INT InSize, const TCHAR* InName, const TCHAR* InPackageName, DWORD InFlags, UStruct* InSuperStruct);
	UStruct(EStaticConstructor, INT InSize, const TCHAR* InName, const TCHAR* InPackageName, DWORD InFlags);
	UStruct(UStruct* InSuperStruct);

	//UObject interface.
	void Serialize(FArchive& Ar);
	void PostLoad();
	void Destroy();
	void Register();

	//UField interface.
	void AddCppProperty(UProperty* Property);
	INT GetPropertiesSize();

	//UStruct interface.
	virtual UStruct* GetInheritanceSuper();
	virtual void Link(FArchive& Ar, UBOOL Props);
	virtual void SerializeBin(FArchive& Ar, BYTE* Data, int);
	virtual void SerializeTaggedProperties(FArchive& Ar, BYTE* Data, UClass* DefaultsClass, int);
	virtual void CleanupDestroyed(BYTE* Data);
	virtual EExprToken SerializeExpr(INT& iCode, FArchive& Ar);
	virtual TCHAR* GetNameCPP() const;

	FString FunctionMD5();
	int GetPropertiesAlign();
	void SetPropertiesSize(INT NewSize);
	bool IsChildOf(const UStruct* SomeBase) const;
	UStruct* GetSuperStruct() const;
	bool StructCompare(const void* A, const void* B);
};

/*-----------------------------------------------------------------------------
	UFunction
-----------------------------------------------------------------------------*/

//
//An UnrealScript function.
//
class CORE_API UFunction : public UStruct{
	DECLARE_CLASS(UFunction,UStruct,0,Core)
	DECLARE_WITHIN(UState)
	NO_DEFAULT_CONSTRUCTOR(UFunction)

	//Persistent variables.
	DWORD FunctionFlags;
	_WORD iNative;
	_WORD RepOffset;
	BYTE  OperPrecedence;

	//Variables in memory only.
	BYTE  NumParms;
	_WORD ParmsSize;
	_WORD ReturnValueOffset;
	void (UObject::*Func)(FFrame& TheStack, RESULT_DECL);

	//Constructors.
	UFunction(UFunction* InSuperFunction);

	//UObject interface.
	void Serialize(FArchive& Ar);
	void PostLoad();

	//UField interface.
	void Bind();

	//UStruct interface.
	UBOOL MergeBools(){ return 0; }
	UStruct* GetInheritanceSuper(){ return NULL; }
	void Link(FArchive& Ar, UBOOL Props);

	//UFunction interface.
	UFunction* GetSuperFunction() const;
	UProperty* GetReturnProperty();
};

/*-----------------------------------------------------------------------------
	UState
-----------------------------------------------------------------------------*/

//
//An UnrealScript state.
//
class CORE_API UState : public UStruct{
	DECLARE_CLASS(UState,UStruct,0,Core)
	NO_DEFAULT_CONSTRUCTOR(UState)

	//Variables.
	QWORD ProbeMask;
	QWORD IgnoreMask;
	DWORD StateFlags;
	_WORD LabelTableOffset;
	UField* VfHash;

	//Constructors.
	UState(ENativeConstructor, INT InSize, const TCHAR* InName, const TCHAR* InPackageName, DWORD InFlags, UState* InSuperState);
	UState(EStaticConstructor, INT InSize, const TCHAR* InName, const TCHAR* InPackageName, DWORD InFlags);
	UState(UState* InSuperState);

	//UObject interface.
	void Serialize(FArchive& Ar);
	void Destroy();

	//UStruct interface.
	UBOOL MergeBools() {return 1;}
	UStruct* GetInheritanceSuper() {return GetSuperState();}
	void Link(FArchive& Ar, UBOOL Props);

	//UState interface.
	UState* GetSuperState() const;
};

/*-----------------------------------------------------------------------------
	UEnum
-----------------------------------------------------------------------------*/

//
//An enumeration, a list of names usable by UnrealScript.
//
class CORE_API UEnum : public UField{
	DECLARE_CLASS(UEnum,UField,0,Core)
	DECLARE_WITHIN(UStruct)
	NO_DEFAULT_CONSTRUCTOR(UEnum)

	//Variables.
	TArray<FName> Names;

	//Constructors.
	UEnum(UEnum* InSuperEnum);

	//UObject interface.
	void Serialize(FArchive& Ar);

	//UEnum interface.
	UEnum* GetSuperEnum() const;
};

/*-----------------------------------------------------------------------------
	UClass
-----------------------------------------------------------------------------*/

//
//An object class.
//
class CORE_API UClass : public UState{
	DECLARE_CLASS(UClass,UState,0,Core)
	DECLARE_WITHIN(UPackage)

	char Padding[128];

	/*//Variables.
	DWORD				ClassFlags;
	INT					ClassUnique;
	FGuid				ClassGuid;
	UClass*				ClassWithin;
	FName				ClassConfigName;
	TArray<FRepRecord>	ClassReps;
	TArray<UField*>		NetFields;
	TArray<FDependency> Dependencies;
	TArray<FName>		PackageImports;
	TArray<BYTE>		Defaults;
	void(*ClassConstructor)(void*);
	void(UObject::*ClassStaticConstructor)();

	//In memory only.
	FString				DefaultPropText;*/

	//Constructors.
	UClass();
	UClass(UClass* InSuperClass);
	UClass(ENativeConstructor, DWORD InSize, DWORD InClassFlags, UClass* InBaseClass, UClass* InWithinClass, FGuid InGuid, const TCHAR* InNameStr, const TCHAR* InPackageName, const TCHAR* InClassConfigName, DWORD InFlags, void(*InClassConstructor)(void*), void(UObject::*InClassStaticConstructor)());
	UClass(EStaticConstructor, DWORD InSize, DWORD InClassFlags, FGuid InGuid, const TCHAR* InNameStr, const TCHAR* InPackageName, const TCHAR* InClassConfigName, DWORD InFlags, void(*InClassConstructor)(void*), void(UObject::*InClassStaticConstructor)());

	//UObject interface.
	void Serialize(FArchive& Ar);
	void PostLoad();
	void Destroy();
	void Register();
	bool IsDefaultValue(const struct FPropertyInstance&);

	//UField interface.
	void Bind();

	//UStruct interface.
	UBOOL MergeBools();
	UStruct* GetInheritanceSuper();
	TCHAR* GetNameCPP() const;
	void Link(FArchive& Ar, UBOOL Props);

	//UClass interface.
	void AddDependency(UClass* InClass, UBOOL InDeep);
	UClass* GetSuperClass() const;
	UObject* GetDefaultObject() const;
	class AActor* GetDefaultActor() const;

private:
	//Hide IsA because calling IsA on a class almost always indicates
	//an error where the caller should use IsChildOf.
	UBOOL IsA(UClass* Parent) const {return UObject::IsA(Parent);}
};

/*-----------------------------------------------------------------------------
	UConst
-----------------------------------------------------------------------------*/

//
//An UnrealScript constant.
//
class CORE_API UConst : public UField{
	DECLARE_CLASS(UConst,UField,0,Core)
	DECLARE_WITHIN(UStruct)
	NO_DEFAULT_CONSTRUCTOR(UConst)

	//Variables.
	FString Value;

	//Constructors.
	UConst(UConst* InSuperConst, const TCHAR* InValue);

	//UObject interface.
	void Serialize(FArchive& Ar);

	//UConst interface.
	UConst* GetSuperConst() const;
};

/*-----------------------------------------------------------------------------
	The End.
-----------------------------------------------------------------------------*/