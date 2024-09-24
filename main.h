#include "run.h"
#include "head/mode_cli.h"

std::string n,cmd;
std::vector<std::string> lines;
bool commenting = false;
int sz;
Rt var_line = {.rt_type=INT,.label=CONST};

req::Req chuli_code(string code,bool quiting=true) {
    err::Error e;
    req::Req r = run::run_code(code);
    e.num = r.error;
    e.content = err::error_tips[e.num];
    if(e.num != NO_ERROR) e.show(quiting);
    return r;
}

void get_help(void) {
    cout << "Using '.exit' to exit.\n";
    cout << "Using '.help' to get help.\n";
}

void mode_cli(void) {
    while(true) {
        cout << "> ";
        getline(cin,cmd);
        str::replace(cmd,"\t"," ");
        if(ci::cli_kws.count(cmd)) {
            if((ci::cli_kws[cmd])()) break;
        }else chuli_code(cmd,false);
    }
}

bool check_line(int& len,std::string& i,int l) {
    if(len >= 1 && i[len-1] == ';') {
        i.pop_back();
        -- len;
    }
    if(i == "/*") return commenting = true; /* 代码规范是什么？我不知道！ */
    else if(len-1 >= 0 && i[len-1] == '{') {
        Sentence s={.num=0,.begin_pos=l-1};
        run::loops.push_back(s);
    }
    return false;
}