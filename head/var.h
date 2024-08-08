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

    int new_glb(string name,string val) {
        Rt v;
        if(variables.count(name)) v = variables[name];                         
        int ty = tp::getType(val);
        if(ty == -1) return ERR_TYPE;
        v.rt_type = ty;
        v.value = val;
        if(ty == STR) v.length = val.length()-2;
        variables[name] = v;
        /*for(map<string,Rt>::iterator i = variables.begin();i != variables.end(); ++ i) 
            cout << i->first << "->" << i->second.value << endl;*/
        return NO_ERROR;
    }
} 
#endif