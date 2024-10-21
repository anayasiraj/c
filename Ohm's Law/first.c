#include <stdio.h>
#include <stdlib.h>

double rounding(double num){
	int dig = (int)(num*100)%10;
	if (dig == 5){
		return (num + 0.01);
	} else {
		return num;
	}
}

void vi(double i, double v){
	double r = (v/i);
	double p = (v*i);
	r = rounding(r);
	p = rounding(p);
	printf("R\tP\t%.1f\t%.1f\n", r, p);
}

void ir(double i, double r){
	double v = (i*r);
	double p = (i*v);
	
	printf("V\tP\t%.1f\t%.1f\n", v, p);
}

void ip(double i, double p){
	double v = (p/i);
	double r = (v/i);
	printf("V\tR\t%.1f\t%.1f\n", v, r);
}

void vr(double v, double r){
	double i = (v/r);
	double p = (v*i);
	printf("I\tP\t%.1f\t%.1f\n", i, p);
}

void vp(double v, double p){
	double i = (p/v);
	double r = (v/i);
	printf("I\tR\t%.1f\t%.1f\n", i, r);
}

/* void rp(int r, int p){
	double r1 = (double)r;
	double p1 = (double)p;
	double i = (double)sqrt(r1*p1);
	double v = (double)(i/p);
	printf("V\tI\t%f\t%f\n", v, i);
} */

int main(int argc, char**argv){
	
	FILE *fp = fopen(argv[1], "r");
	
	//check
	if (fp == NULL) {
        	perror("Error opening file");
        	return 1;
    	}
	
	char char1;
	char char2;
	int int1;
	int int2;
	
	
	while(fscanf(fp, "%c\t%c\t%d\t%d\n", &char1, &char2, &int1, &int2) != EOF){
		
		if ((char1 == 'I') && (char2 == 'V')){
			vi((double)int1, (double)int2);
		} else if ((char1 == 'V' && char2 == 'I')){
			vi((double)int2, (double)int1);
		}
		
		if ((char1 == 'I') && (char2 == 'R')){
			ir((double)int1, (double)int2);
		} else if ((char1 == 'R' && char2 == 'I')){
			ir((double)int2, (double)int1);
		}
		
		if ((char1 == 'I') && (char2 == 'P')){
			ip((double)int1, (double)int2);
		} else if ((char1 == 'P' && char2 == 'I')){
			ip((double)int2, (double)int1);
		}
		
		if ((char1 == 'V') && (char2 == 'R')){
			vr((double)int1, (double)int2);
		} else if ((char1 == 'R' && char2 == 'V')){
			vr((double)int2, (double)int1);
		}
		
		if ((char1 == 'V') && (char2 == 'P')){
			vp((double)int1, (double)int2);
		} else if ((char1 == 'P' && char2 == 'V')){
			vp((double)int2, (double)int1);
		}
		
	}
	
	fclose(fp);

	return EXIT_SUCCESS;
}
