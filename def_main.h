#include "run.h"
#include "head/mode_cli.h"

std::string n,cmd;
std::vector<std::string> lines;
bool commenting = false;
int sz;
Rt var_line = {.rt_type=INT,.label=CONST};

req::Req chuli_code(string,bool);
void get_help(void);
void mode_cli(void);
bool check_line(int&,std::string&,int);

/* 我们至今不知道这个头文件有毛用 */