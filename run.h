#ifndef _NING_RUN_H
#define _NING_RUN_H

#include <map>

#include "head/stdhead.h"
#include "head/rt.h"
#include "head/trans.h"
#include "head/types.h"
#include "head/fs.h"
#include "head/error.h"
#include "head/var.h"

namespace run {

vector<string> sent_split(string sent) {
    int len = sent.length();
    string token,t;
    vector<string> rt,r;
    char c,sign;
    bool stringing = false;
    for(int i=0;i<len;++ i) {
        c = sent[i];
        if(stringing) {
            token += c;
            if(c == sign) {
                stringing = false;
                rt.push_back(token);
                token = "";
            }
            continue;
        }
        switch(c) {
            case ' ':
                if(token != "") rt.push_back(token);
                token = "";
                break;
            case ',':
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
                t = "";
                t += c;
                if(token != "") rt.push_back(token);
                token = "";
                rt.push_back(t);
                if(c == '/' && i != len-1 && sent[i+1] == '/') {
                    rt.pop_back();
                    return rt;
                }
                break;
            case '\'':
            case '"':
                sign = c;
                stringing = true;
                /* 这里不应该写`break;` */
            default:
                token += c;
        }
    }
    if(token != "") rt.push_back(token);
    return rt;
}

}
#endif