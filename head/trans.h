/*
 * 数据类型转换
 */
#include "types.h"
#include <string>
#include <algorithm>
using namespace std;

namespace tr {
    string int_to_str(int x) {
        string r;
        while(x) {
            r += x%10+'0';
            x /= 10;
        }
        reverse(r.begin(),r.end());
        return r;
    }

    int str_to_int(string s) {
        int r=0,
            len = s.length();
        for(int i=0;i<len;++i) {
            r *= 10;
            r += s[i]-'0';
        }
        return r;
    }
}