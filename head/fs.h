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
        std::string line;
        freopen(address.c_str(),"r",stdin);
        while(getline(cin,line)) 
            rt.push_back(line);
        fclose(stdin);
        return rt;
    }
    void writef_v(std::string address,std::vector<std::string> contents) {
        freopen(address.c_str(),"w",stdout);
        int len = contents.size();
        for(int i=0;i<len;i++) cout << contents[i] << "\n";
        fclose(stdout);
    }
    void writef(std::string address,std::string content) {
        freopen(address.c_str(),"w",stdout);
        cout << content << "\n";
        fclose(stdout);
    }
}
