#include <stdio.h>

int main() {
  char op;
  double first, second;

  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &op);

  printf("Enter two operands: ");
  scanf("%lf", &first);
  scanf("%lf", &second);

  printf("%lf ", first);
  printf("%lf ", second);
  printf("%c", op);
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
  }
}
