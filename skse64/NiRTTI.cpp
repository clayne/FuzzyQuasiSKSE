#include "skse64/NiRTTI.h"
#include "skse64/NiObjects.h"

NiObject * DoNiRTTICast(NiObject * src, const NiRTTI * typeInfo)
{
	uintptr_t typeAddr = uintptr_t(typeInfo) + RelocationManager::s_baseAddr;
	if (src)
		for (NiRTTI * iter = src->GetRTTI(); iter; iter = iter->parent)
			if (iter == (NiRTTI *)typeAddr)
				return src;

	return nullptr;
}

bool IsType(NiRTTI * rtti, const NiRTTI * typeInfo)
{
	uintptr_t typeAddr = uintptr_t(typeInfo) + RelocationManager::s_baseAddr;
	if (rtti)
		return uintptr_t(rtti) == typeAddr;

	return false;
}

const NiRTTI *	NiRTTI_BGSDecalNode = (NiRTTI *)0x01EEB338;
const NiRTTI *	NiRTTI_BSAnimGroupSequence = (NiRTTI *)0x01EEB4B0;
const NiRTTI *	NiRTTI_BSSplatterExtraData = (NiRTTI *)0x02EEC500;
const NiRTTI *	NiRTTI_BGSAddonNodeSoundHandleExtra = (NiRTTI *)0x02EEC968;
const NiRTTI *	NiRTTI_REFRSyncController = (NiRTTI *)0x02F269C0;
const NiRTTI *	NiRTTI_bhkCartTether = (NiRTTI *)0x02F28118;
const NiRTTI *	NiRTTI_bhkTiltPreventAction = (NiRTTI *)0x02F28128;
const NiRTTI *	NiRTTI_bhkWheelAction = (NiRTTI *)0x02F28138;
const NiRTTI *	NiRTTI_BSFaceGenAnimationData = (NiRTTI *)0x02F28780;
const NiRTTI *	NiRTTI_BSFaceGenModelExtraData = (NiRTTI *)0x02F2ECA0;
const NiRTTI *	NiRTTI_BSFaceGenBaseMorphExtraData = (NiRTTI *)0x02F2ECC8;
const NiRTTI *	NiRTTI_BSFaceGenMorphData = (NiRTTI *)0x02F2ECD8;
const NiRTTI *	NiRTTI_BSFaceGenMorphDataHead = (NiRTTI *)0x02F2ECE8;
const NiRTTI *	NiRTTI_BSFaceGenMorphDataHair = (NiRTTI *)0x02F2ECF8;
const NiRTTI *	NiRTTI_BSFaceGenNiNode = (NiRTTI *)0x02F2ED38;
const NiRTTI *	NiRTTI_BSTempEffect = (NiRTTI *)0x02F34428;
const NiRTTI *	NiRTTI_BSTempEffectDebris = (NiRTTI *)0x02F344A8;
const NiRTTI *	NiRTTI_BSTempEffectGeometryDecal = (NiRTTI *)0x02F344C8;
const NiRTTI *	NiRTTI_BSTempEffectParticle = (NiRTTI *)0x02F34578;
const NiRTTI *	NiRTTI_BSTempEffectSimpleDecal = (NiRTTI *)0x02F345A0;
const NiRTTI *	NiRTTI_BSTempEffectSPG = (NiRTTI *)0x02F345B8;
const NiRTTI *	NiRTTI_bhkAutoWater = (NiRTTI *)0x02F4B9A0;
const NiRTTI *	NiRTTI_ModelReferenceEffect = (NiRTTI *)0x02F4D1D8;
const NiRTTI *	NiRTTI_ReferenceEffect = (NiRTTI *)0x02F4D210;
const NiRTTI *	NiRTTI_ShaderReferenceEffect = (NiRTTI *)0x02F4D240;
const NiRTTI *	NiRTTI_SummonPlacementEffect = (NiRTTI *)0x02F4D270;
const NiRTTI *	NiRTTI_SceneGraph = (NiRTTI *)0x02F5F950;
const NiRTTI *	NiRTTI_BSDoorHavokController = (NiRTTI *)0x02F61680;
const NiRTTI *	NiRTTI_BSPlayerDistanceCheckController = (NiRTTI *)0x02F61690;
const NiRTTI *	NiRTTI_BSSimpleScaleController = (NiRTTI *)0x02F616A0;
const NiRTTI *	NiRTTI_NiObject = (NiRTTI *)0x03039388;
const NiRTTI *	NiRTTI_NiAVObject = (NiRTTI *)0x030393C0;
const NiRTTI *	NiRTTI_NiNode = (NiRTTI *)0x030393E0;
const NiRTTI *	NiRTTI_NiObjectNET = (NiRTTI *)0x03039508;
const NiRTTI *	NiRTTI_NiLight = (NiRTTI *)0x03039568;
const NiRTTI *	NiRTTI_NiSwitchNode = (NiRTTI *)0x03039578;
const NiRTTI *	NiRTTI_NiStringsExtraData = (NiRTTI *)0x03039588;
const NiRTTI *	NiRTTI_NiCamera = (NiRTTI *)0x03039598;
const NiRTTI *	NiRTTI_BSTriShape = (NiRTTI *)0x030395B0;
const NiRTTI *	NiRTTI_NiProperty = (NiRTTI *)0x030395C0;
const NiRTTI *	NiRTTI_NiAlphaProperty = (NiRTTI *)0x030395D8;
const NiRTTI *	NiRTTI_NiSourceTexture = (NiRTTI *)0x0303A608;
const NiRTTI *	NiRTTI_BSFlattenedBoneTree = (NiRTTI *)0x0303A618;
const NiRTTI *	NiRTTI_BSDismemberSkinInstance = (NiRTTI *)0x0303A660;
const NiRTTI *	NiRTTI_NiStringExtraData = (NiRTTI *)0x0303A670;
const NiRTTI *	NiRTTI_NiTimeController = (NiRTTI *)0x0303A680;
const NiRTTI *	NiRTTI_NiExtraData = (NiRTTI *)0x0303A6A0;
const NiRTTI *	NiRTTI_NiGeometryData = (NiRTTI *)0x0303A6B0;
const NiRTTI *	NiRTTI_BSGeometry = (NiRTTI *)0x0303A6C8;
const NiRTTI *	NiRTTI_BSDynamicTriShape = (NiRTTI *)0x0303A6E0;
const NiRTTI *	NiRTTI_NiPointLight = (NiRTTI *)0x0303A6F0;
const NiRTTI *	NiRTTI_NiDefaultAVObjectPalette = (NiRTTI *)0x0303A700;
const NiRTTI *	NiRTTI_NiBillboardNode = (NiRTTI *)0x0303A728;
const NiRTTI *	NiRTTI_NiDirectionalLight = (NiRTTI *)0x0303A738;
const NiRTTI *	NiRTTI_NiCullingProcess = (NiRTTI *)0x0303A748;
const NiRTTI *	NiRTTI_NiParticles = (NiRTTI *)0x0303A760;
const NiRTTI *	NiRTTI_NiTexture = (NiRTTI *)0x0303A7A0;
const NiRTTI *	NiRTTI_NiSkinPartition = (NiRTTI *)0x0303A8B0;
const NiRTTI *	NiRTTI_NiVertWeightsExtraData = (NiRTTI *)0x0303A8C0;
const NiRTTI *	NiRTTI_NiSkinInstance = (NiRTTI *)0x0303A8D0;
const NiRTTI *	NiRTTI_NiAVObjectPalette = (NiRTTI *)0x0303A8E0;
const NiRTTI *	NiRTTI_NiGeometry = (NiRTTI *)0x0303A8F0;
const NiRTTI *	NiRTTI_NiSkinData = (NiRTTI *)0x0303A920;
const NiRTTI *	NiRTTI_NiShadeProperty = (NiRTTI *)0x0303A930;
const NiRTTI *	NiRTTI_NiAlphaAccumulator = (NiRTTI *)0x0303A948;
const NiRTTI *	NiRTTI_NiAmbientLight = (NiRTTI *)0x0303A958;
const NiRTTI *	NiRTTI_NiBinaryExtraData = (NiRTTI *)0x0303A968;
const NiRTTI *	NiRTTI_NiBooleanExtraData = (NiRTTI *)0x0303A978;
const NiRTTI *	NiRTTI_NiBSPNode = (NiRTTI *)0x0303A988;
const NiRTTI *	NiRTTI_NiColorExtraData = (NiRTTI *)0x0303A998;
const NiRTTI *	NiRTTI_NiFloatExtraData = (NiRTTI *)0x0303A9A8;
const NiRTTI *	NiRTTI_NiFloatsExtraData = (NiRTTI *)0x0303A9B8;
const NiRTTI *	NiRTTI_NiFogProperty = (NiRTTI *)0x0303A9C8;
const NiRTTI *	NiRTTI_NiIntegerExtraData = (NiRTTI *)0x0303A9E0;
const NiRTTI *	NiRTTI_NiIntegersExtraData = (NiRTTI *)0x0303A9F0;
const NiRTTI *	NiRTTI_NiParticlesData = (NiRTTI *)0x0303AA38;
const NiRTTI *	NiRTTI_NiParticleMeshesData = (NiRTTI *)0x0303AA48;
const NiRTTI *	NiRTTI_NiParticleMeshes = (NiRTTI *)0x0303AA58;
const NiRTTI *	NiRTTI_NiSpotLight = (NiRTTI *)0x0303AA68;
const NiRTTI *	NiRTTI_NiSwitchStringExtraData = (NiRTTI *)0x0303AA78;
const NiRTTI *	NiRTTI_NiTriShapeData = (NiRTTI *)0x0303AA88;
const NiRTTI *	NiRTTI_NiTriShape = (NiRTTI *)0x0303AA98;
const NiRTTI *	NiRTTI_NiTriStripsData = (NiRTTI *)0x0303AAA8;
const NiRTTI *	NiRTTI_NiTriStrips = (NiRTTI *)0x0303AAB8;
const NiRTTI *	NiRTTI_NiVectorExtraData = (NiRTTI *)0x0303AAC8;
const NiRTTI *	NiRTTI_BSLODTriShape = (NiRTTI *)0x0303AAF0;
const NiRTTI *	NiRTTI_NiAdditionalGeometryData = (NiRTTI *)0x0303AB00;
const NiRTTI *	NiRTTI_BSSegmentedTriShape = (NiRTTI *)0x0303AB18;
const NiRTTI *	NiRTTI_NiAccumulator = (NiRTTI *)0x0303AB50;
const NiRTTI *	NiRTTI_NiBackToFrontAccumulator = (NiRTTI *)0x0303AB60;
const NiRTTI *	NiRTTI_NiTriBasedGeomData = (NiRTTI *)0x0303AB70;
const NiRTTI *	NiRTTI_NiTriBasedGeom = (NiRTTI *)0x0303AB80;
const NiRTTI *	NiRTTI_NiCollisionData = (NiRTTI *)0x0303ABC8;
const NiRTTI *	NiRTTI_NiControllerManager = (NiRTTI *)0x0303AC58;
const NiRTTI *	NiRTTI_NiControllerSequence = (NiRTTI *)0x0303AC78;
const NiRTTI *	NiRTTI_NiBlendInterpolator = (NiRTTI *)0x0303ACA8;
const NiRTTI *	NiRTTI_NiMultiTargetTransformController = (NiRTTI *)0x0303ACB8;
const NiRTTI *	NiRTTI_BSMultiTargetTreadTransfController = (NiRTTI *)0x0303ACC8;
const NiRTTI *	NiRTTI_NiInterpController = (NiRTTI *)0x0303ACD8;
const NiRTTI *	NiRTTI_NiFloatData = (NiRTTI *)0x0303BAA8;
const NiRTTI *	NiRTTI_NiFloatInterpolator = (NiRTTI *)0x0303BAB8;
const NiRTTI *	NiRTTI_NiColorData = (NiRTTI *)0x0303BAC8;
const NiRTTI *	NiRTTI_NiColorInterpolator = (NiRTTI *)0x0303BAD8;
const NiRTTI *	NiRTTI_NiSingleInterpController = (NiRTTI *)0x0303BAE8;
const NiRTTI *	NiRTTI_NiTransformInterpolator = (NiRTTI *)0x0303BAF8;
const NiRTTI *	NiRTTI_NiPathInterpolator = (NiRTTI *)0x0303BB08;
const NiRTTI *	NiRTTI_NiBlendTransformInterpolator = (NiRTTI *)0x0303BB28;
const NiRTTI *	NiRTTI_NiBlendFloatInterpolator = (NiRTTI *)0x0303BB38;
const NiRTTI *	NiRTTI_NiFloatExtraDataController = (NiRTTI *)0x0303BB48;
const NiRTTI *	NiRTTI_NiTransformController = (NiRTTI *)0x0303BB58;
const NiRTTI *	NiRTTI_NiBlendAccumTransformInterpolator = (NiRTTI *)0x0303BB70;
const NiRTTI *	NiRTTI_NiInterpolator = (NiRTTI *)0x0303BB80;
const NiRTTI *	NiRTTI_BSBlendTreadTransfInterpolator = (NiRTTI *)0x0303BBA0;
const NiRTTI *	NiRTTI_NiKeyBasedInterpolator = (NiRTTI *)0x0303BBB8;
const NiRTTI *	NiRTTI_NiTransformData = (NiRTTI *)0x0303BC38;
const NiRTTI *	NiRTTI_NiPosData = (NiRTTI *)0x0303BC48;
const NiRTTI *	NiRTTI_NiBlendBoolInterpolator = (NiRTTI *)0x0303BC58;
const NiRTTI *	NiRTTI_NiBlendColorInterpolator = (NiRTTI *)0x0303BC68;
const NiRTTI *	NiRTTI_NiBlendPoint3Interpolator = (NiRTTI *)0x0303BC78;
const NiRTTI *	NiRTTI_NiBlendQuaternionInterpolator = (NiRTTI *)0x0303BC88;
const NiRTTI *	NiRTTI_NiBoolData = (NiRTTI *)0x0303BC98;
const NiRTTI *	NiRTTI_NiBoolInterpolator = (NiRTTI *)0x0303BCA8;
const NiRTTI *	NiRTTI_NiBoolTimelineInterpolator = (NiRTTI *)0x0303BCB8;
const NiRTTI *	NiRTTI_NiBSplineBasisData = (NiRTTI *)0x0303BCC8;
const NiRTTI *	NiRTTI_NiBSplineData = (NiRTTI *)0x0303BCD8;
const NiRTTI *	NiRTTI_NiBSplineColorInterpolator = (NiRTTI *)0x0303BCE8;
const NiRTTI *	NiRTTI_NiBSplineCompColorInterpolator = (NiRTTI *)0x0303BCF8;
const NiRTTI *	NiRTTI_NiBSplineCompFloatInterpolator = (NiRTTI *)0x0303BD08;
const NiRTTI *	NiRTTI_NiBSplineCompPoint3Interpolator = (NiRTTI *)0x0303BD18;
const NiRTTI *	NiRTTI_NiBSplineCompTransformInterpolator = (NiRTTI *)0x0303BD28;
const NiRTTI *	NiRTTI_NiBSplineFloatInterpolator = (NiRTTI *)0x0303BD38;
const NiRTTI *	NiRTTI_NiBSplinePoint3Interpolator = (NiRTTI *)0x0303BD48;
const NiRTTI *	NiRTTI_NiBSplineTransformInterpolator = (NiRTTI *)0x0303BD58;
const NiRTTI *	NiRTTI_NiColorExtraDataController = (NiRTTI *)0x0303BD68;
const NiRTTI *	NiRTTI_NiFloatsExtraDataController = (NiRTTI *)0x0303BD78;
const NiRTTI *	NiRTTI_NiFloatsExtraDataPoint3Controller = (NiRTTI *)0x0303BD88;
const NiRTTI *	NiRTTI_NiKeyframeManager = (NiRTTI *)0x0303BDA0;
const NiRTTI *	NiRTTI_NiLightColorController = (NiRTTI *)0x0303BDB0;
const NiRTTI *	NiRTTI_NiLightDimmerController = (NiRTTI *)0x0303BDC0;
const NiRTTI *	NiRTTI_NiLookAtController = (NiRTTI *)0x0303BDD0;
const NiRTTI *	NiRTTI_NiLookAtInterpolator = (NiRTTI *)0x0303BDE0;
const NiRTTI *	NiRTTI_NiMorphData = (NiRTTI *)0x0303BDF0;
const NiRTTI *	NiRTTI_NiPathController = (NiRTTI *)0x0303BE00;
const NiRTTI *	NiRTTI_NiPoint3Interpolator = (NiRTTI *)0x0303BE10;
const NiRTTI *	NiRTTI_NiQuaternionInterpolator = (NiRTTI *)0x0303BE20;
const NiRTTI *	NiRTTI_NiRollController = (NiRTTI *)0x0303BE30;
const NiRTTI *	NiRTTI_NiRotData = (NiRTTI *)0x0303BE40;
const NiRTTI *	NiRTTI_NiSequence = (NiRTTI *)0x0303BE50;
const NiRTTI *	NiRTTI_NiSequenceStreamHelper = (NiRTTI *)0x0303BE70;
const NiRTTI *	NiRTTI_NiStringPalette = (NiRTTI *)0x0303BE80;
const NiRTTI *	NiRTTI_NiTextKeyExtraData = (NiRTTI *)0x0303BE90;
const NiRTTI *	NiRTTI_NiUVData = (NiRTTI *)0x0303BEA0;
const NiRTTI *	NiRTTI_NiVisController = (NiRTTI *)0x0303BEB0;
const NiRTTI *	NiRTTI_BSAnimNote = (NiRTTI *)0x0303BEC0;
const NiRTTI *	NiRTTI_BSAnimNotes = (NiRTTI *)0x0303BED0;
const NiRTTI *	NiRTTI_BSGrabIKNote = (NiRTTI *)0x0303BEE0;
const NiRTTI *	NiRTTI_BSLookIKNote = (NiRTTI *)0x0303BEF0;
const NiRTTI *	NiRTTI_BSRotAccumTransfInterpolator = (NiRTTI *)0x0303BF00;
const NiRTTI *	NiRTTI_BSTreadTransfInterpolator = (NiRTTI *)0x0303BF10;
const NiRTTI *	NiRTTI_BSFrustumFOVController = (NiRTTI *)0x0303BF20;
const NiRTTI *	NiRTTI_NiExtraDataController = (NiRTTI *)0x0303BFB8;
const NiRTTI *	NiRTTI_NiBSplineInterpolator = (NiRTTI *)0x0303BFC8;
const NiRTTI *	NiRTTI_NiPoint3InterpController = (NiRTTI *)0x0303BFD8;
const NiRTTI *	NiRTTI_NiFloatInterpController = (NiRTTI *)0x0303BFE8;
const NiRTTI *	NiRTTI_NiFloatController = (NiRTTI *)0x0303BFF8;
const NiRTTI *	NiRTTI_NiBoolInterpController = (NiRTTI *)0x0303C008;
const NiRTTI *	NiRTTI_NiParticleSystem = (NiRTTI *)0x0303C020;
const NiRTTI *	NiRTTI_NiPSysEmitterCtlr = (NiRTTI *)0x0303C030;
const NiRTTI *	NiRTTI_NiPSysGravityModifier = (NiRTTI *)0x0303C040;
const NiRTTI *	NiRTTI_BSPSysHavokUpdateModifier = (NiRTTI *)0x0303C050;
const NiRTTI *	NiRTTI_NiMeshParticleSystem = (NiRTTI *)0x0303C068;
const NiRTTI *	NiRTTI_NiPSysCylinderEmitter = (NiRTTI *)0x0303C080;
const NiRTTI *	NiRTTI_BSStripParticleSystem = (NiRTTI *)0x0303C090;
const NiRTTI *	NiRTTI_NiPSysEmitter = (NiRTTI *)0x0303C0A0;
const NiRTTI *	NiRTTI_NiPSysModifierCtlr = (NiRTTI *)0x0303C0B8;
const NiRTTI *	NiRTTI_NiPSysModifier = (NiRTTI *)0x0303C0C8;
const NiRTTI *	NiRTTI_NiPSysMeshUpdateModifier = (NiRTTI *)0x0303C0D8;
const NiRTTI *	NiRTTI_NiPSysUpdateCtlr = (NiRTTI *)0x0303C0E8;
const NiRTTI *	NiRTTI_NiMeshPSysData = (NiRTTI *)0x0303C0F8;
const NiRTTI *	NiRTTI_NiPSysAirFieldAirFrictionCtlr = (NiRTTI *)0x0303C108;
const NiRTTI *	NiRTTI_NiPSysAirFieldInheritVelocityCtlr = (NiRTTI *)0x0303C118;
const NiRTTI *	NiRTTI_NiPSysAirFieldModifier = (NiRTTI *)0x0303C128;
const NiRTTI *	NiRTTI_NiPSysAirFieldSpreadCtlr = (NiRTTI *)0x0303C138;
const NiRTTI *	NiRTTI_NiPSysAgeDeathModifier = (NiRTTI *)0x0303C148;
const NiRTTI *	NiRTTI_NiPSysBombModifier = (NiRTTI *)0x0303C158;
const NiRTTI *	NiRTTI_NiPSysBoundUpdateModifier = (NiRTTI *)0x0303C168;
const NiRTTI *	NiRTTI_NiPSysBoxEmitter = (NiRTTI *)0x0303C178;
const NiRTTI *	NiRTTI_NiPSysColliderManager = (NiRTTI *)0x0303C188;
const NiRTTI *	NiRTTI_NiPSysColorModifier = (NiRTTI *)0x0303C198;
const NiRTTI *	NiRTTI_NiPSysData = (NiRTTI *)0x0303C1A8;
const NiRTTI *	NiRTTI_NiPSysDragFieldModifier = (NiRTTI *)0x0303C1B8;
const NiRTTI *	NiRTTI_NiPSysDragModifier = (NiRTTI *)0x0303C1C8;
const NiRTTI *	NiRTTI_NiPSysEmitterCtlrData = (NiRTTI *)0x0303C1D8;
const NiRTTI *	NiRTTI_NiPSysEmitterDeclinationCtlr = (NiRTTI *)0x0303C1E8;
const NiRTTI *	NiRTTI_NiPSysEmitterDeclinationVarCtlr = (NiRTTI *)0x0303C1F8;
const NiRTTI *	NiRTTI_NiPSysEmitterInitialRadiusCtlr = (NiRTTI *)0x0303C208;
const NiRTTI *	NiRTTI_NiPSysEmitterLifeSpanCtlr = (NiRTTI *)0x0303C218;
const NiRTTI *	NiRTTI_NiPSysEmitterPlanarAngleCtlr = (NiRTTI *)0x0303C228;
const NiRTTI *	NiRTTI_NiPSysEmitterPlanarAngleVarCtlr = (NiRTTI *)0x0303C238;
const NiRTTI *	NiRTTI_NiPSysEmitterSpeedCtlr = (NiRTTI *)0x0303C248;
const NiRTTI *	NiRTTI_NiPSysFieldAttenuationCtlr = (NiRTTI *)0x0303C258;
const NiRTTI *	NiRTTI_NiPSysFieldMagnitudeCtlr = (NiRTTI *)0x0303C268;
const NiRTTI *	NiRTTI_NiPSysFieldMaxDistanceCtlr = (NiRTTI *)0x0303C278;
const NiRTTI *	NiRTTI_NiPSysGravityFieldModifier = (NiRTTI *)0x0303C288;
const NiRTTI *	NiRTTI_NiPSysGravityStrengthCtlr = (NiRTTI *)0x0303C298;
const NiRTTI *	NiRTTI_NiPSysGrowFadeModifier = (NiRTTI *)0x0303C2A8;
const NiRTTI *	NiRTTI_NiPSysInitialRotAngleCtlr = (NiRTTI *)0x0303C2B8;
const NiRTTI *	NiRTTI_NiPSysInitialRotAngleVarCtlr = (NiRTTI *)0x0303C2C8;
const NiRTTI *	NiRTTI_NiPSysInitialRotSpeedCtlr = (NiRTTI *)0x0303C2D8;
const NiRTTI *	NiRTTI_NiPSysInitialRotSpeedVarCtlr = (NiRTTI *)0x0303C2E8;
const NiRTTI *	NiRTTI_NiPSysMeshEmitter = (NiRTTI *)0x0303C2F8;
const NiRTTI *	NiRTTI_NiPSysModifierActiveCtlr = (NiRTTI *)0x0303C328;
const NiRTTI *	NiRTTI_NiPSysPlanarCollider = (NiRTTI *)0x0303C338;
const NiRTTI *	NiRTTI_NiPSysPositionModifier = (NiRTTI *)0x0303C350;
const NiRTTI *	NiRTTI_NiPSysRadialFieldModifier = (NiRTTI *)0x0303C360;
const NiRTTI *	NiRTTI_NiPSysResetOnLoopCtlr = (NiRTTI *)0x0303C370;
const NiRTTI *	NiRTTI_NiPSysRotationModifier = (NiRTTI *)0x0303C380;
const NiRTTI *	NiRTTI_NiPSysSpawnModifier = (NiRTTI *)0x0303C390;
const NiRTTI *	NiRTTI_NiPSysSphereEmitter = (NiRTTI *)0x0303C3A0;
const NiRTTI *	NiRTTI_NiPSysSphericalCollider = (NiRTTI *)0x0303C3B0;
const NiRTTI *	NiRTTI_NiPSysTurbulenceFieldModifier = (NiRTTI *)0x0303C3C0;
const NiRTTI *	NiRTTI_NiPSysVortexFieldModifier = (NiRTTI *)0x0303C3D0;
const NiRTTI *	NiRTTI_BSStripPSysData = (NiRTTI *)0x0303C3E0;
const NiRTTI *	NiRTTI_BSPSysRecycleBoundModifier = (NiRTTI *)0x0303C3F8;
const NiRTTI *	NiRTTI_BSPSysInheritVelocityModifier = (NiRTTI *)0x0303C408;
const NiRTTI *	NiRTTI_NiPSysVolumeEmitter = (NiRTTI *)0x0303C418;
const NiRTTI *	NiRTTI_NiPSysModifierFloatCtlr = (NiRTTI *)0x0303C428;
const NiRTTI *	NiRTTI_NiPSysFieldModifier = (NiRTTI *)0x0303C438;
const NiRTTI *	NiRTTI_NiPSysModifierBoolCtlr = (NiRTTI *)0x0303C448;
const NiRTTI *	NiRTTI_NiPSysCollider = (NiRTTI *)0x0303C458;
const NiRTTI *	NiRTTI_BSMultiBound = (NiRTTI *)0x03044708;
const NiRTTI *	NiRTTI_BSMultiBoundRoom = (NiRTTI *)0x03044718;
const NiRTTI *	NiRTTI_BSMultiBoundAABB = (NiRTTI *)0x03044730;
const NiRTTI *	NiRTTI_BSMultiBoundOBB = (NiRTTI *)0x03044748;
const NiRTTI *	NiRTTI_BSXFlags = (NiRTTI *)0x03044768;
const NiRTTI *	NiRTTI_BSValueNode = (NiRTTI *)0x03044780;
const NiRTTI *	NiRTTI_BSWindModifier = (NiRTTI *)0x0304AD00;
const NiRTTI *	NiRTTI_BSTempNodeManager = (NiRTTI *)0x0304AD20;
const NiRTTI *	NiRTTI_BSTempNode = (NiRTTI *)0x0304AD30;
const NiRTTI *	NiRTTI_BSOcclusionShape = (NiRTTI *)0x0304AD50;
const NiRTTI *	NiRTTI_BSRangeNode = (NiRTTI *)0x0304AE48;
const NiRTTI *	NiRTTI_BSBlastNode = (NiRTTI *)0x0304B080;
const NiRTTI *	NiRTTI_BSDebrisNode = (NiRTTI *)0x0304B090;
const NiRTTI *	NiRTTI_BSDamageStage = (NiRTTI *)0x0304B0A0;
const NiRTTI *	NiRTTI_BSPSysArrayEmitter = (NiRTTI *)0x0304B0B0;
const NiRTTI *	NiRTTI_PArrayPoint = (NiRTTI *)0x0304B0C0;
const NiRTTI *	NiRTTI_BSMultiStreamInstanceTriShape = (NiRTTI *)0x0304B0E8;
const NiRTTI *	NiRTTI_BSMultiBoundShape = (NiRTTI *)0x0304B118;
const NiRTTI *	NiRTTI_BSMultiBoundSphere = (NiRTTI *)0x0304B128;
const NiRTTI *	NiRTTI_BSOcclusionBox = (NiRTTI *)0x0304B140;
const NiRTTI *	NiRTTI_BSOcclusionPlane = (NiRTTI *)0x0304B158;
const NiRTTI *	NiRTTI_BSPortal = (NiRTTI *)0x0304B168;
const NiRTTI *	NiRTTI_BSPortalSharedNode = (NiRTTI *)0x0304B178;
const NiRTTI *	NiRTTI_BSBodyMorphOffsetsExtraData = (NiRTTI *)0x0304B190;
const NiRTTI *	NiRTTI_BSBehaviorGraphExtraData = (NiRTTI *)0x0304B1A0;
const NiRTTI *	NiRTTI_NiBSBoneLODController = (NiRTTI *)0x0304B1B8;
const NiRTTI *	NiRTTI_BSCullingProcess = (NiRTTI *)0x0304B1D8;
const NiRTTI *	NiRTTI_BSParticleSystemManager = (NiRTTI *)0x0304B1F8;
const NiRTTI *	NiRTTI_BSFurnitureMarkerNode = (NiRTTI *)0x0304B220;
const NiRTTI *	NiRTTI_BSBound = (NiRTTI *)0x0304B2A0;
const NiRTTI *	NiRTTI_BSMultiBoundNode = (NiRTTI *)0x0304B330;
const NiRTTI *	NiRTTI_BSBoneMap = (NiRTTI *)0x0304B340;
const NiRTTI *	NiRTTI_BSAnimInteractionMarker = (NiRTTI *)0x0304B358;
const NiRTTI *	NiRTTI_BSSceneGraph = (NiRTTI *)0x0304B370;
const NiRTTI *	NiRTTI_BSPSysMultiTargetEmitterCtlr = (NiRTTI *)0x0304B388;
const NiRTTI *	NiRTTI_BSGeometryListCullingProcess = (NiRTTI *)0x0304B3A0;
const NiRTTI *	NiRTTI_BSSubIndexTriShape = (NiRTTI *)0x0304B3B8;
const NiRTTI *	NiRTTI_BSDistantObjectLargeRefExtraData = (NiRTTI *)0x0304B3C8;
const NiRTTI *	NiRTTI_BSMasterParticleSystem = (NiRTTI *)0x0304CD90;
const NiRTTI *	NiRTTI_BSProceduralLightningController = (NiRTTI *)0x0304CDB8;
const NiRTTI *	NiRTTI_BSInvMarker = (NiRTTI *)0x0304CDC8;
const NiRTTI *	NiRTTI_BSBoneLODExtraData = (NiRTTI *)0x0304CDE0;
const NiRTTI *	NiRTTI_BSReference = (NiRTTI *)0x0304CE00;
const NiRTTI *	NiRTTI_BSNodeReferences = (NiRTTI *)0x0304CE10;
const NiRTTI *	NiRTTI_BSDecalPlacementVectorExtraData = (NiRTTI *)0x0304CE20;
const NiRTTI *	NiRTTI_BSParentVelocityModifier = (NiRTTI *)0x0304CE30;
const NiRTTI *	NiRTTI_BSWArray = (NiRTTI *)0x0304CE40;
const NiRTTI *	NiRTTI_BSMultiBoundCapsule = (NiRTTI *)0x0304CE58;
const NiRTTI *	NiRTTI_BSPSysStripUpdateModifier = (NiRTTI *)0x0304CE68;
const NiRTTI *	NiRTTI_BSPSysSubTexModifier = (NiRTTI *)0x0304CE78;
const NiRTTI *	NiRTTI_BSPSysScaleModifier = (NiRTTI *)0x0304CE88;
const NiRTTI *	NiRTTI_BSLagBoneController = (NiRTTI *)0x0304CE98;
const NiRTTI *	NiRTTI_BSNonUniformScaleExtraData = (NiRTTI *)0x0304CEA8;
const NiRTTI *	NiRTTI_BSNiNode = (NiRTTI *)0x0304CEC0;
const NiRTTI *	NiRTTI_BSInstanceTriShape = (NiRTTI *)0x0304CED0;
const NiRTTI *	NiRTTI_bhkWorldObject = (NiRTTI *)0x03053C68;
const NiRTTI *	NiRTTI_bhkWorld = (NiRTTI *)0x03053CA8;
const NiRTTI *	NiRTTI_bhkRigidBody = (NiRTTI *)0x03054DE8;
const NiRTTI *	NiRTTI_bhkCollisionObject = (NiRTTI *)0x03054E00;
const NiRTTI *	NiRTTI_bhkNiCollisionObject = (NiRTTI *)0x03054EB0;
const NiRTTI *	NiRTTI_bhkAttachmentCollisionObject = (NiRTTI *)0x03054F40;
const NiRTTI *	NiRTTI_WeaponObject = (NiRTTI *)0x03054F50;
const NiRTTI *	NiRTTI_bhkRigidBodyT = (NiRTTI *)0x03054F78;
const NiRTTI *	NiRTTI_bhkWorldM = (NiRTTI *)0x03054F88;
const NiRTTI *	NiRTTI_bhkRefObject = (NiRTTI *)0x03054FB0;
const NiRTTI *	NiRTTI_bhkSerializable = (NiRTTI *)0x03054FC0;
const NiRTTI *	NiRTTI_bhkShape = (NiRTTI *)0x03054FF0;
const NiRTTI *	NiRTTI_bhkEntity = (NiRTTI *)0x03055008;
const NiRTTI *	NiRTTI_bhkPhantom = (NiRTTI *)0x03055020;
const NiRTTI *	NiRTTI_bhkAabbPhantom = (NiRTTI *)0x03055038;
const NiRTTI *	NiRTTI_bhkSphereRepShape = (NiRTTI *)0x03055050;
const NiRTTI *	NiRTTI_bhkConvexShape = (NiRTTI *)0x03055068;
const NiRTTI *	NiRTTI_bhkPCollisionObject = (NiRTTI *)0x03055078;
const NiRTTI *	NiRTTI_hkPackedNiTriStripsData = (NiRTTI *)0x03055088;
const NiRTTI *	NiRTTI_bhkShapePhantom = (NiRTTI *)0x030550A0;
const NiRTTI *	NiRTTI_bhkSimpleShapePhantom = (NiRTTI *)0x030550B8;
const NiRTTI *	NiRTTI_bhkCapsuleShape = (NiRTTI *)0x030550D0;
const NiRTTI *	NiRTTI_bhkBoxShape = (NiRTTI *)0x030550E8;
const NiRTTI *	NiRTTI_bhkSphereShape = (NiRTTI *)0x03055100;
const NiRTTI *	NiRTTI_bhkBvTreeShape = (NiRTTI *)0x03055118;
const NiRTTI *	NiRTTI_bhkNiTriStripsShape = (NiRTTI *)0x03055130;
const NiRTTI *	NiRTTI_bhkPackedNiTriStripsShape = (NiRTTI *)0x03055158;
const NiRTTI *	NiRTTI_bhkBlendCollisionObject = (NiRTTI *)0x03055170;
const NiRTTI *	NiRTTI_bhkAvoidBox = (NiRTTI *)0x03055190;
const NiRTTI *	NiRTTI_bhkLimitedHingeConstraint = (NiRTTI *)0x030551A8;
const NiRTTI *	NiRTTI_bhkMalleableConstraint = (NiRTTI *)0x030551C0;
const NiRTTI *	NiRTTI_bhkConstraint = (NiRTTI *)0x030551D8;
const NiRTTI *	NiRTTI_bhkPrismaticConstraint = (NiRTTI *)0x030551F0;
const NiRTTI *	NiRTTI_bhkAction = (NiRTTI *)0x03055208;
const NiRTTI *	NiRTTI_bhkUnaryAction = (NiRTTI *)0x03055220;
const NiRTTI *	NiRTTI_bhkTriSampledHeightFieldBvTreeShape = (NiRTTI *)0x03055238;
const NiRTTI *	NiRTTI_bhkCachingShapePhantom = (NiRTTI *)0x03055EA8;
const NiRTTI *	NiRTTI_bhkRagdollTemplateData = (NiRTTI *)0x03055ED0;
const NiRTTI *	NiRTTI_bhkRagdollTemplate = (NiRTTI *)0x03055EE0;
const NiRTTI *	NiRTTI_bhkSPCollisionObject = (NiRTTI *)0x03055EF0;
const NiRTTI *	NiRTTI_bhkMouseSpringAction = (NiRTTI *)0x03055F08;
const NiRTTI *	NiRTTI_bhkHingeConstraint = (NiRTTI *)0x03055F20;
const NiRTTI *	NiRTTI_bhkCompressedMeshShape = (NiRTTI *)0x03055F98;
const NiRTTI *	NiRTTI_bhkCompressedMeshShapeData = (NiRTTI *)0x03055FA8;
const NiRTTI *	NiRTTI_bhkConvexSweepShape = (NiRTTI *)0x03055FC0;
const NiRTTI *	NiRTTI_bhkConvexTransformShape = (NiRTTI *)0x03055FD8;
const NiRTTI *	NiRTTI_bhkConvexTranslateShape = (NiRTTI *)0x03055FF0;
const NiRTTI *	NiRTTI_bhkConvexVerticesShape = (NiRTTI *)0x03056008;
const NiRTTI *	NiRTTI_bhkCylinderShape = (NiRTTI *)0x03056020;
const NiRTTI *	NiRTTI_bhkMultiSphereShape = (NiRTTI *)0x03056038;
const NiRTTI *	NiRTTI_bhkPlaneShape = (NiRTTI *)0x03056050;
const NiRTTI *	NiRTTI_bhkTriangleShape = (NiRTTI *)0x03056068;
const NiRTTI *	NiRTTI_bhkMoppBvTreeShape = (NiRTTI *)0x03056080;
const NiRTTI *	NiRTTI_bhkTransformShape = (NiRTTI *)0x03056098;
const NiRTTI *	NiRTTI_bhkListShape = (NiRTTI *)0x030560B0;
const NiRTTI *	NiRTTI_bhkBallAndSocketConstraint = (NiRTTI *)0x030560C8;
const NiRTTI *	NiRTTI_bhkBallSocketConstraintChain = (NiRTTI *)0x030560E0;
const NiRTTI *	NiRTTI_bhkGroupConstraint = (NiRTTI *)0x030560F8;
const NiRTTI *	NiRTTI_bhkHingeLimitsConstraint = (NiRTTI *)0x03056110;
const NiRTTI *	NiRTTI_bhkFixedConstraint = (NiRTTI *)0x03056128;
const NiRTTI *	NiRTTI_bhkRagdollConstraint = (NiRTTI *)0x03056140;
const NiRTTI *	NiRTTI_bhkRagdollLimitsConstraint = (NiRTTI *)0x03056158;
const NiRTTI *	NiRTTI_bhkStiffSpringConstraint = (NiRTTI *)0x03056170;
const NiRTTI *	NiRTTI_bhkWheelConstraint = (NiRTTI *)0x03056188;
const NiRTTI *	NiRTTI_bhkBreakableConstraint = (NiRTTI *)0x030561A0;
const NiRTTI *	NiRTTI_bhkAngularDashpotAction = (NiRTTI *)0x030561B8;
const NiRTTI *	NiRTTI_bhkDashpotAction = (NiRTTI *)0x030561D0;
const NiRTTI *	NiRTTI_bhkLiquidAction = (NiRTTI *)0x030561E8;
const NiRTTI *	NiRTTI_bhkMotorAction = (NiRTTI *)0x03056208;
const NiRTTI *	NiRTTI_bhkOrientHingedBodyAction = (NiRTTI *)0x03056220;
const NiRTTI *	NiRTTI_bhkSpringAction = (NiRTTI *)0x03056238;
const NiRTTI *	NiRTTI_bhkBlendController = (NiRTTI *)0x03056248;
const NiRTTI *	NiRTTI_bhkExtraData = (NiRTTI *)0x03056258;
const NiRTTI *	NiRTTI_bhkPoseArray = (NiRTTI *)0x03056268;
const NiRTTI *	NiRTTI_bhkGenericConstraint = (NiRTTI *)0x03056288;
const NiRTTI *	NiRTTI_bhkCharControllerShape = (NiRTTI *)0x03056298;
const NiRTTI *	NiRTTI_bhkCollisionBox = (NiRTTI *)0x030562B0;
const NiRTTI *	NiRTTI_bhkShapeCollection = (NiRTTI *)0x030562C8;
const NiRTTI *	NiRTTI_bhkPositionConstraintMotor = (NiRTTI *)0x03056330;
const NiRTTI *	NiRTTI_bhkVelocityConstraintMotor = (NiRTTI *)0x03056340;
const NiRTTI *	NiRTTI_bhkSpringDamperConstraintMotor = (NiRTTI *)0x03056350;
const NiRTTI *	NiRTTI_bhkCharacterProxy = (NiRTTI *)0x03057108;
const NiRTTI *	NiRTTI_bhkCharacterRigidBody = (NiRTTI *)0x03057120;
const NiRTTI *	NiRTTI_bhkHeightFieldShape = (NiRTTI *)0x03058428;
const NiRTTI *	NiRTTI_bhkConstraintChain = (NiRTTI *)0x03058440;
const NiRTTI *	NiRTTI_bhkBinaryAction = (NiRTTI *)0x03058458;
const NiRTTI *	NiRTTI_bhkPointToPathConstraint = (NiRTTI *)0x03058490;
const NiRTTI *	NiRTTI_DebugTextExtraData = (NiRTTI *)0x03059C80;
const NiRTTI *	NiRTTI_BSFadeNode = (NiRTTI *)0x031F6418;
const NiRTTI *	NiRTTI_BSShaderProperty = (NiRTTI *)0x031F6448;
const NiRTTI *	NiRTTI_BSLeafAnimNode = (NiRTTI *)0x031F6458;
const NiRTTI *	NiRTTI_BSTreeNode = (NiRTTI *)0x031F6468;
const NiRTTI *	NiRTTI_ShadowSceneNode = (NiRTTI *)0x031F6890;
const NiRTTI *	NiRTTI_BSLightingShaderProperty = (NiRTTI *)0x031F7188;
const NiRTTI *	NiRTTI_BSGrassShaderProperty = (NiRTTI *)0x031F71C0;
const NiRTTI *	NiRTTI_BSShaderAccumulator = (NiRTTI *)0x031F73D0;
const NiRTTI *	NiRTTI_BSEffectShaderProperty = (NiRTTI *)0x031F7590;
const NiRTTI *	NiRTTI_BSWaterShaderProperty = (NiRTTI *)0x032583B8;
const NiRTTI *	NiRTTI_BSBloodSplatterShaderProperty = (NiRTTI *)0x032583C8;
const NiRTTI *	NiRTTI_BSParticleShaderProperty = (NiRTTI *)0x03258848;
const NiRTTI *	NiRTTI_BSTextureSet = (NiRTTI *)0x03258B98;
const NiRTTI *	NiRTTI_BSShaderTextureSet = (NiRTTI *)0x03258BA8;
const NiRTTI *	NiRTTI_BSSkyShaderProperty = (NiRTTI *)0x03258EA8;
const NiRTTI *	NiRTTI_BSFadeNodeCuller = (NiRTTI *)0x032A8F30;
const NiRTTI *	NiRTTI_BSDistantTreeShaderProperty = (NiRTTI *)0x032A8F60;
const NiRTTI *	NiRTTI_BSCubeMapCamera = (NiRTTI *)0x032A9140;
const NiRTTI *	NiRTTI_BSFogProperty = (NiRTTI *)0x032A91F8;
const NiRTTI *	NiRTTI_BSClearZNode = (NiRTTI *)0x034BB2D8;
const NiRTTI *	NiRTTI_NiCollisionObject = (NiRTTI *)0x034BB3F8;
const NiRTTI *	NiRTTI_BSOrderedNode = (NiRTTI *)0x034BB408;
const NiRTTI *	NiRTTI_BSLines = (NiRTTI *)0x034BB418;
const NiRTTI *	NiRTTI_BSDynamicLines = (NiRTTI *)0x034BB428;
const NiRTTI *	NiRTTI_BSMultiIndexTriShape = (NiRTTI *)0x034BB448;
const NiRTTI *	NiRTTI_BSLightingShaderPropertyFloatController = (NiRTTI *)0x034BB4F0;
const NiRTTI *	NiRTTI_BSLightingShaderPropertyUShortController = (NiRTTI *)0x034BB508;
const NiRTTI *	NiRTTI_BSLightingShaderPropertyColorController = (NiRTTI *)0x034BB520;
const NiRTTI *	NiRTTI_BSEffectShaderPropertyFloatController = (NiRTTI *)0x034BB558;
const NiRTTI *	NiRTTI_BSEffectShaderPropertyColorController = (NiRTTI *)0x034BB570;
const NiRTTI *	NiRTTI_BSNiAlphaPropertyTestRefController = (NiRTTI *)0x034BB580;
const NiRTTI *	NiRTTI_BSPSysSimpleColorModifier = (NiRTTI *)0x034BB590;
const NiRTTI *	NiRTTI_BSPSysLODModifier = (NiRTTI *)0x034BB5A0;
const NiRTTI *	NiRTTI_BSParabolicCullingProcess = (NiRTTI *)0x034BBA28;
const NiRTTI *	NiRTTI_BSMeshLODTriShape = (NiRTTI *)0x034BBA38;
const NiRTTI *	NiRTTI_BSLODMultiIndexTriShape = (NiRTTI *)0x034BBA48;
const NiRTTI *	NiRTTI_BSSubIndexLandTriShape = (NiRTTI *)0x034BBA60;