#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOPSTACK 64
#define MAXNUMSTACK 64
#define MAXEPRESSIONSIZE 1000

#if defined(__linux__)
#define s21_dot ","
#elif defined(__APPLE__) && defined(__MACH__)  // Apple OSX and iOS (Darwin)
#define s21_dot "."
#else
#define PLATFORM_NAME NULL
#endif

// Operations

double eval_add(double a1, double a2);
double eval_sub(double a1, double a2);
double eval_uminus(double a1, double a2);
double eval_uplus(double a1, double a2);
double eval_sin(double a1, double a2);
double eval_cos(double a1, double a2);
double eval_tan(double a1, double a2);
double eval_acos(double a1, double a2);
double eval_asin(double a1, double a2);
double eval_atan(double a1, double a2);
double eval_sqrt(double a1, double a2);
double eval_ln(double a1, double a2);
double eval_log(double a1, double a2);
double eval_exp(double a1, double a2);
double eval_mul(double a1, double a2);
double eval_div(double a1, double a2);
double eval_mod(double a1, double a2);

// Stacks operations
struct operator_type *getop(char ch);
void push_opstack(struct operator_type *op);
struct operator_type *pop_opstack();
void push_numstack(double num);
double pop_numstack();

int shunt_op(struct operator_type *op);  // Using given operation applies it
                                         // and pushes result to numstack

// Parsing

char *clean_expression(char *expression,
                       double x);  // Presents given expression in the required
                                   // way. Also gives x a given value.

int parse(
    char *expression, double x,
    double *answ);  // Main function that parses the expression and applies
                    // operation to the numstack and returns final result
