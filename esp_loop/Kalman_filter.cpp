#include "Kalman_filter.h"


float kalmanAngleRoll = 0;               //starting guess of 0 degrees
float kalmanUncertaintyAngleRoll = 0;//2*2; //starting uncertainty of 2 degrees;
float kalmanAnglePitch = 0;
float kalmanUncertaintyAnglePitch = 0;//2*2;

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