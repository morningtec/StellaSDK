/*
 * Copyright 2011 Yeecco Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#if defined (__STELLA_WEBOS_PDK)
        #include <SDL/SDL.h>
        #include <PDL.h>
#endif

#if defined (__STELLA_WEBOS_PDK_NSAPP_PRELOAD)
        #ifndef main
        #error "main not defined when using PalmPDK headers'"
        #endif

        #undef main

        /* WC - this is a contamination */
        #import <AppKit/NSApplication.h>


    #if defined (__STELLA_WEBOS_PDK_CPS)
        typedef struct CPSProcessSerNum {
            UInt32        lo;
            UInt32        hi;
        } CPSProcessSerNum;

        extern OSErr    CPSGetCurrentProcess( CPSProcessSerNum *psn);
        extern OSErr     CPSEnableForegroundOperation( CPSProcessSerNum *psn, UInt32 _arg2, UInt32 _arg3, UInt32 _arg4, UInt32 _arg5);
        extern OSErr    CPSSetFrontProcess( CPSProcessSerNum *psn);
    #endif

#endif


