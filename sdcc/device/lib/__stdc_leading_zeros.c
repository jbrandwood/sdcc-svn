/*-------------------------------------------------------------------------
   __stdc_leading_zeros.c - part of bit and byte utilitites

   Copyright (c) 2022-2025, Philipp Klaus Krause . philipp@colecovision.eu

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library; see the file COPYING. If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.

   As a special exception, if you link this library with other files,
   some of which are compiled with SDCC, to produce an executable,
   this library does not by itself cause the resulting executable to
   be covered by the GNU General Public License. This exception does
   not however invalidate any other reasons why the executable file
   might be covered by the GNU General Public License.
-------------------------------------------------------------------------*/

#include <stdbit.h>

#include <limits.h>
#include <stdint.h>

static_assert(INT_FAST8_MAX >= ULLONG_WIDTH, "Unsuitable return type");

unsigned _BitInt(8) __stdc_leading_zeros(unsigned long long value, uint_fast8_t width)
{
	for(int_fast8_t i = width - 1; i >= 0; i--)
		if(value & (1ull << i))
			return (width - i - 1);
	return width;
}

