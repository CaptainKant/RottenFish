//
// Created by Emmanuel Cervetti on 01/10/2016.
//

#ifndef ROTTENFISH_LOG2_H
#define ROTTENFISH_LOG2_H

#define USE_BUILTIN __GNUC__


class Log2 {

#if defined(USE_BUILTIN)
public:
    inline unsigned int log2(unsigned int x)
    {
        if (x > 0) {
            return (31 - (unsigned int) __builtin_clz (x));
        } else {
            return 0 ;
        }

    }
#else
#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n
private:
    const char LogTable256[256] =
            {
                    -1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
                    LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
                    LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
            };
public:
    inline unsigned int log2(unsigned int v){
        unsigned int t, tt; // temporaries
        if ((tt = v >> 16))
        {

            return ((t = tt >> 8)) ? 24 + LogTable256[t] : 16 + LogTable256[tt];
        }
        else
        {
            return  ((t = v >> 8)) ? 8 + LogTable256[t] : LogTable256[v];
        }
    };
#endif

};


#endif //ROTTENFISH_LOG2_H
