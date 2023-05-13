#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80

FILE *fptr;

bool problem_with_clear=true;

typedef struct Circle{
   float rad;
   float square;
   float length;
   bool umova;
} circle;

float input_formula(char* alpha);
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
    char* n_ins_s;
    char* line_with_formula;
    char checker=0,line[MAX_LINE_LENGTH] = {0};
    unsigned int line_count = 0;

    FILE *file = fopen("info.txt", "r");
    
    fgets(line, MAX_LINE_LENGTH, file);
    n_ins_s=line;
    if(!isdigit(atoi(n_ins_s))){n=atoi(n_ins_s);}
    
    circle* qq = (circle*)malloc(n*sizeof(circle));
    
    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        
        line_with_formula=line;
        line_with_formula[strcspn(line_with_formula, "\n")] = 0;

            qq[i].rad = input_formula(line_with_formula);
            x = qq[i].rad;
            
            qq[i].square = calculate_square(x);
            qq[i].length = calculate_length(x);


            if(qq[i].square  < qq[i].length){
                qq[i].umova = true;
            }
            else{qq[i].umova = false;}
            i++;
        
        
    }
    save_in_txt(qq,n);
    free(qq);
}



float input_formula(char* alpha){
    char* radius;
    int i;
    float x=0;
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
