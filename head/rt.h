/*
 * 可以当作是JSON
 */

#include <string>
#include <vector>
#include "types.h"

struct Rt {
    int rt_type;
    std::string value;
    int length = -1;
    std::vector<int> label = {VAR};
};