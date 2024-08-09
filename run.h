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
#include "head/req.h"

namespace run {

int record = 0,now = -1;
bool looping = false;

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
            case '{':
            case '}':
            case '!':
                t = "";
                t += c;
                if(token != "") rt.push_back(token);
                token = "";
                rt.push_back(t);
                if(c == '/' && i != len-1 && sent[i+1] == '/') { /* 注释 */
                    rt.pop_back();
                    return rt;
                }else if((c == '=' || c == '!') && i != len-1 && sent[i+1] == '=') {
                    rt.pop_back();
                    t += "=";
                    t[0] = c;
                    rt.push_back(t);
                    ++ i;
                }else if(c == '+' && i != len-1 && sent[i+1] == '+') {
                    rt.pop_back();
                    rt.push_back("++");
                    ++ i;
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

req::Req run_sent(vector<string> sent) {
    req::Req ret;
    if(sent.empty()) {
        ret.error = NO_ERROR;
        return ret;
    }
    long long key = getcode(sent[0]);
    int sz;
    switch(key) {
        case kw_cd::print:
            kw::print(sent);
            break;
        case kw_cd::var:
            if(sent.size() == 2) {
                vr::new_glb(sent[1],"0");
                break;
            }
            if(sent.size() < 4 && sent[2] != "=") {
                ret.error =  SYNAX_ERROE;
                return ret;
            }
            vr::new_glb(sent[1],sent[3]);
            break;
        case kw_cd::seted:
            if(sent.size() < 2) {
                ret.error =  SYNAX_ERROE;
                return ret;
            }
            vr::check(sent[1]);
            if(!tp::isStr(sent[1])) {
                ret.error =  SYNAX_ERROE;
                return ret;
            }
            sent[1] = str::no_yinghao(str::escape(sent[1]));
            kw::seted(sent[1]);
            break;
        case kw_cd::setsp:
            if(sent.size() < 2) {
                ret.error =  SYNAX_ERROE;
                return ret;
            }
            vr::check(sent[1]);
            if(!tp::isStr(sent[1])) {
                ret.error =  SYNAX_ERROE;
                return ret;
            }
            sent[1] = str::no_yinghao(str::escape(sent[1]));
            kw::setsep(sent[1]);
            break;
        case kw_cd::input:
            if(sent.size() < 2) {
                ret.error =  SYNAX_ERROE;
                return ret;
            }
            else if(!vr::variables.count(sent[1])) {
                ret.error =  SYNAX_ERROE;
                return ret;
            } /* 到时候改 */
            else if(sent.size() > 3) {
                if(sent[2] != ",") {
                ret.error =  SYNAX_ERROE;
                return ret;
            }
                if(!tp::isStr(sent[3])) {
                ret.error =  ERR_TYPE;
                return ret;
            }
                cout << str::no_yinghao(str::escape(sent[3]));
            }else if(sent.size() == 3) {
                ret.error =  SYNAX_ERROE;
                return ret;
            }
            vr::variables[sent[1]].rt_type = STR;
            getline(cin,vr::variables[sent[1]].value);
            vr::variables[sent[1]].value = "\""+vr::variables[sent[1]].value+"\"";
            break;
        case kw_cd::if_:
            sz = sent.size();
            if(sz < 3 && sent[sz-1] != "{") {
                ret.error = SYNAX_ERROE;
                return ret;
            }
            sent.pop_back();
            sent.erase(sent.begin());
            ret.running = bl::cl(sent);
            ret.error = NO_ERROR;
            return ret;
            break;
        case kw_cd::plusplus:
            if(sent.size() < 2) {
                ret.error = SYNAX_ERROE;
                return ret;
            }
            if(!vr::variables.count(sent[1])) {
                ret.error = NOT_FOUND_KEY;
                return ret;
            }
            else if(!tp::isNum(vr::variables[sent[1]].value)) {
                ret.error = ERR_TYPE;
                return ret;
            }
            vr::variables[sent[1]].value = num::add(vr::variables[sent[1]].value,"1");
            break;
        case kw_cd::jump:
            if(sent.size() < 2) {
                ret.error = SYNAX_ERROE;
                return ret;
            }
            vr::check(sent[1]);
            if(!tp::isNum(sent[1])) {
                ret.error = ERR_TYPE;
                return ret;
            }
            ret.jumping = tr::str_to_int(sent[1])-1;
            break;
        case 100224: /* 100224 -> getcode("}") */
            break;
        default:
            ret.error =  NOT_FOUND_KEY;
            return ret;
            break;
    }
    ret.error = NO_ERROR;
    return ret;
}

req::Req run_code(string code) {
    ++ now;
    return run_sent(sent_split(code));
}

}
#endif