#ifndef _NML_FN_H
#define _NML_FN_h

#include <string>
#include "req.h"
#include "error.h"

#define IMPORT 0xa1
#define BUILDIN 0xa2
#define USERDEF 0xa3

namespace fn {
    struct arg {
        /* 函数参数统一结构 */
        std::string str;
        int a,b;
    };
    class func {
        private:
            int line=-1;
            void (*f)(arg args);
            arg a;
        public:
            func(int line) { /* 自定义的函数 */
                this->line = line;
            }
            func(void (*function)(arg),arg a) { /* Nmlang自带的函数 */
                this->f = function;
                this->a = a;
            }
            req::Req call() {
                req::Req ret;
                ret.error = NO_ERROR;
                if(this->line != -1) ret.jumping = this->line;
                else ((*(this->f))(this->a)); /* 这应该是我写过最复杂的表达式了 而且还用了指针*/
                return ret;
            }
    };
}


#endif