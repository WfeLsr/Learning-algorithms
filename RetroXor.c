#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define sigm(x)    1/(1 + exp(-(double)x))
#define entre 8
#define cache 3
#define sortie 8
#define EPSILON 0.05
#define entre_test   10

float w_entre[entre][sortie];
float w_cache[entre][cache];
float w_sortie[cache][sortie];
float delta_entre[entre];
float delta_cache[cache];
float delta_sortie[sortie];
float o1[entre];
float o2[cache];
float o3[sortie];
float x[entre];
float u=0.9;
int E[entre_test][entre]={{1,1,1,1,1,1,1,1},{1,0,1,0,1,0,1,1},{0,1,1,1,1,1,1,1},{1,1,1,1,1,0,1,1},{1,1,1,0,1,1,1,1},{1,1,0,1,1,1,1,1},{1,1,0,1,1,1,0,1},{1,1,0,0,0,1,1,1},{1,1,1,1,1,1,1,0},{1,1,1,1,1,0,0,1}};
float er;

void intialise(){
int i,j;
  for(i=0;i<entre;i++){
  delta_entre[i]=0;
  delta_sortie[i]=0;
   for(j=0;j<cache;j++) {
    w_entre[i][j] = -0.5 + ((float)rand() / RAND_MAX);
    w_sortie[j][i] = -0.5 + ((float)rand() / RAND_MAX);
   }}

  for(i=0;i<cache;i++){
        delta_cache[i]=0;
   for(j=0;j<sortie;j++) {
    w_cache[i][j] = -0.5 + ((float)rand() / RAND_MAX);
   }}

}
void forward(float x[]){
int i,j;
float som;
for(i=0;i<entre;i++){
    som=0;
    for(j=0;j<entre;j++){
       som+=x[i]*w_entre[i][j];
    }
    o1[i]=sigm(som);
    }
for(i=0;i<entre;i++){
    som=0;
    for(j=0;j<cache;j++){
       som+=o1[i]*w_cache[i][j];
    }
   o2[i]=sigm(som);}

for(i=0;i<cache;i++){
    som=0;
    for(j=0;j<sortie;j++){
       som+=o2[i]*w_sortie[i][j];
    }
   o3[i]=sigm(som);}


}
float backward(float x[],float er){
int i,j;
float som;
for(i=0;i<sortie;i++){
    delta_sortie[i]=(x[i]-o3[i])*o3[i]*(1-o3[i]);
    er+=(x[i]-o3[i])*(x[i]-o3[i]);
}
er=0.5*er;
for(i=0;i<cache;i++){
    som=0;
   for(j=0;j<sortie;j++){
    som+=delta_sortie[j]*w_sortie[i][j];
   }
  delta_cache[i]=o2[i]*(1-o2[i])*som;
}
for(i=0;i<entre;i++){
    som=0;
   for(j=0;j<cache;j++){
    som+=delta_cache[j]*w_cache[i][j];
   }
  delta_entre[i]=o1[i]*(1-o1[i])*som;
}


return er;

}
void correction(float x[]){
int i,j;
for(i=0;i<entre;i++){
    for(j=0;j<entre;j++){
        w_entre[i][j]+=u*delta_entre[i]*x[j];
    }
}
for(i=0;i<cache;i++){
    for(j=0;j<entre;j++){
        w_cache[i][j]+=u*delta_cache[i]*o1[j];
    }
}
for(i=0;i<sortie;i++){
    for(j=0;j<cache;j++){
        w_sortie[i][j]+=u*delta_sortie[i]*o2[j];
    }
}

}


void aprentissage(){
int i,j,periode=1;
intialise();
do{
er=0.;
for(j=0;j<entre;j++){
for(i=0;i<entre;i++)x[i]=E[i][j];
forward(x);
er=backward(x,er);
correction(x);
}
printf("%f ",er);
puts("");
periode++;
}while(er>EPSILON);}


void test(){
float y[8];
int i;
printf("entre le vecteur \n");
for(i=0;i<8;i++){
    scanf("%f",&y[i]);
}
for(i=0;i<8;i++){
    printf("%f ",y[i]);
}
puts("");
forward(y);
for(i=0;i<8;i++){
    printf("%f ",o3[i]);
}
}


int main()
{
    aprentissage();
    printf("%f ",er);
    test();
    getchar();
    return 0;
}