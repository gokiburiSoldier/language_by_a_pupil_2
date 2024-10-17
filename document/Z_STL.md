# 直接手搓STL (`${workspaceFloder}/z_stl`目录)

| 文件名 | 描述 | 参数 | 实例 | 成员 |
| ----  | --- | --- | ---- | --- |
| vector.h | 利用动态数组 手搓vector | 模板参数: 一个类型, <br> 参数: 一个数字(表示最大大小)(默认为1145) | 见例I | 见 方法/vector |

# 例子

## 例I
```c++
#include "vector.h"
vector<int> vec;

int main(void) {
    vec.push_back(114514);
}
```

# 方法

## vector
| 函数名 | 作用 | 参数 |
| ----- | --- | ---- |
