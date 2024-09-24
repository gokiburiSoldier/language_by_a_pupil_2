# `${workspaceFloder}/head/trans.h` API文档

## 头文件
- `string`

头文件宏: `_NING_TYPES_H`

## API
| 名称 | 类型 | 参数(成员) | 返回 |
| ---  | ---- | --------- | --- |
| `INT` | 宏 | 无 | 无 |
| `BOOL` | 宏 | 无 | 无 |
| `STR` | 宏 | 无 | 无 |
| `VAR` | 宏 | 无 | 无 |
| `FUNC` | 宏 | 无 | 无 |
| `KEY` | 宏 | 无 | 无 |
| `CONST` | 宏 | 无 | 无 |
| `tp::isNum` | `bool` | *n `std::string`* | *n*是否符合数字的标准 |
| `tp::isStr` | `bool` | *s `std::string`* | *s*是否符合字符串的标准 |
| `tp::isBool` | `bool` | *b `std::string`* | *b*是否符合布尔值的标准 |
| `tp::getType` | `bool` | *s `std::string`* | *s*的类型(前文的宏) 若无合适的则返回 <font color="yellow">-1</font> |