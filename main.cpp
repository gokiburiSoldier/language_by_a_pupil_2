/*
 * 十年OI一场空 不开long long见祖宗
 */
#include "main.h"

int main(int argc,char* argv[]) {
    str::init();
    if(argc > 1) {
        /* 为什么用static_case? 因为它善 */
        lines = fs::readf(static_cast<string>(argv[1]));
        sz = lines.size();
        for(int l=0;l<sz;++l) {
            std::string i = lines[l];
            int len = i.length();
            if(commenting) {
                if(str::count(i,"*/") == 1) commenting = false;
                continue;
            }
            /* 盲猜一波 len不可能为0x0 */
            if(len-1 > 0 && i[len-1] == ';') {
                i.pop_back();
                -- len;
            }
            if(i == "/*") {
                commenting = true;
                continue;
            }
            else if(len-1 >= 0 && i[len-1] == '{') {
                Sentence s;
                s.begin_pos = l-1;
                //cout << "  " << l << endl;
                run::loops.push_back(s);
            }
            req::Req res = chuli_code(i);
            if(res.jumping != -1) l = res.jumping;
            else if(!res.running) {
                while(l < sz && lines[l].find('}') == string::npos) ++ l;
            }
        }
    }
}