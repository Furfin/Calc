#include "s21_shunting_yard.h"
//! @brief End of program status flag
int status = 0;
//! @brief End of program function expression flag
int x_flag = 0;
enum { ASSOC_NONE = 0, ASSOC_LEFT, ASSOC_RIGHT };

/**
 * Struct that represents operations. Can be used to apply said operations to
 * arguments.
 *
 *
 * @param op Character representation of operation
 * @param prec Represents hierarchy of operations
 * @param assoc Used when parsing operations and changes how operation is
 * applied on arguments
 * @param unary 0 or 1. Represents unary operations
 * @param eval Stores eval function of operator
 *
 */
struct operator_type {
  char op;
  int prec;
  int assoc;
  int unary;
  double (*eval)(double a1, double a2);
};

struct operator_type operators[] = {{'_', 10, ASSOC_RIGHT, 1, eval_uminus},
                                    {'p', 10, ASSOC_RIGHT, 1, eval_uplus},
                                    {'s', 10, ASSOC_RIGHT, 1, eval_sin},
                                    {'c', 10, ASSOC_RIGHT, 1, eval_cos},
                                    {'t', 10, ASSOC_RIGHT, 1, eval_tan},
                                    {'C', 10, ASSOC_RIGHT, 1, eval_acos},
                                    {'S', 10, ASSOC_RIGHT, 1, eval_asin},
                                    {'T', 10, ASSOC_RIGHT, 1, eval_atan},
                                    {'\\', 10, ASSOC_RIGHT, 1, eval_sqrt},
                                    {'l', 10, ASSOC_RIGHT, 1, eval_ln},
                                    {'L', 10, ASSOC_RIGHT, 1, eval_log},
                                    {'^', 9, ASSOC_RIGHT, 0, eval_exp},
                                    {'*', 8, ASSOC_LEFT, 0, eval_mul},
                                    {'/', 8, ASSOC_LEFT, 0, eval_div},
                                    {'%', 8, ASSOC_LEFT, 0, eval_mod},
                                    {'+', 5, ASSOC_LEFT, 0, eval_add},
                                    {'-', 5, ASSOC_LEFT, 0, eval_sub},
                                    {'(', 0, ASSOC_NONE, 0, NULL},
                                    {')', 0, ASSOC_NONE, 0, NULL}};
//! @brief Stack of operators
struct operator_type *opstack[MAXOPSTACK];
//! @brief Number of elements in operator's stack
int nopstack = 0;

//! @brief Stack of numbers
double numstack[MAXNUMSTACK];
//! @brief Number of elements in number's stack
int nnumstack = 0;
/**
 * Addition operation implementation
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_add(double a1, double a2) { return a1 + a2; }
/**
 * Subtraction operation implementation
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_sub(double a1, double a2) { return a1 - a2; }
/**
 * Unary minus implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_uminus(double a1, double a2) { return -a1 + a2; }
/**
 * Unary plus implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_uplus(double a1, double a2) { return a1 + a2; }
/**
 * Sinus function implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_sin(double a1, double a2) { return sin(a1) + a2; }
/**
 * Cosinus function implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_cos(double a1, double a2) { return cos(a1) + a2; }
/**
 * Tangent function implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_tan(double a1, double a2) {
  if (fabs(cos(a1)) <= 1e-1) {
    return NAN;
  }
  return tan(a1) + a2;
}
/**
 * Arccosinus function implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_acos(double a1, double a2) {
  if (fabs(a1) > 1) {
    return NAN;
  }
  return acos(a1) + a2;
}
/**
 * Arcsinus function implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_asin(double a1, double a2) {
  if (fabs(a1) > 1) {
    return NAN;
  }
  return asin(a1) + a2;
}
/**
 * Arctangent function implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_atan(double a1, double a2) { return atan(a1) + a2; }
/**
 * Square root function implementation. Only a1 parameter is actually used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_sqrt(double a1, double a2) {
  if (a1 < 0) {
    return NAN;
  }
  return pow(a1, 0.5) + a2;
}
/**
 * Natural logarithm function implementation. Only a1 parameter is actually
 * used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_ln(double a1, double a2) {
  if (a1 < 0) {
    return NAN;
  }
  return log(a1) + a2;
}
/**
 * Logarithm of base 10 function implementation. Only a1 parameter is actually
 * used.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_log(double a1, double a2) {
  if (a1 < 0) {
    return NAN;
  }
  return log10(a1) + a2;
}
/**
 * Power of a num function implementation.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_exp(double a1, double a2) { return pow(a1, a2); }
/**
 * Multiplication function implementation.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_mul(double a1, double a2) { return a1 * a2; }
/**
 * Division function implementation.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 * @return Double, result of an operation
 */
double eval_div(double a1, double a2) {
  if (!a2) {
    return NAN;
  }
  return a1 / a2;
}
/**
 * Modulus function implementation.
 * @param a1 first argument of an operation
 * @param a2 second argument of an operation
 */
double eval_mod(double a1, double a2) {
  if (!a2) {
    return NAN;
  }
  return fmodf(a1, a2);
}

/**
 * Function that returns object of type struct operation_type
 * @param ch Parameter that defines operation that will be returned
 * @return operation object
 */
struct operator_type *getop(char ch) {
  long unsigned int i;
  for (i = 0; i < sizeof operators / sizeof operators[0]; ++i) {
    if (operators[i].op == ch) return operators + i;
  }
  return NULL;
}

/**
 * Function that pushes operation to the operations stack
 * @param op Operation
 */
void push_opstack(struct operator_type *op) {
  if (nopstack > MAXOPSTACK - 1) {
    fprintf(stderr, "ERROR: Operator stack overflow\n");
    status = (EXIT_FAILURE);
  }
  opstack[nopstack++] = op;
}

/**
 * Function pops operation from operators stack
 * @return Operations that was deleted from stack
 */
struct operator_type *pop_opstack() {
  if (!nopstack) {
    fprintf(stderr, "ERROR: Operator stack empty\n");
    status = (EXIT_FAILURE);
    return NULL;
  }
  return opstack[--nopstack];
}

/**
 * Function that pushes number to numbers stack. Numbers in that stack are used
 * as arguments of operations
 * @param num Number that is added to stack
 */
void push_numstack(double num) {
  if (nnumstack > MAXNUMSTACK - 1) {
    fprintf(stderr, "ERROR: Number stack overflow\n");
    status = (EXIT_FAILURE);
  }
  numstack[nnumstack++] = num;
}

/**
 * Function pops number from number's stack
 * @return Number that was deleted from stack
 */
double pop_numstack() {
  if (!nnumstack) {
    fprintf(stderr, "ERROR: Number stack empty\n");
    status = (EXIT_FAILURE);
    return 0.0;
  }
  return numstack[--nnumstack];
}

/**
 * Function that applies given operation to the arguments from number stack and
 * pushes result to the number's stack
 * @param op Operator that is being applied
 * @return Status code: 1 - Error 0 - Ok
 */
int shunt_op(struct operator_type *op) {
  struct operator_type *pop;
  double n1, n2;
  int sstatus = EXIT_SUCCESS;

  if (op->op == '(') {
    push_opstack(op);
    return sstatus;
  } else if (op->op == ')') {
    while (status != (EXIT_FAILURE) && nopstack > 0 &&
           opstack[nopstack - 1]->op != '(') {
      pop = pop_opstack();
      n1 = pop_numstack();
      if (pop->unary)
        push_numstack(pop->eval(n1, 0));
      else {
        n2 = pop_numstack();
        push_numstack(pop->eval(n2, n1));
      }
    }

    if (!(pop = pop_opstack()) || pop->op != '(' || status == (EXIT_FAILURE)) {
      fprintf(stderr, "ERROR: Stack error. No matching \'(\'\n");
      sstatus = EXIT_FAILURE;
    }
    return sstatus;
  }

  if (op->assoc == ASSOC_RIGHT) {
    while (status != (EXIT_FAILURE) && nopstack &&
           op->prec < opstack[nopstack - 1]->prec) {
      pop = pop_opstack();
      n1 = pop_numstack();
      if (pop->unary)
        push_numstack(pop->eval(n1, 0));
      else {
        n2 = pop_numstack();
        push_numstack(pop->eval(n2, n1));
      }
    }
  } else {
    while (status != (EXIT_FAILURE) && nopstack &&
           op->prec <= opstack[nopstack - 1]->prec) {
      pop = pop_opstack();
      n1 = pop_numstack();
      if (pop->unary)
        push_numstack(pop->eval(n1, 0));
      else {
        n2 = pop_numstack();
        push_numstack(pop->eval(n2, n1));
      }
    }
  }
  push_opstack(op);
  return sstatus;
}

/**
 * Function that presents given expression in parsable way. Also changes x to a
 * given value and checks x_flag.
 * @param expression expression input
 * @param x value that will be given to x
 * @return parsable expression
 */
char *clean_expression(char *expression, double x) {
  char *new_exp = malloc(MAXEPRESSIONSIZE + 1);
  char *double_buff = malloc(MAXEPRESSIONSIZE + 1);
  int new_exp_index = 0;
  int i = 0;
  while (expression[i] != '\0') {
    if (expression[i] == 'x') {
      x_flag = 1;
      i++;
      int j = 0;
      sprintf(double_buff, "%lf", x);
      while (double_buff[j] != '\0') {
        new_exp[new_exp_index] = double_buff[j];
        j++;
        new_exp_index++;
      }
    } else if (expression[i] == 's' && strlen(expression) - i >= 2 &&
               expression[i + 1] == 'i' && expression[i + 2] == 'n') {
      new_exp[new_exp_index] = 's';
      i += 3;
      new_exp_index++;
    } else if (expression[i] == 'm' && strlen(expression) - i >= 2 &&
               expression[i + 1] == 'o' && expression[i + 2] == 'd') {
      new_exp[new_exp_index] = '%';
      i += 3;
      new_exp_index++;
    } else if (expression[i] == 'c' && strlen(expression) - i >= 2 &&
               expression[i + 1] == 'o' && expression[i + 2] == 's') {
      new_exp[new_exp_index] = 'c';
      i += 3;
      new_exp_index++;
    } else if (expression[i] == 't' && strlen(expression) - i >= 2 &&
               expression[i + 1] == 'a' && expression[i + 2] == 'n') {
      new_exp[new_exp_index] = 't';
      i += 3;
      new_exp_index++;
    } else if (expression[i] == 'a' && strlen(expression) - i >= 3 &&
               expression[i + 1] == 'c' && expression[i + 2] == 'o' &&
               expression[i + 3] == 's') {
      new_exp[new_exp_index] = 'C';
      i += 4;
      new_exp_index++;
    } else if (expression[i] == 'a' && strlen(expression) - i >= 3 &&
               expression[i + 1] == 's' && expression[i + 2] == 'i' &&
               expression[i + 3] == 'n') {
      new_exp[new_exp_index] = 'S';
      i += 4;
      new_exp_index++;
    } else if (expression[i] == 'a' && strlen(expression) - i >= 3 &&
               expression[i + 1] == 't' && expression[i + 2] == 'a' &&
               expression[i + 3] == 'n') {
      new_exp[new_exp_index] = 'T';
      i += 4;
      new_exp_index++;
    } else if (expression[i] == 's' && strlen(expression) - i >= 3 &&
               expression[i + 1] == 'q' && expression[i + 2] == 'r' &&
               expression[i + 3] == 't') {
      new_exp[new_exp_index] = '\\';
      i += 4;
      new_exp_index++;
    } else if (expression[i] == 'l' && strlen(expression) - i >= 1 &&
               expression[i + 1] == 'n') {
      new_exp[new_exp_index] = 'l';
      i += 2;
      new_exp_index++;
    } else if (expression[i] == 'l' && strlen(expression) - i >= 2 &&
               expression[i + 1] == 'o' && expression[i + 2] == 'g') {
      new_exp[new_exp_index] = 'L';
      i += 3;
      new_exp_index++;
    } else {
      new_exp[new_exp_index] = expression[i];
      i++;
      new_exp_index++;
    }
  }
  free(double_buff);
  new_exp[new_exp_index] = '\0';
  return new_exp;
}

/**
 * Main function. Used as backend to the Calc mode.
 * @param expression Expression given by user
 * @param x Value that will be given to x
 * @param answer buffer that holds value of output or nan if there were any
 * errors
 * @return status code 0 - Ok 1 - Error 2 - Ok and there is a function with x
 */

int parse(char *expression, double x, double *answer) {
  nnumstack = 0;
  nopstack = 0;
  x_flag = 0;
  setlocale(LC_ALL, "en_US.UTF-8");
  expression = clean_expression(expression, x);

  char *expr;
  char *tstart = NULL;
  struct operator_type startop = {'X', 0, ASSOC_NONE, 0, NULL};
  struct operator_type *op = NULL;
  double n1, n2;
  struct operator_type *lastop = &startop;

  for (expr = expression; *expr; ++expr) {
    if (!tstart) {
      if ((op = getop(*expr))) {
        if (lastop && (lastop == &startop || lastop->op != ')')) {
          if (op->op == '-')
            op = getop('_');
          else if (op->op == 's') {
            op = getop('s');
          } else if (op->op == '+') {
            op = getop('p');
          } else if (op->op == 'c') {
            op = getop('c');
          } else if (op->op == 't') {
            op = getop('t');
          } else if (op->op == 'C') {
            op = getop('C');
          } else if (op->op == 'S') {
            op = getop('S');
          } else if (op->op == 'T') {
            op = getop('T');
          } else if (op->op == '\\') {
            op = getop('\\');
          } else if (op->op == 'l') {
            op = getop('l');
          } else if (op->op == 'L') {
            op = getop('L');
          } else if (op->op != '(') {
            fprintf(stderr, "ERROR: Illegal use of binary operator (%c)\n",
                    op->op);
            free(expression);
            status = 0;
            return (EXIT_FAILURE);
          }
        }
        shunt_op(op);
        if (status == EXIT_FAILURE) {
          free(expression);
          status = 0;
          return (EXIT_FAILURE);
        }
        lastop = op;
      } else if (*expr == '.' || isdigit(*expr))
        tstart = expr;
      else if (!isspace(*expr)) {
        fprintf(stderr, "ERROR: Syntax error\n");
        free(expression);
        nnumstack = 0;
        status = 0;
        return (EXIT_FAILURE);
      }
    } else {
      if (isspace(*expr)) {
        push_numstack(atof(tstart));
        tstart = NULL;
        lastop = NULL;
      } else if ((op = getop(*expr))) {
        push_numstack(atof(tstart));
        tstart = NULL;
        shunt_op(op);
        if (status == EXIT_FAILURE) {
          free(expression);
          status = 0;
          return (EXIT_FAILURE);
        }
        lastop = op;
      } else if (!(*expr == '.' || isdigit(*expr))) {
        fprintf(stderr, "ERROR: Syntax error\n");
        free(expression);
        nnumstack = 0;
        status = 0;
        return (EXIT_FAILURE);
      }
    }
  }
  if (tstart) push_numstack(atof(tstart));

  while (nopstack) {
    op = pop_opstack();
    n1 = pop_numstack();
    if (status == EXIT_FAILURE) {
      free(expression);
      status = 0;
      return (EXIT_FAILURE);
    }
    if (op->unary)
      push_numstack(op->eval(n1, 0));
    else {
      n2 = pop_numstack();
      if (status == EXIT_FAILURE) {
        free(expression);
        status = 0;
        return (EXIT_FAILURE);
      }
      push_numstack(op->eval(n2, n1));
    }
  }

  if (nnumstack != 1) {
    fprintf(
        stderr,
        "ERROR: Number stack has %d elements after evaluation. Should be 1.\n",
        nnumstack);
    free(expression);
    nnumstack = 0;
    status = 0;
    return (EXIT_FAILURE);
  }
  *answer = (double)numstack[0];
  free(expression);
  if (x_flag == 0 && status == 0) {
    return EXIT_SUCCESS;
  } else if (status == 0) {
    return 2;
  } else {
    return 0;
  }
}
