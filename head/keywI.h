#ifndef _NING_KEYWI_H
#define _NING_KEYWI_H

#include <string>
#include <vector>
#include <iostream>
#include "str.h"
#include "types.h"
#include "calc.h"
using namespace std;

namespace kw {
    string ed = "\n",sep = "";
    int print(vector<string> cont) {
        cont.push_back(",");
        int len = cont.size();
        vector<string> every_unit;
        for(int i=0;i<len;++i) {
            string ci = cont[i];
            if(ci == "," || ci == ";") {
                Rt out = cl::calc(every_unit);
                if(out.rt_type == ERR) return -1;
                else if(out.rt_type != STR) cout << out.value;
                else cout << str::no_yinghao(str::escape(out.value));
                every_unit.clear();
                if(i+1-len) cout << sep;
                if(ci == ";") break;
            }else every_unit.push_back(ci);
        }
        cout << ed;
        return 0;
    }
    int seted(string e) {
        ed = e;
        return 0;
    }
    int setsep(string s) {
        sep = s;
        return 0;
    }
} 

namespace kw_cd {
    const long long 
    print = 4397,
    input = 11946,
    var = 12288,
    if_ = 857,
    while_ = 15023,
    seted = 19654,
    setsp = 15013,
    plusplus = 430,
    jump = 17367,
    const_ = 13299; /* ++ */
}

#endif