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
#include "head/keywI.h"

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
                if(c == '/' && i != len-1 && sent[i+1] == '/') { /* 注释 */
                    rt.pop_back();
                    return rt;
                }
                break;
            case '#': /* 也是注释 */
                if(token != "") rt.push_back(token);
                return rt;
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

int run_sent(vector<string> sent) {
    if(sent.empty()) return NO_ERROR;
    long long key = getcode(sent[0]);
    switch(key) {
        case kw_cd::print:
            kw::print(sent);
            break;
        case kw_cd::var:
            if(sent.size() < 4 && sent[2] != "=") return NO_ERROR; /* 到时候记得改 */
            vr::new_glb(sent[1],sent[3]);
            break;
        default:
            return NOT_FOUND_KEY;
            break;
    }
    return NO_ERROR;
}

}
#endif