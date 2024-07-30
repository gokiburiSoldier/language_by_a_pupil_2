#ifndef _NING_STR_H
#define _NING_STR_H

#include <string>
#include <map>
#include <stdio.h>

namespace str {
    std::map<std::string,std::string> escaping;
    bool inited = false;
    void init(void) {
        if(inited) return;
        inited = true;
        escaping["\\t"] = "\t";
        escaping["\\n"] = "\n";
        escaping["\\033"] = "\033";
        return;
    }
    std::string escape(std::string s) {
        for(std::map<std::string,std::string>::iterator i=escaping.begin();i != escaping.end();++i) {
            int a = s.find(i->first);
            while(a != std::string::npos) {
                s = s.replace(a,a+(i->first.length())-1,i->second);
                a = s.find(i->first);
            }
        }
        return s;
    }

    std::string no_yinghao(std::string s) {
        return s.substr(1,s.length()-2);
    }
}

#endif