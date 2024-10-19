#ifndef _Z_STL_STR
#define _Z_STL_STR

class string {
    private:
        int len;
        char str_bas[114514]; /* 没什么好说的了 */
    public:
        string(void) {
        }
        string(const char right[]) {
            int i=0;
            while(right[i]) {
                str_bas[i] = right[i];
                i++;
            }
            len = i;
        }
        const char* operator= (const char right[]) {
            int i=0;
            while(right[i]) {
                str_bas[i] = right[i];
                i++;
            }
            len = i;
            return right;
        }
        bool operator== (string other) {
            int ol = other.length();
            if(this->len != ol) return false;
            for(int i=0;i<ol;i++) if(this->str_bas[i] != other[i]) return false;
            return true;
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
        char operator+= (char right) {
            this->str_bas[this->len++] = right;
            return right;
        }
        string substr(int begin,int lent) {
            string ret;
            for(int i=0;i<lent;i++) ret += this->str_bas[i+begin];
            return ret;
        }
};

#endif
