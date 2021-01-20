//
//  FIRCrashlyticsReport.h
//  Pods
//
//  Created by Sam Edson on 12/14/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The Firebase Crashlytics Report provides a way to read and write information
 * to a past Crashlytics reports. A common use case is gathering end-user feedback
 * on the next run of the app.
 */
NS_SWIFT_NAME(CrashlyticsReport)
@interface FIRCrashlyticsReport : NSObject

/** :nodoc: */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Returns the unique ID for the Crashlytics report.
 */
@property(nonatomic, readonly) NSString *reportID;

/**
 * Returns the date that the report was created.
 */
@property(nonatomic, readonly) NSDate *dateCreated;

/**
 * Returns true when one of the events in the Crashlytics report is a crash.
 */
@property(nonatomic, readonly) BOOL hasCrash;

/**
 * Adds logging that is sent with your crash data. The logging does not appear  in the
 * system.log and is only visible in the Crashlytics dashboard.
 *
 * @param msg Message to log
 */
- (void)log:(NSString *)msg;

/**
 * Adds logging that is sent with your crash data. The logging does not appear  in the
 * system.log and is only visible in the Crashlytics dashboard.
 *
 * @param format Format of string
 * @param ... A comma-separated list of arguments to substitute into format
 */
- (void)logWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

/**
 * Adds logging that is sent with your crash data. The logging does not appear  in the
 * system.log and is only visible in the Crashlytics dashboard.
 *
 * @param format Format of string
 * @param args Arguments to substitute into format
 */
- (void)logWithFormat:(NSString *)format
            arguments:(va_list)args NS_SWIFT_NAME(log(format:arguments:));

/**
 * Sets a custom key and value to be associated with subsequent fatal and non-fatal reports.
 * When setting an object value, the object is converted to a string. This is
 * typically done by calling "-[NSObject description]".
 *
 * @param value The value to be associated with the key
 * @param key A unique key
 */
- (void)setCustomValue:(id)value forKey:(NSString *)key;

/**
 * Records a user ID (identifier) that's associated with subsequent fatal and non-fatal reports.
 *
 * If you want to associate a crash with a specific user, we recommend specifying an arbitrary
 * string (e.g., a database, ID, hash, or other value that you can index and query, but is
 * meaningless to a third-party observer). This allows you to facilitate responses for support
 * requests and reach out to users for more information.
 *
 * @param userID An arbitrary user identifier string that associates a user to a record in your
 * system.
 */
- (void)setUserID:(NSString *)userID;

@end

NS_ASSUME_NONNULL_END
