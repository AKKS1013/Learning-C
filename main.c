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
    switch (ask("Will you: \x1B[36ma - Try to communicate to the visions or b "
                "- Ignore the visions and focus on the crystal]")) {
    case 1:
      printf("As you focus on the visions, you feel a strange tingling "
             "sensation in your mind. You try to speak mentally, and to your "
             "surprise, you hear a voice in your head. It's a deep, resonant "
             "voice that speaks in a language you don't understand. However, "
             "you feel a sense of peace and understanding as you listen.\n");
      printf("The voice in your head continues to speak, and you gradually "
             "begin to understand the language. It's a language of pure "
             "thought, a way of communicating without words. The voice tells "
             "you that you have been chosen to receive a great gift, a power "
             "that can change the world.\n");
      printf("The voice in your head continues to speak, revealing the secrets "
             "of the universe. You learn about ancient civilizations, powerful "
             "beings, and the true nature of reality. The voice tells you that "
             "you are destined to play a crucial role in the future of the "
             "world.\n");
    case 2:
      printf(
          "As you focus on the crystal, you feel a surge of power that courses "
          "through your body. You realize that the crystal is a powerful "
          "artifact, capable of granting incredible abilities. You can control "
          "the elements, manipulate time, and even travel through dimensions. "
          "However, with great power comes great responsibilities and you "
          "realize you must use your powers wisely.\n");
    }

  case 2:
    printf("You decide to wear the crystal as a necklace.\n");
    printf("As soon as you place the crystal around your neck, you feel a "
           "surge of power. You can sense the world around you in a new way, "
           "like you're connected to everything. You also feel a strange pull "
           "towards the nearest body of water.\n");
    switch (ask("Will you: \x1b[36ma - Resist the pull and stay where you are "
                "or b - Follow the pull and go to the water")) {
    case 1:
      printf("You fight against the pull towards the water, but it's stronger "
             "than you. You feel a sense of panic as you realize you have no "
             "control over your body. The pull becomes so intense that you "
             "feel like you're being ripped apart.\n");
      printf("You slowly lose consciousness as the pain overwhelms you, and "
             "everything fades to black.\n");
    }

  case 3:
    printf(
        "You think the package might be dangerous and call the authorities.\n");
    printf("The police arrive and take the crystal away for examination. They "
           "thank you for reporting the suspicious package. However, you can't "
           "shake the feeling that something is amiss.\n");
  }
}
