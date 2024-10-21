/*
 * 可以当作是JSON
 */

#ifndef _NING_RT_H
#define _NING_RT_H

#include <string>
#include <vector>
#include "types.h"
#include "error.h"

#if 0
struct arg {
    std::string str;
    int num;
};

class basic_object {
    public:
        vector<arg> all_values;
    public:
        void set_kv(arg val) {
            this->all_values.push_back(val);
        }
        virtual basic_object to_object(void);
        virtual void call(int/* 操作指令 */,void* /* 操作参数 */ );
};

class Rt2 : public basic_object {
    private:
        int rt_type;
        std::string value;
        int length;
        int label;
    private:
        int GETYPE,GETVAL,LENG,LABEL;
    public:
        Rt2() {
            GETYPE=1;
            GETVAL=2;
            LENG=3;
            LABEL=4;
        }
        basic_object to_object(void) {
            basic_object ret;
            arg a;
            a.str = "rt_type";
            a.num = GETYPE;
            ret.all_values.push_back(a);
            a.str;
            return ret;
        }
        void call(int,void*);
};
#endif

struct Rt {
    int rt_type;
    std::string value;
    int length;
    int label;
};

struct sent_stack {
    long long num;
    int begin_pos;
};

/*
template<class T>
class varp {
    private:
        T val;
        int length;
        static bool isConst;
    public:
        varp(bool ic = true) {
            this->isConst = ic;
        }
        T get_val(void) const {return this->val;}
        int assign(T v) {
            if(this->isConst) return ASSIGN_CONST;
            this->val = v;
            return NO_ERROR;
        }
};
*/

#endif