// ----------------------------------------------------------------------------
//  FILE: CIDOrbUC_CfgSrvClientProxy.hpp
//  DATE: Wed, Jun 26 17:43:28 2019 -0400
//    ID: 9BEA088A1BD33D3A-FB3EA0B995167E0E
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------
#pragma once

#pragma CIDLIB_PACK(CIDLIBPACK)

class CIDORBUCEXP TCIDCfgSrvClientProxy : public TOrbClientBase
{
    public :
        // --------------------------------------------------------------------
        // Public, static data
        // --------------------------------------------------------------------
        static const TString strInterfaceId;
        static const TString strScope;
        static const TString strAdminBinding;
        static const TString strBinding;



        // --------------------------------------------------------------------
        // Public Constructors and Destructor
        // --------------------------------------------------------------------
        TCIDCfgSrvClientProxy();
        TCIDCfgSrvClientProxy(const TOrbObjId& ooidSrc, const TString& strNSBinding);
        TCIDCfgSrvClientProxy(const TCIDCfgSrvClientProxy&) = delete;
        ~TCIDCfgSrvClientProxy();

        // --------------------------------------------------------------------
        // Public operators
        // --------------------------------------------------------------------
        TCIDCfgSrvClientProxy& operator=(const TCIDCfgSrvClientProxy&) = delete;

        // --------------------------------------------------------------------
        // Public, inherited methods
        // --------------------------------------------------------------------
        tCIDLib::TVoid SetObjId
        (
            const   TOrbObjId& ooidToSet
            , const TString& strNSBinding
            , const tCIDLib::TBoolean bCheck = kCIDLib::True
        )   override;

        // --------------------------------------------------------------------
        // Public, non-virtual methods
        // --------------------------------------------------------------------
        tCIDLib::TVoid AddObject
        (
            const TString& strKey
            , const tCIDLib::TCard4 c4BufSz_mbufObjData
            , const THeapBuf& mbufObjData
            , const tCIDLib::TCard4 c4Reserve
        );

        tCIDLib::TBoolean bAddOrUpdate
        (
            const TString& strKey
            , tCIDLib::TCard4& c4Version
            , const tCIDLib::TCard4 c4BufSz_mbufObjData
            , const THeapBuf& mbufObjData
            , const tCIDLib::TCard4 c4Reserve
        );

        tCIDLib::TBoolean bAllObjectsUnder
        (
            const TString& strStartScope
            , TVector<TString>& colPathsFound
        );

        tCIDLib::TBoolean bDeleteObjectIfExists
        (
            const TString& strKey
        );

        tCIDLib::TBoolean bFindNameUnder
        (
            const TString& strName
            , const TString& strStartScope
            , TVector<TString>& colPathsFound
        );

        tCIDLib::TBoolean bKeyExists
        (
            const TString& strKey
        );

        tCIDLib::TBoolean bKeyExists2
        (
            const TString& strKey
            , tCIDLib::TCard4& c4Version
        );

        tCIDLib::TBoolean bReadObject
        (
            const TString& strKey
            , tCIDLib::TCard4& c4BufSz_mbufToFill
            , THeapBuf& mbufToFill
            , tCIDLib::TCard4& c4Version
        );

        tCIDLib::TCard4 c4QueryObjectsInScope
        (
            const TString& strParScope
            , TVector<TString>& colToFill
        );

        tCIDLib::TCard4 c4QuerySubScopes
        (
            const TString& strParScope
            , TVector<TString>& colToFill
        );

        tCIDLib::TCard4 c4UpdateObject
        (
            const TString& strKey
            , const tCIDLib::TCard4 c4BufSz_mbufObjData
            , const THeapBuf& mbufObjData
        );

        tCIDLib::TVoid DeleteObject
        (
            const TString& strKey
        );

        tCIDLib::TVoid DeleteScope
        (
            const TString& strScopeKey
        );

        tCIDLib::ELoadRes eReadObject
        (
            const TString& strKey
            , tCIDLib::TCard4& c4BufSz_mbufToFill
            , THeapBuf& mbufToFill
            , tCIDLib::TCard4& c4Version
            , const tCIDLib::TBoolean bThrowIfNot
        );

    protected :
        // --------------------------------------------------------------------
        // Declare our friends
        // --------------------------------------------------------------------
        friend class TFacCIDOrb;

    private :
        // --------------------------------------------------------------------
        // Magic macros
        // --------------------------------------------------------------------
        RTTIDefs(TCIDCfgSrvClientProxy,TOrbClientBase)
};

#pragma CIDLIB_POPPACK

inline tCIDLib::TVoid
TCIDCfgSrvClientProxy::SetObjId(const  TOrbObjId& ooidToSet
              , const TString& strNSBinding
              , const tCIDLib::TBoolean bCheck)
{
    TParent::SetObjId(ooidToSet, strNSBinding, bCheck);
}

