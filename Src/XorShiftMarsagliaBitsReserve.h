//
// Created by Emmanuel Cervetti on 01/10/2016.
//

#ifndef ROTTENFISH_RANDOMXORSHIFTPLUS_H
#define ROTTENFISH_RANDOMXORSHIFTPLUS_H

#include <iostream>

class XorShiftMarsagliaBitsReserve {
    private:
    unsigned int availableBits = 0;
    unsigned long x=123456789 ;
    unsigned long  y=362436069 ;
    unsigned long randfeed;
    unsigned long randfeed_backup=521288629  ;

    void reloadRandomFeed() {
        unsigned long t;
        x ^= x << 16;
        x ^= x >> 5;
        x ^= x << 1;
        t = x;
        x = y;
        y = randfeed_backup;
        randfeed = t ^ x ^ y;
        randfeed_backup = randfeed ;
        availableBits = 8*sizeof(unsigned long);
    }

public:

    /**
     * Get one double value in [0,1]
     * @param bitsNeeded to consume only random we need we specify the resolution
     * @return
     */
    double rand(int bitsNeeded){
        unsigned long out = 0 ;
        unsigned long max = 0 ;

        //Tant que la demande est plus forte que l'offre
        while (bitsNeeded > availableBits) {
            bitsNeeded-=availableBits;
            consumeBitsReserve(availableBits,out,max);
            reloadRandomFeed();
        }

        //La demande est plus faible que l'offre
        consumeBitsReserve(bitsNeeded ,out,max);
        return (double) out / (double) max ;
    }




private:
    inline void consumeBitsReserve(unsigned int nbBits,unsigned long &out,unsigned long &max) {
        unsigned long mask = ( 1 << nbBits ) -1 ; //ex : nbBits = 4 -> 1111
        out = out << nbBits ; //left shift
        out+= randfeed & mask; //add the rightest bits from randfeed
        randfeed = randfeed >> nbBits; //right shift randfeed because we lost nbBits values
        availableBits-=nbBits ;
        max = max << nbBits ;
        max += mask ;
    }



};


#endif //ROTTENFISH_RANDOMXORSHIFTPLUS_H
