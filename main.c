#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool ask() {
  bool done = true;

  while (done == true) {
    char ans;

    printf("What will you do (a or b): ");
    scanf(" %c", &ans);

    if (tolower(ans) == *"a") {
      done = false;
      return true;
    }
    else if (tolower(ans) == *"b") {
      done = false;
      return false;
    }
    else {
      done = true;
      printf("Invalid response. Please try again\n");
    }
  }
}

int main() {
  char *textA[] = {"Text", "Text2", "Text3"};
  char *textB[] = {"TextB", "TextB2", "TextB3"};
  printf("%d", ask());
}


