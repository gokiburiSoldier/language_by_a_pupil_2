/*
 * 十年OI一场空 不开long long见祖宗
 * 长期CSP/GESP/NOI导致的
 * Blue Archive,启动！
 */
#include "main.h"

int main(int argc,char* argv[]) {
    str::init();
    err::init();
    ci::init();
    vr::global_const();
    #ifdef _WIN32 /* Windows用户 */
    fs::init();
    #endif
    if(argc > 1 && (string)argv[1] != "-c") {
        /* 为什么用static_case? 因为它善 */
        lines = fs::readf(static_cast<string>(argv[1]));
        sz = lines.size();
        for(int line_num=0;line_num<sz;++line_num) {
            var_line.value = tr::int_to_str(line_num+1);
            vr::variables["$__line__"] = var_line;
            std::string i = lines[line_num];
            str::replace(i,"\t"," "); /* 为什么vim和Dev-CPP默认是Tab！！为什么用Dev-CPP写！！！ */
            int len = i.length();
            str::strip(i,len);
            if(commenting) {
                commenting = str::count(i,"*/") != 1;
                continue;
            }
            /* 盲猜一波 len不可能为0 */
            if(check_line(len,i,line_num)) continue;
            req::Req res = chuli_code(i); /* 满级命名 */
            if(res.jumping != -1) line_num = res.jumping;
            else if(!res.running) while(line_num < sz && lines[line_num].find('}') == string::npos) ++ line_num;
        }
    }else if(argc > 1 && (string)argv[1] == "-c") mode_cli();
    else {
        printf("使用 -c 选项进入命令行模式\n");
    }

    return 0; /* 震惊！我竟然会写 `return 0;` ! */
}
