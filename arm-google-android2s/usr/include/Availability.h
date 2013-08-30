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

#ifndef __AVAILABILITY_H__
#define __AVAILABILITY_H__


#if ! defined (__STELLA_VERSION_MAX_ALLOWED)
    #define __STELLA_VERSION_MAX_ALLOWED
#endif



#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
    #define DEPRECATED_ATTRIBUTE    __attribute__((deprecated))
    #define UNAVAILABLE_ATTRIBUTE   __attribute__((unavailable))

#else
    #define DEPRECATED_ATTRIBUTE
    #define UNAVAILABLE_ATTRIBUTE

#endif





#endif /* __AVAILABILITY_H__ */
