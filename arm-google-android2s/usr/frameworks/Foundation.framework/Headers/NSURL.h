/* NSURL.h - Class NSURL
   Copyright (C) 1999 Free Software Foundation, Inc.
   
   Written by: 	Manuel Guesdon <mguesdon@sbuilders.com>
   Date:	Jan 1999
   
   This file is part of the GNUstep Library.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02111 USA.
*/

#ifndef __NSURL_h_GNUSTEP_BASE_INCLUDE
#define __NSURL_h_GNUSTEP_BASE_INCLUDE
#import	<GNUstepBase/GSVersionMacros.h>

#import	<Foundation/NSURLHandle.h>

#if	defined(__cplusplus)
extern "C" {
#endif

#if	OS_API_VERSION(GS_API_MACOSX, GS_API_LATEST)

@class NSError;
@class NSNumber;

/**
 *  URL scheme constant for use with [NSURL-initWithScheme:host:path:].
 */
GS_EXPORT NSString* const NSURLFileScheme;

/**
 * This class permits manipulation of URLs and the resources to which they
 * refer.  They can be used to represent absolute URLs or relative URLs
 * which are based upon an absolute URL.  The relevant RFCs describing
 * how a URL is formatted, and what is legal in a URL are -
 * 1808, 1738, and 2396.<br />
 * Handling of the underlying resources is carried out by NSURLHandle
 * objects, but NSURL provides a simplified API wrapping these objects.
 */
@interface NSURL: NSObject <NSCoding, NSCopying, NSURLHandleClient>
{
#if	GS_EXPOSE(NSURL)
@private
  NSString	*_urlString;
  NSURL		*_baseURL;
  void		*_clients;
  void		*_data;
#endif
}
 
/**
 * Create and return a file URL with the supplied path.<br />
 * The value of aPath must be a valid filesystem path.<br />
 * Calls -initFileURLWithPath: which escapes characters in the
 * path where necessary.
 */
+ (id) fileURLWithPath: (NSString*)aPath;

#if OS_API_VERSION(100600,GS_API_LATEST) 
/** Creates a file URL using a path built from components.
 */
+ (NSURL*) fileURLWithPathComponents: (NSArray*)components;
#endif

/**
 * Create and return a URL with the supplied string, which should
 * be a string (containing percent escape codes where necessary)
 * conforming to the description (in RFC2396) of an absolute URL.<br />
 * Calls -initWithString:
 */
+ (id) URLWithString: (NSString*)aUrlString;

/**
 * Create and return a URL with the supplied string, which should
 * be a string (containing percent escape codes where necessary)
 * conforming to the description (in RFC2396) of a relative URL.<br />
 * Calls -initWithString:relativeToURL:
 */
+ (id) URLWithString: (NSString*)aUrlString
       relativeToURL: (NSURL*)aBaseUrl;

/**
 * Initialise as a file URL with the specified path (which must
 * be a valid path on the local filesystem).<br />
 * Raises NSInvalidArgumentException if aPath is nil.<br />
 * Converts relative paths to absolute ones.<br />
 * Appends a trailing slash to the path when necessary if it
 * specifies a directory.<br />
 * Calls -initWithScheme:host:path:
 */
- (id) initFileURLWithPath: (NSString*)aPath;

#if OS_API_VERSION(100500,GS_API_LATEST) 
/**
 * Initialise as a file URL with the specified path (which must
 * be a valid path on the local filesystem).<br />
 * Raises NSInvalidArgumentException if aPath is nil.<br />
 * Converts relative paths to absolute ones.<br />
 * Appends a trailing slash to the path when necessary if it
 * specifies a directory.<br />
 * Calls -initWithScheme:host:path:
 */
- (id) initFileURLWithPath: (NSString*)aPath isDirectory: (BOOL)isDir;
#endif

/**
 * Initialise by building a URL string from the supplied parameters
 * and calling -initWithString:relativeToURL:<br />
 * This method adds percent escapes to aPath if it contains characters
 * which need escaping.<br />
 * Accepts RFC2732 style IPv6 host addresses either with or without the
 * enclosing square brackets (MacOS-X at least up to version 10.5 does
 * not handle these correctly, but GNUstep does).<br />
 * Permits the 'aHost' part to contain 'username:password@host:port' or
 * 'host:port' in addition to a simple host name or address.
 */
- (id) initWithScheme: (NSString*)aScheme
		 host: (NSString*)aHost
		 path: (NSString*)aPath;

/**
 * Initialise as an absolute URL.<br />
 * Calls -initWithString:relativeToURL:
 */
- (id) initWithString: (NSString*)aUrlString;

/** <init />
 * Initialised using aUrlString and aBaseUrl.  The value of aBaseUrl
 * may be nil, but aUrlString must be non-nil.<br />
 * Accepts RFC2732 style IPv6 host addresses.<br />
 * Parses a string wihthout a scheme as a simple path.<br />
 * Parses an empty string as an empty path.<br />
 * If the string cannot be parsed the method returns nil.
 */
- (id) initWithString: (NSString*)aUrlString
	relativeToURL: (NSURL*)aBaseUrl;

/**
 * Returns the full string describing the receiver resolved against its base.
 */
- (NSString*) absoluteString;

/**
 * If the receiver is an absolute URL, returns self.  Otherwise returns an
 * absolute URL referring to the same resource as the receiver.
 */
- (NSURL*) absoluteURL;

/**
 * If the receiver is a relative URL, returns its base URL.<br />
 * Otherwise, returns nil.
 */
- (NSURL*) baseURL;

#if OS_API_VERSION(100600,GS_API_LATEST) 
/** Attempts to load from the specified URL and provides an error
 * response if the data is unrachable.<br />
 * Returns YES on success, NO on failure.
 */
- (BOOL) checkResourceIsReachableAndReturnError: (NSError **)error;
#endif

/**
 * Returns the fragment portion of the receiver or nil if there is no
 * fragment supplied in the URL.<br />
 * The fragment is everything in the original URL string after a '#'<br />
 * File URLs do not have fragments.
 */
- (NSString*) fragment;

/**
 * Returns the host portion of the receiver or nil if there is no
 * host supplied in the URL.<br />
 * Percent escape sequences in the user string are translated and the string
 * treated as UTF8.<br />
 * Returns IPv6 addresses <em>without</em> the enclosing square brackets
 * required (by RFC2732) in URL strings.
 */
- (NSString*) host;

/**
 * Returns YES if the receiver is a file URL, NO otherwise.
 */
- (BOOL) isFileURL;

#if OS_API_VERSION(100600,GS_API_LATEST) 
/** Returns the last (rightmost) path component of the receiver.
 */
- (NSString*) lastPathComponent;
#endif

/**
 * Loads resource data for the specified client.
 * <p>
 *   If shouldUseCache is YES then an attempt
 *   will be made to locate a cached NSURLHandle to provide the
 *   resource data, otherwise a new handle will be created and
 *   cached.
 * </p>
 * <p>
 *   If the handle does not have the data available, it will be
 *   asked to load the data in the background by calling its
 *   loadInBackground  method.
 * </p>
 * <p>
 *   The specified client (if non-nil) will be set up to receive
 *   notifications of the progress of the background load process.
 * </p>
 * <p>
 *   The processes current run loop must be run in order for the
 *   background load operation to operate!
 * </p>
 */
- (void) loadResourceDataNotifyingClient: (id)client
			      usingCache: (BOOL)shouldUseCache;

/**
 * Returns the parameter portion of the receiver or nil if there is no
 * parameter supplied in the URL.<br />
 * The parameters are everything in the original URL string after a ';'
 * but before the query.<br />
 * File URLs do not have parameters.
 */
- (NSString*) parameterString;

/**
 * Returns the password portion of the receiver or nil if there is no
 * password supplied in the URL.<br />
 * Percent escape sequences in the user string are translated and the string
 * treated as UTF8 in GNUstep but this appears to be broken in MacOS-X.<br />
 * NB. because of its security implications it is recommended that you
 * do not use URLs with users and passwords unless necessary.
 */
- (NSString*) password;

/**
 * Returns the path portion of the receiver.<br />
 * Replaces percent escapes with unescaped values, interpreting non-ascii
 * character sequences as UTF8.<br />
 * NB. This does not conform strictly to the RFCs, in that it includes a
 * leading slash ('/') character (whereas the path part of a URL strictly
 * should not) and the interpretation of non-ascii character is (strictly
 * speaking) undefined.<br />
 * Also, this breaks strict conformance in that a URL of file scheme is
 * treated as having a path (contrary to RFCs)
 */
- (NSString*) path;

#if OS_API_VERSION(100600,GS_API_LATEST) 
/** Returns thepath components of the receiver.<br />
 * See [NSString-pathComponents].
 */
- (NSArray*) pathComponents;

/** Returns the file extension (text after the rightmost dot in the path)
 * of the receiver.<br />
 * see [NSString-pathExtension].
 */
- (NSString*) pathExtension;
#endif

/**
 * Returns the port portion of the receiver or nil if there is no
 * port supplied in the URL.<br />
 * Percent escape sequences in the user string are translated in GNUstep
 * but this appears to be broken in MacOS-X.
 */
- (NSNumber*) port;

/**
 * Asks a URL handle to return the property for the specified key and
 * returns the result.
 */
- (id) propertyForKey: (NSString*)propertyKey;

/**
 * Returns the query portion of the receiver or nil if there is no
 * query supplied in the URL.<br />
 * The query is everything in the original URL string after a '?'
 * but before the fragment.<br />
 * File URLs do not have queries.
 */
- (NSString*) query;

/**
 * Returns the path of the receiver, without taking any base URL into account.
 * If the receiver is an absolute URL, -relativePath is the same as -path.<br />
 * Returns nil if there is no path specified for the URL.
 */
- (NSString*) relativePath;

/**
 * Returns the relative portion of the URL string.  If the receiver is not
 * a relative URL, this returns the same as absoluteString.
 */
- (NSString*) relativeString;

/**
 * Loads the resource data for the represented URL and returns the result.
 * The shouldUseCache flag determines whether data previously retrieved by
 * an existing NSURLHandle can be used to provide the data, or if it should
 * be refetched.
 */
- (NSData*) resourceDataUsingCache: (BOOL)shouldUseCache;

/**
 * Returns the resource specifier of the URL ... the part which lies
 * after the scheme.
 */
- (NSString*) resourceSpecifier;

/**
 * Returns the scheme of the receiver.
 */
- (NSString*) scheme;

/**
 * Calls [NSURLHandle-writeProperty:forKey:] to set the named property.
 */
- (BOOL) setProperty: (id)property
	      forKey: (NSString*)propertyKey;

/**
 * Calls [NSURLHandle-writeData:] to write the specified data object
 * to the resource identified by the receiver URL.<br />
 * Returns the result.
 */
- (BOOL) setResourceData: (NSData*)data;

/**
 * Returns a URL with '/./' and '/../' sequences resolved etc.
 */
- (NSURL*) standardizedURL;

#if OS_API_VERSION(100600,GS_API_LATEST) 
/** Returns a URL formed by adding a path component to the path of the
 * receiver.<br />
 * See [NSString-stringByAppendingPathComponent:].
 */
- (NSURL*) URLByAppendingPathComponent: (NSString*)pathComponent;

/** Returns a URL formed by adding a path extension to the path of the
 * receiver.<br />
 * See [NSString-stringByAppendingPathExtension:].
 */
- (NSURL*) URLByAppendingPathExtension: (NSString*)pathExtension;

/** Returns a URL formed by removing a path component from the path of the
 * receiver.<br />
 * See [NSString-stringByDeletingLastPathComponent].
 */
- (NSURL*) URLByDeletingLastPathComponent;

/** Returns a URL formed by removing an extension from the path of the
 * receiver.<br />
 * See [NSString-stringByDeletingPathExtension].
 */
- (NSURL*) URLByDeletingPathExtension;

/** Returns self unless the receiver is a file URL, in which case it returns
 * a URL formed by calling [NSString-stringByResolvingSymlinksInPath].
 */
- (NSURL*) URLByResolvingSymlinksInPath;

/** Returns self unless the receiver is a file URL, in which case it returns
 * a URL formed by calling [NSString-stringByStandardizingPath].
 */
- (NSURL*) URLByStandardizingPath;

#endif

/**
 * Returns an NSURLHandle instance which may be used to write data to the
 * resource represented by the receiver URL, or read data from it.<br />
 * The shouldUseCache flag indicates whether a cached handle may be returned
 * or a new one should be created.
 */
- (NSURLHandle*)URLHandleUsingCache: (BOOL)shouldUseCache;

/**
 * Returns the user portion of the receiver or nil if there is no
 * user supplied in the URL.<br />
 * Percent escape sequences in the user string are translated and
 * the whole is treated as UTF8 data.<br />
 * NB. because of its security implications it is recommended that you
 * do not use URLs with users and passwords unless necessary.
 */
- (NSString*) user;

@end

@interface NSObject (NSURLClient)

/** <override-dummy />
 * Some data has become available.  Note that this does not mean that all data
 * has become available, only that a chunk of data has arrived.
 */
- (void) URL: (NSURL*)sender
  resourceDataDidBecomeAvailable: (NSData*)newBytes;

/** <override-dummy />
 * Loading of resource data is complete.
 */
- (void) URLResourceDidFinishLoading: (NSURL*)sender;

/** <override-dummy />
 * Loading of resource data was cancelled by programmatic request
 * (not an error).
 */
- (void) URLResourceDidCancelLoading: (NSURL*)sender;

/** <override-dummy />
 * Loading of resource data has failed, for given human-readable reason.
 */
- (void) URL: (NSURL*)sender
  resourceDidFailLoadingWithReason: (NSString*)reason;
@end

#endif	/* GS_API_MACOSX */

#if	defined(__cplusplus)
}
#endif

#if     !NO_GNUSTEP && !defined(GNUSTEP_BASE_INTERNAL)
#import <GNUstepBase/NSURL+GNUstepBase.h>
#endif

#endif	/* __NSURL_h_GNUSTEP_BASE_INCLUDE */

