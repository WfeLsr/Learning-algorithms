#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float w[3],u=1,eps=0.01;

int E[4][3]={{1,0,1},
              {1,1,0},
              {1,1,1},
              {1,0,0}};

int des[4]={1,1,1,0};
int compard(int a,int b){
        return a!=b?1:0;
 }


/* Calcul de la sortie obtenue   */
void apprenti(int c){int t=1,i,period=0,j;float som,er;int a;
    while(t||er<eps){
            for(i=0;i<4;i++)
            printf("d=%d\n",E[i][3]);
        t=0;
        er=0;
        for(i=0;i<4;i++){
            som=0.;
            for(j=0;j<3;j++){
                som+=E[i][j]*w[j];
                /*printf("boucle  d=%d\n",E[i][3]);}
            printf("la somme %f",som);*/

                er=0.5*(E[i][3]-som)*(E[i][3]-som);
                a=E[i][3];
                /*printf(" er d=%d\n",E[i][3]);
               printf("la somme %f",som);
                printf("a=%d  o=%d",a,c);*/
                E[i][3]=a;
                
                if(compard(c,a)){
                    for(j=0;j<3;j++){
                        printf(" change d=%d\n",E[i][3]);
                                w[j]=w[j]+u*((E[i][3]-som)*E[i][j]);
                                /*printf("%f  ",w[j]);*/
                                }

                                t=1;
                }

  /*getchar();*/
        }period++;

    }
    printf("nbre des periods est : %d ",period);

}}
void compar(void){int j,n1,n2;float som=0,o;
    printf("Please enter a number: ");
    scanf("%d",&n1);
    printf("Please enter a number: ");
    scanf("%d",&n2);
    som+=w[0]+w[1]*n1+w[2]*n2;

    o=(som<0)?0:1;
    if(o==1)
                printf("Logic OR is 1\n");
    else
                printf("logic OR is 0\n");


}
int main(){int i,k;int c;
/*initialisation des poids    */
w[0]=-1;
w[1]=0;
w[2]=-0.6;

for(i=0;i<3;i++){
printf("w[%d]=%.2f\n",i,w[i]);
}
printf("\n");
apprenti(c);
printf("\n");
for(i=0;i<3;i++){
printf("w[%d]=%.2f\n",i,w[i]);
}
do{
compar();
getchar();
system("cls");
printf("Tape 0 exit or 1 to continue");
scanf("%d",&k);
}while(k!=0);
       return 0;
}
