//
// FILE NAME: CIDDBase_Typess.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 09/21/2003
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
//  This is the types header for the CIDDBase facility.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


namespace tCIDDBase
{
    // -----------------------------------------------------------------------
    //  We define some opque structures that each platform driver defines internally
    //  for its own needs. We just need them here so that we can can refer to them
    //  in the classes that wrap these things and so that other wrapper classes can
    //  access them.
    // -----------------------------------------------------------------------
    struct TBindingInfo;
    struct TConnHandle;
    struct TDBEnvHandle;
    struct TStmtHandle;


    // -----------------------------------------------------------------------
    //  The direction of a bound parameter. For now, we just support in parms,
    //  but can expand it later if needed to handle procedure calls.
    // -----------------------------------------------------------------------
    enum class EParmDirs
    {
        In
    };


    // -----------------------------------------------------------------------
    //  The types of data sources available
    // -----------------------------------------------------------------------
    enum class ESrcTypes
    {
        System
        , User
        , Both
    };


    // -----------------------------------------------------------------------
    //  The types of ODBC SQL types and C++ types supported in our bindings
    //  system
    //
    //  NOTE:   Our default character is Unicode, so Char and VarChar are
    //          wide char, and ShortChar and VarShortChar are short chars.
    // -----------------------------------------------------------------------
    enum class ECppTypes
    {
        Boolean
        , Card1
        , Card2
        , Card4
        , Card8
        , Date
        , Int1
        , Int2
        , Int4
        , Int8
        , String
        , Time

        , Count
    };

    enum class ESQLTypes
    {
        None
        , Char
        , Date
        , Decimal
        , Double
        , Float
        , Integer
        , Real
        , ShortChar
        , SmallInt
        , Time
        , TimeStamp
        , TinyInt
        , VarShortChar
        , VarChar

        , Count
    };
}

