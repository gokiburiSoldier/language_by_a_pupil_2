#ifndef _Z_STL_LLL
#define _Z_STL_LLL

#include <stdio.h>

#ifndef byte
#define byte unsigned char
#endif

template<int len>
class longlonglong {
    private:
        byte* array;
        bool sign,isinf /* 在这里就要用掉2个字节（悲 */;
    public:
        longlonglong(void) {
            this->array = new byte [len];
            for(int i=0;i<len;i++) this->array[i] = 0;
            sign = 0;
            isinf=false;
        }
        longlonglong(long long right) {
            this->array = new byte [len];
            for(int i=0;i<len;i++) {
                this->array[i] = right % 100;
                right /= 100;
            }
            sign = 0;
            isinf=false;
        }
        longlonglong(const char str[]) {
            this->array = new byte [len];
            int l=0,p;
            while(str[l]) l ++;
            if(l >= 3 && str[0] == 'i' && str[1] == 'n' && str[2] == 'f') {
                isinf=true;
                return;
            }
            p = l >> 1;
            if(l&1) ++p;
            byte num=0;
            for(int i=0;i < l;++i) {
                num = num * 10 + str[i]-'0';
                if((l-i)&1) {
                    this->array[--p] = num;
                    num = 0;
                }
            }
            if(num) this->array[p]=num;
            sign = 0;
            isinf=false;
        }
        void print(const char* str="") const {
            bool out=false,first=false;
            if(this->isinf) {
                printf("infinite%s",str);
                return;
            }
            for(int i=len-1;i>=0;i--) {
                if(!out) out = this->array[i];
                if(out && first) {
                    printf("%02d",this->array[i]);
                }else if(out && !first) {
                    printf("%d",this->array[i]);
                    first = true;
                }
            }
            if(!out) printf("0");
            printf("%s",str);
        }
        byte operator[] (int index) const {
            return this->array[index];
        }
        bool is_infinite(void) const {
            return this->isinf;
        }
        longlonglong<len> operator+= (longlonglong<len> right) {
            short jw=0;
            if(this->isinf || right.is_infinite()) {
                this->isinf = true;
                return right;
            }
            for(int i=0;i<len;i++) {
                short n = (short)this->array[i] + (short)right[i] + jw;
                this->array[i] = n % 100;
                /* 进位计算 */
                jw = n / 100;
            }
            return right;
        }
};

typedef longlonglong<512> /* 应该够用了 */ longer;

#endif
