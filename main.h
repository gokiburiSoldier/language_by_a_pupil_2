#include <string>
#include <vector>

std::string n;
std::vector<std::string> lines;
bool commenting = false;

void chuli_code(string code) {
    err::Error e;
    switch(run::run_code(code)) {
        case FILE_NOT_FOUND:
            e.content = "File Not Found";
            e.num     = FILE_NOT_FOUND;
            break;
        case SYNAX_ERROE:
            e.content = "Synax Error";
            e.num     = SYNAX_ERROE;
            break;
        case DEF_AGAIN:
            e.content = "Define Again";
            e.num     = DEF_AGAIN;
            break;
        case ERR_TYPE:
            e.content = "Type Error";
            e.num     = ERR_TYPE;
            break;
        case ASSIGN_CONST:
            e.content = "Try to fuzhi a const";
            e.num     = ASSIGN_CONST;
            break;
        case NOT_FOUND_KEY:
            e.content = "Keyword Not Found";
            e.num     = NOT_FOUND_KEY;
            break;
        case NO_ERROR:
            e.num = NO_ERROR;
            break;
    }
    if(e.num != NO_ERROR) e.show();
}