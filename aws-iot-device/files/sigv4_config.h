#ifndef SIGV4_CONFIG_H_
#define SIGV4_CONFIG_H_

/* Logging configuration for the SigV4 library. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME    "SIGV4"
#endif

#ifndef LIBRARY_LOG_LEVEL
    /* Define log levels if not already defined */
    #ifndef LOG_NONE
        #define LOG_NONE     0
        #define LOG_ERROR    1  
        #define LOG_WARN     2
        #define LOG_INFO     3
        #define LOG_DEBUG    4
    #endif
    #define LIBRARY_LOG_LEVEL    LOG_ERROR
#endif

/* Only define logging macros if they haven't been defined elsewhere */
#ifndef LogError
    #define LogError(message)   printf message
#endif

#ifndef LogWarn
    #define LogWarn(message)    printf message
#endif

#ifndef LogInfo
    #define LogInfo(message)    printf message
#endif

#ifndef LogDebug
    #define LogDebug(message)   printf message
#endif

/**
 * @brief The size of the compile time allocated internal library buffer that is used
 * for generating the canonical request.
 */
#define SIGV4_PROCESSING_BUFFER_LENGTH    1600U

/**
 * @brief Number of HTTP headers does not exceed a maximum of 10 in HTTP requests sent to S3
 * for the demo application.
 */
#define SIGV4_MAX_HTTP_HEADER_COUNT       10U

/**
 * @brief Query parameters used in requests to S3.
 */
#define SIGV4_MAX_QUERY_PAIR_COUNT        1U

/**
 * @brief Maximum of all the block sizes of hashing algorithms used in the demo for the
 * calculation of hash digest.
 *
 * @note SHA256 hashing Algorithm is used in the demo for calculating the
 * hash digest and maximum block size for this is 64U.
 */
#define SIGV4_HASH_MAX_BLOCK_LENGTH       64U

/**
 * @brief Maximum digest length of hash algorithm used to calculate the hash digest.
 *
 * @note SHA256 hashing algorithm is used in the demo for calculating the
 * hash digest and maximum length for this 32U.
 */
#define SIGV4_HASH_MAX_DIGEST_LENGTH      32U

/**
 * @brief Setting SIGV4_MAX_QUERY_PAIR_COUNT to 1 as the HTTP request is not pre-canonicalized
 * in the demo application.
 */
#define SIGV4_USE_CANONICAL_SUPPORT       1

#endif /* ifndef SIGV4_CONFIG_H_ */