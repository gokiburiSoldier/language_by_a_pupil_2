#include "get_code.h"
#include <stdio.h>

int main(int argc,char* argv[]) {
    argc -= 1;
    for(int i=1;i<=argc;i++) printf("%lld\n",getcode(std::string(argv[i])));
}