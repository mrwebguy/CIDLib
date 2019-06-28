// ----------------------------------------------------------------------------
//  FILE: ORB1SampC_IntfClientProxy.cpp
//  DATE: Wed, Jun 26 17:43:29 2019 -0400
//    ID: E1CCC9CBCFA1FDAF-29A8F7CB04763265
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "ORB1SampC.hpp"

// ----------------------------------------------------------------------------
// Magic macros
// ----------------------------------------------------------------------------
AdvRTTIDecls(TORB1SampClientProxy,TOrbClientBase)


// ----------------------------------------------------------------------------
// TORB1SampClientProxy: Public, static data
// ----------------------------------------------------------------------------
const TString TORB1SampClientProxy::strInterfaceId(L"E1CCC9CBCFA1FDAF-29A8F7CB04763265");
const TString TORB1SampClientProxy::strBinding(L"/ORB1Samp/IntfImpl");



// ----------------------------------------------------------------------------
// TORB1SampClientProxy: Constructors and Destructor
// ----------------------------------------------------------------------------
TORB1SampClientProxy::TORB1SampClientProxy()
{
}

TORB1SampClientProxy::
TORB1SampClientProxy(const TOrbObjId& ooidSrc, const TString& strNSBinding)
{
    #if CID_DEBUG_ON
    if (!ooidSrc.oidKey().bIsInterfaceId(strInterfaceId))
    {
        facCIDOrb().ThrowErr
        (
            CID_FILE
            , CID_LINE
            , kOrbErrs::errcClient_BadIntfId
            , tCIDLib::ESeverities::Failed
            , tCIDLib::EErrClasses::BadParms
            , ooidSrc.oidKey().mhashInterface()
            , strInterfaceId
        );
    }
    #endif
    SetObjId(ooidSrc, strNSBinding, kCIDLib::False);
}

TORB1SampClientProxy::~TORB1SampClientProxy()
{
}

// ----------------------------------------------------------------------------
// TORB1SampClientProxy: Public, non-virtual methods
// ----------------------------------------------------------------------------
tCIDLib::TBoolean TORB1SampClientProxy::bQueryByName
(
    const TString& strToFind
    , TORB1SampRec& recFound)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bQueryByName");
        ocmdToUse.strmOut() << strToFind;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> recFound;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TBoolean TORB1SampClientProxy::bQueryAllStatus
(
    const tORB1SampSh::EStatus eToFind
    , TVector<TORB1SampRec>& colFound)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bQueryAllStatus");
        ocmdToUse.strmOut() << eToFind;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> colFound;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

