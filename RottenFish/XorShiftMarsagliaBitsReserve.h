//
// Created by Emmanuel Cervetti on 01/10/2016.
//

#ifndef ROTTENFISH_RANDOMXORSHIFTPLUS_H
#define ROTTENFISH_RANDOMXORSHIFTPLUS_H

#include <iostream>

class XorShiftMarsagliaBitsReserve {
    private:
    int availableBits = 0;
    unsigned long x=123456789 ;
    unsigned long  y=362436069 ;
    unsigned long randfeed=521288629 ;

    void reloadRandomFeed() {
        unsigned long t;
        x ^= x << 16;
        x ^= x >> 5;
        x ^= x << 1;
        t = x;
        x = y;
        y = randfeed;
        randfeed = t ^ x ^ y;
    }

public:

    /**
     * Get one double value in [0,1]
     * @param bitsResolution to consume only random we need we specify the resolution
     * @return
     */
    double rand(int bitsResolution){
        unsigned long out = 0 ;
        unsigned long max = 0 ;
        bool isAllOne = true ;
        for (int i = 0; i < bitsResolution; i++) {
            if (bitsResolution > availableBits) {
                reloadRandomFeed();
            }
            out = out << 1 ; //left shift
            out+= randfeed & 1; //add the rightest bit from randfeed
            randfeed = randfeed >> 1; //right shift randfeed because we lost one value
            availableBits-- ;
            max = max << 1 ;
            max+=1 ;
        }
        return (double) out / (double) max ;
    }




};


#endif //ROTTENFISH_RANDOMXORSHIFTPLUS_H
