//
//  NSFileManager+KRGBackupSkipping.h
//  FileHenge
//
//  Created by Kiel Gillard on 2/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const KRGBackupSkippingErrorDomain;           /**< Domain used for errors when skipping backups. */

@interface NSFileManager (KRGBackupSkipping)

/**
 * API Apple should have provided us. iOS 5.0.1 beta introduces a new "do not back up" attribute for specifying files that
 * should remain on device, even in low storage situations.
 * Use this attribute with data that can be recreated but needs to persist even in low storage situations for proper functioning of your app or 
 * because customers expect it to be available during offline use. This attribute works on marked files regardless of what directory they are in, 
 * including the Documents directory. These files will not be purged and will not be included in the user's iCloud or iTunes backup. 
 * Because these files do use on-device storage space, your app is responsible for monitoring and purging these files periodically. 
 * To set the "do not back up" attribute, add the following method to a class in your application. 
 * Whenever you create a file that should not be backed up to iCloud, write the data to the file and 
 * then call this method, passing in a URL that points to the file.
 * @param skipsBackup YES indicates the item should not be backed up and persist on the device. Otherwise, item may be automatically backed up or cleaned up.
 * @param URL File URL to item.
 * @param error On return, an error explaining why the message returned NO. Code of the error may be errorno if setxattr failed, 
 * NSFileNoSuchFileError if an invalid path is given or NSURLErrorUnsupportedURL if an invalid URL is given.
 * @result YES indicates com.apple.MobileBackup extended attribute set successfully.
 */
- (BOOL)setSkipsBackupAttribute:(BOOL)skipsBackup ofItemAtURL:(NSURL *)URL error:(out NSError **)error;

/**
 * API Apple should have provided us. iOS 5.0.1 beta introduces a new "do not back up" attribute for specifying files that
 * should remain on device, even in low storage situations.
 * Use this attribute with data that can be recreated but needs to persist even in low storage situations for proper functioning of your app or 
 * because customers expect it to be available during offline use. This attribute works on marked files regardless of what directory they are in, 
 * including the Documents directory. These files will not be purged and will not be included in the user's iCloud or iTunes backup. 
 * Because these files do use on-device storage space, your app is responsible for monitoring and purging these files periodically. 
 * To set the "do not back up" attribute, add the following method to a class in your application. 
 * Whenever you create a file that should not be backed up to iCloud, write the data to the file and 
 * then call this method, passing in a URL that points to the file.
 * @param skipsBackup YES indicates the item should not be backed up and persist on the device. Otherwise, item may be automatically backed up or cleaned up.
 * @param Path Path to item.
 * @param error On return, an error explaining why the message returned NO. Code of the error may be errorno if setxattr failed, 
 * NSFileNoSuchFileError if an invalid path is given or NSURLErrorUnsupportedURL if an invalid URL is given.
 * @result YES indicates com.apple.MobileBackup extended attribute set successfully.
 */
- (BOOL)setSkipsBackupAttribute:(BOOL)skipsBackup ofItemAtPath:(NSString *)path error:(out NSError **)error;

@end
