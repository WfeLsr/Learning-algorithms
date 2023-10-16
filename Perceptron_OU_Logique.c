/* Rosenblatt perceptron is a binary single neuron model.
The inputs integration is implemented through the addition of the weighted inputs that have fixed weights obtained during the training stage.
If the result of this addition is larger than a given threshold θ the neuron fires.*/


#include<stdio.h>
#include <unistd.h> 
#include<stdlib.h>
float w[3];/*les poids*/
float u=1;/*variable empirique géneralement comprise entre 0 et 1*/
int periode;
/*Base apprentissage (etape2)*/
int E[4][3]={{1,0,1},{1,1,0},{1,1,1},{1,0,0}}; /*Les enttrées*/
int des[4]={1,1,1,0};/*Sorties désirées*/

/*Phase d'apprentissage*/
void phase_apprentissage(){
	int flag=0;/*vérification des changements des poids*/
	int i,j,period=0;
	float som,ob;

	while(flag){
		flag=0;
		for(i=0;i<4;i++){
			som=0;
			for(j=0;j<3;j++){
				som+=E[i][j]*w[j];/*Etape3*/
				ob=(som<0)?0:1;/*Etape4*/
				if(ob!=des[i]){
					for(j=0;j<3;j++){
						w[j]=w[j]+u*((des[i]-ob)*E[i][j]);
					} 
					flag=1;	
					 
				}
			}period++;
		}
		periode=period;
		printf("			 Period = %d \n",period);
	}
}void phase_utilistion(void){
	int j,n1,n2;
	float som=0,o;
    

	do{
    	printf("					Please enter  0 or 1: ");
	    scanf("%d",&n1);
	    if((n1 != 0 && n1 != 1)){
	    	puts("					Error the number is not a binary (0/1) digit. Try again: ");
	    }

	}while((n1 != 0 && n1 != 1));
	do{
    	printf("					Please enter  0 or 1: ");
	    scanf("%d",&n2);
	    if((n2 != 0 && n2 != 1)){
	    	puts("					Error the number is not a binary (0/1) digit. Try again: ");
	    }

	}while((n2 != 0 && n2 != 1));
    som+=w[0]+w[1]*n1+w[2]*n2;
    o=(som<0)?0:1;
    if(o==1){
    	printf("			 	After using the machine learning <Rosenblatt Perceptron> supervised Model we get that: %d OR %d = %.f \n",n1,n2,o);
    }
    else{
    	printf("			 	Result: %d OR %d = %.f \n",n1,n2,o);
    }

}

int main(){
	int i,k;
    puts("\n");
    puts("					Rosenblatt perceptron : ");
    puts("			Rosenblatt perceptron is a binary single neuron model.");
    puts("			The inputs integration is implemented through ");
    puts("			the addition of the weighted inputs that have fixed ");
    puts("			weights obtained during the training stage.");
    puts("			If the result of this addition is larger than a given threshold θ the neuron fires.\n");

	/*Initialisation des poids (etape1)*/
	w[0]=-0.2;
	w[1]=1;
	w[2]=0;
    printf("			Starting \n");
	puts("					Initial weights :");
	for(i=0;i<3;i++){
		printf("						w[%d]=%.2f \n",i,w[i]);
	}
	puts("\n");
	puts("					Learning Phase...\n");
	/*Aprenntissage (etapeZ)*/
	phase_apprentissage();
	puts("\n");    
    puts("					Final weights (after learning):");
	for(i=0;i<3;i++){
		printf("					w[%d]=%.2f \n",i,w[i]);
	}
    puts("\n");
    printf("			Finished Learning\n");
    do{	
    puts("			Start testing :\n");
    /*Utilisation (etape3)*/
    phase_utilistion();
    getchar();
    /*system("cls");*/
    puts("\n");
    printf("			To contiue tape 1 / To exit tape 0 ");
    puts("\n");
    scanf("%d",&k);
    }while(k!=0);
    return 0; 
}