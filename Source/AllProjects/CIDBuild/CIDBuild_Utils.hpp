//
// FILE NAME: CIDBuild_Utils.Hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 08/21/1998
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
//  This is the header for the CIDBuild_Utils.Cpp file, which just provides
//  some grunt work utility functions.
//
// CAVEATS/GOTCHAS:
//
//  1)  This file contains almost all of the conditional code in the whole
//      program. There is a little in the main header and a little in the
//      tools driver class. But this is where most of it is, since we have
//      to abstract some system specific functionality here.
//
// LOG:
//
//  $_CIDLib_Log_$
//

// ---------------------------------------------------------------------------
//  Forward references
// ---------------------------------------------------------------------------
class TFindInfo;
template <typename T> class TList;


// ---------------------------------------------------------------------------
//  The TUtils namepace
// ---------------------------------------------------------------------------
namespace TUtils
{
    //
    //  These are platform independent, or implemented in terms of other
    //  per-platform stuff.
    //
    tCIDLib::TBoolean bCopyAll
    (
        const   TBldStr&                    strSrcDir
        , const TBldStr&                    strTargetDir
    );

    tCIDLib::TBoolean bCopyFile
    (
        const   TBldStr&                    strSourceName
        , const TBldStr&                    strSourceDir
        , const TBldStr&                    strTargetName
        , const TBldStr&                    strTargetDir
        , const tCIDLib::TBoolean           bFailIfExists = false
    );

    tCIDLib::TBoolean bFindNVParts
    (
        const   TBldStr&                    strSource
        ,       TBldStr&                    strName
        ,       TBldStr&                    strValue
    );

    tCIDLib::TBoolean bIsHppFile
    (
        const   TBldStr&                    strFileName
    );

    tCIDLib::TBoolean bIsPrivateHeader
    (
        const   TBldStr&                    strToTest
    );

    tCIDLib::TBoolean bReplicateTree
    (
        const   TBldStr&                    strSrcDir
        , const TBldStr&                    strTargetDir
    );

    tCIDLib::TBoolean bUpdateOutputFile
    (
        const   TBldStr&                    strNewFile
        , const TBldStr&                    strOldFile
    );

    tCIDLib::TBoolean bXlatBool
    (
        const   TBldStr&                    strValue
        ,       tCIDLib::TBoolean&          bToFill
    );

    tCIDLib::TVoid CompletePath
    (
        const   TBldStr&                    strWCSpec
        , const TBldStr&                    strFileFound
        ,       TBldStr&                    strFullName
    );

    tCIDLib::TVoid FindPathParts
    (
        const   TBldStr&                    strSource
        ,       tCIDLib::TCard4&            c4Name
        ,       tCIDLib::TCard4&            c4Extension
    );



    //
    //  These are per-platform, and implemented in each per-platform
    //  directory.
    //
    tCIDLib::TBoolean bExists
    (
        const   TBldStr&                    strFile
    );

    tCIDLib::TBoolean bChangeDir
    (
        const   TBldStr&                    strChangeTo
    );

    tCIDLib::TBoolean bCmpBufs
    (
        const   tCIDLib::TCard1* const      pc1Buf1
        , const tCIDLib::TCard1* const      pc1Buf2
        , const tCIDLib::TCard4             c4Count
    );

    tCIDLib::TBoolean bCopyFile
    (
        const   TBldStr&                    strSourceName
        , const TBldStr&                    strTargetName
        , const tCIDLib::TBoolean           bFailIfExists = false
    );

    tCIDLib::TBoolean bDeleteFile
    (
        const   TBldStr&                    strToDelete
    );

    tCIDLib::TBoolean bExec
    (
        const   tCIDLib::TCh**              apszParams
        , const tCIDLib::TCard4             c4Count
        ,       tCIDLib::TCard4&            c4Result
        , const tCIDLib::TCard4             c4Flags
    );

    tCIDLib::TBoolean bGetEnvVar
    (
        const   TBldStr&                    strVarName
        ,       TBldStr&                    strToFill
    );

    tCIDLib::TBoolean bIsFQPath
    (
        const   TBldStr&                    strFileName
    );

    tCIDLib::TBoolean bMakeDir
    (
        const   TBldStr&                    strToMake
    );

    tCIDLib::TBoolean bMakePath
    (
        const   TBldStr&                    strParent
        , const TBldStr&                    strToMake
    );

    tCIDLib::TBoolean bParseInclExclLists
    (
        const   TBldStr&                    strSrc
        ,       tCIDBuild::TStrList&        listProjIncl
        ,       tCIDBuild::TStrList&        listProjExcl
        ,       TBldStr&                    strError
    );

    tCIDLib::TBoolean bParseInclExclLists
    (
                tCIDBuild::TStrList::TCursor& cusrSrc
        ,       tCIDBuild::TStrList&        listProjIncl
        ,       tCIDBuild::TStrList&        listProjExcl
        ,       TBldStr&                    strError
    );

    tCIDLib::TBoolean bRunCmdLine
    (
        const   TBldStr&                    strToRun
        ,       tCIDLib::TCard4&            c4Result
        , const tCIDLib::TBoolean           bLowPrio = kCIDLib::False
    );

    tCIDLib::TBoolean bSupportsPlatform
    (
        const   TBldStr&                    strToCheck
        , const tCIDBuild::TStrList&        listInclude
        , const tCIDBuild::TStrList&        listExclude
    );

    tCIDLib::TBoolean bSupportsThisPlatform
    (
        const   tCIDBuild::TStrList&        listInclude
        , const tCIDBuild::TStrList&        listExclude
    );

    tCIDLib::TBoolean bTokenize
    (
        const   TBldStr&                    strSrc
        , const TBldStr&                    strSpecial
        , const TBldStr&                    strSpace
        ,       tCIDBuild::TStrList&        listTokens
    );

    tCIDLib::TVoid Beep
    (
        const   tCIDLib::TCard4             c4Freq
        , const tCIDLib::TCard4             c4Duration
    );

    tCIDLib::TCard4 c4CPUCount();

    tCIDLib::TVoid CompletePath
    (
        const   TBldStr&                    strOrgName
        ,       TBldStr&                    strFullName
    );

    tCIDLib::TVoid QueryCurDir
    (
                TBldStr&                    strToFill
    );

    tCIDLib::TVoid SetEnvVar
    (
        const   TBldStr&                    strVarName
        , const TBldStr&                    strValue
    );
}

