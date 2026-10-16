#include "ft_traceroute.h"

static void print_usages(void)
{
    printf(USAGE, PROG_NAME, PROG_NAME);
}

static int parse_args(int argc, char **argv, t_config *config)
{
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h"))
            config->help = true;
        else if (argv[i][0] == '-')
        {
            fprintf(stderr, "%s: invalid option -- '%s'\n",
                    PROG_NAME, argv[i]);
            return ERR;
        }
        else if (argv[i][0] != '-' && config->target == NULL)
            config->target = argv[i];
        else
        {
            fprintf(stderr, "%s: extra operand '%s'\n",
                    PROG_NAME, argv[i]);
            return ERR;
        }
    }

    if (!config->help && config->target == NULL)
    {
        fprintf(stderr, "%s: missing host operand\n", PROG_NAME);
        return ERR;
    }
    return OK;
}

int main(int argc, char **argv) {
        t_config config = {0};

        if (parse_args(argc, argv, &config) != OK)
        {
                print_usages();
                return ERR;
        }
        if (config.help)
        {
                print_usages();
                return OK;
        }

        printf("ft_traceroute\n");
        return OK;
}