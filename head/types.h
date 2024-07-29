#ifndef _NING_TYPES_H
#define _NING_TYPES_H

#include <string>

#define INT 0x101
#define BOOL 0x102
#define STR 0x103

#define VAR 0x004
#define FUNC 0x005
#define KEY 0x006
#define CONST 0x007

namespace tp {
    bool isNum(std::string n) {
        bool floating = false;
        int len = n.length();
        for(int i=0;i < len;++ i) 
            if(n[i] >= '0' && n[i] <= '9') 
                continue; 
            else if(n[i] == '.') if(floating) return false;
                                 else         floating = true;
            else 
                return false;
        return true;
    }
    bool isStr(std::string s) {
        int end = s.length()-1;
        return s[0] == '"' && s[end] == '"' || s[0]=='\'' && s[end] == '\'';
    }
    bool isBool(std::string b) {
        return b == "true" || b == "false";
    }

    int getType(std::string s) {
        if(isNum(s)) return INT;
        else if(isStr(s)) return STR;
        else if(isBool(s)) return BOOL;
        else return -1;
    }
}

#endif