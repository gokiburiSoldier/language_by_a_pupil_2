#ifndef _ZJX_GETCODE_H
#define _ZJX_GETCODE_H

#include <string>
#define MOD_NUMBER 114514

long long pow(long long a,long long n) {
    /*if(n == 1) return a;
    else if(n == 0) return 1;
    return pow(a*a,n >> 1) * (n & (n-1) ? a : 1);*/
    long long res = 1;
    for(long long i=1;i<=n;++i) {
        res *= a;
        if(res >= MOD_NUMBER) res %= MOD_NUMBER;
    }
    return res;
}

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};

char anay(char c) { /* 为什么不用`char &c` 因为不习惯 */
    if(c >= '0' && c <= '9') c -= '0';
    else if(c >= 'A' && c <= 'Z') c -= 'A'-10;
    else if(c >= 'a' && c <= 'z') c -= 'a'-36;
    return c;
}

long long getcode(std::string str) {
    int len = str.length();
    long long sum=0,cnt=0; /* sum处理每个字符取模114514,cnt计算除以114514 */
    if(len >= sizeof(primes)) return -1; /* 字符串过长 */
    for(int i=0;i<len;++i) {
        int c = anay(str[i]);
        long long s = pow(primes[i],c);
        sum += s % MOD_NUMBER;
        cnt += s / MOD_NUMBER;
    }
    return (sum/(cnt+1)) ^ (sum%(cnt+1));
}

#endif