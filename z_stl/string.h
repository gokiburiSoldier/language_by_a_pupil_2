#ifndef _Z_STL_STR
#define _Z_STL_STR

class string {
    private:
        int len;
        char str_bas[114514]; /* 没什么好说的了 */
    public:
        string(void) {}
        string(const char right[]) {
            int i=0;
            while(right[i]) {
                str_bas[i] = right[i];
                i++;
            }
            len = i;
        }
    public:
        const char* c_str(void) const {
            return this->str_bas;
        }
        char& operator[] (int pos) {
            return this->str_bas[pos];
        }
        void pop_back(void) { /* 最重要的一点 */
            this->str_bas[--len] = 0;
        }
        int length(void) const {
            return this->len;
        }
};

#endif
