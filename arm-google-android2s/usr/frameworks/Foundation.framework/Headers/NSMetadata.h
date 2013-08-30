/**Interface for NSMetadataQuery for GNUStep
   Copyright (C) 2012 Free Software Foundation, Inc.

   Written by: Gregory Casamento
   Date: 2012
   
   This file is part of the GNUstep Base Library.

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

   AutogsdocSource: NSMetadataQuery.h
*/ 

#ifndef __NSMetadata_h_GNUSTEP_BASE_INCLUDE
#define __NSMetadata_h_GNUSTEP_BASE_INCLUDE

#import <Foundation/NSObject.h>
#import <Foundation/NSTimer.h>

@class NSPredicate, NSMutableDictionary, NSDictionary, NSMutableArray;
@protocol NSMetadataQueryDelegate;

// Metadata item constants...
GS_EXPORT NSString * const NSMetadataItemFSNameKey;
GS_EXPORT NSString * const NSMetadataItemDisplayNameKey;
GS_EXPORT NSString * const NSMetadataItemURLKey;
GS_EXPORT NSString * const NSMetadataItemPathKey;
GS_EXPORT NSString * const NSMetadataItemFSSizeKey;
GS_EXPORT NSString * const NSMetadataItemFSCreationDateKey;
GS_EXPORT NSString * const NSMetadataItemFSContentChangeDateKey;

@interface NSMetadataItem : NSObject
{
  NSMutableDictionary *attributes;
}

- (NSArray *)attributes;
- (id)valueForAttribute: (NSString *)key;
- (NSDictionary *)valuesForAttributes: (NSArray *)keys;
@end

// Metdata Query Constants...
GS_EXPORT NSString * const NSMetadataQueryUserHomeScope;
GS_EXPORT NSString * const NSMetadataQueryLocalComputerScope;
GS_EXPORT NSString * const NSMetadataQueryNetworkScope;
GS_EXPORT NSString * const NSMetadataQueryUbiquitousDocumentsScope;
GS_EXPORT NSString * const NSMetadataQueryUbiquitousDataScope;

GS_EXPORT NSString * const NSMetadataQueryDidFinishGatheringNotification;
GS_EXPORT NSString * const NSMetadataQueryDidStartGatheringNotification;
GS_EXPORT NSString * const NSMetadataQueryDidUpdateNotification;
GS_EXPORT NSString * const NSMetadataQueryGatheringProgressNotification;

/* Abstract interface for metadata query... */
@interface NSMetadataQuery : NSObject
{
  BOOL _isStopped;
  BOOL _isGathering;
  BOOL _isStarted;

  NSArray *_searchURLs;
  NSArray *_scopes;
  NSArray *_sortDescriptors;
  NSPredicate *_predicate;
  NSArray *_groupingAttributes;
  NSArray *_valueListAttributes;

  NSTimeInterval _notificationBatchingInterval;
  NSMutableDictionary *_results;

  id<NSMetadataQueryDelegate> _delegate;
}

/* Instance methods */
- (id)valueOfAttribute:(id)attr forResultAtIndex:(NSUInteger)index;
- (NSArray *)groupedResults;
- (NSDictionary *)valueLists;
- (NSUInteger)indexOfResult:(id)result;
- (NSArray *)results;
- (id)resultAtIndex:(NSUInteger)index;
- (NSUInteger)resultCount;

// Enable/Disable updates
- (void)enableUpdates;
- (void)disableUpdates;

// Status of the query...
- (BOOL)isStopped;
- (BOOL)isGathering;
- (BOOL)isStarted;
- (void)stopQuery;
- (BOOL)startQuery;

// Search URLS
- (void)setSearchItemURLs:(NSArray *)urls;
- (NSArray *)searchItemURLs;

// Search scopes 
- (void)setSearchScopes:(NSArray *)scopes;
- (NSArray *)searchScopes;

// Notification interval
- (void)setNotificationBatchingInterval:(NSTimeInterval)interval;
- (NSTimeInterval)notificationBatchingInterval;

// Grouping Attributes.
- (void)setGroupingAttributes:(NSArray *)attrs;
- (NSArray *)groupingAttributes;
- (void)setValueListAttributes:(NSArray *)attrs;
- (NSArray *)valueListAttributes;

// Sort descriptors
- (void)setSortDescriptors:(NSArray *)attrs;
- (NSArray *)sortDescriptors;

// Predicate
- (void)setPredicate:(NSPredicate *)predicate;
- (NSPredicate *)predicate;

// Delegate
- (void)setDelegate:(id<NSMetadataQueryDelegate>)delegate;
- (id<NSMetadataQueryDelegate>)delegate;

@end

@protocol NSMetadataQueryDelegate
#ifdef __OBJC2__
@optional
#endif
- (id)metadataQuery:(NSMetadataQuery *)query replacementObjectForResultObject:(NSMetadataItem *)result;
- (id)metadataQuery:(NSMetadataQuery *)query replacementValueForAttribute:(NSString *)attribute value:(id)attributeValue;
@end

@interface NSMetadataQueryAttributeValueTuple : NSObject
{
  id         _attribute;
  id         _value;
  NSUInteger _count;
}

- (NSString *) attribute;
- (id) value;
- (NSUInteger) count;

@end

@interface NSMetadataQueryResultGroup : NSObject
{
  NSString *_attribute;
  id _value;
  NSMutableArray *_subgroups;
}

- (NSString *) attribute;
- (id) value;
- (NSArray *) subgroups;
- (NSUInteger) resultCount;
- (id) resultAtIndex: (NSUInteger)index;
- (NSArray *) results;

@end

#endif
