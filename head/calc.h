#ifndef _NING_CLAC_H
#define _NING_CLAC_H

/* 最重要的头文件之一 */

#include <algorithm>
#include <string>
#include "rt.h"
#include "types.h"
#include "var.h"
#define ERR 0x104
using namespace std;

/* The code is from: f-Shell */
namespace num { /* 高精度运算 */
    string add(string a,string b) {
        int lena = a.length(),lenb = b.length();
        if(lena < lenb) {
            swap(lena,lenb);
            swap(a,b);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(lena-lenb) {
            b += "0";
            ++ lenb;
        }
        for(int i=0;i<lena;++i) {
            a[i] += b[i]-'0';
            if(a[i] > '9') {
                if(i != lena-1) a[i+1] += 1;
                else            a += "1";
                a[i] -= 10;
            }
        }
        reverse(a.begin(),a.end());
        return a;
    }
    string subtra(string a,string b) {
        int lena=a.length(),lenb=b.length();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(lena-lenb) {
            b += "0";
            ++ lenb;
        }
        for(int i=0;i<lena;++ i) {
            a[i] -= b[i]-'0';
            if(a[i] < '0') {
                a[i] += 10;
                a[i+1] -= 1;
            }
        }
        reverse(a.begin(),a.end());
        while(a[0] == '0' && a[1] != '\0') a = a.substr(1,lena-1);
        return a;
    }
    bool compare(string a,string b) {
        int lena = a.length(),lenb = b.length();
        if(lena != lenb) return lena < lenb;
        for(int i=0;i<lena;++i) if(a[i] != b[i]) return a[i] < b[i];
        return false;
    }
    string full_subt(string a,string b) {
        if(compare(a,b)) return subtra(a,b);
        return "-"+subtra(b,a);
    }
    string mul(string a,string b) {
        string rt;
        int lena=a.length(),lenb=b.length();
        if(lena > 300 || lenb > 300) return "";
        int ai[301]={},bi[301]={},jw,c[602]={},lenc=lena+lenb;
        for(int i=0;i<lena;++i) ai[lena-i-1] = a[i]-'0';
        for(int i=0;i<lenb;++i) bi[lenb-i-1] = b[i]-'0';
        for(int i=0;i<lena;++i) {
            jw = 0;
            for(int j=0;j<lenb;++j) {
                c[i+j] += ai[i]*bi[j]+jw;
                jw = c[i+j] / 10;
                c[i+j] %= 10;
            }
            c[i+lenb] = jw;
        }
        for(int i=lenc-1;i>=0;--i) {
            if(c[i] == 0 && lenc > 1) --lenc;
            else                      break;
        }
        for(int i=lenc-1;i >= 0;--i) rt += c[i]+'0';
        return rt;
    }
}

namespace cl {
    Rt calc(vector<string>,bool);
}

namespace bl {
    bool cl(vector<string> exp) {
        Rt ret = cl::calc(exp,true);
        bool r;
        switch(ret.rt_type) {
            case INT:
                r = ret.value != "0";
                break;
            case STR:
                r = str::no_yinghao(ret.value) != "";
                break;
            case BOOL:
                r = ret.length;
                break;
            default:
                r = false;
                break;
        }
        return r;
    }
}

namespace cl {
    int get_level(string s,int cnt) { /* 应该不会有人写2147483647个括号 */
        if(cnt) cnt += 114;
        if(s == "=") return cnt; /* 0+cnt */
        else if(s == "+" || s == "-") return 1+cnt;
        else if(s == "*" || s == "/") return 2+cnt;
        else if(s == "**" || s == "%") return 3+cnt;
        else if(s == "==" || s == "!=") return 4+cnt;
        return -1;
    }
    int getmin(vector<string> express) {
        int cnt = 0,index = -1,minx = 2147483647,len=express.size(),t;
        for(int i=0;i<len;++i) {
            if(express[i] == "(") {
                cnt++;
                continue;
            }
            else if(express[i] == ")") {
                cnt--;
                continue;
            }
            if((t=get_level(express[i],cnt)) != -1 && t < minx) {
                minx = t;
                index = i;
            }
        }
        return index;
    }
    Rt calc(vector<string> express,bool check=true) {
        Rt ret;
        ret.rt_type = INT;
        int len = express.size(),index;
        if(express[0] == "(" && len != 1 && express[len-1] == ")") {
            express.erase(express.begin());
            express.pop_back();
            len -= 2;
        }
        if(len == 1) {
            if(check) vr::check(express[0]);
            ret.value = express[0];
            return ret;
        }
        index = getmin(express);
        vector<string> left (express.begin(),express.begin()+index),
                       right (express.begin()+index+1,express.end());
        /* 判断运算符 */
        switch(express[index][0]) {
            case '+':
                ret.value = num::add(calc(left).value,calc(right).value);
                break;
            case '-':
                ret.value = num::subtra(calc(left).value,calc(right).value);
                break;
            case '*':
                ret.value = num::mul(calc(left).value,calc(right).value);
                break;
            case '/':
                ret.value = num::add(calc(left).value,calc(right).value);
                break;
            case '=':
                if(express[index].length() > 1) {
                    ret.rt_type = BOOL;
                    ret.length = calc(left).value == calc(right).value;
                } else {
                    ret = calc(right);
                    vr::new_glb(left[0],ret.value);
                }
                break;
            case '!':
                if(express[index].length() > 1) {
                    ret.rt_type = BOOL;
                    ret.length = calc(left).value != calc(right).value;
                }
                break;
        }
        return ret;
    }
}


#endif