//
//  NSFileManager+KRGBackupSkipping.m
//  FileHenge
//
//  Created by Kiel Gillard on 2/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <sys/xattr.h>
#import "NSFileManager+KRGBackupSkipping.h"

NSString *const KRGBackupSkippingErrorDomain = @"KRGBackupSkippingErrorDomain";

@implementation NSFileManager (KRGBackupSkipping)

- (BOOL)setSkipsBackupAttribute:(BOOL)skipsBackup ofItemAtURL:(NSURL *)URL error:(out NSError **)error
{
    BOOL result;
    
    if ([URL isFileURL]) {
        
        result = [self setSkipsBackupAttribute:skipsBackup ofItemAtPath:[URL path] error:error];
        
    } else {
        
        result = NO;
        
        if (error) {
            
            *error = [NSError errorWithDomain:KRGBackupSkippingErrorDomain
                                         code:NSURLErrorUnsupportedURL
                                     userInfo:[NSDictionary dictionaryWithObjectsAndKeys:NSLocalizedString(@"Unable to set \"skip backup\" attribute.", nil), NSLocalizedDescriptionKey, nil]];
        }
    }
    
    return result;
}

- (BOOL)setSkipsBackupAttribute:(BOOL)skipsBackup ofItemAtPath:(NSString *)path error:(out NSError **)error
{
    BOOL result;
    
    if (path) {
        
        u_int8_t b = (skipsBackup ? 1 : 0);
        
        if (setxattr([path fileSystemRepresentation], "com.apple.MobileBackup", &b, 1, 0, 0) == 0) {
            
            result = YES;
            
        } else {
            
            result = NO;
            
            if (error) {
                
                *error = [NSError errorWithDomain:KRGBackupSkippingErrorDomain
                                             code:errno
                                         userInfo:[NSDictionary dictionaryWithObjectsAndKeys:NSLocalizedString(@"Unable to set \"skip backup\" attribute.", nil), NSLocalizedDescriptionKey, nil]];
            }
        }
        
    } else {
        
        result = NO;
        
        if (error) {
            
            *error = [NSError errorWithDomain:KRGBackupSkippingErrorDomain
                                         code:NSFileNoSuchFileError
                                     userInfo:[NSDictionary dictionaryWithObjectsAndKeys:NSLocalizedString(@"Unable to set \"skip backup\" attribute.", nil), NSLocalizedDescriptionKey, nil]];
        }
    }
    
    return result;
}

@end
