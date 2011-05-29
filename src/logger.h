#ifndef _logger_h
#define _logger_h

#include <stdio.h>

#if defined(LOGGER_TRACE)
#define Logger_trace()       printf("TRACE : [%s:%d] %s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__)
#define Logger_debug(M, ...) printf("DEBUG : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define Logger_info(M, ...)  printf("INFO : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define Logger_error(M, ...) printf("ERROR : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#elif defined(LOGGER_DEBUG)
#define Logger_trace()      
#define Logger_debug(M, ...) printf("DEBUG : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define Logger_info(M, ...)  printf("INFO : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define Logger_error(M, ...) printf("ERROR : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#elif defined(LOGGER_INFO)
#define Logger_trace()       
#define Logger_debug(M, ...) 
#define Logger_info(M, ...)  printf("INFO : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define Logger_error(M, ...) printf("ERROR : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#elif defined(LOGGER_ERROR)
#define Logger_trace()
#define Logger_debug(M, ...) 
#define Logger_info(M, ...) 
#define Logger_error(M, ...) printf("ERROR : [%s:%d] " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#else
#define Logger_trace()
#define Logger_debug(M, ...) 
#define Logger_info(M, ...) 
#define Logger_error(M, ...)
#endif

#endif
