//
// FILE NAME: CIDLib_Type.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 04/02/1995
//
// COPYRIGHT: Charmed Quark Systems, Ltd @ 2019
//
//  This software is copyrighted by 'Charmed Quark Systems, Ltd' and
//  the author (Dean Roddey.) It is licensed under the MIT Open Source
//  license:
//
//  https://opensource.org/licenses/MIT
//
// DESCRIPTION:
//
//  This header contains some stuff related to the types in the tCIDLib
//  namespace. For architectural reasons, CIDLib's namespace is actually
//  down in the kernel facility. For all other facility's, this file
//  would contain the namespace for types as well.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


// ---------------------------------------------------------------------------
//  This macro generates the standard enum streaming methods. For the
//  one that formats to a text stream, the implementation must be provided,
//  since this only provides the definition. For enums that are just to be
//  binary streamed, another version is provided. It does all the work
//  required.
// ---------------------------------------------------------------------------
#define EnumStreamMacros(eEnumType) \
DLLEXPORT TTextOutStream& operator<<(TTextOutStream& strmToWriteTo, const eEnumType eVal); \
inline TBinOutStream& operator<<(TBinOutStream& strmToWriteTo, const eEnumType eVal) \
{ \
    strmToWriteTo.WriteEnum(tCIDLib::TCard4(eVal)); \
    return strmToWriteTo; \
} \
 \
inline TBinInStream& operator>>(TBinInStream& strmToReadFrom, eEnumType& eVal) \
{ \
    eVal = (eEnumType)strmToReadFrom.c4ReadEnum(); \
    return strmToReadFrom; \
}

#define EnumBinStreamMacros(eEnumType) \
inline TBinOutStream& operator<<(TBinOutStream& strmToWriteTo, const eEnumType eVal) \
{ \
    strmToWriteTo.WriteEnum(tCIDLib::TCard4(eVal)); \
    return strmToWriteTo; \
} \
 \
inline TBinInStream& operator>>(TBinInStream& strmToReadFrom, eEnumType& eVal) \
{ \
    eVal = (eEnumType)strmToReadFrom.c4ReadEnum(); \
    return strmToReadFrom; \
} \
inline tCIDLib::TVoid TBinInStream_ReadArray(       TBinInStream&       strmSrc \
                                            ,       eEnumType* const    aeList \
                                            , const tCIDLib::TCard4     c4Count) \
{ \
    tCIDLib::TCard4 c4Cur = 0; \
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++) \
    { \
        strmSrc >> c4Cur; \
        aeList[c4Index] = eEnumType(c4Cur); \
    } \
} \
inline tCIDLib::TVoid TBinOutStream_WriteArray(         TBinOutStream&      strmTar \
                                                , const eEnumType* const    aeList \
                                                , const tCIDLib::TCard4     c4Count) \
{ \
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4Count; c4Index++) \
        strmTar << tCIDLib::TCard4(aeList[c4Index]); \
}



#pragma CIDLIB_PACK(CIDLIBPACK)

class TString;

// ---------------------------------------------------------------------------
//  Most of the enums are actually defined in the CIDKernel's types header,
//  for a number of bootstrapping reasons.
// ---------------------------------------------------------------------------
namespace tCIDLib
{
    // -----------------------------------------------------------------------
    //  Used by the standard command line parameter parsing stuff in TSysInfo
    // -----------------------------------------------------------------------
    enum class ECmdLnPTypes
    {
        Value
        , Option
        , OptionVal

        , Count
    };

    enum class ECmdLnPRes
    {
        NotFound
        , BadValue
        , Found

        , Count
    };


    // -----------------------------------------------------------------------
    //  Our CIDLib logging flags. These are used to turn off and on logging in the
    //  stats cache item that our facility object creates. It provides a helper
    //  method to get/set those flags. These enum values are bit indices into the
    //  64 bit stats item value.
    //
    //  - BitsBytes is stuff like bit sequences, byte buffer, bit sets, etc...
    //  - Trace causes all exceptions thrown to be logged.
    //  - ValFormat is stuff like Cardinal, Integer, Money, etc...
    //  - Verbose means that we'll log informational stuff in those sections that
    //    are otherwise enabled by their respective flags. Else only non-info
    //    stuff is logged (in enabled areas.)
    // -----------------------------------------------------------------------
    enum class ELogFlags
    {
        Audio
        , Base64
        , BinStreams
        , BitsBytes
        , Collects
        , Color
        , Coords
        , DataSrc
        , Facility
        , Files
        , FileSystem
        , FundCollects
        , MemBuf
        , Other
        , Processes
        , Speech
        , SearchNSort
        , Strings
        , Synchro
        , TextConvert
        , TextStreams
        , Threads
        , ValFormat
        , Volumes

        , Trace
        , Verbose

        , Count
        , Min       = Audio
        , Max       = Verbose
    };



    // -----------------------------------------------------------------------
    //  Translation methods. In higher level code, these are generated by the IDL
    //  compiler, but we can't use the IDL compiler, so we have to do them manually.
    //  The Xlat ones work on the literal textual names of the enums and the Load
    //  versions load up human readable text for them.
    // -----------------------------------------------------------------------
    CIDLIBEXP tCIDLib::EDirs eXlatEDirs
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP tCIDLib::EErrClasses eXlatEErrClasses
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP tCIDLib::ELogFlags eXlatELogFlags
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP tCIDLib::EHJustify eXlatEHJustify
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP tCIDLib::EHJustify eAltXlatEHJustify
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP tCIDLib::ERadices eXlatERadices
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP tCIDLib::ESeverities eXlatESeverities
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP tCIDLib::EVJustify eXlatEVJustify
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP tCIDLib::EVJustify eAltXlatEVJustify
    (
        const   TString&                strToXlat
    );

    CIDLIBEXP const tCIDLib::TCh* pszXlatEDirs
    (
        const   tCIDLib::EDirs          eToXlat
    );

    CIDLIBEXP const tCIDLib::TCh* pszXlatEErrClasses
    (
        const   tCIDLib::EErrClasses    eToXlat
    );

    CIDLIBEXP const tCIDLib::TCh* pszXlatELogFlags
    (
        const   tCIDLib::ELogFlags      eToXlat
    );

    CIDLIBEXP const tCIDLib::TCh* pszXlatEHJustify
    (
        const   tCIDLib::EHJustify      eToXlat
    );

    CIDLIBEXP const tCIDLib::TCh* pszAltXlatEHJustify
    (
        const   tCIDLib::EHJustify      eToXlat
    );

    CIDLIBEXP const tCIDLib::TCh* pszXlatESeverities
    (
        const   tCIDLib::ESeverities    eToXlat
    );

    CIDLIBEXP const tCIDLib::TCh* pszXlatEVJustify
    (
        const   tCIDLib::EVJustify      eToXlat
    );

    CIDLIBEXP const tCIDLib::TCh* pszAltXlatEVJustify
    (
        const   tCIDLib::EVJustify      eToXlat
    );

    CIDLIBEXP const TString& strLoadEErrClasses
    (
        const   tCIDLib::EErrClasses    eToXlat
    );

    CIDLIBEXP TString strLoadEExitCodes
    (
        const   tCIDLib::EExitCodes     eToXlat
    );

    CIDLIBEXP const TString& strLoadEHJustify
    (
        const   tCIDLib::EHJustify      eToXlat
    );

    CIDLIBEXP const TString& strLoadELanguages
    (
        const   tCIDLib::ELanguages     eToXlat
    );

    CIDLIBEXP const TString& strLoadESeverities
    (
        const   tCIDLib::ESeverities    eToXlat
    );

    CIDLIBEXP const TString& strLoadEVJustify
    (
        const   tCIDLib::EVJustify      eToXlat
    );


    // To support TEArray below
    CIDLIBEXP tCIDLib::TVoid ThrowArrayIndexErr
    (
        const   tCIDLib::TCard4         c4At
        , const tCIDLib::TCard4         c4Size
    );
}


//
//  This let's us create a simple array that can be indexed by a given type, so
//  for arrays intended to be based on an enum, we can use this to avoid having to
//  cast.
//
template
<
    typename ElemType
    , typename IndexType
    , IndexType ListSize
    , const tCIDLib::TCard4 c4Extra = 0> class TEArray
{
    public :
        // -----------------------------------------------------------------------
        //  Public class types
        // -----------------------------------------------------------------------
        using TMyType = TEArray<ElemType, IndexType, ListSize, c4Extra>;


        // -----------------------------------------------------------------------
        //  Constructors and destructors
        // -----------------------------------------------------------------------
        TEArray() = delete;

        #pragma warning(suppress : 26495) // We are going to initialize the array below
        TEArray(const ElemType InitVal) :

            m_c4Size(tCIDLib::TCard4(ListSize) + c4Extra)
        {
            for (tCIDLib::TCard4 c4Index = 0; c4Index < m_c4Size; c4Index++)
                m_aetArray[c4Index] = InitVal;
        }

        #pragma warning(suppress : 26495) // We are going to initialize the array below
        TEArray(const ElemType aValues[tCIDLib::TCard4(ListSize) + c4Extra]) :

            m_atomLoaded(kCIDLib::True)
            , m_c4Size(tCIDLib::TCard4(ListSize) + c4Extra)
        {
            for (tCIDLib::TCard4 c4Index = 0; c4Index < m_c4Size; c4Index++)
                m_aetArray[c4Index] = aValues[c4Index];
        }

        TEArray(const TMyType& eaSrc) :

            m_atomLoaded(eaSrc.m_atomLoaded.bValue())
            , m_c4Size(eaSrc.m_c4Size)
        {
            for (tCIDLib::TCard4 c4Index = 0; c4Index < m_c4Size; c4Index++)
                m_aetArray[c4Index] = eaSrc.m_aetArray[c4Index];
        }

        ~TEArray()
        {
        }


        // -----------------------------------------------------------------------
        //  Public operators
        // -----------------------------------------------------------------------
        TEArray& operator=(const TMyType&) = delete;
        TEArray& operator=(TMyType&&) = delete;

        ElemType& operator[](const IndexType eAt)
        {
            if (tCIDLib::TCard4(eAt) >= m_c4Size)
                tCIDLib::ThrowArrayIndexErr(tCIDLib::TCard4(eAt), m_c4Size);
            return m_aetArray[tCIDLib::TCard4(eAt)];
        }

        const ElemType& operator[](const IndexType eAt) const
        {
            if (tCIDLib::TCard4(eAt) >= m_c4Size)
                tCIDLib::ThrowArrayIndexErr(tCIDLib::TCard4(eAt), m_c4Size);
            return m_aetArray[tCIDLib::TCard4(eAt)];
        }


        // -----------------------------------------------------------------------
        //  Public, non-virtual methods
        // -----------------------------------------------------------------------
        tCIDLib::TBoolean bIsLoaded() const
        {
            return m_atomLoaded.bValue();
        }

        tCIDLib::TVoid SetLoaded()
        {
            m_atomLoaded.Set();
        }


    private :
        // -----------------------------------------------------------------------
        //  Private data members
        // -----------------------------------------------------------------------
        ElemType            m_aetArray[tCIDLib::TCard4(ListSize) + c4Extra];
        TAtomicFlag         m_atomLoaded;
        tCIDLib::TCard4     m_c4Size;
};

#pragma CIDLIB_POPPACK

