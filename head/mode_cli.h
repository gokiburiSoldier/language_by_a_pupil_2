#ifndef _NML_CLI_H
#define _NML_CLI_H

#include <map>
#include <stdio.h>
#include <string>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

namespace ci {
    std::map<std::string,int (*)(void)> cli_kws;
    int ret1(void) {
        return 1;
    }
    int get_help(void) {
        printf("Type .exit to exit\n");
        printf("Type .help to get help\n");
        printf("Type .clear to clear screen\n");
        return 0;
    }
    int cls(void) {
        system(CLEAR);
        return 0;
    }
    void init(void) {
        cli_kws[".exit"] = ret1;
        cli_kws[".help"] = get_help;
        cli_kws[".clear"] = cls;
    }
}


#endif