#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#define DELTA_TIME 0.004
#define PROCESS_NOISE 0.000256
#define MEASUREMENT_NOISE 9

void  Kalman1D( float *kalmanState, float *kalmanUncertainty, 
                float kalmanInput, float kalmanMeasurement);

#endif