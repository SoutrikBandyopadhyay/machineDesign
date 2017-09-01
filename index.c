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
  float Ai; //Iron area
  float Agi; // Gross Area of Core
  float Ki; //Stacking Factor

  float ct; //Ai = ct*d^2
  float p;
  float q;
  float r;
  float s;

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

  readFloat("Enter the value of K\nFor Distribution Transformers, K=0.45\nFor Power Transformers, K=0.6 to 0.7",&ans.K);

  //Et
  ans.Et = ans.K * sqrt(transformerData.kVA);
  printf("\n=> Et = %.2f V",ans.Et);

  //phi_m
  ans.phi_m = ans.Et/(4.44*transformerData.frequency);
  printf("\n=> phi_m = %.4f Wb\n",ans.phi_m);

  //Ai
  readFloat("Enter the value of Bm(in Wb/m^2)\nFor Distribution Transformers,Bm=1 to 1.35 Wb/m^2\nFor Power Transformers,Bm = 1.25 to 1.45 Wb/m^2",&ans.Bm);
  ans.Ai = ans.phi_m/ans.Bm;
  printf("\n=> Net Iron Area = %.4f m^2\n",ans.Ai);

  //Agi
  readFloat("Enter the value of Stacking Factor (Typically 0.9)",&ans.Ki);
  ans.Agi = ans.Ai/ans.Ki;
  printf("\n=> Gross Area = %.4f m^2\n",ans.phi_m);

  readInt("\nEnter the Core Type\n1. Square\n2. Cruciform\n3. 3-stepped\n4. 4-stepped",&ans.coreType);
  switch(ans.coreType){
    case 1:
      ans.ct = 0.45;
      ans.d = sqrt(ans.Ai/ans.ct);
      printf("\n=> Diameter of core is %.4f m",ans.d);
      ans.p = sqrt(0.5)*ans.d;
      printf("\n=> Dimension is %.4f m",ans.p);
      break;

    case 2:
      ans.ct = 0.56;
      ans.d = sqrt(ans.Ai/ans.ct);
      printf("\n=> Diameter of core is %.4f m",ans.d);
      ans.p = 0.85*ans.d;
      ans.q = 0.53*ans.d;
      printf("\n=> Dimension is p = %.4f m , q = %.4f m",ans.p,ans.q);
      break;

    case 3:
      ans.ct = 0.6;
      ans.d = sqrt(ans.Ai/ans.ct);
      printf("\n=> Diameter of core is %.4f m",ans.d);
      ans.p = 0.9*ans.d;
      ans.q = 0.7*ans.d;
      ans.r = 0.42*ans.d;
      printf("\n=> Dimension is p = %.4f m , q = %.4f m , r = %.4f m",ans.p,ans.q,ans.r);
      break;

    case 4:
      ans.ct = 0.62;
      ans.d = sqrt(ans.Ai/ans.ct);
      printf("\n=> Diameter of core is %.4f m",ans.d);
      ans.p = 0.36*ans.d;
      ans.q = 0.36*ans.d;
      ans.r = 0.78*ans.d;
      ans.s = 0.92*ans.d;
      printf("\n=> Dimension is p = %.4f m , q = %.4f m , r = %.4f m , s = %.4f m",ans.p,ans.q,ans.r,ans.s);
      break;
  }

  return ans;
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
