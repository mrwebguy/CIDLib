//
// FILE NAME: CIDEncode_ISO8859_6.cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 05/29/1999
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
//  This file implements the TLatin6Converter class, which handles converting
//  the Latin-1 encoding to and from the internal Unicode format. We really
//  just have to provide it the mapping arrays.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//

// ---------------------------------------------------------------------------
//  Facility specific includes
// ---------------------------------------------------------------------------
#include    "CIDEncode_.hpp"



// ---------------------------------------------------------------------------
//  Magic RTTI macros. We support advanced RTTI so that converters can be
//  created by class name.
// ---------------------------------------------------------------------------
AdvRTTIDecls(TLatin6Converter,TMode1EncodingBase)



namespace CIDEncode_ISO8859_2
{
    // -----------------------------------------------------------------------
    //  Local const data
    //
    //  achFromMap
    //      This is the 'from' map that maps from the external encoding to the
    //      internal Unicode encoding. External code point X is used to index
    //      the table, and that entry holds the equivalent Unicode value. If
    //      there is no legal external code point at that index, its 0xFFFF.
    //
    //  achToMap
    //      This is the table that maps from the internal Unicode encoding to
    //      the external encoding. The table is sorted by the Unicode value.
    //
    //  c1RepChar
    //      This is the replacement char, which is used to represent Unicode
    //      values that cannot be represented, if converter is set up to do
    //      that.
    //
    //  c4ToMapSize
    //      This is the number of entries in the 'to' map. Since there can be
    //      more than one Unicode value that maps to a particular external
    //      code point, its not just a 256 entry table.
    // -----------------------------------------------------------------------
    const tCIDLib::TCh achFromMap[256] =
    {
        0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007
      , 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F
      , 0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017
      , 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F
      , 0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027
      , 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F
      , 0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037
      , 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F
      , 0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047
      , 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F
      , 0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057
      , 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F
      , 0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067
      , 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F
      , 0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077
      , 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x007F
      , 0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087
      , 0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F
      , 0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097
      , 0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F
      , 0x00A0, 0xFFFF, 0xFFFF, 0xFFFF, 0x00A4, 0xFFFF, 0xFFFF, 0xFFFF
      , 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x060C, 0x00AD, 0xFFFF, 0xFFFF
      , 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
      , 0xFFFF, 0xFFFF, 0xFFFF, 0x061B, 0xFFFF, 0xFFFF, 0xFFFF, 0x061F
      , 0xFFFF, 0x0621, 0x0622, 0x0623, 0x0624, 0x0625, 0x0626, 0x0627
      , 0x0628, 0x0629, 0x062A, 0x062B, 0x062C, 0x062D, 0x062E, 0x062F
      , 0x0630, 0x0631, 0x0632, 0x0633, 0x0634, 0x0635, 0x0636, 0x0637
      , 0x0638, 0x0639, 0x063A, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
      , 0x0640, 0x0641, 0x0642, 0x0643, 0x0644, 0x0645, 0x0646, 0x0647
      , 0x0648, 0x0649, 0x064A, 0x064B, 0x064C, 0x064D, 0x064E, 0x064F
      , 0x0650, 0x0651, 0x0652, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
      , 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
    };
    const tCIDEncode::TCharMap acmToMap[] =
    {
        { 0x0000, 0x00 }, { 0x0001, 0x01 }, { 0x0002, 0x02 }, { 0x0003, 0x03 }
      , { 0x0004, 0x04 }, { 0x0005, 0x05 }, { 0x0006, 0x06 }, { 0x0007, 0x07 }
      , { 0x0008, 0x08 }, { 0x0009, 0x09 }, { 0x000A, 0x0A }, { 0x000B, 0x0B }
      , { 0x000C, 0x0C }, { 0x000D, 0x0D }, { 0x000E, 0x0E }, { 0x000F, 0x0F }
      , { 0x0010, 0x10 }, { 0x0011, 0x11 }, { 0x0012, 0x12 }, { 0x0013, 0x13 }
      , { 0x0014, 0x14 }, { 0x0015, 0x15 }, { 0x0016, 0x16 }, { 0x0017, 0x17 }
      , { 0x0018, 0x18 }, { 0x0019, 0x19 }, { 0x001A, 0x1A }, { 0x001B, 0x1B }
      , { 0x001C, 0x1C }, { 0x001D, 0x1D }, { 0x001E, 0x1E }, { 0x001F, 0x1F }
      , { 0x0020, 0x20 }, { 0x0021, 0x21 }, { 0x0022, 0x22 }, { 0x0023, 0x23 }
      , { 0x0024, 0x24 }, { 0x0025, 0x25 }, { 0x0026, 0x26 }, { 0x0027, 0x27 }
      , { 0x0028, 0x28 }, { 0x0029, 0x29 }, { 0x002A, 0x2A }, { 0x002B, 0x2B }
      , { 0x002C, 0x2C }, { 0x002D, 0x2D }, { 0x002E, 0x2E }, { 0x002F, 0x2F }
      , { 0x0030, 0x30 }, { 0x0031, 0x31 }, { 0x0032, 0x32 }, { 0x0033, 0x33 }
      , { 0x0034, 0x34 }, { 0x0035, 0x35 }, { 0x0036, 0x36 }, { 0x0037, 0x37 }
      , { 0x0038, 0x38 }, { 0x0039, 0x39 }, { 0x003A, 0x3A }, { 0x003B, 0x3B }
      , { 0x003C, 0x3C }, { 0x003D, 0x3D }, { 0x003E, 0x3E }, { 0x003F, 0x3F }
      , { 0x0040, 0x40 }, { 0x0041, 0x41 }, { 0x0042, 0x42 }, { 0x0043, 0x43 }
      , { 0x0044, 0x44 }, { 0x0045, 0x45 }, { 0x0046, 0x46 }, { 0x0047, 0x47 }
      , { 0x0048, 0x48 }, { 0x0049, 0x49 }, { 0x004A, 0x4A }, { 0x004B, 0x4B }
      , { 0x004C, 0x4C }, { 0x004D, 0x4D }, { 0x004E, 0x4E }, { 0x004F, 0x4F }
      , { 0x0050, 0x50 }, { 0x0051, 0x51 }, { 0x0052, 0x52 }, { 0x0053, 0x53 }
      , { 0x0054, 0x54 }, { 0x0055, 0x55 }, { 0x0056, 0x56 }, { 0x0057, 0x57 }
      , { 0x0058, 0x58 }, { 0x0059, 0x59 }, { 0x005A, 0x5A }, { 0x005B, 0x5B }
      , { 0x005C, 0x5C }, { 0x005D, 0x5D }, { 0x005E, 0x5E }, { 0x005F, 0x5F }
      , { 0x0060, 0x60 }, { 0x0061, 0x61 }, { 0x0062, 0x62 }, { 0x0063, 0x63 }
      , { 0x0064, 0x64 }, { 0x0065, 0x65 }, { 0x0066, 0x66 }, { 0x0067, 0x67 }
      , { 0x0068, 0x68 }, { 0x0069, 0x69 }, { 0x006A, 0x6A }, { 0x006B, 0x6B }
      , { 0x006C, 0x6C }, { 0x006D, 0x6D }, { 0x006E, 0x6E }, { 0x006F, 0x6F }
      , { 0x0070, 0x70 }, { 0x0071, 0x71 }, { 0x0072, 0x72 }, { 0x0073, 0x73 }
      , { 0x0074, 0x74 }, { 0x0075, 0x75 }, { 0x0076, 0x76 }, { 0x0077, 0x77 }
      , { 0x0078, 0x78 }, { 0x0079, 0x79 }, { 0x007A, 0x7A }, { 0x007B, 0x7B }
      , { 0x007C, 0x7C }, { 0x007D, 0x7D }, { 0x007E, 0x7E }, { 0x007F, 0x7F }
      , { 0x0080, 0x80 }, { 0x0081, 0x81 }, { 0x0082, 0x82 }, { 0x0083, 0x83 }
      , { 0x0084, 0x84 }, { 0x0085, 0x85 }, { 0x0086, 0x86 }, { 0x0087, 0x87 }
      , { 0x0088, 0x88 }, { 0x0089, 0x89 }, { 0x008A, 0x8A }, { 0x008B, 0x8B }
      , { 0x008C, 0x8C }, { 0x008D, 0x8D }, { 0x008E, 0x8E }, { 0x008F, 0x8F }
      , { 0x0090, 0x90 }, { 0x0091, 0x91 }, { 0x0092, 0x92 }, { 0x0093, 0x93 }
      , { 0x0094, 0x94 }, { 0x0095, 0x95 }, { 0x0096, 0x96 }, { 0x0097, 0x97 }
      , { 0x0098, 0x98 }, { 0x0099, 0x99 }, { 0x009A, 0x9A }, { 0x009B, 0x9B }
      , { 0x009C, 0x9C }, { 0x009D, 0x9D }, { 0x009E, 0x9E }, { 0x009F, 0x9F }
      , { 0x00A0, 0xA0 }, { 0x00A4, 0xA4 }, { 0x00AD, 0xAD }, { 0x060C, 0xAC }
      , { 0x061B, 0xBB }, { 0x061F, 0xBF }, { 0x0621, 0xC1 }, { 0x0622, 0xC2 }
      , { 0x0623, 0xC3 }, { 0x0624, 0xC4 }, { 0x0625, 0xC5 }, { 0x0626, 0xC6 }
      , { 0x0627, 0xC7 }, { 0x0628, 0xC8 }, { 0x0629, 0xC9 }, { 0x062A, 0xCA }
      , { 0x062B, 0xCB }, { 0x062C, 0xCC }, { 0x062D, 0xCD }, { 0x062E, 0xCE }
      , { 0x062F, 0xCF }, { 0x0630, 0xD0 }, { 0x0631, 0xD1 }, { 0x0632, 0xD2 }
      , { 0x0633, 0xD3 }, { 0x0634, 0xD4 }, { 0x0635, 0xD5 }, { 0x0636, 0xD6 }
      , { 0x0637, 0xD7 }, { 0x0638, 0xD8 }, { 0x0639, 0xD9 }, { 0x063A, 0xDA }
      , { 0x0640, 0xE0 }, { 0x0641, 0xE1 }, { 0x0642, 0xE2 }, { 0x0643, 0xE3 }
      , { 0x0644, 0xE4 }, { 0x0645, 0xE5 }, { 0x0646, 0xE6 }, { 0x0647, 0xE7 }
      , { 0x0648, 0xE8 }, { 0x0649, 0xE9 }, { 0x064A, 0xEA }, { 0x064B, 0xEB }
      , { 0x064C, 0xEC }, { 0x064D, 0xED }, { 0x064E, 0xEE }, { 0x064F, 0xEF }
      , { 0x0650, 0xF0 }, { 0x0651, 0xF1 }, { 0x0652, 0xF2 }
    };
    const tCIDLib::TCard1 c1RepChar = 0x20;
    const tCIDLib::TCard4 c4ToMapSize = tCIDLib::c4ArrayElems(acmToMap);
}



// ---------------------------------------------------------------------------
//  TLatin6Converter: Constructors and Destructor
// ---------------------------------------------------------------------------
TLatin6Converter::TLatin6Converter() :

    TMode1EncodingBase
    (
        L"ISO-8859-6"
        , CIDEncode_ISO8859_2::achFromMap
        , CIDEncode_ISO8859_2::acmToMap
        , CIDEncode_ISO8859_2::c4ToMapSize
    )
{
}

TLatin6Converter::TLatin6Converter(const TLatin6Converter& tcvtToCopy) :

    TMode1EncodingBase(tcvtToCopy)
{
}

TLatin6Converter::~TLatin6Converter()
{
}


// ---------------------------------------------------------------------------
//  TLatin6Converter: Constructors and Destructor
// ---------------------------------------------------------------------------
TLatin6Converter&
TLatin6Converter::operator=(const TLatin6Converter& tcvtToAssign)
{
    if (this == &tcvtToAssign)
        return *this;

    TParent::operator=(tcvtToAssign);
    return *this;
}

