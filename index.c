#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>



#define pi 3.141592653589
#define muo 0.000001256

// Object oriented code = best code

typedef struct _core{
  float K; //Value of the Voltage per turn Factor
  float Et; // Voltage per turn
  float phi_m;
  float Bm; //Max Flux density
  float Ai;

  float a;
  float b;
  float c;
  float d;
  int coreType;

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
  float kVA;
  float Vp; //Primary HV side Voltage(in KV)
  float Vs; //Secondary LV side Volatge(in KV)
  float phase; // Number of phases
  float frequency; //Obvio
  float maxTappings;

  Core Core;
  Window W;
  Yoke Y;
  LVwindingData LV;
  HVwindingData HV;


} Transformer;


void readFloat(char *c,float *f){
  printf("\n");
  printf("%s : ",c);
  scanf("%f",f);
}

void readInt(char *c,int *f){
  printf("\n");
  printf("%s : ",c);
  scanf("%d",f);
}




Core coreDesign(Transformer transformerData){
  Core ans;
  readFloat("Enter the value of K",&ans.K);

  //Et
  ans.Et = ans.K * sqrt(transformerData.kVA);
  printf("\n=> Et = %.2f V",ans.Et);

  //phi_m
  ans.phi_m = ans.Et/(4.44*transformerData.frequency);
  printf("\n=> phi_m = %.4f Wb",ans.phi_m);

  //Ai
  readFloat("Enter the value of Bm(in Wb/m^2)",&ans.Bm);




}








int main(int argc, char const *argv[]) {
  /* code */

  Transformer transformerData;

  printf("============================\n");
  printf("    TRANSFORMER DESIGN      \n");
  printf("============================\n");

  //_________Initialization________________
  readFloat("Enter the kVA rating(in kVA)",&transformerData.kVA);
  readFloat("Enter the HV Voltage(in kV)",&transformerData.Vp);
  readFloat("Enter the LV Voltage(in kV)",&transformerData.Vs);
  readFloat("Enter the rated frequency(in Hz)",&transformerData.frequency);
  readFloat("Enter the number of phases(1 or 3)",&transformerData.phase);
  readFloat("Enter the tappings(in %)",&transformerData.maxTappings);


  //________Core Design__________________
  // system("cls");
  printf("\n============================\n");
  printf("         CORE DESIGN        \n");
  printf("============================\n");

  transformerData.Core = coreDesign(transformerData);




  return 0;
}
