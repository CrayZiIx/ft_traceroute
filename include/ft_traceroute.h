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

#define FT_IPV4_MIN_HEADER_SIZE 20
#define FT_ICMP_HEADER_SIZE     8
#define FT_DEFAULT_INTERVAL_US 1000000LL

#ifdef __APPLE__

typedef struct ip   t_ip_header;
typedef struct icmp t_icmp_header;

# define FT_IP_LENGTH(ip)       ((ip)->ip_hl * 4)
# define FT_IP_TTL(ip)          ((ip)->ip_ttl)

# define FT_ICMP_TYPE(icmp)     ((icmp)->icmp_type)
# define FT_ICMP_CODE(icmp)     ((icmp)->icmp_code)
# define FT_ICMP_CHECKSUM(icmp) ((icmp)->icmp_cksum)
# define FT_ICMP_ID(icmp)       ((icmp)->icmp_id)
# define FT_ICMP_SEQUENCE(icmp) ((icmp)->icmp_seq)

# define FT_ICMP_DEST_UNREACH ICMP_UNREACH
# define FT_ICMP_TIME_EXCEEDED ICMP_TIMXCEED

#else

typedef struct iphdr   t_ip_header;
typedef struct icmphdr t_icmp_header;

# define FT_IP_LENGTH(ip)       ((ip)->ihl * 4)
# define FT_IP_TTL(ip)          ((ip)->ttl)

# define FT_ICMP_TYPE(icmp)     ((icmp)->type)
# define FT_ICMP_CODE(icmp)     ((icmp)->code)
# define FT_ICMP_CHECKSUM(icmp) ((icmp)->checksum)
# define FT_ICMP_ID(icmp)       ((icmp)->un.echo.id)
# define FT_ICMP_SEQUENCE(icmp) ((icmp)->un.echo.sequence)

# define FT_ICMP_DEST_UNREACH ICMP_DEST_UNREACH
# define FT_ICMP_TIME_EXCEEDED ICMP_TIME_EXCEEDED

#endif

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