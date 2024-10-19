#ifndef _Z_STL_MAP
#define _Z_STL_MAP

template<class K,class V>
class map {
    private:
        int maxs,len;
        K* keys;
        V* values;
    public:
        ~map() {
            delete[] keys;
            delete[] values;
        }
        map(int presize=1024) {
            this->maxs = presize;
            this->len = 0;
            this->keys = new K [presize];
            this->values = new V [presize];
            for(int i=0;i<presize;i++) {
                keys[i] = 0;
                values[i] = 0;
            }
        }
    public:
        V& operator[] (K index) {
            /* 查找到index标记 */
            int pos=-1;
            for(int i=0;i<len;i++) if(keys[i] == index) {
                pos = i;
                break;
            }
            /* 特判 */
            if(!(~pos)) { /* 没有 */
                keys[this->len++] = index;
                return values[this->len-1];
            }
            return values[pos];
        }
        int size(void) const {
            return this->len;
        }
        bool count(K index) const {
            for(int i=0;i<len;i++) if(keys[i] == index) return true;
            return false;
        }
};

#endif
