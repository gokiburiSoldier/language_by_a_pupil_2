/*
 * 十年OI一场空 不开long long见祖宗
 */

#include "run.h"
#include "head/keywI.h"
#include "main.h"

int main(int argc,char* argv[]) {
    str::init();
    getline(cin,n);
    vector<string> v = run::sent_split(n);
    kw::print(v);
}