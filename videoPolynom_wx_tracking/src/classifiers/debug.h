#define DEBUG 0

#ifdef DEBUG
#define PRINT_DEBUG(format, args...) \
	printf("\033[34;40m"format"\033[0m", ##args);
#else
#define PRINT_DEBUG(format, args...)
#endif
