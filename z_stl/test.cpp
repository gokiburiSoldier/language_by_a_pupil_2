#include "iostream.h"
#include <time.h>

clock_t begin,end;
long long a,b;

int main() {
    begin = clock();
    io::init();
    end = clock();
    printf("\n%f\n",(double(end-begin))/CLOCKS_PER_SEC);
    begin = clock();
    cin >> a >> b;
    cout << a+b;
    end = clock();
    printf("\n%f\n",(double(end-begin))/CLOCKS_PER_SEC);
}
