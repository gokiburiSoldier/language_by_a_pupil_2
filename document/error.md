# `${workspaceFloder}/head/error.h` API文档

## 头文件
- `string`
- `cstdlib`
- `iostream`

头文件宏名: `_NING_ERROR_H`

## API

| 名称 | 类型 | 参数(成员) |
| ---  | ---- | --------- |
| `NO_ERROR` | 宏 | 无 |
| `FILE_NOT_FOUND` | 宏 | 无 |
| `SYNAX_ERROE` | 宏 | 无 |
| `DEF_AGAIN` | 宏 | 无 |
| `ERR_TYPE` | 宏 | 无 |
| `ASSIGN_CONST` | 宏 | 无 |
| `err::Error` | `struct` | *num `int`*<br>*content `std::string`* |
| `err::Error`的`show`方法 | `void` | *quit `bool` (是否退出程序 默认值为`true`)* |