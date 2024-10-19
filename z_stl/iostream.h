#ifndef _Z_STL_IO
#define _Z_STL_IO

#include <typeinfo>
#include <stdio.h>
#include "map.h"
#include "string.h"

/* 
 * 也不知道谁更快 
 * (STL的iostream 和 本文件)
 */

map<const char*,const char*> ptformats; /* printf formatting string */

namespace io {
    void init(void) {
        ptformats[typeid(char*).name()] = "%s";
        ptformats[typeid(const char*).name()] = "%s";
        ptformats[typeid(int).name()] = "%d";
        ptformats[typeid(long long).name()] = "%lld";
        ptformats[typeid(long).name()] = "%ld";
        ptformats[typeid(char).name()] = "%c";
        ptformats[typeid(bool).name()] = "%d";
        ptformats[typeid(float).name()] = "%f";
        ptformats[typeid(double).name()] = "%f";
    }
}

class ostream {
    private:
        bool flush;
    public:
        ostream(bool fs) {
            this->flush = fs;
        }
    public:
        template<class T>
        ostream operator<< (T element) {
            printf(ptformats[typeid(element).name()],element);
            if(this->flush) fflush(stdout);
            return *this;
        }
};

class istream {
    public:
        istream(void) {
        }
        template<class T>
        istream operator>> (T& right) {
            scanf(ptformats[typeid(right).name()],&right);
            return *this;
        }
};

ostream cout=0;
ostream clog=0;
ostream cerr=1;

istream cin;

#endif
