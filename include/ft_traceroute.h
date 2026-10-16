#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

// Use to enable the POSIX API to let the IDE find getaddrinfo - struct addrinfo
#ifdef __APPLE__
# define _DARWIN_C_SOURCE
#else
# define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_config
{
    bool verbose;
    bool help;
    const char *target;
} t_config;

// define
# define PROG_NAME "ft_traceroute"
# define OK 0
# define ERR 1
# define USAGE \
        "Usage: %s [OPTION...] HOST\n"\
        "%s - Print the route packets trace to network host.\n"\
        "\n"\
        "Options:\n" \
        "  -h        display this help and exit\n"

#endif