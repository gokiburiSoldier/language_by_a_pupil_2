/*
 * 可以当作是JSON
 */

#ifndef _NING_RT_H
#define _NING_RT_H


#include <string>
#include <vector>
#include "types.h"

struct Rt {
    int rt_type;
    std::string value;
    int length = -1;
    std::vector<int> label = {VAR};
};

#endif