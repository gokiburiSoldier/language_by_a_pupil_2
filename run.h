#include <map>

#include "head/stdhead.h"
#include "head/rt.h"
#include "head/trans.h"
#include "head/types.h"
#include "head/fs.h"
#include "head/error.h"

class runner {
    private:
        map<string,Rt> vars;
    public:
        runner() {}
        ~runner() {}

        int new_var(string name,string value) {
            if(vars.count(name)) 
                return DEF_AGAIN;
            Rt val;
            val.value = value;
            int type = tp::getType(value);
            if(type == -1) return SYNAX_ERROE;
            val.rt_type = type;
            vars[name] = val;
            return NO_ERROR;
        }
};