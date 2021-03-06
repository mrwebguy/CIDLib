// ----------------------------------------------------------------------------
//  FILE: CIDResEd_Types.hpp
//  DATE: Fri, Feb 14 18:42:56 2020 -0500
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------
#pragma once

#pragma CIDLIB_PACK(CIDLIBPACK)

// ----------------------------------------------------------------------------
// Constants namespace
// ----------------------------------------------------------------------------
namespace kCIDResEd
{
    
    // ------------------------------------------------------------------------
    //  These are constants for the various item and dialog attributes
    //  that we use, to avoid typos and such. Some of them are done
    //  via enums below.
    //                  
    // ------------------------------------------------------------------------
     const extern TString strAttr_Area;
     const extern TString strAttr_Anchor;
     const extern TString strAttr_AppImage;
     const extern TString strAttr_Hints;
     const extern TString strAttr_InitFocus;
     const extern TString strAttr_ResId;
     const extern TString strAttr_ScreenOrigin;
     const extern TString strAttr_SetFgn;
     const extern TString strAttr_Sizeable;
     const extern TString strAttr_Symbol;
     const extern TString strAttr_Theme;
     const extern TString strAttr_Title;
     const extern TString strAttr_UseOrigin;
    
    // ------------------------------------------------------------------------
    //  These are constants for the special attribute types that we
    //  set on some attributes, so that we can easily recognize them
    //  when we receive a change or in validation.
    //                  
    // ------------------------------------------------------------------------
     const extern TString strSpecType_LoadText;
     const extern TString strSpecType_Hint;
     const extern TString strSpecType_DlgItemFlag;
}

// ----------------------------------------------------------------------------
// Types namespace
// ----------------------------------------------------------------------------
namespace tCIDResEd
{
    
    // ------------------------------------------------------------------------
    //  The types of loadable text we support.
    //                  
    // ------------------------------------------------------------------------
    enum class EMsgTypes
    {
        Common
        , Error
        , Message
        , Count
        , Min = Common
        , Max = Message
    };
     const TString& strLoadEMsgTypes(const EMsgTypes eToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::False);
     const TString& strAltXlatEMsgTypes(const EMsgTypes eToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::True);
     EMsgTypes eAltXlatEMsgTypes(const TString& strToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::False);
     tCIDLib::TBoolean bIsValidEnum(const EMsgTypes eVal);

    
    // ------------------------------------------------------------------------
    //  The types of text symbols a dialog ite can have
    //                  
    // ------------------------------------------------------------------------
    enum class ETextSyms
    {
        Cue
        , Flyover
        , Text
        , Count
        , Min = Cue
        , Max = Text
    };
     ETextSyms eXlatETextSyms(const TString& strToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::False);
     const TString& strXlatETextSyms(const ETextSyms eToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::True);
     tCIDLib::TBoolean bIsValidEnum(const ETextSyms eVal);

}

#pragma CIDLIB_POPPACK

 TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDResEd::EMsgTypes eToStream);
 TBinInStream& operator>>(TBinInStream& strmSrc, tCIDResEd::EMsgTypes& eToFill);
 tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDResEd::EMsgTypes* const aeList, const tCIDLib::TCard4 c4Count);
 tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDResEd::EMsgTypes* const aeList, const tCIDLib::TCard4 c4Count);
 tCIDResEd::EMsgTypes operator++(tCIDResEd::EMsgTypes& eVal, int);
 TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDResEd::EMsgTypes eToStream);

 tCIDResEd::ETextSyms operator++(tCIDResEd::ETextSyms& eVal, int);

