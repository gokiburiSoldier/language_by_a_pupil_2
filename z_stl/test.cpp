#include "string.h"
#include <stdio.h>
#include <time.h>

clock_t begin,end;

int main() {
    begin = clock();
    string str;
    str = "1145";
    printf("%s",str.c_str());
    end = clock();
    printf("\n%ld\n",end-begin);
}
