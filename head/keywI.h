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
    int print(vector<string> cont,string ed="\n",string sep="") {
        cont.push_back(",");
        int len = cont.size();
        vector<string> every_unit;
        for(int i=0;i<len;++i) {
            string ci = cont[i];
            if(ci == "print") continue;
            else if(ci == ";") break;
            else if(ci == ",") {
                Rt out = cl::calc(every_unit);
                if(out.rt_type == ERR) return -1;
                else if(out.rt_type != STR) cout << out.value << sep;
                else cout << str::no_yinghao(str::escape(out.value)) << sep;
                every_unit.clear();
            }else every_unit.push_back(ci);
        }
        cout << ed;
        return 0;
    }
} 

namespace kw_cd {
    const long long 
    print = 236174,
    input = 211898,
    var = 185766,
    if_ = 87449,
    for_ = 83298,
    while_ = 218878;
}


#endif