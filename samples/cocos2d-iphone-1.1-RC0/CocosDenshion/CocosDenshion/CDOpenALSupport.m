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

 $Id: CDOpenALSupport.h 16 2010-03-11 06:22:10Z steveoldmeadow $
 */

#import "CDOpenALSupport.h"
#import "CocosDenshion.h"
#if defined (__STELLA_VERSION_MAX_ALLOWED)
#import "SMSTBVorbis+Stella.h"

/* WC - see http://www.gamedev.net/community/forums/topic.asp?topic_id=505152&whichpage=1&#3296091
to be replaced with alure */

typedef struct _BasicWAVEHeader {
        char              riff[4];        // 'RIFF'
        unsigned int      riffSize;
        char              wave[4];        // 'WAVE'

        char              fmt[4];         // 4 'fmt '
        unsigned int      fmtSize;        // 4

        unsigned short    format;         // 2
        unsigned short    channels;       // 2
        unsigned int      sampleRate;     // 4
        unsigned int      byteRate;       // 4
        unsigned short    blockAlign;     // 2
        unsigned short    bitsPerSample;  // 2
} BasicWAVEHeader;

typedef struct _CDWaveChunkHeader {
        char                chunkID[4];   // 'data'
        uint32_t            chunkSize;
} CDWaveChunkHeader;

typedef struct _CDWaveRIFFChunk {
        CDWaveChunkHeader       header;
        char                    format[4];

} CDWaveRIFFChunk;

typedef struct _CDWaveFormatChunk {
        CDWaveChunkHeader       header;

        unsigned short          audioFormat;   
        unsigned short          numChannels;   
        unsigned int            sampleRate;    
        unsigned int            byteRate;      
        unsigned short          blockAlign;    
        unsigned short          bitsPerSample; 
} CDWaveFormatChunk;



void * CDAllocWaveAudioData (NSString * path, ALsizei * outDataSize, ALenum * outDataFormat, ALsizei * outSampleRate)
{
        CDLOG (@"dataFromPath: %@", path);

        NSData    * data; 
        data        = [NSData dataWithContentsOfFile: path];
        if (! data) {
                return NULL;
        }

        // SGDebugLog (@"SSSoundEngine", @"data: %@", data);

        // BasicWAVEHeader       * header;
        // header      = (BasicWAVEHeader *) [data bytes];

        CDWaveChunkHeader     * header;
        header      = (CDWaveChunkHeader *) [data bytes];

        if (memcmp (header->chunkID, "RIFF", 4)) {
                CDLOG (@"CocosDenshion: chunk header not valid: riff");
                return NULL;
        }

        CDWaveRIFFChunk       * riffChunk   = (CDWaveRIFFChunk *) header;
        if (memcmp (riffChunk->format, "WAVE", 4)) {
                CDLOG (@"CocosDenshion: chunk header not valid: riff/wave");
                return NULL;
        }
        // SGDebugLog (@"SSSoundEngine", @"found riff/wave chunk: %d bytes", header->chunkSize);


        header  = (CDWaveChunkHeader *) ((unsigned char *) header + sizeof (CDWaveChunkHeader) + 4);
        if (memcmp (header->chunkID, "fmt ", 4)) {
                CDLOG (@"CocosDenshion: chunk header not valid: fmt");
                return NULL;
        }
        // SGDebugLog (@"SSSoundEngine", @"found fmt chunk: %d bytes", header->chunkSize);

        CDWaveFormatChunk     * formatChunk     = (CDWaveFormatChunk *) header;


        while (YES) {
                CDLOG (@"skipping %d + %d bytes", sizeof (CDWaveChunkHeader), header->chunkSize);
                header  = (CDWaveChunkHeader *) ((unsigned char *) header + sizeof (CDWaveChunkHeader) + header->chunkSize);
                        if (! memcmp (header->chunkID, "FLLR", 4)) {
                        continue;
                }

                if (! memcmp (header->chunkID, "data", 4)) {
                        break;
                }

                CDLOG (@"unknown chunk header: %c%c%c%c", 
                header->chunkID[0], header->chunkID[1], header->chunkID[2], header->chunkID[3] );

                return NULL;
        }

        CDLOG (@"found data chunk: %d bytes", header->chunkSize);

        unsigned char     * buffer;
        buffer  = (unsigned char *) malloc (header->chunkSize);

        memcpy (buffer,  (unsigned char *) header + sizeof (CDWaveChunkHeader),  header->chunkSize);
        // [data getBytes: buffer range: NSMakeRange (sizeof (header), header->dataSize)];

        if (outDataSize) {
                *outDataSize      = header->chunkSize;
        }

        if (outDataFormat) {
                 if (formatChunk->bitsPerSample == 16) {
                         *outDataFormat  = (formatChunk->numChannels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
                 }
                 else {
                         *outDataFormat  = (formatChunk->numChannels == 1) ? AL_FORMAT_MONO8 : AL_FORMAT_STEREO8;
                 }
        }

        if (outSampleRate) {
             *outSampleRate    = formatChunk->sampleRate;
        }

        return buffer;
}


 /* ref link: https://gist.github.com/965399 */

typedef struct {
        stb_vorbis    * stream;
        stb_vorbis_info info;


        size_t          bufferSize;
        size_t          totalSamplesLeft;

} SMOggAudioStream;




void * CDAllocOggAudioData (NSString * path, ALsizei * outDataSize, ALenum * outDataFormat, ALsizei * outSampleRate)
{
        CDLOG(@"%@", path);

        //init 
        SMOggAudioStream    * oggStream;
        oggStream           = (SMOggAudioStream *) malloc (sizeof (SMOggAudioStream));

        // 
        // alGenSources (1, & oggStream->source );
        // alGenBuffers (2, oggStream->buffers );

        //oggStream->bufferSize   = 4096*8;


        //open file        
        NSData    * data; 
        data        = [NSData dataWithContentsOfFile: path];
        if (! data) {
             free (oggStream);
             return NO;
        }

        int                 dataLength   = [data length];
        unsigned char     * dataBytes    = (unsigned char *)[data bytes];
        int                 error;         


        oggStream->stream = stb_vorbis_open_memory (dataBytes, dataLength, &error, NULL);   /* WC - to handle error */

        if (!oggStream->stream) {
             CDLOG (@"Load OggStream Error: 0x%x", error);               
             [data release];
             free (oggStream);
             return NO;
        }

        CDLOG (@"Load OggStream Success");                

        oggStream->info                 = stb_vorbis_get_info (oggStream->stream);
        oggStream->totalSamplesLeft     = stb_vorbis_stream_length_in_samples (oggStream->stream) * oggStream->info.channels;

        oggStream->bufferSize           = oggStream->totalSamplesLeft;


        ALshort         * pcm;
        pcm  = (ALshort *) malloc (oggStream->bufferSize * sizeof (ALshort));
        if (pcm == NULL) {
             return NO;
        }

        NSUInteger      size    = 0;
        NSUInteger      result  = 0;



        while (size < oggStream->bufferSize){

             result      = stb_vorbis_get_samples_short_interleaved (oggStream->stream, oggStream->info.channels, pcm+size, 4096*8);

             if (result <= 0)        break;
             size       += result * oggStream->info.channels;
        }


        if (size == 0) {
             return NO;
        }

        CDLOG (@"totalSamplesLeft: %d, read %d", oggStream->totalSamplesLeft, size);
        oggStream->totalSamplesLeft     -= size;


        if (outDataSize) {
             *outDataSize    = size * sizeof (ALshort);
        }

        if (outDataFormat) {
             /* WC - assuming bits per sample == 16 */
             *outDataFormat  = (oggStream->info.channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
        }

        if (outSampleRate) {
             *outSampleRate  = oggStream->info.sample_rate;
        }

        CDLOG (@"totalSamplesLeft: %d, read %d", oggStream->totalSamplesLeft, size);

        return pcm;
}


void * CDGetOpenALAudioData (NSString * path, ALsizei * outDataSize, ALenum * outDataFormat, ALsizei * outSampleRate)
{    
        //SGDebugLog (@"SDUtilities", @"SDGetOpenALAudioData: %@", path);
        //SGDebugLog (@"SDUtilities", @"SDGetOpenALAudioData: ext: %@", [path pathExtension]);

        NSString    * fileType;
        fileType    = [path pathExtension];

        if ([fileType isEqualToString: @"wav"]) {
                return CDAllocWaveAudioData (path, outDataSize, outDataFormat, outSampleRate);
        } 
        else if ([fileType isEqualToString: @"ogg"]) {
                return CDAllocOggAudioData (path, outDataSize, outDataFormat, outSampleRate);
        }
        else {
                return nil;
        }
}
#else
#import <AudioToolbox/AudioToolbox.h>
#import <AudioToolbox/ExtendedAudioFile.h>


//Taken from oalTouch MyOpenALSupport 1.1
void* CDloadWaveAudioData(CFURLRef inFileURL, ALsizei *outDataSize, ALenum *outDataFormat, ALsizei*	outSampleRate)
{
	OSStatus						err = noErr;
	UInt64							fileDataSize = 0;
	AudioStreamBasicDescription		theFileFormat;
	UInt32							thePropertySize = sizeof(theFileFormat);
	AudioFileID						afid = 0;
	void*							theData = NULL;

	// Open a file with ExtAudioFileOpen()
	err = AudioFileOpenURL(inFileURL, kAudioFileReadPermission, 0, &afid);
	if(err) { CDLOG(@"MyGetOpenALAudioData: AudioFileOpenURL FAILED, Error = %ld\n", err); goto Exit; }

	// Get the audio data format
	err = AudioFileGetProperty(afid, kAudioFilePropertyDataFormat, &thePropertySize, &theFileFormat);
	if(err) { CDLOG(@"MyGetOpenALAudioData: AudioFileGetProperty(kAudioFileProperty_DataFormat) FAILED, Error = %ld\n", err); goto Exit; }

	if (theFileFormat.mChannelsPerFrame > 2)  {
		CDLOG(@"MyGetOpenALAudioData - Unsupported Format, channel count is greater than stereo\n"); goto Exit;
	}

	if ((theFileFormat.mFormatID != kAudioFormatLinearPCM) || (!TestAudioFormatNativeEndian(theFileFormat))) {
		CDLOG(@"MyGetOpenALAudioData - Unsupported Format, must be little-endian PCM\n"); goto Exit;
	}

	if ((theFileFormat.mBitsPerChannel != 8) && (theFileFormat.mBitsPerChannel != 16)) {
		CDLOG(@"MyGetOpenALAudioData - Unsupported Format, must be 8 or 16 bit PCM\n"); goto Exit;
	}


	thePropertySize = sizeof(fileDataSize);
	err = AudioFileGetProperty(afid, kAudioFilePropertyAudioDataByteCount, &thePropertySize, &fileDataSize);
	if(err) { CDLOG(@"MyGetOpenALAudioData: AudioFileGetProperty(kAudioFilePropertyAudioDataByteCount) FAILED, Error = %ld\n", err); goto Exit; }

	// Read all the data into memory
	UInt32		dataSize = (UInt32)fileDataSize;
	theData = malloc(dataSize);
	if (theData)
	{
		memset(theData, 0, dataSize);

		AudioFileReadBytes(afid, false, 0, &dataSize, theData);
		if(err == noErr)
		{
			// success
			*outDataSize = (ALsizei)dataSize;
			//This fix was added by me, however, 8 bit sounds have a clipping sound at the end so aren't really usable (SO)
			if (theFileFormat.mBitsPerChannel == 16) {
				*outDataFormat = (theFileFormat.mChannelsPerFrame > 1) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16;
			} else {
				*outDataFormat = (theFileFormat.mChannelsPerFrame > 1) ? AL_FORMAT_STEREO8 : AL_FORMAT_MONO8;
			}
			*outSampleRate = (ALsizei)theFileFormat.mSampleRate;
		}
		else
		{
			// failure
			free (theData);
			theData = NULL; // make sure to return NULL
			CDLOG(@"MyGetOpenALAudioData: ExtAudioFileRead FAILED, Error = %ld\n", err); goto Exit;
		}
	}

Exit:
	// Dispose the ExtAudioFileRef, it is no longer needed
	if (afid) AudioFileClose(afid);
	return theData;
}

//Taken from oalTouch MyOpenALSupport 1.4
void* CDloadCafAudioData(CFURLRef inFileURL, ALsizei *outDataSize, ALenum *outDataFormat, ALsizei* outSampleRate)
{
	OSStatus						status = noErr;
	BOOL							abort = NO;
	SInt64							theFileLengthInFrames = 0;
	AudioStreamBasicDescription		theFileFormat;
	UInt32							thePropertySize = sizeof(theFileFormat);
	ExtAudioFileRef					extRef = NULL;
	void*							theData = NULL;
	AudioStreamBasicDescription		theOutputFormat;
	UInt32							dataSize = 0;

	// Open a file with ExtAudioFileOpen()
	status = ExtAudioFileOpenURL(inFileURL, &extRef);
	if (status != noErr)
	{
		CDLOG(@"MyGetOpenALAudioData: ExtAudioFileOpenURL FAILED, Error = %ld\n", status);
		abort = YES;
	}
	if (abort)
		goto Exit;

	// Get the audio data format
	status = ExtAudioFileGetProperty(extRef, kExtAudioFileProperty_FileDataFormat, &thePropertySize, &theFileFormat);
	if (status != noErr)
	{
		CDLOG(@"MyGetOpenALAudioData: ExtAudioFileGetProperty(kExtAudioFileProperty_FileDataFormat) FAILED, Error = %ld\n", status);
		abort = YES;
	}
	if (abort)
		goto Exit;

	if (theFileFormat.mChannelsPerFrame > 2)
	{
		CDLOG(@"MyGetOpenALAudioData - Unsupported Format, channel count is greater than stereo\n");
		abort = YES;
	}
	if (abort)
		goto Exit;

	// Set the client format to 16 bit signed integer (native-endian) data
	// Maintain the channel count and sample rate of the original source format
	theOutputFormat.mSampleRate = theFileFormat.mSampleRate;
	theOutputFormat.mChannelsPerFrame = theFileFormat.mChannelsPerFrame;

	theOutputFormat.mFormatID = kAudioFormatLinearPCM;
	theOutputFormat.mBytesPerPacket = 2 * theOutputFormat.mChannelsPerFrame;
	theOutputFormat.mFramesPerPacket = 1;
	theOutputFormat.mBytesPerFrame = 2 * theOutputFormat.mChannelsPerFrame;
	theOutputFormat.mBitsPerChannel = 16;
	theOutputFormat.mFormatFlags = kAudioFormatFlagsNativeEndian | kAudioFormatFlagIsPacked | kAudioFormatFlagIsSignedInteger;

	// Set the desired client (output) data format
	status = ExtAudioFileSetProperty(extRef, kExtAudioFileProperty_ClientDataFormat, sizeof(theOutputFormat), &theOutputFormat);
	if (status != noErr)
	{
		CDLOG(@"MyGetOpenALAudioData: ExtAudioFileSetProperty(kExtAudioFileProperty_ClientDataFormat) FAILED, Error = %ld\n", status);
		abort = YES;
	}
	if (abort)
		goto Exit;

	// Get the total frame count
	thePropertySize = sizeof(theFileLengthInFrames);
	status = ExtAudioFileGetProperty(extRef, kExtAudioFileProperty_FileLengthFrames, &thePropertySize, &theFileLengthInFrames);
	if (status != noErr)
	{
		CDLOG(@"MyGetOpenALAudioData: ExtAudioFileGetProperty(kExtAudioFileProperty_FileLengthFrames) FAILED, Error = %ld\n", status);
		abort = YES;
	}
	if (abort)
		goto Exit;

	// Read all the data into memory
	dataSize = (UInt32) theFileLengthInFrames * theOutputFormat.mBytesPerFrame;
	theData = malloc(dataSize);
	if (theData)
	{
		memset(theData, 0, dataSize);

		AudioBufferList		theDataBuffer;
		theDataBuffer.mNumberBuffers = 1;
		theDataBuffer.mBuffers[0].mDataByteSize = dataSize;
		theDataBuffer.mBuffers[0].mNumberChannels = theOutputFormat.mChannelsPerFrame;
		theDataBuffer.mBuffers[0].mData = theData;

		// Read the data into an AudioBufferList
		status = ExtAudioFileRead(extRef, (UInt32*)&theFileLengthInFrames, &theDataBuffer);
		if(status == noErr)
		{
			// success
			*outDataSize = (ALsizei)dataSize;
			*outDataFormat = (theOutputFormat.mChannelsPerFrame > 1) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16;
			*outSampleRate = (ALsizei)theOutputFormat.mSampleRate;
		}
		else
		{
			// failure
			free (theData);
			theData = NULL; // make sure to return NULL
			CDLOG(@"MyGetOpenALAudioData: ExtAudioFileRead FAILED, Error = %ld\n", status);
			abort = YES;
		}
	}
	if (abort)
		goto Exit;

Exit:
	// Dispose the ExtAudioFileRef, it is no longer needed
	if (extRef) ExtAudioFileDispose(extRef);
	return theData;
}

void* CDGetOpenALAudioData(CFURLRef inFileURL, ALsizei *outDataSize, ALenum *outDataFormat, ALsizei*	outSampleRate) {

	CFStringRef extension = CFURLCopyPathExtension(inFileURL);
	CFComparisonResult isWavFile = 0;
	if (extension != NULL) {
		isWavFile = CFStringCompare (extension,(CFStringRef)@"wav", kCFCompareCaseInsensitive);
		CFRelease(extension);
	}

	if (isWavFile == kCFCompareEqualTo) {
		return CDloadWaveAudioData(inFileURL, outDataSize, outDataFormat, outSampleRate);
	} else {
		return CDloadCafAudioData(inFileURL, outDataSize, outDataFormat, outSampleRate);
	}
}
#endif

