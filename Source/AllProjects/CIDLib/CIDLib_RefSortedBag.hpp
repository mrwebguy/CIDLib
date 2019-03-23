//
// FILE NAME: CIDLib_RefSortedBag.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 03/06/2001
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
//  This header defines a very simple derivative of TRefBag, TRefSortedBag,
//  which just adds the capability to insert new objects in sorted order. All
//  it requires, beyond the usual RTTI and constructor/destructor stuff, is
//  to override the Add() method and find the correct sorted add position.
//
//  The comp function cannot be a capturing lambda because we have no way to
//  specialize a template on a lambda. So we have to define it as a regular
//  function pointer, and we need to have a member of that type as well.
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
//   CLASS: TRefSortedBag
//  PREFIX: col
// ---------------------------------------------------------------------------
template <typename TElem> class TRefSortedBag : public TRefBag<TElem>
{
    public  :
        // -------------------------------------------------------------------
        //  Public types
        // -------------------------------------------------------------------
        using TMyType = TRefSortedBag<TElem>;
        using TCompFunc = tCIDLib::ESortComps (*)(const TElem&, const TElem&);


        // -------------------------------------------------------------------
        //  Constructors and Destructor
        // -------------------------------------------------------------------
        TRefSortedBag() = delete;

        TRefSortedBag(  const   tCIDLib::EAdoptOpts eAdopt
                        ,       TCompFunc           pfnComp
                        , const tCIDLib::ESortDirs  eDir = tCIDLib::ESortDirs::Ascending
                        , const tCIDLib::EMTStates  eMTSafe = tCIDLib::EMTStates::Unsafe) :

            TRefBag<TElem>(eAdopt, eMTSafe)
            , m_eDir(eDir)
            , m_pfnComp(pfnComp)
        {
        }

        TRefSortedBag(const TMyType&) = delete;
        TRefSortedBag(TMyType&&) = delete;

        ~TRefSortedBag()
        {
        }


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TMyType& operator=(const TMyType&) = delete;
        TMyType& operator=(TMyType&&) = delete;


        // -------------------------------------------------------------------
        //  Public, inherited methods
        // -------------------------------------------------------------------
        tCIDLib::TVoid Add(TElem* const pobjToAdd) override
        {
            //
            //  The base class would catch this, but we will deref it below to
            //  find the insert point before we add.
            //
            if (!pobjToAdd)
                this->NullNodeAdded(CID_FILE, CID_LINE);

            // Lock the collection
            TMtxLocker lockCol(this->pmtxLock());

            // Optimize if the bag is empty
            if (this->bIsEmpty())
            {
                this->AddAtTop(pobjToAdd);
                return;
            }

            //
            //  Find the position to put the new element at. We just iterate
            //  the nodes until we find one that is greater than (or less
            //  than if descending) the new object. We then insert the new
            //  element before it.
            //
            TBasicDLinkedRefCol<TElem>::TCursor cursAdd(this);
            while (cursAdd)
            {
                if (m_eDir == tCIDLib::ESortDirs::Ascending)
                {
                    if (m_pfnComp(*cursAdd, *pobjToAdd) != tCIDLib::ESortComps::FirstLess)
                        break;
                }
                 else
                {
                    if (m_pfnComp(*pobjToAdd, *cursAdd) != tCIDLib::ESortComps::FirstLess)
                        break;
                }
                ++cursAdd;
            }

            // If the cursor is invalid, it will go at the end
            this->InsertAfter(pobjToAdd, cursAdd);

            // Invalidate any cursors
            this->c4IncSerialNum();
        }


    private :
        // -------------------------------------------------------------------
        //  Private data members
        //
        //  m_eDir
        //      Indicates whether we are to sort ascending or descending.
        //
        //  m_pfnComp
        //      The comparator function to use for comparing objects to find
        //      their insert position.
        // -------------------------------------------------------------------
        tCIDLib::ESortDirs  m_eDir;
        TCompFunc           m_pfnComp;


        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        TemplateRTTIDefs(TMyType,TRefBag<TElem>)
};

#pragma CIDLIB_POPPACK


