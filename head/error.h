#include <string>
#include <cstdlib>
#include <iostream>

#define FILE_NOT_FOUND 0xe00
#define SYNAX_ERROE    0xe01
#define DEF_AGAIN      0xe02

#define NO_ERROR 114514

namespace err {
    struct Error {
        int num = FILE_NOT_FOUND;
        std::string content = "文件未找到";
        void show(bool quit=true) {
            std::cerr << "\033[31mError: " << content << " (0x" << std::hex << num << std::dec << ")\033[0m";
            if(quit) exit(0);
        }
    };
}