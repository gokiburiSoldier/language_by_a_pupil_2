/*
 * 十年OI一场空 不开long long见祖宗
 */

#include "run.h"
#include "head/keywI.h"
#include "main.h"

int main(int argc,char* argv[]) {
    str::init();
    for(int i=0;i<2;++i) {
        getline(cin,n);
        vector<string> v = run::sent_split(n);
        run::run_sent(v);
    }
}