#ifndef _NING_CLAC_H
#define _NING_CLAC_H

#include <algorithm>
#include <string>
#include "rt.h"
#include "types.h"
#include "var.h"
#define ERR 0x104
using namespace std;

/* The code is from: f-Shell */
namespace num {
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

namespace bl {
    ;
}

namespace cl {
    Rt calc(vector<string> express) {
        int len = express.size(),t;
        Rt ret;
        string elem;
        switch(len) {
            case 0:
                ret.rt_type = ERR;
                break;
            case 1:
                elem = express[0];
                if(vr::variables.count(elem)) elem = vr::variables[elem].value;
                t = tp::getType(elem);
                ret.value = elem;
                if(t != -1) {
                    ret.rt_type = t;
                    break;
                }
                ret.rt_type = ERR;
                break;
            default:
                ret.rt_type = ERR;
        }
        return ret;
    }
}


#endif