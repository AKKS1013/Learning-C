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
}
