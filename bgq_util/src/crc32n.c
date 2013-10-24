/* begin_generated_IBM_copyright_prolog                             */
/*                                                                  */
/* This is an automatically generated copyright prolog.             */
/* After initializing,  DO NOT MODIFY OR MOVE                       */
/* ================================================================ */
/*                                                                  */
/* Licensed Materials - Property of IBM                             */
/*                                                                  */
/* Blue Gene/Q                                                      */
/*                                                                  */
/* (C) Copyright IBM Corp.  2010, 2012                              */
/*                                                                  */
/* US Government Users Restricted Rights -                          */
/* Use, duplication or disclosure restricted                        */
/* by GSA ADP Schedule Contract with IBM Corp.                      */
/*                                                                  */
/* This software is available to you under the                      */
/* Eclipse Public License (EPL).                                    */
/*                                                                  */
/* ================================================================ */
/*                                                                  */
/* end_generated_IBM_copyright_prolog                               */

#include "crc32n.h"

#if !defined(__ASSEMBLY__) && defined(__cplusplus)
extern "C" {
#endif

//////////////////////////////////////////////////////
//
// This file contains the function to generate a 32 bit
// CRC utilizing a 16 entry table.
//
//
// The CRC polynomial used here is:
//
// x^32 + x^26 + x^23 + x^22 + x^16 +
// x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^1 + x^0
//
//
//

static unsigned long Crc32x4_Table[16] = {
    0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
    0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
    0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
    0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
};


///////////////////////////////////////////////////////////
unsigned long Crc32n(unsigned long ulInitialCrc,
                     unsigned char *pData,
                     unsigned long ulLen)
//
// Calcuate the CRC for a given buffer of data.
// To do just one buffer start with an ulInitialCrc of 0.
// To continue a multibuffer CRC provide the value
// returned from the last call to Crc32n as the ulInitialCrcValue.
//
// inputs:
//    ulInitialCrc -- initial value for the CRC.
//    pData -- pointer to the data to calculate the CRC for.
//    ulLen -- length of the data to calculate the CRC for.
// outputs:
//    returns -- the CRC of the buffer.
//
//
{
    unsigned long n;
    unsigned long t;
    unsigned char *p;
    unsigned long ulCrc= ulInitialCrc;


    for (n = ulLen, p = pData;
         n > 0;
         n--, p++)
    {
        unsigned char c;
        c = *p;                     // gbrab the character.


        t = ulCrc ^ (c & 0x0f);                         // lower nibble
        ulCrc = (ulCrc>>4) ^ Crc32x4_Table[t & 0xf];
        t = ulCrc ^ (c>>4);                             // upper nibble.
        ulCrc = (ulCrc>>4) ^ Crc32x4_Table[t & 0xf];
    }

    return(ulCrc);
}

#if !defined(__ASSEMBLY__) && defined(__cplusplus)
}
#endif

