#ifndef LOG_H
    #define LOG_H

    #define LOG 1
    #if LOG
        #include <stdio.h>
        #define log_info(format, ...)  printf("[" __FILE__ "]\t INFO:"  format "\r\n", ##__VA_ARGS__)
        #define log_debug(format, ...) printf("[" __FILE__ "]\t DEBUG:" format "\r\n", ##__VA_ARGS__)
        #define log_error(format, ...) printf("[" __FILE__ "]\t ERROR:" format "\r\n", ##__VA_ARGS__)
    #else
        #define log_info(format, ...)
        #define log_debug(format, ...)
        #define log_error(format, ...)
    #endif
#endif
