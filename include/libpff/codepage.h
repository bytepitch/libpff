/*
 * Codepage definitions for libpff
 *
 * Copyright (C) 2008-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBPFF_CODEPAGE_H )
#define _LIBPFF_CODEPAGE_H

#include <libpff/types.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* The codepage definitions
 */
enum LIBPFF_CODEPAGES
{
	LIBPFF_CODEPAGE_ASCII				= 20127,

	LIBPFF_CODEPAGE_ISO_8859_1			= 28591,
	LIBPFF_CODEPAGE_ISO_8859_2			= 28592,
	LIBPFF_CODEPAGE_ISO_8859_3			= 28593,
	LIBPFF_CODEPAGE_ISO_8859_4			= 28594,
	LIBPFF_CODEPAGE_ISO_8859_5			= 28595,
	LIBPFF_CODEPAGE_ISO_8859_6			= 28596,
	LIBPFF_CODEPAGE_ISO_8859_7			= 28597,
	LIBPFF_CODEPAGE_ISO_8859_8			= 28598,
	LIBPFF_CODEPAGE_ISO_8859_9			= 28599,
	LIBPFF_CODEPAGE_ISO_8859_10			= 28600,
	LIBPFF_CODEPAGE_ISO_8859_11			= 28601,
	LIBPFF_CODEPAGE_ISO_8859_13			= 28603,
	LIBPFF_CODEPAGE_ISO_8859_14			= 28604,
	LIBPFF_CODEPAGE_ISO_8859_15			= 28605,
	LIBPFF_CODEPAGE_ISO_8859_16			= 28606,

	LIBPFF_CODEPAGE_KOI8_R				= 20866,
	LIBPFF_CODEPAGE_KOI8_U				= 21866,

	LIBPFF_CODEPAGE_WINDOWS_874			= 874,
	LIBPFF_CODEPAGE_WINDOWS_932			= 932,
	LIBPFF_CODEPAGE_WINDOWS_936			= 936,
	LIBPFF_CODEPAGE_WINDOWS_949			= 949,
	LIBPFF_CODEPAGE_WINDOWS_950			= 950,
	LIBPFF_CODEPAGE_WINDOWS_1250			= 1250,
	LIBPFF_CODEPAGE_WINDOWS_1251			= 1251,
	LIBPFF_CODEPAGE_WINDOWS_1252			= 1252,
	LIBPFF_CODEPAGE_WINDOWS_1253			= 1253,
	LIBPFF_CODEPAGE_WINDOWS_1254			= 1254,
	LIBPFF_CODEPAGE_WINDOWS_1255			= 1255,
	LIBPFF_CODEPAGE_WINDOWS_1256			= 1256,
	LIBPFF_CODEPAGE_WINDOWS_1257			= 1257,
	LIBPFF_CODEPAGE_WINDOWS_1258			= 1258
};

#define LIBPFF_CODEPAGE_US_ASCII			LIBPFF_CODEPAGE_ASCII

#define LIBPFF_CODEPAGE_ISO_WESTERN_EUROPEAN		LIBPFF_CODEPAGE_ISO_8859_1
#define LIBPFF_CODEPAGE_ISO_CENTRAL_EUROPEAN		LIBPFF_CODEPAGE_ISO_8859_2
#define LIBPFF_CODEPAGE_ISO_SOUTH_EUROPEAN		LIBPFF_CODEPAGE_ISO_8859_3
#define LIBPFF_CODEPAGE_ISO_NORTH_EUROPEAN		LIBPFF_CODEPAGE_ISO_8859_4
#define LIBPFF_CODEPAGE_ISO_CYRILLIC			LIBPFF_CODEPAGE_ISO_8859_5
#define LIBPFF_CODEPAGE_ISO_ARABIC			LIBPFF_CODEPAGE_ISO_8859_6
#define LIBPFF_CODEPAGE_ISO_GREEK			LIBPFF_CODEPAGE_ISO_8859_7
#define LIBPFF_CODEPAGE_ISO_HEBREW			LIBPFF_CODEPAGE_ISO_8859_8
#define LIBPFF_CODEPAGE_ISO_TURKISH			LIBPFF_CODEPAGE_ISO_8859_9
#define LIBPFF_CODEPAGE_ISO_NORDIC			LIBPFF_CODEPAGE_ISO_8859_10
#define LIBPFF_CODEPAGE_ISO_THAI			LIBPFF_CODEPAGE_ISO_8859_11
#define LIBPFF_CODEPAGE_ISO_BALTIC			LIBPFF_CODEPAGE_ISO_8859_13
#define LIBPFF_CODEPAGE_ISO_CELTIC			LIBPFF_CODEPAGE_ISO_8859_14

#define LIBPFF_CODEPAGE_ISO_LATIN_1			LIBPFF_CODEPAGE_ISO_8859_1
#define LIBPFF_CODEPAGE_ISO_LATIN_2			LIBPFF_CODEPAGE_ISO_8859_2
#define LIBPFF_CODEPAGE_ISO_LATIN_3			LIBPFF_CODEPAGE_ISO_8859_3
#define LIBPFF_CODEPAGE_ISO_LATIN_4			LIBPFF_CODEPAGE_ISO_8859_4
#define LIBPFF_CODEPAGE_ISO_LATIN_5			LIBPFF_CODEPAGE_ISO_8859_9
#define LIBPFF_CODEPAGE_ISO_LATIN_6			LIBPFF_CODEPAGE_ISO_8859_10
#define LIBPFF_CODEPAGE_ISO_LATIN_7			LIBPFF_CODEPAGE_ISO_8859_13
#define LIBPFF_CODEPAGE_ISO_LATIN_8			LIBPFF_CODEPAGE_ISO_8859_14
#define LIBPFF_CODEPAGE_ISO_LATIN_9			LIBPFF_CODEPAGE_ISO_8859_15
#define LIBPFF_CODEPAGE_ISO_LATIN_10			LIBPFF_CODEPAGE_ISO_8859_16

#define LIBPFF_CODEPAGE_KOI8_RUSSIAN			LIBPFF_CODEPAGE_KOI8_R
#define LIBPFF_CODEPAGE_KOI8_UKRAINIAN			LIBPFF_CODEPAGE_KOI8_U

#define LIBPFF_CODEPAGE_WINDOWS_THAI			LIBPFF_CODEPAGE_WINDOWS_874
#define LIBPFF_CODEPAGE_WINDOWS_JAPANESE		LIBPFF_CODEPAGE_WINDOWS_932
#define LIBPFF_CODEPAGE_WINDOWS_CHINESE_SIMPLIFIED	LIBPFF_CODEPAGE_WINDOWS_936
#define LIBPFF_CODEPAGE_WINDOWS_KOREAN			LIBPFF_CODEPAGE_WINDOWS_949
#define LIBPFF_CODEPAGE_WINDOWS_CHINESE_TRADITIONAL	LIBPFF_CODEPAGE_WINDOWS_950
#define LIBPFF_CODEPAGE_WINDOWS_CENTRAL_EUROPEAN	LIBPFF_CODEPAGE_WINDOWS_1250
#define LIBPFF_CODEPAGE_WINDOWS_CYRILLIC		LIBPFF_CODEPAGE_WINDOWS_1251
#define LIBPFF_CODEPAGE_WINDOWS_WESTERN_EUROPEAN	LIBPFF_CODEPAGE_WINDOWS_1252
#define LIBPFF_CODEPAGE_WINDOWS_GREEK			LIBPFF_CODEPAGE_WINDOWS_1253
#define LIBPFF_CODEPAGE_WINDOWS_TURKISH			LIBPFF_CODEPAGE_WINDOWS_1254
#define LIBPFF_CODEPAGE_WINDOWS_HEBREW			LIBPFF_CODEPAGE_WINDOWS_1255
#define LIBPFF_CODEPAGE_WINDOWS_ARABIC			LIBPFF_CODEPAGE_WINDOWS_1256
#define LIBPFF_CODEPAGE_WINDOWS_BALTIC			LIBPFF_CODEPAGE_WINDOWS_1257
#define LIBPFF_CODEPAGE_WINDOWS_VIETNAMESE		LIBPFF_CODEPAGE_WINDOWS_1258

#if defined( __cplusplus )
}
#endif

#endif

