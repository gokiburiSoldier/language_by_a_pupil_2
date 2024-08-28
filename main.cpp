/*
 * 十年OI一场空 不开long long见祖宗
 */
#include "main.h"

int main(int argc,char* argv[]) {
    str::init();
    err::init();
    ci::init();
    if(argc > 1 && (string)argv[1] != "-c") {
        /* 为什么用static_case? 因为它善 */
        lines = fs::readf(static_cast<string>(argv[1]));
        sz = lines.size();
        for(int l=0;l<sz;++l) {
            var_line.value = tr::int_to_str(l+1);
            vr::variables["__line__"] = var_line;
            std::string i = lines[l];
            str::replace(i,"\t"," "); /* 为什么vim和Dev-CPP默认是Tab！！！ */
            int len = i.length();
            if(commenting) {
                commenting = str::count(i,"*/") != 1;
                continue;
            }
            /* 盲猜一波 len不可能为0x0 */
            if(check_line(len,i,l)) continue;
            req::Req res = chuli_code(i);
            if(res.jumping != -1) l = res.jumping;
            else if(!res.running) while(l < sz && lines[l].find('}') == string::npos) ++ l;
        }
    }else if(argc > 1 && (string)argv[1] == "-c") mode_cli();
    #ifdef _WIN32
    return 114514; /* 为什么return 114514?因为他善 */
    #else
    return 0;
    #endif
}