#ifndef _NING_STR_H
#define _NING_STR_H

#include <string>
#include <map>
#include <stdio.h>
#include <algorithm>

namespace str {
    std::map<std::string,std::string> escaping;
    bool inited = false;
    void replace(string &str,string before,string after) {
        int len = before.length(),
            lens = str.length();
        for(int i=0;i<lens-len;++i) 
            if(str.substr(i,len) == before) str.replace(i,len,after);
    }
    int count(string str,string fd) {
        int ret = 0,lena = str.length(),lenb = fd.length();
        for(int i=0;i<=lena-lenb;++i) 
            if(str.substr(i,lenb) == fd) ++ret;
        return ret;
    }
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
            replace(s,i->first,i->second);
        }
        return s;
    }

    std::string no_yinghao(std::string s) {
        return s.substr(1,s.length()-2);
    }
    void strip(std::string& str,int& len) {
        while(len && str[len-1] == ' ') {
            str.pop_back();
            len--;
        }
    }
}

#endif