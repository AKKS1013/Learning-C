#include <stdio.h>
#include <stdbool.h>

int main() {
  char op;
  double first, second;
  bool quit = true;

  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &op);

  printf("Enter two operands: ");
  scanf("%lf %lf", &first, &second);

  switch (op) {
    case '+':
      printf("%.2lf + %.2lf = %.2lf\n", first, second, first + second);
      break;
    case '-':
      printf("%.2lf - %.2lf = %.2lf\n", first, second, first - second);
      break;
    case '*':
      printf("%.2lf * %.2lf = %.2lf\n", first, second, first * second);
      break;
    case '/':
      printf("%.2lf / %.2lf = %.2lf\n", first, second, first / second);
      break;
  // operator doesn't match any case constant
    default:
      printf("Invalid operator entered. Please try again\n");
  }
 }
