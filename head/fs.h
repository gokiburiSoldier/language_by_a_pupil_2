#include <fstream>
#include <vector>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

namespace fs {
    #ifdef _WIN32
    /* 用什么破Windows */
    void init(void) {
        SetConsoleOutputCP(CP_UTF8);
    }
    #endif
    std::vector<std::string> readf(std::string address) {
        std::vector<std::string> rt;
        std::ifstream fin(address);
        std::string line;
        while(getline(fin,line)) {
            #ifdef __linux__
            line.pop_back(); /* 行尾的回车((char)(13)) */
            #endif
            rt.push_back(line);
        }
        return rt;
    }
    void writef_v(std::string address,std::vector<std::string> cnt) {
        std::ofstream fout;
        std::string str;
        int len = cnt.size();
        for(int i=0;i<len;++i) str += cnt[i]+"\n";
        fout << str;
    }
    void writef(std::string address,std::string cnt) {
        std::ofstream fout;
        fout << cnt;
    }
}