#ifndef _NING_REQ_H
#define _NING_REQ_H

namespace req {
    struct Req {
        int error,jumping = -1;
        bool running = true;
    };
}


#endif