//
// Created by Emmanuel Cervetti on 30/09/2016.
//

#ifndef ROTTENFISH_ROTTENFISH_H
#define ROTTENFISH_ROTTENFISH_H

#include <zconf.h>
#include "new_experiences.h"
#include "Log2.h"
#include "XorShiftMarsagliaBitsReserve.h"

class RottenFish {

public:

    Log2 *log2op ;
    XorShiftMarsagliaBitsReserve *randomOp ;

    static const int SIZE_EXPERIENCE_RAW = 17;
    static constexpr double NATIVE_SAMPLING_WIDTH = 0.1;
    static constexpr int NATIVE_SAMPLING_NUMBER = 1/NATIVE_SAMPLING_WIDTH;

    float experiences[32*32*SIZE_EXPERIENCE_RAW ];

    float getVal(int i,int j, int k) {
        return experiences[getKForIJ(i,j)+k];
    };

    RottenFish(){
        log2op = new Log2();
        randomOp = new XorShiftMarsagliaBitsReserve();
    }

    ~RottenFish() {
        delete(log2op);
        delete(randomOp);
        static_pInstance = NULL ;
    }
    inline void setIndex( double m , unsigned  int n, unsigned int & m_index, unsigned int & n_index  ) {
        bag_m = m ;
        bag_n = n ;
        setIndex(m_index, n_index);
    }


    inline void setIndex( unsigned int & m_index, unsigned int & n_index  )
    {
        n_index = log2op->log2(bag_n);
        double half_n = (double) bag_n/2.0 ;
        if (bag_m < half_n) {
            m_index = log2op->log2( (unsigned int) (bag_n /bag_m) ) - 1;
            if (m_index > 14) {
                m_index = 14 ;
                bag_m = 0 ;
            }
        } else {
            m_index = 15 + log2op->log2( (unsigned int) ( bag_n / (bag_n - bag_m)) ) ;
            if (m_index > 30) {
                m_index = 30 ;
                bag_m = bag_n ;
            }
        }
    }

private :
    unsigned int bag_n ;
    double bag_m ;
    unsigned int bag_n_index ;
    unsigned int bag_m_index ;
    unsigned int bag_m_index_sup ;
    float bag_linear_cursor_interpolation ;
    unsigned int bag_nativeIndex ;
    unsigned int bag_nativeIndex_supp ;
    unsigned int bag_needed_random_resolution ;
    double bag_yMin ;
    double bag_yDelta ;

public:

    inline void loadExperience(double p, unsigned  int n) {
        loadExperienceFromExpected(p*n,n);
    }

    inline void loadExperienceFromExpected(double m, unsigned  int n) {
        bag_m = m ;
        bag_n = n ;
        setIndex(bag_m_index,bag_n_index);
        bag_m_index_sup = bag_m_index+1 ;
        bag_nativeIndex = getKForIJ(bag_n_index,bag_m_index);
        float $mInferiorReference = experiences[bag_nativeIndex+16];
        bag_needed_random_resolution = (unsigned int) experiences[bag_nativeIndex+2];
        bag_nativeIndex_supp = getKForIJ(bag_n_index,bag_m_index_sup);
        float $mSuperiorReference = experiences[bag_nativeIndex_supp+16];
        bag_linear_cursor_interpolation = (float) ( bag_m - $mInferiorReference ) / ($mSuperiorReference-$mInferiorReference) ;
        if (bag_n==1 || bag_m < NATIVE_SAMPLING_WIDTH) {
            if ( bag_m <=  ((float) bag_n / 2.0)) {
                bag_needed_random_resolution = 2+ log2op->log2( (unsigned int) (2*bag_n/bag_m) ) ;
            } else {
                bag_needed_random_resolution = 2+ log2op->log2( (unsigned int) (2*bag_n/(bag_n-bag_m)) ) ;
            }
        } else if (bag_n == 2) {
            if (bag_m <= ((float) bag_n / 2.0)) {
                bag_needed_random_resolution = 2+ log2op->log2( (unsigned int) (2*bag_n/bag_m ) ) ;
            } else {
                bag_needed_random_resolution = 2+ log2op->log2( (unsigned int) (2*bag_n/(bag_n-bag_m) ) ) ;
            }
        }


        float yMinPlotOne = experiences[bag_nativeIndex];
        bag_yMin = (yMinPlotOne + (experiences[bag_nativeIndex_supp] - yMinPlotOne) * bag_linear_cursor_interpolation ) * bag_m;
        float yMinPlotTwo = experiences[bag_nativeIndex + 1];
        bag_yDelta = (yMinPlotTwo + (experiences[bag_nativeIndex_supp + 1] - yMinPlotTwo) * bag_linear_cursor_interpolation ) * bag_m;
        bag_yDelta = bag_yDelta - bag_yMin ;
    }


    unsigned int getSimulation(){

        unsigned int res = 0 ;
        //First, particular cases that don't handle very well the main algo

        if (  (bag_m+ 0.00001) > bag_n ) { //n=m in a float approximation
            return bag_n ;
        } else if (  (bag_m - 0.00001) < 0 ) { //m=0 in a float approximation
            return 0 ;
        }
        if (bag_n==1 || bag_m < NATIVE_SAMPLING_WIDTH) {

            if (randomOp->rand(bag_needed_random_resolution) < bag_m) { //pourcentage de chance d'avoir un tirage de 1
                return 1 ;
            }
            return 0 ;
        } else if (bag_n == 2) {
            if ((bag_n*randomOp->rand(bag_needed_random_resolution)) < bag_m) {
                res++;
            }
            if ((bag_n*randomOp->rand(bag_needed_random_resolution))< bag_m) {
                res++;
            }
            return res ;
        }

        //Main algo
        double $x = randomOp->rand(bag_needed_random_resolution);
        double $xp = $x * NATIVE_SAMPLING_NUMBER ;
        unsigned int $i = (unsigned int) ($xp);
        double $k = $xp - $i;
        float plot_two = experiences[bag_nativeIndex + $i + 3];
        double $y1 = (plot_two + (experiences[bag_nativeIndex_supp+ $i + 3] - plot_two) * bag_linear_cursor_interpolation );
        float plotOne = experiences[bag_nativeIndex + $i + 4];
        double $y2 = (plotOne + (experiences[bag_nativeIndex_supp + $i + 4] - plotOne) * bag_linear_cursor_interpolation );
        res = (unsigned int) (bag_yMin + ((1 - $k) * $y1 + $k * $y2) * bag_yDelta);
        return res;

    }


static
    RottenFish *static_pInstance  ;
static



    unsigned int inline getKForIJ(int i, int j){
        return (unsigned) 32*SIZE_EXPERIENCE_RAW*i+SIZE_EXPERIENCE_RAW*j ;
    }

static
    void
    loadExperience(int i, int j, float relativeMin, float relativeMax, float resolutionClientRandom, float x0, float x1,
                   float x2, float x3, float x4, float x5, float x6, float x7,
                   float x8, float x9, float x10, float k50m, float k50p, float m, double n

    ) {
    RottenFish *rottenFish = RottenFish::getInstance();
    int k = getKForIJ(i,j);
    rottenFish->experiences[k+0] = relativeMin ;
    rottenFish->experiences[k+1] = relativeMax ;
    rottenFish->experiences[k+2] = resolutionClientRandom ;
    rottenFish->experiences[k+3] = x0 ;
    rottenFish->experiences[k+4] = x1 ;
    rottenFish->experiences[k+5] = x2 ;
    rottenFish->experiences[k+6] = x3 ;
    rottenFish->experiences[k+7] = x4 ;
    rottenFish->experiences[k+8] = x5 ;
    rottenFish->experiences[k+9] = x6 ;
    rottenFish->experiences[k+10] = x7 ;
    rottenFish->experiences[k+11] = x8 ;
    rottenFish->experiences[k+12] = x9 ;
    rottenFish->experiences[k+13] = x10 ;
    rottenFish->experiences[k+14] = k50m ;
    rottenFish->experiences[k+15] = k50p ;
    rottenFish->experiences[k+16] = m ;
}

static RottenFish * getInstance(void){
        if (!static_pInstance) {
            static_pInstance = new RottenFish;
            load_all_poisson();
        }
    return static_pInstance ;
    }
};


#endif //ROTTENFISH_ROTTENFISH_H
