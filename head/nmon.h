/* 
 * 一种数据结构
 * 此文件只是解析
 * 用于包时请见本目录下的 `package.h`
 */
#ifndef _NML_NMON_H
#define _NML_NMON_H

#include <string>
#include <vector>
#include "types.h"

namespace nn { /* 这什么破缩写 */
    struct key_val { /* 键值对 */
        std::string name;
        int type;
        std::string value;
        std::vector<std::string> address;
    };
    struct st { /* 结构体 */
        std::vector<std::string> address;
        std::vector<std::string> signs;
        std::vector<key_val> vars;
    };
    struct tag { /* 属性 */
        std::string text;
        std::string name;
        std::vector<key_val> attr;
        std::vector<std::string> address;
    };
    struct special { /* ~~后排 <-玩ブルーアーカイブ玩的~~ 特殊类别 */
        std::vector<std::string> address;
        std::vector<st> strs;
        std::vector<tag> tags;
    };
}


#endif