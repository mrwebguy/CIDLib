// ----------------------------------------------------------------------------
//  FILE: CIDMData_Shared.cpp
//  DATE: Wed, Jun 26 17:43:27 2019 -0400
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

#include "CIDMData_.hpp"

const TString kCIDMData::strAttrLim_Required(L"[Required]");
const TString kCIDMData::strAttrLim_SingleLine(L"[SingleLine]");
const TString kCIDMData::strAttrLim_SingleReq(L"[SingleReq]");
const TString kCIDMData::strAttrLim_AreaPref(L"Area:");
const TString kCIDMData::strAttrLim_CharPref(L"Char");
const TString kCIDMData::strAttrLim_EnumPref(L"Enum:");
const TString kCIDMData::strAttrLim_FileSelPref(L"FileSel:");
const TString kCIDMData::strAttrLim_RangePref(L"Range:");
const TString kCIDMData::strAttrLim_SizePref(L"Size:");
const TString kCIDMData::strAttrVal_False(L"False");
const TString kCIDMData::strAttrVal_AltFalse1(L"0");
const TString kCIDMData::strAttrVal_AltFalse2(L"No");
const TString kCIDMData::strAttrVal_True(L"True");
const TString kCIDMData::strAttrVal_AltTrue1(L"1");
const TString kCIDMData::strAttrVal_AltTrue2(L"Yes");
const TString kCIDMData::strChunkId_Data(L"/CQSL/CF/Data");
const TString kCIDMData::strChunkId_Meta(L"/CQSL/CF/Meta");
const TString kCIDMData::strChFlMetaKey_Application(L"/CQSL/CF/Application");
const TString kCIDMData::strChFlMetaKey_Author(L"/CQSL/CF/Author");
const TString kCIDMData::strChFlMetaKey_FileName(L"/CQSL/CF/Source");
const TString kCIDMData::strChFlMetaKey_Notes(L"/CQSL/CF/Notes");
const TString kCIDMData::strChFlMetaKey_Title(L"/CQSL/CF/Title");
const TString kCIDMData::strChFlMetaKey_Version(L"/CQSL/CF/Version");
const TString kCIDMData::strChFlMetaKey_StdPrefix(L"/CQSL/CF/");


static TEnumMap::TEnumValItem aeitemValues_EAttrTypes[19] = 
{
    {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Area), 0, 0,  { L"", L"", L"", L"Area", L"EAttrTypes::Area", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::AppImage), 0, 0,  { L"", L"", L"", L"AppImage", L"EAttrTypes::AppImage", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Binary), 0, 0,  { L"", L"", L"", L"Binary", L"EAttrTypes::Binary", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Bool), 0, 0,  { L"", L"", L"", L"Bool", L"EAttrTypes::Bool", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Card), 0, 0,  { L"", L"", L"", L"Card", L"EAttrTypes::Card", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Card64), 0, 0,  { L"", L"", L"", L"Card64", L"EAttrTypes::Card64", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::CardRange), 0, 0,  { L"", L"", L"", L"CardRange", L"EAttrTypes::CardRange", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Char), 0, 0,  { L"", L"", L"", L"Char", L"EAttrTypes::Char", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::File), 0, 0,  { L"", L"", L"", L"File", L"EAttrTypes::File", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Float), 0, 0,  { L"", L"", L"", L"Float", L"EAttrTypes::Float", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Int), 0, 0,  { L"", L"", L"", L"Int", L"EAttrTypes::Int", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::IntRange), 0, 0,  { L"", L"", L"", L"IntRange", L"EAttrTypes::IntRange", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::MLString), 0, 0,  { L"", L"", L"", L"MLString", L"EAttrTypes::MLString", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Point), 0, 0,  { L"", L"", L"", L"Point", L"EAttrTypes::Point", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::RGBColor), 0, 0,  { L"", L"", L"", L"RGBColor", L"EAttrTypes::RGBColor", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::String), 0, 0,  { L"", L"", L"", L"String", L"EAttrTypes::String", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Separator), 0, 0,  { L"", L"", L"", L"Separator", L"EAttrTypes::Separator", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Size), 0, 0,  { L"", L"", L"", L"Size", L"EAttrTypes::Size", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrTypes::Time), 0, 0,  { L"", L"", L"", L"Time", L"EAttrTypes::Time", L"" } }

};

static TEnumMap emapEAttrTypes
(
     L"EAttrTypes"
     , 19
     , kCIDLib::False
     , aeitemValues_EAttrTypes
     , nullptr
     , tCIDLib::TCard4(tCIDMData::EAttrTypes::Count)
);

const TString& tCIDMData::strXlatEAttrTypes(const tCIDMData::EAttrTypes eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapEAttrTypes.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, bThrowIfNot);
}

tCIDMData::EAttrTypes tCIDMData::eXlatEAttrTypes(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDMData::EAttrTypes(emapEAttrTypes.i4MapEnumText(strVal, TEnumMap::ETextVals::BaseName, bThrowIfNot));
}

TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDMData::EAttrTypes eVal)
{
    strmTar << emapEAttrTypes.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, kCIDLib::False);
    return strmTar;
}
TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDMData::EAttrTypes eVal)
{
    strmTar.WriteEnum(tCIDLib::TCard4(eVal));
    return strmTar;
}
TBinInStream& operator>>(TBinInStream& strmSrc, tCIDMData::EAttrTypes& eVal)
{
    eVal = tCIDMData::EAttrTypes(strmSrc.c4ReadEnum());
    return strmSrc;
}
tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDMData::EAttrTypes* const aeList, const tCIDLib::TCard4 c4Count)
{
    tCIDLib::TCard4 c4Cur;
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
    {
        strmSrc >> c4Cur;
        aeList[c4Index] = tCIDMData::EAttrTypes(c4Cur);
    }
}
tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDMData::EAttrTypes* const aeList, const tCIDLib::TCard4 c4Count)
{
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
        strmTar << tCIDLib::TCard4(aeList[c4Index]);
}
tCIDLib::TBoolean tCIDMData::bIsValidEnum(const tCIDMData::EAttrTypes eVal)
{
    return emapEAttrTypes.bIsValidEnum(tCIDLib::TCard4(eVal));

}



static TEnumMap::TEnumValItem aeitemValues_EAttrEdTypes[4] = 
{
    {  tCIDLib::TInt4(tCIDMData::EAttrEdTypes::None), 0, 0,  { L"", L"", L"", L"None", L"EAttrEdTypes::None", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrEdTypes::InPlace), 0, 0,  { L"", L"", L"", L"InPlace", L"EAttrEdTypes::InPlace", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrEdTypes::Visual), 0, 0,  { L"", L"", L"", L"Visual", L"EAttrEdTypes::Visual", L"" } }
  , {  tCIDLib::TInt4(tCIDMData::EAttrEdTypes::Both), 0, 0,  { L"", L"", L"", L"Both", L"EAttrEdTypes::Both", L"" } }

};

static TEnumMap emapEAttrEdTypes
(
     L"EAttrEdTypes"
     , 4
     , kCIDLib::False
     , aeitemValues_EAttrEdTypes
     , nullptr
     , tCIDLib::TCard4(tCIDMData::EAttrEdTypes::Count)
);

const TString& tCIDMData::strXlatEAttrEdTypes(const tCIDMData::EAttrEdTypes eVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return emapEAttrEdTypes.strMapEnumVal(tCIDLib::TCard4(eVal), TEnumMap::ETextVals::BaseName, bThrowIfNot);
}

tCIDMData::EAttrEdTypes tCIDMData::eXlatEAttrEdTypes(const TString& strVal, const tCIDLib::TBoolean bThrowIfNot)
{
    return tCIDMData::EAttrEdTypes(emapEAttrEdTypes.i4MapEnumText(strVal, TEnumMap::ETextVals::BaseName, bThrowIfNot));
}

TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDMData::EAttrEdTypes eVal)
{
    strmTar.WriteEnum(tCIDLib::TCard4(eVal));
    return strmTar;
}
TBinInStream& operator>>(TBinInStream& strmSrc, tCIDMData::EAttrEdTypes& eVal)
{
    eVal = tCIDMData::EAttrEdTypes(strmSrc.c4ReadEnum());
    return strmSrc;
}
tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDMData::EAttrEdTypes* const aeList, const tCIDLib::TCard4 c4Count)
{
    tCIDLib::TCard4 c4Cur;
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
    {
        strmSrc >> c4Cur;
        aeList[c4Index] = tCIDMData::EAttrEdTypes(c4Cur);
    }
}
tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDMData::EAttrEdTypes* const aeList, const tCIDLib::TCard4 c4Count)
{
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++)
        strmTar << tCIDLib::TCard4(aeList[c4Index]);
}
tCIDLib::TBoolean tCIDMData::bIsValidEnum(const tCIDMData::EAttrEdTypes eVal)
{
    return emapEAttrEdTypes.bIsValidEnum(tCIDLib::TCard4(eVal));

}

