// ----------------------------------------------------------------------------
//  FILE: CIDMath_Shared.hpp
//  DATE: Mon, Dec 02 17:25:34 2019 -0500
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------
#pragma once

#pragma CIDLIB_PACK(CIDLIBPACK)

// ----------------------------------------------------------------------------
// Types namespace
// ----------------------------------------------------------------------------
namespace tCIDMath
{
    
    // ------------------------------------------------------------------------
    //  The available graph vertical scaling types
    //                  
    // ------------------------------------------------------------------------
    enum class EGraphScales
    {
        Linear
        , Log10
        , Count
        , Min = Linear
        , Max = Log10
    };
    CIDMATHEXP EGraphScales eXlatEGraphScales(const TString& strToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::False);
    CIDMATHEXP const TString& strXlatEGraphScales(const EGraphScales eToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::True);
    CIDMATHEXP tCIDLib::TVoid FormatEGraphScales
        (
                         TString&            strTarget
              , const    TString&            strPrefix
              , const    tCIDLib::TCh        chSepChar
              , const    TEnumMap::ETextVals eVal = TEnumMap::ETextVals::BaseName
        );
    CIDMATHEXP tCIDLib::TBoolean bIsValidEnum(const EGraphScales eVal);

    
    // ------------------------------------------------------------------------
    //  The types of logarithmic algorithms. Used by TFLogMap, but it is
    //  generally useful.
    //                  
    // ------------------------------------------------------------------------
    enum class ELogTypes
    {
        Natural
        , Base10
        , Count
        , Min = Natural
        , Max = Base10
    };
    CIDMATHEXP ELogTypes eXlatELogTypes(const TString& strToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::False);
    CIDMATHEXP const TString& strXlatELogTypes(const ELogTypes eToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::True);
    CIDMATHEXP tCIDLib::TBoolean bIsValidEnum(const ELogTypes eVal);

    
    // ------------------------------------------------------------------------
    //  This enum is used to index matrices via the subscript operator.
    //                  
    // ------------------------------------------------------------------------
    enum class EMatrixElems
    {
        M11
        , M12
        , M13
        , M14
        , M21
        , M22
        , M23
        , M24
        , M31
        , M32
        , M33
        , M34
        , MXt
        , MYt
        , MZt
        , M44
        , Count
        , Min = M11
        , Max = M44
    };
    CIDMATHEXP EMatrixElems eXlatEMatrixElems(const TString& strToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::False);
    CIDMATHEXP const TString& strXlatEMatrixElems(const EMatrixElems eToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::True);
    CIDMATHEXP const TString& strAltXlatEMatrixElems(const EMatrixElems eToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::True);
    CIDMATHEXP EMatrixElems eAltXlatEMatrixElems(const TString& strToXlat, const tCIDLib::TBoolean bThrowIfNot = kCIDLib::False);
    CIDMATHEXP tCIDLib::TBoolean bIsValidEnum(const EMatrixElems eVal);

}

#pragma CIDLIB_POPPACK

CIDMATHEXP TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDMath::EGraphScales eToStream);
CIDMATHEXP TBinInStream& operator>>(TBinInStream& strmSrc, tCIDMath::EGraphScales& eToFill);
CIDMATHEXP tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDMath::EGraphScales* const aeList, const tCIDLib::TCard4 c4Count);
CIDMATHEXP tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDMath::EGraphScales* const aeList, const tCIDLib::TCard4 c4Count);
CIDMATHEXP tCIDMath::EGraphScales operator++(tCIDMath::EGraphScales& eVal, int);
CIDMATHEXP TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDMath::EGraphScales eToStream);

CIDMATHEXP TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDMath::ELogTypes eToStream);
CIDMATHEXP TBinInStream& operator>>(TBinInStream& strmSrc, tCIDMath::ELogTypes& eToFill);
CIDMATHEXP tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDMath::ELogTypes* const aeList, const tCIDLib::TCard4 c4Count);
CIDMATHEXP tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDMath::ELogTypes* const aeList, const tCIDLib::TCard4 c4Count);
CIDMATHEXP tCIDMath::ELogTypes operator++(tCIDMath::ELogTypes& eVal, int);
CIDMATHEXP TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDMath::ELogTypes eToStream);

CIDMATHEXP TBinOutStream& operator<<(TBinOutStream& strmTar, const tCIDMath::EMatrixElems eToStream);
CIDMATHEXP TBinInStream& operator>>(TBinInStream& strmSrc, tCIDMath::EMatrixElems& eToFill);
CIDMATHEXP tCIDLib::TVoid TBinInStream_ReadArray(TBinInStream& strmSrc, tCIDMath::EMatrixElems* const aeList, const tCIDLib::TCard4 c4Count);
CIDMATHEXP tCIDLib::TVoid TBinOutStream_WriteArray(TBinOutStream& strmTar, const tCIDMath::EMatrixElems* const aeList, const tCIDLib::TCard4 c4Count);
CIDMATHEXP tCIDMath::EMatrixElems operator++(tCIDMath::EMatrixElems& eVal, int);
CIDMATHEXP TTextOutStream& operator<<(TTextOutStream& strmTar, const tCIDMath::EMatrixElems eToStream);

