//I Jacob Oh here certify that this programming assignment reflects my own work
//without the use of any external individuals(other than course/department staff), 
//,generative-AI, or any other forbidden resources. I understand/accept the 
//consequences of cheating as outlined in the course syllabus.



#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//used to call functions in testing 
double linear_func(int a, int b, double x);
double quadratic_func(int a, int b, double x);
double exp_func(int a , int b, double x);
double sin_func(int a , int b, double x);
double func_comp(double(*fcnA)(int,int,double), double (*fcnB)(int,int,double), int a, int b, double x);
double fcnA(int a, int b, double x);
double fcnB(int a, int b, double x);
double func_derivative(double(*fcnA)(int,int,double),int a, int b, double x, int order, double h);
double * func_equality(double(*fcnA) (int,int,double), double (*fcnB)(int,int,double), double *values, int size, double tol);

int main(int argc, char *argv[]){

	int size = argc - 1;
	double *arr = (double*)malloc(size*sizeof(double));

	for(int i = 0; i<size; i++){

		arr[i] = atof(argv[i+1]);

	}



	return 0;

}

double linear_func(int a, int b, double x){

	double y = (double)a * x;
	y += (double) b;




return y;
}


double quadratic_func(int a, int b, double x){

	double y = pow(x,2);
	y += (double)a*x;
	y+=b;




return y;
}


double exp_func(int a , int b, double x){
	
	double y = exp((double)a*x);


return y;
}


double sin_func(int a , int b, double x){

	double y = (double)a * sin((double)b * x);

return y;
}



double func_comp(double(*fcnA)(int,int,double), double (*fcnB)(int,int,double), int a, int b, double x){

	double resultOfB = fcnB(a,b,x);
	double resul`tFromB = fcnA(a,b,resultOfB);


	return resultFromB;

}



double fcnA(int a, int b, double x){

	double y = (double) a * x;
	y+=b;

return y;

}


double fcnB(int a, int b, double x){

	double y = (double) a * x;
	y+=b;

return y;




}



double func_derivative(double(*fcnA)(int,int,double),int a, int b, double x, int order, double h){

	switch (order){

	case 1:

	double returnableFcnA = fcnA(a,b,x);
	return returnableFcnA;
	break;
	case 2:

	double returnableFcnA_Deriv = fcnA(a,b,x+h);
	returnableFcnA_Deriv -= fcnA(a,b,x);
	returnableFcnA_Deriv = returnableFcnA_Deriv/h;
	return returnableFcnA_Deriv;
	break;
	case 3:

	double returnableFcnA_Deriv2 = fcnA(a,b,x+h);
	returnableFcnA_Deriv2 -= 2*fcnA(a,b,x);
	returnableFcnA_Deriv2 += fcnA(a,b,x-h);
	returnableFcnA_Deriv2 = returnableFcnA_Deriv2/ pow(h,2);
	return returnableFcnA_Deriv2;
	break;
	default:

	return 3.14159;

	break;
	}

return 0;
}


double * func_equality(double(*fcnA) (int,int,double), double (*fcnB)(int,int,double), double *values, int size, double tol){


	double h = 0.001;

	double* valuesResized = realloc(values,size *3* sizeof(double));
	if (valuesResized == NULL){

	free(values);
	return NULL;

	}


	int a = values[0];
	int b = values[1];
	double x = values[2];

	for(int i = 0; i<size; i++){

	double functionA_Eval = fcnA(a,b,x);
	double functionB_Eval = fcnB(a,b,x);


	double functionDerivative_A = fcnA(a,b,x+h);
	functionDerivative_A -= fcnA(a,b,x);
	functionDerivative_A = functionDerivative_A/h;

	double functionDerivative_B = fcnB(a,b,x+h);
	functionDerivative_B -= fcnB(a,b,x);
	functionDerivative_B = functionDerivative_B/h;


	double functionSecondDerivA = fcnA(a,b,x+h);
	functionSecondDerivA -= 2*fcnA(a,b,x);
	functionSecondDerivA += fcnA(a,b,x-h);
	functionSecondDerivA = functionSecondDerivA/ pow(h,2);

	double functionSecondDerivB = fcnB(a,b,x+h);
	functionSecondDerivB -= 2*fcnB(a,b,x);
	functionSecondDerivB += fcnB(a,b,x-h);
	functionSecondDerivB = functionSecondDerivB/ pow(h,2);


	if (fabs(functionA_Eval - functionB_Eval) >= tol){

	return NULL;

	}

	if (fabs(functionDerivative_A - functionDerivative_B) >= tol){

		return NULL;
	}

	if (fabs(functionSecondDerivA - functionSecondDerivB >= tol)){
		return NULL;
	}



	if(fabs(functionA_Eval - functionB_Eval) < tol){
		valuesResized[i*3] = 1.0;

	}else{
		valuesResized[i*3] = 0.0;

	}

	if(fabs(functionDerivative_A - functionDerivative_B) < tol){
		valuesResized[i*3+1] = 1.0;

	}else{
		valuesResized[i*3+1] = 0.0;

	}

	if(fabs(functionSecondDerivA - functionSecondDerivB) < tol){
		valuesResized[i*3+2] = 1.0;

	}else{
		valuesResized[i*3+2] = 0.0;

	}




	return valuesResized;

}

}
