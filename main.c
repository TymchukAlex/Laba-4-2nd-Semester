#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

FILE *fptr;

bool problem_with_clear=true;

typedef struct Circle{
   float rad;
   float square;
   float length;
   bool umova;
} circle;

float input_formula();
float calculate_length(float radius);
float calculate_square(float radius);
void output_characteristics_of_circle(circle *ss, int i);
float execute();
void check_umovu(circle *ss, int n);
float input_formula();
void save_in_txt(circle *out, int n);

void main()
{
    execute();
}


float calculate_length(float radius){
    float x;

    x = 2*M_PI*radius;

    return x;
}

float calculate_square(float radius){
    float x;

    x = M_PI*radius*radius;

    return x;
}

float execute(){
    int n,i;
    float x;


    printf("input number of circles ");
    scanf("%d",&n);

    circle* qq = (circle*)malloc(n*sizeof(circle));

    for(i = 0;i < n;i++){

        printf("\n\n%d)",i);
        qq[i].rad = input_formula();
        x = qq[i].rad;
        qq[i].square = calculate_square(x);
        qq[i].length = calculate_length(x);

        output_characteristics_of_circle(qq,i);

        if(qq[i].square  < qq[i].length){
            qq[i].umova = true;
        }
        else{qq[i].umova = false;}
    }

    check_umovu(qq,n);
    save_in_txt(qq,n);
    free(qq);
}

void output_characteristics_of_circle(circle *ss, int i){

    printf("\n%f",ss[i].rad);
    printf("\n%f",ss[i].square);
    printf("\n%f",ss[i].length);

}

void check_umovu(circle *ss, int n){

    int i;

    printf("\nUmovu zadovilnaut kola №:   ");

    for(i=0;i<n;i++){
        if(ss[i].umova==true){
            printf(" %d ",i);
        }
    }
}

float input_formula(){
    char* radius;
    int i;
    float x=0;
	char alpha[50];

	if(problem_with_clear==true){gets(alpha); problem_with_clear=false;}

	fgets(alpha, 50, stdin);

    radius=strchr(alpha,'=');
	for(i=1;i<strlen(radius);i++){
	    if((radius[i]=='\n')&&(i!=1)){break;}
	    x=x*10+(radius[i]-'0');
	}
	return x;
}

void save_in_txt(circle *out, int n){
    int i;
    FILE *fpt=fopen("results.txt", "w");
    fprintf(fpt,"Всього кіл: %d\n",n);
    for(i=0;i<n;i++){
        fprintf(fpt,"Коло номер %d: радіус: %f  довжина кола: %f    площа кола: %f\n",i,out[i].rad,out[i].length,out[i].square);
    }
    fprintf(fpt,"Умову задовільняють наступні кола:");
    for(i=0;i<n;i++){
        if(out[i].umova==true){
            fprintf(fpt," %d ",i);
        }
    }
    fclose(fpt);
}
