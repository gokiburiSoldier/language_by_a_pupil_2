/*
 * 可以当作是JSON
 */

#ifndef _NING_RT_H
#define _NING_RT_H


#include <string>
#include <vector>
#include "types.h"
#include "error.h"

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