#include<stdio.h>
#include<math.h>
#include<stdlib.h>


#define pi 3.141592653589
#define muo 0.000001256

// Object oriented code = best code

typedef struct _core{

} Core;

typedef struct _window{

} Window;

typedef struct _yoke{

} Yoke;

typedef struct _lv{

} LVwindingData;

typedef struct _hv{

} HVwindingData;

typedef struct _transformer{
  float KVA;
  float Vp; //Primary HV side Voltage(in KV)
  float Vs; //Secondary LV side Volatge(in KV)
  float Bm; //Max Flux density
  float phase; // Number of phases
  float frequency; //Obvio




  Core C;
  Window W;
  Yoke Y;
  LVwindingData LV;
  HVwindingData HV;


} Transformer;

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
