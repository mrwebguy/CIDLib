// ----------------------------------------------------------------------------
//  FILE: CIDOrbUC_LogSrvClientProxy.cpp
//  DATE: Mon, Dec 02 17:25:35 2019 -0500
//    ID: 7F1112BEFF72CF9A-1A3600EA74289F30
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "CIDOrbUC_.hpp"

// ----------------------------------------------------------------------------
// Magic macros
// ----------------------------------------------------------------------------
AdvRTTIDecls(TCIDLogSrvClientProxy,TOrbClientBase)


// ----------------------------------------------------------------------------
// TCIDLogSrvClientProxy: Public, static data
// ----------------------------------------------------------------------------
const TString TCIDLogSrvClientProxy::strInterfaceId(L"7F1112BEFF72CF9A-1A3600EA74289F30");
const TString TCIDLogSrvClientProxy::strScope(L"/CIDLib/CIDLogSrv");
const TString TCIDLogSrvClientProxy::strAdminBinding(L"/CIDLib/CIDLogSrv/CoreAdmin");
const TString TCIDLogSrvClientProxy::strBinding(L"/CIDLib/CIDLogSrv/LogObj");



// ----------------------------------------------------------------------------
// TCIDLogSrvClientProxy: Constructors and Destructor
// ----------------------------------------------------------------------------
TCIDLogSrvClientProxy::TCIDLogSrvClientProxy()
{
}

TCIDLogSrvClientProxy::
TCIDLogSrvClientProxy(const TOrbObjId& ooidSrc, const TString& strNSBinding)
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

TCIDLogSrvClientProxy::~TCIDLogSrvClientProxy()
{
}

// ----------------------------------------------------------------------------
// TCIDLogSrvClientProxy: Public, non-virtual methods
// ----------------------------------------------------------------------------
tCIDLib::TBoolean TCIDLogSrvClientProxy::bGetLiveEvents
(
    tCIDLib::TCard4& c4NextEventId
    , TVector<TLogEvent>& colToFill)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bGetLiveEvents");
        ocmdToUse.strmOut() << c4NextEventId;
        Dispatch(10000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        if (retVal)
        {
            ocmdToUse.strmIn() >> c4NextEventId;
            ocmdToUse.strmIn() >> colToFill;
        }
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

tCIDLib::TCard4 TCIDLogSrvClientProxy::c4QueryEvents
(
    TVector<TLogEvent>& colToFill
    , const tCIDLib::TCard4 c4MaxToReturn)
{
    tCIDLib::TCard4 retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"c4QueryEvents");
        ocmdToUse.strmOut() << c4MaxToReturn;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> colToFill;
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

tCIDLib::TCard4 TCIDLogSrvClientProxy::c4QueryEvents
(
    TVector<TLogEvent>& colToFill
    , const tCIDLib::TCard4 c4Minutes
    , const tCIDLib::TCard4 c4MaxToReturn)
{
    tCIDLib::TCard4 retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"c4QueryEvents1");
        ocmdToUse.strmOut() << c4Minutes;
        ocmdToUse.strmOut() << c4MaxToReturn;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> colToFill;
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

tCIDLib::TCard4 TCIDLogSrvClientProxy::c4QueryEvents
(
    TVector<TLogEvent>& colToFill
    , const tCIDLib::TCard4 c4MaxToReturn
    , const TString& strHostExpr
    , const TString& strProcExpr
    , const TString& strFacExpr
    , const TString& strThreadExpr
    , const tCIDLib::TCard8 c8SevLevels
    , const tCIDLib::TCard8 c8ErrClasses)
{
    tCIDLib::TCard4 retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"c4QueryEvents2");
        ocmdToUse.strmOut() << c4MaxToReturn;
        ocmdToUse.strmOut() << strHostExpr;
        ocmdToUse.strmOut() << strProcExpr;
        ocmdToUse.strmOut() << strFacExpr;
        ocmdToUse.strmOut() << strThreadExpr;
        ocmdToUse.strmOut() << c8SevLevels;
        ocmdToUse.strmOut() << c8ErrClasses;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> colToFill;
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

tCIDLib::TVoid TCIDLogSrvClientProxy::DebugDump
(
    tCIDLib::TCard4& c4BufSz_mbufData
    , THeapBuf& mbufData)
{
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"DebugDump");
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> c4BufSz_mbufData;
        ocmdToUse.strmIn().c4ReadBuffer(mbufData, c4BufSz_mbufData);
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
}

tCIDLib::TVoid TCIDLogSrvClientProxy::LogSingle
(
    const TLogEvent& logevToSend)
{
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"LogSingle");
        ocmdToUse.strmOut() << logevToSend;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
}

tCIDLib::TVoid TCIDLogSrvClientProxy::LogMultiple
(
    const TBag<TLogEvent>& colErrors)
{
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"LogMultiple");
        ocmdToUse.strmOut() << colErrors;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
}

tCIDLib::TVoid TCIDLogSrvClientProxy::RemoveAll()
{
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"RemoveAll");
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
}

