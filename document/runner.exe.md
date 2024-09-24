# `${workspaceFlodar}/runner.exe` 说明文档

## 源代码
```c++
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

string file,cmd;
clock_t start,ed;
int rt;

int main(int argc,char* argv[]) {
    if(argc < 2) return 1;
    file = argv[1];
    file = file.substr(0,file.length()-4);
    cmd = "g++ "+file+".cpp -o "+file+".exe";
    system(cmd.c_str());

    cmd = file;
    start = clock();
    rt = system(cmd.c_str());
    ed = clock();
    cout << "\n--------------------------------\n";
    cout << "Process exited after " << (double)(ed-start)/CLOCKS_PER_SEC << " seconds with return value " << rt << "\n";
    system("pause");
    return 0;
}
```

## 用法
PowerShell:
```bash
./runner "文件.cpp"
```

此程序会先对 "<font color="#CE9178" face="宋体"><s>文件.cpp</s></font>"