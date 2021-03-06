//
// FILE NAME: CIDGraphDev_InfoDevice.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 05/27/1997
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
//  This is the header for the CIDGraphDev_InfoDevice.cpp file. This file
//  implements the TGraphInfoDev class, which is a derivative of the base
//  device class that is used for information gathering. It should be very
//  low overhead on most platforms.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


#pragma CIDLIB_PACK(CIDLIBPACK)

// ---------------------------------------------------------------------------
//  CLASS: TGraphInfoDev
// PREFIX: gdev
// ---------------------------------------------------------------------------
class CIDGRDEVEXP TGraphInfoDev : public TGraphicDevice
{
    public  :
        // -------------------------------------------------------------------
        // Constructors and Destructor
        // -------------------------------------------------------------------
        TGraphInfoDev() = delete;

        TGraphInfoDev
        (
            const   TString&                strDriveName
            , const TString&                strDeviceName
        );

        TGraphInfoDev(const TGraphInfoDev&) = delete;

        ~TGraphInfoDev();


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TGraphInfoDev& operator=(const TGraphInfoDev&) = delete;


    private :
        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TGraphInfoDev,TGraphicDevice)
};

#pragma CIDLIB_POPPACK

