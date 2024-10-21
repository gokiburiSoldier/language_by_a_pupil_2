/* 
 * 仅供娱乐
 * Only For Entertainment
 * 话说这么写可以读懂吗 
 */

#define 模板 template
#define 类 class
#define 私 private
#define 公 public
#define 指针 *
#define 取 *
#define 址 &
#define 此 this
#define 新 new
#define 回 return
#define 复 for
#define 符 operator
#define 空 void
#define 常 const
#define 删 delete
#define 增 ++
#define 减 --
#define 为 =
#define 若 if
#define 反之 else

模板<类 型>
类 向量 {
    私:
        int 最,长;
        型 指针 数组;
    公:
        向量(int 预留 为 1145) {
            此->最 为 预留;
            此->长 为 0;
            此->数组 为 新 型 [预留];
            复(int 次 为 0;次<预留;次 增) 
                此->数组[次] 为 0;
        }
        ~ 向量() {
            删 [] 此->数组;
        }
    公:
        型 指针 头(空) 常 {
            回 此->数组;
        }
        型 指针 尾(空) 常 {
            回 此->数组 + 此->长 + 1;
        }
        型 址 符 [] (int 处) 常 {
            回 此->数组 [处];
        }
        int 大小(空) 常 {
            回 此->长;
        }
        空 入(型 物) {
            若(此->长 + 1 >= 此->最) 回;
            此->数组 [此->长 增] 为 物;
        }
        型 出(空) {
            型 物 为 此->数组[减 此->长];
            此->数组[此->长] 为 0;
            回 物;
        }
        空 去(型 指针 始) {
            型 指针 终 = 此->数组 + 此->长 + 1;
            复(型 指针 次 为 始;次 != 终; 次 增)
                取 次 为 取 (次 + 1);
        }
};

#undef 模板
#undef 类
#undef 私
#undef 公
#undef 指针
#undef 取
#undef 址
#undef 此
#undef 新
#undef 回
#undef 复
#undef 符
#undef 空
#undef 常
#undef 删
#undef 增
#undef 减
#undef 为
#undef 若
#undef 反之

/* 
 * 写的时候可能精神状态不是很好
 * ~~梓，我的梓！~~
 * ~~其实梓是我的第一个三星 没想到吧（~~
 * 话说这玩意编译能过？
 */
