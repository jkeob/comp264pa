// I Jacob Oh certify that this programming assignment reflects my own work,
// without the use of any external individuals (other than course/department staff),
// generative-AI, or any other forbidden resources. I understand/accept the consequences
// of cheating as outlined in the course syllabus.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// global variable for the step size
double h;

// linear function implementation
double * linear_func(int a, int b, const double * values, int size){
    // allocate memory for the result of the linear function
    double * linear_func_result = (double*)malloc(size * sizeof(double));
    if (linear_func_result == NULL) {
        return NULL;
    }
    // loop through all the values to calculate linear function
    for (int i = 0; i < size; i++) {
        linear_func_result[i] = a * values[i] + b;
    }
    // return the calculated results
    return linear_func_result;
}

// quadratic function implementation
double * quadratic_func(int a, int b, const double * values, int size) {
    // allocate memory for the result of the quadratic function
    double *quad_func_result = (double*)malloc(size * sizeof(double));
    if (quad_func_result == NULL) {
        return NULL;
    }
    // loop through all the values to calculate quadratic function
    for (int i = 0; i < size; i++) {
        quad_func_result[i] = pow(values[i], 2) + a * values[i] + b;
    }

    // return the calculated results
    return quad_func_result;
}

// exponential function implementation
double * exp_func(int a, int b, const double * values, int size)  {
        // allocate memory for the result of the exponential function
        double * exp_func_result = (double*)malloc(size * sizeof(double));
    if (exp_func_result == NULL) {
        return NULL;
    }

        // loop through all the values to calculate exp equation
        for (int i = 0; i < size; i++) {
        exp_func_result[i] = exp(a * values[i]);
        }
        // return the calculated results
    return exp_func_result;
}



// sin function implementation
double * sin_func(int a, int b, const double * values, int size) {
    // allocate memory for the result of the sine function
    double * sin_func_result = (double*)malloc(size * sizeof(double));
    if (sin_func_result == NULL) {
        return NULL;
    }
        // loop through all the values to calculate the sin equation
        for (int i = 0; i < size; i++) {
        sin_func_result[i] = a * sin(b * values[i]);
    }
    // return the calculated results
    return sin_func_result;
}



// first derivative calculation helper method
double * func_firstDerivative(double *(*fcn)(int, int, const double *, int), int a, int b, const double *values, const double *values_plus, int size) {
    double * first_derivative_result = (double*)malloc(size * sizeof(double));
    if (first_derivative_result == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        double fOfx = fcn(a, b, values, size)[i];
        double fOfx_plus_h = fcn(a, b, values_plus, size)[i];
        first_derivative_result[i] = (fOfx_plus_h - fOfx) / (values_plus[i] - values[i]);
    }
    return first_derivative_result;
}

// second derivative calculation helper method
double * func_secondDerivative(double *(*fcn)(int, int, const double *, int), int a, int b, const double *values, const double *values_plus, const double *values_minus, int size) {
    double * second_derivative_result = (double*)malloc(size * sizeof(double));
    if (second_derivative_result == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        double fx_plus_h = fcn(a, b, values_plus, size)[i];
        double fx_minus_h = fcn(a, b, values_minus, size)[i];
        double fx = fcn(a, b, values, size)[i];
        second_derivative_result[i] = (fx_plus_h - 2 * fx + fx_minus_h) / (h * h);
    }
    return second_derivative_result;
}

// function to compare the strings (helper)
int compareStringsForFunction(char const * left, char const * right) {
    if (left == right) return 0;
    if (!left) return -*right;
    if (!right) return *left;
    while (*left && *left == *right) left++, right++;
    return *left - *right;
}

// main function for calculating derivatives based on the function type
double * func_derivative(const char *func, const double *values_plus, const double *values, const double *values_minus, int a, int b, int order, double h, int size) {
    double * (*function_selected)(int, int, const double *, int);
    double * default_value = (double*)malloc(size * sizeof(double));

    if (default_value == NULL) {
        return NULL;
    }
    if (compareStringsForFunction(func, "lin") == 0) {
        function_selected = linear_func;
    } else if (compareStringsForFunction(func, "quad") == 0) {
        function_selected = quadratic_func;
    } else if (compareStringsForFunction(func, "exp") == 0) {
        function_selected = exp_func;
    } else if (compareStringsForFunction(func, "sin") == 0) {
        function_selected = sin_func;
    }

    switch (order) {
        case 0:
            return function_selected(a, b, values, size);
        case 1:
            return func_firstDerivative(function_selected, a, b, values, values_plus, size);
        case 2:
            return func_secondDerivative(function_selected, a, b, values, values_plus, values_minus, size);
        default:
            for (int i = 0; i < size; i++) {
                default_value[i] = 3.14159;
            }
            return default_value;
    }
}

// main program entry point
int main(int argc, char *argv[]) {
    // check if enough arguments are passed if not return "error" message
    if (argc < 6) {
        return 1;
    }

    // set a, b, and h, and size using specific locations in argv
    const char *func = argv[1];
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    h = atof(argv[argc - 1]);
    int size = argc - 5;

    // allocate memory for the values and values plus and minus
    double *values = (double*)malloc(size * sizeof(double));
    double *values_plus = (double*)malloc(size * sizeof(double));
    double *values_minus = (double*)malloc(size * sizeof(double));


    // calculate the values_plus and values_minus arrays using the h variable
    for (int i = 0; i < size; i++) {
        values[i] = atof(argv[i + 5]);
        values_plus[i] = values[i] + h;
        values_minus[i] = values[i] - h;
    }


    // free allocated memory
    free(values);
    free(values_plus);
    free(values_minus);


    return 0;
}
