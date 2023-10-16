#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <math.h>

float w[7],seuil=1,u=0.9;
int E[10][8]={{1,1,1,1,1,1,0,1},
              {0,1,1,0,0,0,0,1},
			  {1,1,0,1,1,0,1,1},
			  {1,1,1,1,0,0,1,1},
			  {0,1,1,0,0,1,1,1},
			  {1,0,1,1,0,1,1,1},
			  {1,0,1,1,1,1,1,1},
			  {1,1,1,0,0,0,0,1},
			  {1,1,1,1,1,1,1,1},
			  {1,1,1,1,0,1,1,1}};

int des[10]={0,1,0,1,0,1,0,1,0,1};

/* Calcul de la sortie obtenue   */
void apprenti()
{ int t=1,i,priod=0,j;float som,o;
 float er=0;
	while(t&&er<0.000001){
		t=0;
		er=0;
		for(i=0;i<10;i++){
			som=0.;
			for(j=0;j<8;j++) som=som+E[i][j]*w[j];
				/*printf("la somme est :%lf\n",som);*/
                o=(som<0)?0:1;
                if(o!=des[i]){
                	for(j=0;j<8;j++){
                                w[j]=w[j]+u*((des[i]-som)*E[i][j]);
								}
                                t=1;
				}
  j=des[i]-som;
  er=0.5*j*j;
  /*printf("L'erreur est:%lf\n",er);*/
		}priod++;

		for(i=0;i<7;i++){
             printf("w[%d]=%.2f\n",i,w[i]);
               }
	}
	printf("Period=%d\n",priod);

}

void compar(void){int j,n;float som=0,o;
do {som=0;
	printf("Please enter a number:");
	scanf("%d",&n);
	for(j=0;j<8;j++)
			som+=E[n][j]*w[j];
				som=som-seuil;
                o=(som<0)?0:1;
                if(o==1)
                printf("The number is odd\n");
                else
                printf("The number is even\n");}while(n>0&&n<10);


}

int main(){int i;
/*srand(time(NULL));*/

/*initialisation des poids    */
for(i=0;i<7;i++){
	w[i]=(double)(rand()) / RAND_MAX;
}
for(i=0;i<7;i++){
printf("w[%d]=%.2f\n",i,w[i]);
}
puts("");
apprenti();
for(i=0;i<7;i++){
printf("w[%d]=%.2f\n ",i,w[i]);

}
puts("");
compar();
return 0;
}
