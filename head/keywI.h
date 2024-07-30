#ifndef _NING_KEYWI_H
#define _NING_KEYWI_H

#include <string>
#include <vector>
#include <iostream>
#include "str.h"
#include "types.h"
using namespace std;

namespace kw {
    int print(vector<string> cont,string ed="\n",string sep="") {
        int len = cont.size();
        for(int i=0;i<len;++i) {
            string ci = cont[i];
            if(ci == "print") continue;
            else if(ci == ";") break;
            else if(tp::isNum(ci) || tp::isBool(ci)) cout << ci << sep;
            else if(tp::isStr(ci)) cout << str::no_yinghao(str::escape(ci)) << sep;
            else return -1;
        }
        cout << ed;
        return 0;
    }
} 

#endif