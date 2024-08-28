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
            if(ci == "print") continue;
            else if(ci == "," || ci == ";") {
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
    print = 236174,
    input = 211898,
    var = 185766,
    if_ = 87449,
    while_ = 218878,
    seted = 323176,
    setsp = 421085,
    plusplus = 29141,
    jump = 301003,
    const_ = 262808; /* ++ */
}

#endif