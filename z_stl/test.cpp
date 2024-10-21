#include "../document/vector_伪代码.cpp"
#include "longlonglong.h"
#include <time.h>

clock_t begin,end;

int main() {
    begin = clock();
    向量<int> a;
    a.入(114514);
    a[0] = 1;
    printf("a[0]=%d,the beginning of a=%p\n",a[0],a.头());
    end = clock();
    printf("\n%f\n",(double(end-begin))/CLOCKS_PER_SEC);
}
