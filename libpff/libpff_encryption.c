/*
 * De/Encryption functions
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

#include <common.h>
#include <types.h>

#include "libpff_encryption.h"
#include "libpff_definitions.h"
#include "libpff_libcerror.h"

/* The transposition array contains the un-encrypted (plain) values.
 * The un-encrypted value is in the position of the encrypted value.
 * i.e. the encrypted value 0x13 represents 0x02
 * encrypted:		0     1     2     3     4     5     6     7
 * un-encrypted:	8     9     a     b     c     d     e     f
 */

/* For compressible encryption
 */
static uint8_t libpff_encryption_compressible[] = {
	0x47, 0xf1, 0xb4, 0xe6, 0x0b, 0x6a, 0x72, 0x48, 0x85, 0x4e, 0x9e, 0xeb, 0xe2, 0xf8, 0x94, 0x53,
	0xe0, 0xbb, 0xa0, 0x02, 0xe8, 0x5a, 0x09, 0xab, 0xdb, 0xe3, 0xba, 0xc6, 0x7c, 0xc3, 0x10, 0xdd,
	0x39, 0x05, 0x96, 0x30, 0xf5, 0x37, 0x60, 0x82, 0x8c, 0xc9, 0x13, 0x4a, 0x6b, 0x1d, 0xf3, 0xfb,
	0x8f, 0x26, 0x97, 0xca, 0x91, 0x17, 0x01, 0xc4, 0x32, 0x2d, 0x6e, 0x31, 0x95, 0xff, 0xd9, 0x23,
	0xd1, 0x00, 0x5e, 0x79, 0xdc, 0x44, 0x3b, 0x1a, 0x28, 0xc5, 0x61, 0x57, 0x20, 0x90, 0x3d, 0x83,
	0xb9, 0x43, 0xbe, 0x67, 0xd2, 0x46, 0x42, 0x76, 0xc0, 0x6d, 0x5b, 0x7e, 0xb2, 0x0f, 0x16, 0x29,
	0x3c, 0xa9, 0x03, 0x54, 0x0d, 0xda, 0x5d, 0xdf, 0xf6, 0xb7, 0xc7, 0x62, 0xcd, 0x8d, 0x06, 0xd3,
	0x69, 0x5c, 0x86, 0xd6, 0x14, 0xf7, 0xa5, 0x66, 0x75, 0xac, 0xb1, 0xe9, 0x45, 0x21, 0x70, 0x0c,
	0x87, 0x9f, 0x74, 0xa4, 0x22, 0x4c, 0x6f, 0xbf, 0x1f, 0x56, 0xaa, 0x2e, 0xb3, 0x78, 0x33, 0x50,
	0xb0, 0xa3, 0x92, 0xbc, 0xcf, 0x19, 0x1c, 0xa7, 0x63, 0xcb, 0x1e, 0x4d, 0x3e, 0x4b, 0x1b, 0x9b,
	0x4f, 0xe7, 0xf0, 0xee, 0xad, 0x3a, 0xb5, 0x59, 0x04, 0xea, 0x40, 0x55, 0x25, 0x51, 0xe5, 0x7a,
	0x89, 0x38, 0x68, 0x52, 0x7b, 0xfc, 0x27, 0xae, 0xd7, 0xbd, 0xfa, 0x07, 0xf4, 0xcc, 0x8e, 0x5f,
	0xef, 0x35, 0x9c, 0x84, 0x2b, 0x15, 0xd5, 0x77, 0x34, 0x49, 0xb6, 0x12, 0x0a, 0x7f, 0x71, 0x88,
	0xfd, 0x9d, 0x18, 0x41, 0x7d, 0x93, 0xd8, 0x58, 0x2c, 0xce, 0xfe, 0x24, 0xaf, 0xde, 0xb8, 0x36,
	0xc8, 0xa1, 0x80, 0xa6, 0x99, 0x98, 0xa8, 0x2f, 0x0e, 0x81, 0x65, 0x73, 0xe4, 0xc2, 0xa2, 0x8a,
	0xd4, 0xe1, 0x11, 0xd0, 0x08, 0x8b, 0x2a, 0xf2, 0xed, 0x9a, 0x64, 0x3f, 0xc1, 0x6c, 0xf9, 0xec
};

/* For high encryption
 */
static uint8_t libpff_encryption_high1[] = {
	0x41, 0x36, 0x13, 0x62, 0xa8, 0x21, 0x6e, 0xbb, 0xf4, 0x16, 0xcc, 0x04, 0x7f, 0x64, 0xe8, 0x5d,
	0x1e, 0xf2, 0xcb, 0x2a, 0x74, 0xc5, 0x5e, 0x35, 0xd2, 0x95, 0x47, 0x9e, 0x96, 0x2d, 0x9a, 0x88,
	0x4c, 0x7d, 0x84, 0x3f, 0xdb, 0xac, 0x31, 0xb6, 0x48, 0x5f, 0xf6, 0xc4, 0xd8, 0x39, 0x8b, 0xe7,
	0x23, 0x3b, 0x38, 0x8e, 0xc8, 0xc1, 0xdf, 0x25, 0xb1, 0x20, 0xa5, 0x46, 0x60, 0x4e, 0x9c, 0xfb,
	0xaa, 0xd3, 0x56, 0x51, 0x45, 0x7c, 0x55, 0x00, 0x07, 0xc9, 0x2b, 0x9d, 0x85, 0x9b, 0x09, 0xa0,
	0x8f, 0xad, 0xb3, 0x0f, 0x63, 0xab, 0x89, 0x4b, 0xd7, 0xa7, 0x15, 0x5a, 0x71, 0x66, 0x42, 0xbf,
	0x26, 0x4a, 0x6b, 0x98, 0xfa, 0xea, 0x77, 0x53, 0xb2, 0x70, 0x05, 0x2c, 0xfd, 0x59, 0x3a, 0x86,
	0x7e, 0xce, 0x06, 0xeb, 0x82, 0x78, 0x57, 0xc7, 0x8d, 0x43, 0xaf, 0xb4, 0x1c, 0xd4, 0x5b, 0xcd,
	0xe2, 0xe9, 0x27, 0x4f, 0xc3, 0x08, 0x72, 0x80, 0xcf, 0xb0, 0xef, 0xf5, 0x28, 0x6d, 0xbe, 0x30,
	0x4d, 0x34, 0x92, 0xd5, 0x0e, 0x3c, 0x22, 0x32, 0xe5, 0xe4, 0xf9, 0x9f, 0xc2, 0xd1, 0x0a, 0x81,
	0x12, 0xe1, 0xee, 0x91, 0x83, 0x76, 0xe3, 0x97, 0xe6, 0x61, 0x8a, 0x17, 0x79, 0xa4, 0xb7, 0xdc,
	0x90, 0x7a, 0x5c, 0x8c, 0x02, 0xa6, 0xca, 0x69, 0xde, 0x50, 0x1a, 0x11, 0x93, 0xb9, 0x52, 0x87,
	0x58, 0xfc, 0xed, 0x1d, 0x37, 0x49, 0x1b, 0x6a, 0xe0, 0x29, 0x33, 0x99, 0xbd, 0x6c, 0xd9, 0x94,
	0xf3, 0x40, 0x54, 0x6f, 0xf0, 0xc6, 0x73, 0xb8, 0xd6, 0x3e, 0x65, 0x18, 0x44, 0x1f, 0xdd, 0x67,
	0x10, 0xf1, 0x0c, 0x19, 0xec, 0xae, 0x03, 0xa1, 0x14, 0x7b, 0xa9, 0x0b, 0xff, 0xf8, 0xa3, 0xc0,
	0xa2, 0x01, 0xf7, 0x2e, 0xbc, 0x24, 0x68, 0x75, 0x0d, 0xfe, 0xba, 0x2f, 0xb5, 0xd0, 0xda, 0x3d
};

static uint8_t libpff_encryption_high2[] = {
	0x14, 0x53, 0x0f, 0x56, 0xb3, 0xc8, 0x7a, 0x9c, 0xeb, 0x65, 0x48, 0x17, 0x16, 0x15, 0x9f, 0x02,
	0xcc, 0x54, 0x7c, 0x83, 0x00, 0x0d, 0x0c, 0x0b, 0xa2, 0x62, 0xa8, 0x76, 0xdb, 0xd9, 0xed, 0xc7,
	0xc5, 0xa4, 0xdc, 0xac, 0x85, 0x74, 0xd6, 0xd0, 0xa7, 0x9b, 0xae, 0x9a, 0x96, 0x71, 0x66, 0xc3,
	0x63, 0x99, 0xb8, 0xdd, 0x73, 0x92, 0x8e, 0x84, 0x7d, 0xa5, 0x5e, 0xd1, 0x5d, 0x93, 0xb1, 0x57,
	0x51, 0x50, 0x80, 0x89, 0x52, 0x94, 0x4f, 0x4e, 0x0a, 0x6b, 0xbc, 0x8d, 0x7f, 0x6e, 0x47, 0x46,
	0x41, 0x40, 0x44, 0x01, 0x11, 0xcb, 0x03, 0x3f, 0xf7, 0xf4, 0xe1, 0xa9, 0x8f, 0x3c, 0x3a, 0xf9,
	0xfb, 0xf0, 0x19, 0x30, 0x82, 0x09, 0x2e, 0xc9, 0x9d, 0xa0, 0x86, 0x49, 0xee, 0x6f, 0x4d, 0x6d,
	0xc4, 0x2d, 0x81, 0x34, 0x25, 0x87, 0x1b, 0x88, 0xaa, 0xfc, 0x06, 0xa1, 0x12, 0x38, 0xfd, 0x4c,
	0x42, 0x72, 0x64, 0x13, 0x37, 0x24, 0x6a, 0x75, 0x77, 0x43, 0xff, 0xe6, 0xb4, 0x4b, 0x36, 0x5c,
	0xe4, 0xd8, 0x35, 0x3d, 0x45, 0xb9, 0x2c, 0xec, 0xb7, 0x31, 0x2b, 0x29, 0x07, 0x68, 0xa3, 0x0e,
	0x69, 0x7b, 0x18, 0x9e, 0x21, 0x39, 0xbe, 0x28, 0x1a, 0x5b, 0x78, 0xf5, 0x23, 0xca, 0x2a, 0xb0,
	0xaf, 0x3e, 0xfe, 0x04, 0x8c, 0xe7, 0xe5, 0x98, 0x32, 0x95, 0xd3, 0xf6, 0x4a, 0xe8, 0xa6, 0xea,
	0xe9, 0xf3, 0xd5, 0x2f, 0x70, 0x20, 0xf2, 0x1f, 0x05, 0x67, 0xad, 0x55, 0x10, 0xce, 0xcd, 0xe3,
	0x27, 0x3b, 0xda, 0xba, 0xd7, 0xc2, 0x26, 0xd4, 0x91, 0x1d, 0xd2, 0x1c, 0x22, 0x33, 0xf8, 0xfa,
	0xf1, 0x5a, 0xef, 0xcf, 0x90, 0xb6, 0x8b, 0xb5, 0xbd, 0xc0, 0xbf, 0x08, 0x97, 0x1e, 0x6c, 0xe2,
	0x61, 0xe0, 0xc6, 0xc1, 0x59, 0xab, 0xbb, 0x58, 0xde, 0x5f, 0xdf, 0x60, 0x79, 0x7e, 0xb2, 0x8a
};

/* Decrypts the data
 * Returns the number of bytes decrypted if successful or -1 on error
 */
ssize_t libpff_encryption_decrypt(
         uint8_t encryption_type,
         uint32_t key,
         uint8_t *data,
         size_t size,
         libcerror_error_t **error )
{
	static char *function = "libpff_encryption_decrypt";
	size_t iterator       = 0;
	uint16_t salt         = 0;
	uint8_t index         = 0;
	uint8_t upper_salt    = 0;
	uint8_t lower_salt    = 0;

	if( ( encryption_type != LIBPFF_ENCRYPTION_TYPE_COMPRESSIBLE )
	 && ( encryption_type != LIBPFF_ENCRYPTION_TYPE_NONE )
	 && ( encryption_type != LIBPFF_ENCRYPTION_TYPE_HIGH ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported compression type.",
		 function );

		return( -1 );
	}
	if( data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data.",
		 function );

		return( -1 );
	}
	if( size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( encryption_type == LIBPFF_ENCRYPTION_TYPE_COMPRESSIBLE )
	{
		for( iterator = 0; iterator < size; iterator++ )
		{
			index            = data[ iterator ];
			data[ iterator ] = libpff_encryption_compressible[ index ];
		}
	}
	else if( encryption_type == LIBPFF_ENCRYPTION_TYPE_NONE )
	{
		iterator = size;
	}
	else if( encryption_type == LIBPFF_ENCRYPTION_TYPE_HIGH )
	{
		salt = (uint16_t) ( ( ( key & 0xffff0000 ) >> 16 ) ^ ( key & 0x0000ffff ) );

		for( iterator = 0; iterator < size; iterator++ )
		{
			lower_salt       = salt & 0x00ff;
			upper_salt       = ( salt & 0xff00 ) >> 8;
			index            =  data[ iterator ];
			index           += lower_salt;
			index            = libpff_encryption_high1[ index ];
			index           += upper_salt;
			index            = libpff_encryption_high2[ index ];
			index           -= upper_salt;
			index            = libpff_encryption_compressible[ index ];
			index           -= lower_salt;
			data[ iterator ] = index;

			salt++;
		}
	}
	return( (ssize_t) iterator );
}

