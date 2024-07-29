/*
 * 发现还是用 `map` 更好
 * 请不要使用 `dt::dict`
 */

namespace dt {
    template<class key,class val>
    class dict {
    public:
        const int MAX = 114514;
    private:
        key keys[114514];
        val values[114514];
        int len = 0;
    public:
        bool isIn(key k) {
            for(int i=0;i<len;++i) if(this->keys[i] == k) return true;
            return false;
        }
        val index(key k) {
            for(int i=0;i<len;++i) if(this->keys[i] == k) return this->values[i];
            val x;
            return x;
        }
        int add(key k,val v) {
            if(!isIn(k)) {
                if(len >= MAX) return 1;
                this->keys[len] = k;
                this->values[len] = v;
                ++len;
                return 0;
            }
            for(int i=0;i<len;++i) if(this->keys[i] == k) this->values[i] = v;
            return 0;
        }
        key* getKeys(void) const {return this->keys;}
        int length(void) const   {return this->len;}

        bool operator==(dict d) {
            key ks = d.getKeys();
            if(d.length() != this->len) return false;
            for(int i=0;i<(this->len);++i) {
                key k = this->keys[i],
                    k2 = ks[i];
                if(k != k2 || this->index(k) != d.index(k2)) return false;
            }
            return true;
        }
    };
}