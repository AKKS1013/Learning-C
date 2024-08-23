#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

int ask(char msg[]) {
  printf("%s %s %s", RED, msg, RESET);

  bool done = true;

  while (done == true) {
    char ans;

    scanf(" %c", &ans);

    if (tolower(ans) == *"a") {
      done = false;
      return 1;
    } else if (tolower(ans) == *"b") {
      done = false;
      return 2;
    } else if (tolower(ans) == *"c") {
      done = false;
      return 3;
    } else {
      done = true;
      printf(YEL "Invalid response. Please try again\n" RESET);
    }
    printf(RED "What will you do (a, b or c): " RESET);
  }
}

int main() {
  char name[] = "";

  printf(BLU "Welcome to the [Adventure Game Title]\n" RESET);
  printf("-------------------------------------\n");
  printf("\n");
  printf("You're sitting at your desk, minding your own business, when a "
         "strange package arrives. It's addressed to you with no return "
         "address. Intrigued, you open it to find a small, ornate box. Inside, "
         "there's a single, glowing crystal.\n");
  switch (ask("Will you: \x1B[36ma - Examine the crystal, b - Put it on or c - "
              "Call the police")) {
  case 1:
    printf("You carefully inspect the crystal, trying to determine its "
           "properties.\n");
    printf("\n");
    printf("As you examine the crystal, you notice it seems to pulse with an "
           "otherworldly energy. You feel a strange warmth spreading through "
           "your body. Suddenly, you see visions of a distant planet, filled "
           "with towering, crystalline structures.\n");

  case 2:
    printf("You decide to wear the crystal as a necklace.\n");
    printf("As soon as you place the crystal around your neck, you feel a "
           "surge of power. You can sense the world around you in a new way, "
           "like you're connected to everything. You also feel a strange pull "
           "towards the nearest body of water.\n");

  case 3:
    printf(
        "You think the package might be dangerous and call the authorities.\n");
    printf("The police arrive and take the crystal away for examination. They "
           "thank you for reporting the suspicious package. However, you can't "
           "shake the feeling that something is amiss.\n");
  }
}
