#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

// Use to enable the POSIX API to let the IDE find getaddrinfo - struct addrinfo
#ifdef __APPLE__
# define _DARWIN_C_SOURCE
#else
# define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>

#endif