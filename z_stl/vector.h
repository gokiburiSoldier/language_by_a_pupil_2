/* */
#ifndef _Z_STL_VEC
#define _Z_STL_VEC

template<class T> 
class vector {
    private:
        int maxs,len;
        T *vec_array;
    public:
        ~vector() {
            delete[] vec_array;
        }
        vector(int pre_size=1145) { /* 好臭的大小(悲) */
            this->maxs = pre_size;
            this->vec_array = new T [pre_size];
            /* 填充为默认值 */
            for(int i=0;i<pre_size;++i) 
                this->vec_array[i] = 0;
        }
    public:
        T* begin(void) const {
            return this->vec_array;
        }
        T* end(void) const {
            return this->vec_array+len+1;
        }
        T& operator[] (int index) const {
            return this->vec_array[index];
        }
        int size(void) const {
            return this->len;
        }
        void push_back(T element) {
            if(len+1 >= maxs) return;
            this->vec_array[len++] = element;
        }
        T pop_back(void) {
            T ret = this->vec_array[--len];
            this->vec_array[len] = 0;
            return ret;
        }
        void erase(T* pos) { /* 说实话 我也不知道能不能Run */
            T* endi = this->vec_array+len+1;
            for(T* i=pos;i != endi; i++) 
                *i = *(i+1);
        }
};

#endif
