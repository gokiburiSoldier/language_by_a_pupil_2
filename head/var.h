#ifndef _NING_VAR_H
#define _NING_VAR_H

#include "stdhead.h"
#include "rt.h"
#include "trans.h"
#include "error.h"
#include "../get_code.h"
#include <map>
using namespace std;

namespace vr {
    map<string,Rt> variables;

    int new_glb(string name,string val,bool isConst=false) {
        Rt v;
        if(variables.count(name)) {
            if(variables[name].label == CONST) return ASSIGN_CONST;
            v = variables[name];
        }
        int ty = tp::getType(val);
        if(ty == -1) return ERR_TYPE;
        v.rt_type = ty;
        v.value = val;
        if(ty == STR) v.length = val.length()-2;
        if(isConst) v.label = CONST;
        variables[name] = v;
        return NO_ERROR;
    }
    void check(string &str) {
        if(variables.count(str)) str = variables[str].value;
    }
    void get(void) {
        for(map<string,Rt>::iterator i = variables.begin();i != variables.end(); ++ i) 
            cout << i->first << "->" << i->second.value << endl;
    }
    void global_const(void) {
        Rt temp_const;
        /* NML版本 */
        temp_const.label = CONST;
        temp_const.rt_type = INT;
        temp_const.value = tr::int_to_str(nml_version);
        variables["$__ver__"] = temp_const;
    }
} 
#endif