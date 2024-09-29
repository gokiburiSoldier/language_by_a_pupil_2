#ifndef _NING_ERROR_H
#define _NING_ERROR_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>

#define FILE_NOT_FOUND 0xe00
#define SYNAX_ERROE    0xe01 /* 我的天那 写了这么久 没发现是"E" */
#define DEF_AGAIN      0xe02
#define ERR_TYPE       0xe03
#define ASSIGN_CONST   0xe04
#define NOT_FOUND_KEY  0xe05

#define NO_ERROR 114514

namespace err {
    struct Error {
        int num = FILE_NOT_FOUND;
        std::string content = "文件未找到";
        void show(bool quit=true) {
            std::cerr << "\033[31mError: " << content << " (0x" << std::hex << num << std::dec << ")\033[0m\n";
            if(quit) exit(0);
        }
    };
    std::map<int,std::string> error_tips;
    void init(void) {
        error_tips[FILE_NOT_FOUND] = "File Not Found Error";
        error_tips[SYNAX_ERROE] = "Synax Error";
        error_tips[DEF_AGAIN] = "Define Again";
        error_tips[ERR_TYPE] = "Type Error";
        error_tips[ASSIGN_CONST] = "Try to Assign a Constant";
        error_tips[NOT_FOUND_KEY] = "Keyword Not Found";
        error_tips[NO_ERROR] = "";
    }
}

#endif