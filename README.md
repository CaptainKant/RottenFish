RottenFish is under MIT Licence and is written By Emmanuel Cervetti

RottenFish is a very fast Poisson Distribution (X,K) approximate implementation for normal and "extreme" values.

    -> Number of occurences K up to 2^31
    ->  X down to 2^-16

 The main goal is to provide a fast random generator that follow the Poisson Distribution.
    -> constant ~100 cpu cycles for every experience


 It's not intended to be monte-carlo critical accurate, but to give a credible magnitude approximation.
 Good for time critical applications, videogames or CGI.

 The library works using precomputed data tables (~4k of data) .
 With some bit-like magnitude and linear interpolation, try to give the best values matching your experiment variables.

 The random generator service underlying is a Xor Shift "Marsaglia"

 -----------------------------------
 EXAMPLE USE WITH CPP , X=187/8653159 , K=8653159
 -----------------------------------
 RottenFish *rottenFishOperator = RottenFish::getInstance();
 rottenFishOperator->loadExperienceFromExpected(187,8653159);
 int simulation = rottenFishOperator->getSimulation();




