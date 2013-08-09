/*

 Disclaimer: IMPORTANT:  This Apple software is supplied to you by
 Apple Inc. ("Apple") in consideration of your agreement to the
 following terms, and your use, installation, modification or
 redistribution of this Apple software constitutes acceptance of these
 terms.  If you do not agree with these terms, please do not use,
 install, modify or redistribute this Apple software.

 In consideration of your agreement to abide by the following terms, and
 subject to these terms, Apple grants you a personal, non-exclusive
 license, under Apple's copyrights in this original Apple software (the
 "Apple Software"), to use, reproduce, modify and redistribute the Apple
 Software, with or without modifications, in source and/or binary forms;
 provided that if you redistribute the Apple Software in its entirety and
 without modifications, you must retain this notice and the following
 text and disclaimers in all such redistributions of the Apple Software.
 Neither the name, trademarks, service marks or logos of Apple Inc.
 may be used to endorse or promote products derived from the Apple
 Software without specific prior written permission from Apple.  Except
 as expressly stated in this notice, no other rights or licenses, express
 or implied, are granted by Apple herein, including but not limited to
 any patent rights that may be infringed by your derivative works or by
 other works in which the Apple Software may be incorporated.

 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.

 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.

 Copyright (C) 2009 Apple Inc. All Rights Reserved.

 $Id$
 */

/*
 This file contains code from version 1.1 and 1.4 of MyOpenALSupport.h taken from Apple's oalTouch version.
 The 1.4 version code is used for loading IMA4 files, however, this code causes very noticeable clicking
 when used to load wave files that are looped so the 1.1 version code is used specifically for loading
 wav files.
 */

#ifndef __CD_OPENAL_H
#define __CD_OPENAL_H

#ifdef __cplusplus
extern "C" {
#endif


#import <OpenAL/al.h>
#import <OpenAL/alc.h>
#import <CoreFoundation/CFURL.h>


//Taken from oalTouch MyOpenALSupport 1.1
#if defined (__STELLA_VERSION_MAX_ALLOWED)  && defined (__STELLA_HANDROID2)
#import <Foundation/Foundation.h>
void * CDAllocWaveAudioData (NSString * path, ALsizei * outDataSize, ALenum * outDataFormat, ALsizei * outSampleRate);
void * CDAllocOggAudioData (NSString * path, ALsizei * outDataSize, ALenum * outDataFormat, ALsizei * outSampleRate);
void * CDGetOpenALAudioData (NSString * path, ALsizei *outDataSize, ALenum *outDataFormat, ALsizei* outSampleRate);
#else
void* CDloadWaveAudioData(CFURLRef inFileURL, ALsizei *outDataSize, ALenum *outDataFormat, ALsizei*	outSampleRate);
void* CDloadCafAudioData(CFURLRef inFileURL, ALsizei *outDataSize, ALenum *outDataFormat, ALsizei* outSampleRate);
void* CDGetOpenALAudioData(CFURLRef inFileURL, ALsizei *outDataSize, ALenum *outDataFormat, ALsizei* outSampleRate);
#endif


#ifdef __cplusplus
}
#endif

#endif

#if defined (__STELLA_VERSION_MAX_ALLOWED) && defined (__STELLA_HANDROID2)
/* precursors */
#define STB_VORBIS_NO_CRT

#ifndef STB_VORBIS_INCLUDE_STB_VORBIS_H
#define STB_VORBIS_INCLUDE_STB_VORBIS_H

#if defined(STB_VORBIS_NO_CRT) && !defined(STB_VORBIS_NO_STDIO)
#define STB_VORBIS_NO_STDIO 1
#endif

#ifndef STB_VORBIS_NO_STDIO
#include <stdio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


typedef struct
{
   char *alloc_buffer;
   int   alloc_buffer_length_in_bytes;
} stb_vorbis_alloc;


///////////   FUNCTIONS USEABLE WITH ALL INPUT MODES

typedef struct stb_vorbis stb_vorbis;

typedef struct
{
   unsigned int sample_rate;
   int channels;

   unsigned int setup_memory_required;
   unsigned int setup_temp_memory_required;
   unsigned int temp_memory_required;

   int max_frame_size;
} stb_vorbis_info;

// get general information about the file
extern stb_vorbis_info stb_vorbis_get_info(stb_vorbis *f);

// get the last error detected (clears it, too)
extern int stb_vorbis_get_error(stb_vorbis *f);

// close an ogg vorbis file and free all memory in use
extern void stb_vorbis_close(stb_vorbis *f);

// this function returns the offset (in samples) from the beginning of the
// file that will be returned by the next decode, if it is known, or -1
// otherwise. after a flush_pushdata() call, this may take a while before
// it becomes valid again.
// NOT WORKING YET after a seek with PULLDATA API
extern int stb_vorbis_get_sample_offset(stb_vorbis *f);

// returns the current seek point within the file, or offset from the beginning
// of the memory buffer. In pushdata mode it returns 0.
extern unsigned int stb_vorbis_get_file_offset(stb_vorbis *f);

///////////   PUSHDATA API

#ifndef STB_VORBIS_NO_PUSHDATA_API


extern stb_vorbis *stb_vorbis_open_pushdata(
         unsigned char *datablock, int datablock_length_in_bytes,
         int *datablock_memory_consumed_in_bytes,
         int *error,
         stb_vorbis_alloc *alloc_buffer);


extern int stb_vorbis_decode_frame_pushdata(
         stb_vorbis *f, unsigned char *datablock, int datablock_length_in_bytes,
         int *channels,             // place to write number of float * buffers
         float ***output,           // place to write float ** array of float * buffers
         int *samples               // place to write number of output samples
     );


extern void stb_vorbis_flush_pushdata(stb_vorbis *f);

#endif


//////////   PULLING INPUT API

#ifndef STB_VORBIS_NO_PULLDATA_API

#if !defined(STB_VORBIS_NO_STDIO) && !defined(STB_VORBIS_NO_INTEGER_CONVERSION)
extern int stb_vorbis_decode_filename(char *filename, int *channels, short **output);
#endif
extern int stb_vorbis_decode_memory(unsigned char *mem, int len, int *channels, short **output);


extern stb_vorbis * stb_vorbis_open_memory(unsigned char *data, int len,
                                  int *error, stb_vorbis_alloc *alloc_buffer);


#ifndef STB_VORBIS_NO_STDIO
extern stb_vorbis * stb_vorbis_open_filename(char *filename,
                                  int *error, stb_vorbis_alloc *alloc_buffer);


extern stb_vorbis * stb_vorbis_open_file(FILE *f, int close_handle_on_close,
                                  int *error, stb_vorbis_alloc *alloc_buffer);


extern stb_vorbis * stb_vorbis_open_file_section(FILE *f, int close_handle_on_close,
                int *error, stb_vorbis_alloc *alloc_buffer, unsigned int len);

#endif

extern int stb_vorbis_seek_frame(stb_vorbis *f, unsigned int sample_number);
extern int stb_vorbis_seek(stb_vorbis *f, unsigned int sample_number);


extern void stb_vorbis_seek_start(stb_vorbis *f);
// this function is equivalent to stb_vorbis_seek(f,0), but it
// actually works

extern unsigned int stb_vorbis_stream_length_in_samples(stb_vorbis *f);
extern float        stb_vorbis_stream_length_in_seconds(stb_vorbis *f);
// these functions return the total length of the vorbis stream

extern int stb_vorbis_get_frame_float(stb_vorbis *f, int *channels, float ***output);


#ifndef STB_VORBIS_NO_INTEGER_CONVERSION
extern int stb_vorbis_get_frame_short_interleaved(stb_vorbis *f, int num_c, short *buffer, int num_shorts);
extern int stb_vorbis_get_frame_short            (stb_vorbis *f, int num_c, short **buffer, int num_samples);
#endif


extern int stb_vorbis_get_samples_float_interleaved(stb_vorbis *f, int channels, float *buffer, int num_floats);
extern int stb_vorbis_get_samples_float(stb_vorbis *f, int channels, float **buffer, int num_samples);


#ifndef STB_VORBIS_NO_INTEGER_CONVERSION
extern int stb_vorbis_get_samples_short_interleaved(stb_vorbis *f, int channels, short *buffer, int num_shorts);
extern int stb_vorbis_get_samples_short(stb_vorbis *f, int channels, short **buffer, int num_samples);
#endif


#endif

////////   ERROR CODES

enum STBVorbisError
{
   VORBIS__no_error,

   VORBIS_need_more_data=1,             // not a real error

   VORBIS_invalid_api_mixing,           // can't mix API modes
   VORBIS_outofmem,                     // not enough memory
   VORBIS_feature_not_supported,        // uses floor 0
   VORBIS_too_many_channels,            // STB_VORBIS_MAX_CHANNELS is too small
   VORBIS_file_open_failure,            // fopen() failed
   VORBIS_seek_without_length,          // can't seek in unknown-length file

   VORBIS_unexpected_eof=10,            // file is truncated?
   VORBIS_seek_invalid,                 // seek past EOF

   // decoding errors (corrupt/invalid stream) -- you probably
   // don't care about the exact details of these

   // vorbis errors:
   VORBIS_invalid_setup=20,
   VORBIS_invalid_stream,

   // ogg errors:
   VORBIS_missing_capture_pattern=30,
   VORBIS_invalid_stream_structure_version,
   VORBIS_continued_packet_flag_invalid,
   VORBIS_incorrect_stream_serial_number,
   VORBIS_invalid_first_page,
   VORBIS_bad_packet_type,
   VORBIS_cant_find_last_page,
   VORBIS_seek_failed,
};


#ifdef __cplusplus
}
#endif

#endif // STB_VORBIS_INCLUDE_STB_VORBIS_H

#endif



