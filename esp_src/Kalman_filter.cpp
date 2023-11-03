#include "Kalman_filter.h"

void  Kalman1D( float *kalmanState, float *kalmanUncertainty, 
                float kalmanInput, float kalmanMeasurement)
{
  //prediction
  (*kalmanState) = (*kalmanState) + DELTA_TIME * kalmanInput;
  (*kalmanUncertainty) += PROCESS_NOISE;
  //correction
  float kalmanGain = (*kalmanUncertainty) / ((*kalmanUncertainty) + MEASUREMENT_NOISE);
  (*kalmanState) += kalmanGain * (kalmanMeasurement - (*kalmanState));
  (*kalmanUncertainty) *= (1-kalmanGain);
}