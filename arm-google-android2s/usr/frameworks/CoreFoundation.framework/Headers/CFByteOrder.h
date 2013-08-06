/* CFByteOrder.h
   
   Copyright (C) 2010 Free Software Foundation, Inc.
   
   Written by: Eric Wasylishen
   Date: June, 2010
   
   Most of the code here was copied from NSByteOrder.h in GNUstep-base
   written by Richard Frith-Macdonald.
   
   This file is part of GNUstep CoreBase Library.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/ 

#ifndef __COREFOUNDATION_CFBYTEORDER_H__
#define __COREFOUNDATION_CFBYTEORDER_H__ 1

#include <CoreFoundation/CFBase.h>

typedef enum
{
  CFByteOrderUnknown,
  CFByteOrderLittleEndian,
  CFByteOrderBigEndian
} CFByteOrder;

typedef UInt32 CFSwappedFloat32;  /* Same as GNUstep NSSwappedFloat */
typedef UInt64 CFSwappedFloat64;  /* Same as GNUstep NSSwappedDouble */

CF_INLINE CFByteOrder
CFByteOrderGetCurrent()
{
#if __BIG_ENDIAN__
  return CFByteOrderBigEndian;
#else
  return CFByteOrderLittleEndian;
#endif
}

CF_INLINE UInt16
CFSwapInt16(UInt16 in)
{
  union swap
    {
      UInt16 num;
      UInt8  byt[2];
    } dst;
  union swap *src = (union swap*)&in;
  dst.byt[0] = src->byt[1];
  dst.byt[1] = src->byt[0];
  return dst.num;
}

CF_INLINE UInt32
CFSwapInt32(UInt32 in)
{
  union swap
    {
      UInt32 num;
      UInt8  byt[4];
    } dst;
  union swap *src = (union swap*)&in;
  dst.byt[0] = src->byt[3];
  dst.byt[1] = src->byt[2];
  dst.byt[2] = src->byt[1];
  dst.byt[3] = src->byt[0];
  return dst.num;
}

CF_INLINE UInt64
CFSwapInt64(UInt64 in)
{
  union swap
    {
      UInt64 num;
      UInt8  byt[8];
    } dst;
  union swap *src = (union swap*)&in;
  dst.byt[0] = src->byt[7];
  dst.byt[1] = src->byt[6];
  dst.byt[2] = src->byt[5];
  dst.byt[3] = src->byt[4];
  dst.byt[4] = src->byt[3];
  dst.byt[5] = src->byt[2];
  dst.byt[6] = src->byt[1];
  dst.byt[7] = src->byt[0];
  return dst.num;
}



#if __BIG_ENDIAN__

CF_INLINE UInt16
CFSwapInt16BigToHost(UInt16 in)
{
  return in;
}

CF_INLINE UInt16
CFSwapInt16HostToBig(UInt16 in)
{
  return in;
}
CF_INLINE UInt16
CFSwapInt16HostToLittle(UInt16 in)
{
  return CFSwapInt16(in);
}

CF_INLINE UInt16
CFSwapInt16LittleToHost(UInt16 in)
{
  return CFSwapInt16(in);
}

CF_INLINE UInt32
CFSwapInt32BigToHost(UInt32 in)
{
  return in;
}

CF_INLINE UInt32
CFSwapInt32HostToBig(UInt32 in)
{
  return in;
}

CF_INLINE UInt32
CFSwapInt32HostToLittle(UInt32 in)
{
  return CFSwapInt32(in);
}

CF_INLINE UInt32
CFSwapInt32LittleToHost(UInt32 in)
{
  return CFSwapInt32(in);
}

CF_INLINE UInt64
CFSwapInt64BigToHost(UInt64 in)
{
  return in;
}

CF_INLINE UInt64
CFSwapInt64HostToBig(UInt64 in)
{
  return in;
}

CF_INLINE UInt64
CFSwapInt64HostToLittle(UInt64 in)
{
  return CFSwapInt64(in);
}

CF_INLINE UInt64
CFSwapInt64LittleToHost(UInt64 in)
{
  return CFSwapInt64(in);
}

#else

CF_INLINE UInt16
CFSwapInt16BigToHost(UInt16 in)
{
  return CFSwapInt16(in);
}

CF_INLINE UInt16
CFSwapInt16HostToBig(UInt16 in)
{
  return CFSwapInt16(in);
}
CF_INLINE UInt16
CFSwapInt16HostToLittle(UInt16 in)
{
  return in;
}

CF_INLINE UInt16
CFSwapInt16LittleToHost(UInt16 in)
{
  return in;
}

CF_INLINE UInt32
CFSwapInt32BigToHost(UInt32 in)
{
  return CFSwapInt32(in);
}

CF_INLINE UInt32
CFSwapInt32HostToBig(UInt32 in)
{
  return CFSwapInt32(in);
}

CF_INLINE UInt32
CFSwapInt32HostToLittle(UInt32 in)
{
  return in;
}

CF_INLINE UInt32
CFSwapInt32LittleToHost(UInt32 in)
{
  return in;
}

CF_INLINE UInt64
CFSwapInt64BigToHost(UInt64 in)
{
  return CFSwapInt64(in);
}

CF_INLINE UInt64
CFSwapInt64HostToBig(UInt64 in)
{
  return CFSwapInt64(in);
}

CF_INLINE UInt64
CFSwapInt64HostToLittle(UInt64 in)
{
  return in;
}

CF_INLINE UInt64
CFSwapInt64LittleToHost(UInt64 in)
{
  return in;
}

#endif



union dconv
{
  double           d;
  Float64          num;
  CFSwappedFloat64 sf;
};

union fconv
{
  float            f;
  Float32          num;
  CFSwappedFloat32 sf;
};

CF_INLINE CFSwappedFloat64
CFConvertFloat64HostToSwapped (Float64 in)
{
  union dconv conv;
  conv.num = in;
  return CFSwapInt64 (conv.sf);
}

CF_INLINE Float64
CFConvertFloat64SwappedToHost (CFSwappedFloat64 in)
{
  union dconv conv;
  conv.sf = CFSwapInt64 (in);
  return conv.num;
}

CF_INLINE CFSwappedFloat64
CFConvertDoubleHostToSwapped (double in)
{
  union dconv conv;
  conv.d = in;
  return CFSwapInt64 (conv.sf);
}

CF_INLINE double
CFConvertDoubleSwappedToHost(CFSwappedFloat64 in)
{
  union dconv conv;
  conv.sf = CFSwapInt64 (in);
  return conv.d;
}

CF_INLINE CFSwappedFloat32
CFConvertFloat32HostToSwapped(Float32 in)
{
  union fconv conv;
  conv.num = in;
  return CFSwapInt32 (conv.sf);
}

CF_INLINE Float32
CFConvertFloat32SwappedToHost(CFSwappedFloat32 in)
{
  union fconv conv;
  conv.sf = CFSwapInt32 (in);
  return conv.num;
}

CF_INLINE CFSwappedFloat32
CFConvertFloatHostToSwapped(float in)
{
  union fconv conv;
  conv.f = in;
  return CFSwapInt32 (conv.sf);
}

CF_INLINE float
CFConvertFloatSwappedToHost(CFSwappedFloat32 in)
{
  union fconv conv;
  conv.sf = CFSwapInt32 (in);
  return conv.f;
}

#endif /* __COREFOUNDATION_CFBYTEORDER_H__ */

