/*===========================================================================
	C++ class definitions exported from UnrealScript.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/

#ifndef EDITOR_NATIVE_DEFS
#define EDITOR_NATIVE_DEFS

#include "../../Engine/Inc/Engine.h"

LINK_LIB(Editor)

#if SUPPORTS_PRAGMA_PACK
#pragma pack (push,4)
#endif

#ifndef EDITOR_API
#define EDITOR_API DLL_IMPORT
#endif

/*
*	AnimNotifyProps
*/

class EDITOR_API UAnimNotifyProps : public UObject{
public:
	class UAnimNotify* Notify;
	
	DECLARE_CLASS(UAnimNotifyProps,UObject,0,Editor)
	NO_DEFAULT_CONSTRUCTOR(UAnimNotifyProps)
};

/*
*	BrushBuilder
*/

struct FBuilderPoly{
	TArray<INT> VertexIndices;
	INT Direction;
	FName ItemName;
	INT PolyFlags;

	FBuilderPoly()
	: VertexIndices(), Direction(0), ItemName(NAME_None)
	{}
};

class EDITOR_API UBrushBuilder : public UObject{
public:
	FStringNoInit BitmapFilename;
	FStringNoInit ToolTip;
	TArrayNoInit<FVector> Vertices;
	TArrayNoInit<FBuilderPoly> Polys;
	FName Group;
	BITFIELD MergeCoplanars:1;
	UBOOL Build();
	DECLARE_CLASS(UBrushBuilder,UObject,0,Editor)
	NO_DEFAULT_CONSTRUCTOR(UBrushBuilder)
};

/*
*	AnalyzeContentCommandlets
*/

class EDITOR_API UAnalyzeContentCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UAnalyzeContentCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UAnalyzeContentCommandlet)
};

/*
*	BatchExportCommandlet
*/

class EDITOR_API UBatchExportCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UBatchExportCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UBatchExportCommandlet)
};

/*
*	ChecksumPackageCommandlet
*/

class EDITOR_API UChecksumPackageCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UChecksumPackageCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UChecksumPackageCommandlet)
};

/*
*	CheckUnicodeCommandlet
*/

class EDITOR_API UCheckUnicodeCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UCheckUnicodeCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UCheckUnicodeCommandlet)
};

/*
*	CompareIntCommandlet
*/

class EDITOR_API UCompareIntCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UCompareIntCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UCompareIntCommandlet)
};

/*
*	CompressToDXTCommandlet
*/

class EDITOR_API UCompressToDXTCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UCompressToDXTCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UCompressToDXTCommandlet)
};

/*
*	ConformCommandlet
*/

class EDITOR_API UConformCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UConformCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UConformCommandlet)
};

/*
*	ComvertMaterialCommandlet
*/

class EDITOR_API UConvertMaterialCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UConvertMaterialCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UConvertMaterialCommandlet)
};

/*
*	CutdownContentCommandlet
*/

class EDITOR_API UCutdownContentCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UCutdownContentCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UCutdownContentCommandlet)
};

/*
*	DataRipCommandlet
*/

class EDITOR_API UDataRipCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UDataRipCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UDataRipCommandlet)
};

/*
*	AnimNotifyProps
*/

class EDITOR_API UDumpIntCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UDumpIntCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UDumpIntCommandlet)
};

/*
*	DumpSoundParamsCommandlet
*/

class EDITOR_API UDumpSoundParamsCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UDumpSoundParamsCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UDumpSoundParamsCommandlet)
};

/*
*	DumpSoundPropLogCommandlet
*/

class EDITOR_API UDumpSoundPropLogCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UDumpSoundPropLogCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UDumpSoundPropLogCommandlet)
};

/*
*	DXTConvertCommandlet
*/

class EDITOR_API UDXTConvertCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UDXTConvertCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UDXTConvertCommandlet)
};

/*
*	ExecCommandlet
*/

class EDITOR_API UExecCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UExecCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UExecCommandlet)
};

/*
*	FontUpdateCommandlet
*/

class EDITOR_API UFontUpdateCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UFontUpdateCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UFontUpdateCommandlet)
};

/*
*	ImportAseCommandlet
*/

class EDITOR_API UImportAseCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UImportAseCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UImportAseCommandlet)
};

/*
*	ImportTextureCommandlet
*/

class EDITOR_API UImportTextureCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UImportTextureCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UImportTextureCommandlet)
};

/*
*	ListPackageContentsCommandlet
*/

class EDITOR_API UListPackageContentsCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UListPackageContentsCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UListPackageContentsCommandlet)
};

/*
*	MakeCommandlet
*/

class EDITOR_API UMakeCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UMakeCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UMakeCommandlet)
};

/*
*	MapConvertCommandlet
*/

class EDITOR_API UMapConvertCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UMapConvertCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UMapConvertCommandlet)
};

/*
*	MasterCommandlet
*/

class EDITOR_API UMasterCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UMasterCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UMasterCommandlet)
};

/*
*	MergeIntCommandlet
*/

class EDITOR_API UMergeIntCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UMergeIntCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UMergeIntCommandlet)
};

/*
*	ModifyPackageFlagsCommandlet
*/

class EDITOR_API UModifyPackageFlagsCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UModifyPackageFlagsCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UModifyPackageFlagsCommandlet)
};

/*
*	PackageFlagCommandlet
*/

class EDITOR_API UPackageFlagCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UPackageFlagCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UPackageFlagCommandlet)
};

/*
*	PkgCommandlet
*/

class EDITOR_API UPkgCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UPkgCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UPkgCommandlet)
};

/*
*	RearrangeIntCommandlet
*/

class EDITOR_API URearrangeIntCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(URearrangeIntCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(URearrangeIntCommandlet)
};

/*
*	ResavePackageCommandlet
*/

class EDITOR_API UResavePackageCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UResavePackageCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UResavePackageCommandlet)
};

/*
*	StripSourceCommandlet
*/

class EDITOR_API UStripSourceCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UStripSourceCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UStripSourceCommandlet)
};

/*
*	TestMathCommandlet
*/

class EDITOR_API UTestMathCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UTestMathCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UTestMathCommandlet)
};

/*
*	UpdateUModCommandlet
*/

class EDITOR_API UUpdateUModCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UUpdateUModCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UUpdateUModCommandlet)
};

/*
*	XACTExportCommandlet
*/

class EDITOR_API UXACTExportCommandlet : public UCommandlet{
public:
	DECLARE_CLASS(UXACTExportCommandlet,UCommandlet,CLASS_Transient,Editor)
	NO_DEFAULT_CONSTRUCTOR(UXACTExportCommandlet)
};

/*
*	EditInfo
*/

class EDITOR_API UEditInfo : public UObject{
public:
	DECLARE_CLASS(UEditInfo,UObject,0,Editor)
	NO_DEFAULT_CONSTRUCTOR(UEditInfo)
};

/*
*	MaterialFactory
*/

#define UCONST_RF_Standalone 0x00080000

class EDITOR_API UMaterialFactory : public UObject{
public:
	FStringNoInit Description;
	class UMaterial* CreateMaterial(class UObject* InOuter, FString const& InPackage, FString const& InGroup, FString const& InName);
	
	DECLARE_CLASS(UMaterialFactory,UObject,0,Editor)
	NO_DEFAULT_CONSTRUCTOR(UMaterialFactory)
};

/*
*	Prefab
*/

class EDITOR_API UPrefab : public UObject{
public:
	DECLARE_CLASS(UPrefab,UObject,0,Editor)
	NO_DEFAULT_CONSTRUCTOR(UPrefab)
};

/*
*	Transactor
*/

class EDITOR_API UTransactor : public UObject{
public:
	DECLARE_CLASS(UTransactor,UObject,0,Editor)
	NO_DEFAULT_CONSTRUCTOR(UTransactor)
};

/*
*	TransBuffer
*/

class EDITOR_API UTransBuffer : public UObject{
public:
	DECLARE_CLASS(UTransBuffer,UObject,0,Editor)
	NO_DEFAULT_CONSTRUCTOR(UTransBuffer)
};

/*
*	EditorEngine
*/

class EDITOR_API UEditorEngine : public UEngine{
public:
	class ULevel* Level;
	class UModel* TempModel;
	class UTexture* CurrentTexture;
	class UStaticMesh* CurrentStaticMesh;
	class UMesh* CurrentMesh;
	class UClass* CurrentClass;
	class UClass* LastClass;
	class UTransBuffer* Trans;
	class UTextBuffer* Results;
	INT Pad[8];
	class UTexture* Bad;
	class UTexture* Bkgnd;
	class UTexture* BkgndHi;
	class UTexture* BadHighlight;
	class UTexture* MaterialArrow;
	class UTexture* MaterialBackdrop;
	class UStaticMesh* TexPropCube;
	class UStaticMesh* TexPropSphere;
	BITFIELD bFastRebuild:1;
	BITFIELD bBootstrapping:1;
	INT AutoSaveIndex;
	INT AutoSaveCount;
	INT Mode;
	INT TerrainEditBrush;
	INT ClickFlags;
	BITFIELD MightNeedSave:1;
	FLOAT MovementSpeed;
	class UPackage* PackageContext;
	FVector AddLocation;
	FPlane AddPlane;
	TArrayNoInit<class UObject*> Tools;
	class UClass* BrowseClass;
	INT ConstraintsVtbl;
	BITFIELD GridEnabled:1;
	BITFIELD SnapVertices:1;
	FLOAT SnapDistance;
	FVector GridSize;
	BITFIELD RotGridEnabled:1;
	FRotator RotGridSize;
	BITFIELD UseSizingBox:1;
	BITFIELD UseAxisIndicator:1;
	FLOAT FovAngleDegrees;
	BITFIELD GodMode:1;
	BITFIELD AutoSave:1;
	BYTE AutosaveTimeMinutes;
	FStringNoInit GameCommandLine;
	TArrayNoInit<FString> EditPackages;
	TArrayNoInit<FString> NativePackages;
	BITFIELD AlwaysShowTerrain:1;
	BITFIELD UseOldInterface:1;
	BITFIELD DontUseArcball:1;
	BITFIELD HideOrthoAxes:1;
	BITFIELD MayaStyleMovement:1;
	
	DECLARE_CLASS(UEditorEngine,UEngine,CLASS_Transient|CLASS_Config,Editor)

	//Overrides
	virtual void Click(class UViewport*, unsigned long, float, float);
	virtual void Destroy();
	virtual void Draw(class UViewport*, int, unsigned char*, int*);
	virtual int Exec(const char*, FOutputDevice&);
	virtual void Init();
	virtual void MouseDelta(class UViewport*, unsigned long, float, float);
	virtual void MousePosition(class UViewport*, unsigned long, float, float);
	virtual void MouseWheel(class UViewport*, unsigned long, int);
	virtual void Serialize(class FArchive&);
	virtual void SetClientTravel(class UPlayer*, const char*, int, enum ETravelType);
	virtual void Tick(float);

	//Virtual Functions
	virtual int SafeExec(const char*, FOutputDevice&);
	virtual class FVector GetPivotLocation();
	virtual void SetPivot(class FVector const&, class FRotator, int, int, int);
	virtual void SetPivot(class FVector const&, int, int, int);
	virtual void ResetPivot();
	virtual void Cleanse(int, const char*);
	virtual void FinishAllSnaps(class ULevel*);
	virtual void RedrawLevel(class ULevel*);
	virtual void StopSound();
	virtual void ResetSound();
	virtual void NoteSelectionChange(class ULevel*);
	virtual class AActor* AddActor(class ULevel*, class UClass*, class FVector const&, int);
	virtual void NoteActorMovement(class ULevel*);
	virtual class UTransactor* CreateTrans();
	virtual void csgPrepMovingBrush(class ABrush*);
	virtual void csgCopyBrush(class ABrush*, class ABrush*, unsigned long, unsigned long, int);
	virtual class ABrush* csgAddOperation(class ABrush*, class ULevel*, unsigned long, enum ECsgOper);
	virtual void csgRebuild(class ULevel*);
	virtual const char* csgGetName(enum ECsgOper);
	virtual int polyFindMaster(class UModel*, int, class FPoly&);
	virtual void polyUpdateMaster(class UModel*, int, int);
	virtual void polyGetLinkedPolys(class ABrush*, class FPoly*, TArray<class FPoly>*);
	virtual void polyGetOuterEdgeList(TArray<class FPoly>*, TArray<class FEdge>*);
	virtual void polySplitOverlappingEdges(TArray<class FPoly>*, TArray<class FPoly>*);
	virtual void polySetAndClearPolyFlags(class UModel*, unsigned long, unsigned long, int, int);
	virtual void SelectActor(class ULevel*, class AActor*, int, int);
	virtual void SelectNone(class ULevel*, int, int);
	virtual void SelectBSPSurf(class ULevel*, int, int, int);
	virtual void polySelectAll(class UModel*);
	virtual void polySelectMatchingGroups(class UModel*);
	virtual void polySelectMatchingItems(class UModel*);
	virtual void polySelectCoplanars(class UModel*);
	virtual void polySelectAdjacents(class UModel*);
	virtual void polySelectAdjacentWalls(class UModel*);
	virtual void polySelectAdjacentFloors(class UModel*);
	virtual void polySelectAdjacentSlants(class UModel*);
	virtual void polySelectMatchingBrush(class UModel*);
	virtual void polySelectMatchingTexture(class UModel*);
	virtual void polySelectReverse(class UModel*);
	virtual void polyMemorizeSet(class UModel*);
	virtual void polyRememberSet(class UModel*);
	virtual void polyXorSet(class UModel*);
	virtual void polyUnionSet(class UModel*);
	virtual void polyIntersectSet(class UModel*);
	virtual void polySelectZone(class UModel*);
	virtual void polyTexPan(class UModel*, int, int, int);
	virtual void polyTexScale(class UModel*, float, float, float, float, int);
	virtual void mapSelectOperation(class ULevel*, enum ECsgOper);
	virtual void mapSelectFlags(class ULevel*, unsigned long);
	virtual void mapSelectFirst(class ULevel*);
	virtual void mapSelectLast(class ULevel*);
	virtual void mapBrushGet(class ULevel*);
	virtual void mapBrushPut(class ULevel*);
	virtual void mapSendToFirst(class ULevel*);
	virtual void mapSendToLast(class ULevel*);
	virtual void mapSendToSwap(class ULevel*);
	virtual void mapSetBrush(class ULevel*, enum EMapSetBrushFlags, unsigned short, class FName, unsigned long, unsigned long, unsigned long, int);
	virtual void bspRepartition(class ULevel*, int, int);
	virtual int bspAddVector(class UModel*, class FVector*, int);
	virtual int bspAddPoint(class UModel*, class FVector*, int);
	virtual int bspNodeToFPoly(class UModel*, int, class FPoly*);
	virtual void bspBuild(class UModel*, enum EBspOptimization, int, int, int, int);
	virtual void bspRefresh(class UModel*, int);
	virtual void bspCleanup(class UModel*);
	virtual void bspBuildBounds(class UModel*);
	virtual void bspBuildFPolys(class UModel*, int, int);
	virtual void bspMergeCoplanars(class UModel*, int, int);
	virtual int bspBrushCSG(class ABrush*, class UModel*, unsigned long, enum ECsgOper, int, int);
	virtual void bspOptGeom(class UModel*);
	virtual void bspValidateBrush(class UModel*, int, int);
	virtual void bspUnlinkPolys(class UModel*);
	virtual int bspAddNode(class UModel*, int, enum ENodePlace, unsigned long, class FPoly*);
	virtual int bspSanityTest(class UModel*, int&) const;
	virtual void shadowIlluminateBsp(class ULevel*, int, int);
	virtual void meshVertImport(const char*, class UObject*, const char*, const char*, int, int, int, struct FLODProcessInfo*);
	virtual void meshSkelImport(const char*, class UObject*, const char*, int, int, int, struct FLODProcessInfo*);
	virtual void meshVertLODProcess(class UVertMesh*, TArray<struct FMeshTri>&, struct FLODProcessInfo*);
	virtual void meshSkelLODProcess(class USkeletalMesh*, struct FLODProcessInfo*, struct USkelImport*);
	virtual void meshDropFrames(class UVertMesh*, int, int);
	virtual int animGetBoneIndex(class UMeshAnimation*, class FName);
	virtual class UMeshAnimation* animationImport(const char*, const char*, class FString const&, TArray<class FString> const&, bool, float, bool);
	virtual void UnClick(class UViewport*, unsigned long, int, int);
	virtual void sequenceCompress(class UMeshAnimation*, class FSkelAnimSeq*);
	virtual void TestVisibility(class ULevel*, class UModel*, int, int);
	virtual int MakeScripts(class UPackage*, class FFeedbackContext*, int, int);
	virtual int CheckScripts(class FFeedbackContext*, int, class UPackage*);
	virtual int CheckScripts(class FFeedbackContext*, class UClass*, FOutputDevice&);
	virtual void Get(const char*, const char*, FOutputDevice&);
	virtual void Set(const char*, const char*, const char*);
protected:
	virtual int bspTestForNoCyclesHelper(class UModel&, int, TArray<int>*, int, int&) const;
	virtual int bspTestForNoNeighborCyclesHelper() const;

public:
	//Functions
	void ExecMacro(const char*, FOutputDevice&);
	int Exec_Anim(const char*, FOutputDevice&);
	int Exec_Audio(const char*, FOutputDevice&);
	int Exec_BSP(const char*, FOutputDevice&);
	int Exec_Brush(const char*, FOutputDevice&);
	int Exec_BrushClip(const char*, FOutputDevice&);
	int Exec_Camera(const char*, FOutputDevice&);
	int Exec_Class(const char*, FOutputDevice&);
	int Exec_Fluid(const char*, FOutputDevice&);
	int Exec_Level(const char*, FOutputDevice&);
	int Exec_Light(const char*, FOutputDevice&);
	int Exec_Map(const char*, FOutputDevice&);
	int Exec_Obj(const char*, FOutputDevice&);
	int Exec_Paths(const char*, FOutputDevice&);
	int Exec_Poly(const char*, FOutputDevice&);
	int Exec_Select(const char*, FOutputDevice&);
	int Exec_Shader(const char*, FOutputDevice&);
	int Exec_StaticMesh(const char*, FOutputDevice&);
	int Exec_Terrain(const char*, FOutputDevice&);
	int Exec_Texture(const char*, FOutputDevice&);
	int Exec_Transaction(const char*, FOutputDevice&);
	class UViewport* GetCurrentViewport();
	class FString GetDefaultScriptText(class FString const&, class FString const&, unsigned long);
	void InitEditor();
	void RedrawAllViewports(int);
	void RedrawCurrentViewport();
	void brushclipDeleteMarkers();
	void polygonDeleteMarkers();
};

#if SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#endif // EDITOR_NATIVE_DEFS