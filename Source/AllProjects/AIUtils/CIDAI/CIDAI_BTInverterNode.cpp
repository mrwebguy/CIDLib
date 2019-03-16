//
// FILE NAME: CIDAI_BTInverterNode.cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 12/27/2016
//
// COPYRIGHT: Charmed Quark Systems, Ltd - 2019
//
//  This software is copyrighted by 'Charmed Quark Systems, Ltd' and 
//  the author (Dean Roddey.) It is licensed under the MIT Open Source 
//  license:
//
//  https://opensource.org/licenses/MIT
//
// DESCRIPTION:
//
//  This file implements the inverter node type.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include    "CIDAI_.hpp"
#include    "CIDAI_BTInverterNode_.hpp"


// ---------------------------------------------------------------------------
//  Magic macros
// ---------------------------------------------------------------------------
RTTIDecls(TAIBTInverterNode, TAIBTNode)



// ---------------------------------------------------------------------------
//   CLASS: TAIBTInverterNode
//  PREFIX: btnode
// ---------------------------------------------------------------------------

// -------------------------------------------------------------------
//  TAIBTInverterNode: Constructors and Destructor
// -------------------------------------------------------------------
TAIBTInverterNode::TAIBTInverterNode(const  TString& strPath, const TString& strName) :

    TAIBTNode(strPath, strName, kCIDAI::strDefFact_Inverter, 1, 1)
{
}

TAIBTInverterNode::~TAIBTInverterNode()
{
}


// -------------------------------------------------------------------
//  TAIBTInverterNode: Public, virtual methods
// -------------------------------------------------------------------
tCIDAI::ENodeStates TAIBTInverterNode::eRun(TAIBehaviorTree& btreeOwner)
{
    // Run our one child
    tCIDAI::ENodeStates eRes = eRunChildAt(btreeOwner, 0);

    // And flip the result
    if (eRes == tCIDAI::ENodeStates::Success)
        eRes = tCIDAI::ENodeStates::Failure;
    else if (eRes == tCIDAI::ENodeStates::Failure)
        eRes = tCIDAI::ENodeStates::Success;

    return eRes;
}

