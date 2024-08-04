#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

bool ask(char msg[]) {
  printf("%s %s %s", RED, msg, RESET);

  bool done = true;

  while (done == true) {
    char ans;

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
      printf(YEL "Invalid response. Please try again\n" RESET);
    }
    printf(RED "What will you do (a or b): " RESET);
  }
}

int main() {
  char name[] = "";

  printf(BLU "Welcome to the [Adventure Game Title]\n" RESET);
  printf("-------------------------------------\n");
  printf("\n");
  printf("Long, long ago there was a land, far far away\n");
  printf("You are a young orphan, raised by merchants, given the name: ");
  scanf(" %s", &name);
  printf("\n");
  printf("You wake up one day to sound of fighting outside your window\n");
  printf("Living in the slums. this is not an uncommon sight to you, until you suddenly hear a familar scream...\n");
  if (ask("Would you like to:\nA - Run to the fight  OR  B - Find people to come and help\n")) {
    printf("You rush into the fight, attacking both friend and foe, until you see the source of the scream\n");
    printf("The scream had come from you brother, Irwin, who was lying on the floor bleeding profusely from the face\n");
    ask("Do you:\nA - Run to your brother trying to help him  OR  B - run after the man who had hit him in the face, and was currently disappearing into the crowd\n");
  }  
  else {
    printf("Who run into the main room to find the house deserted\n");
    printf("You quickly move your search outside and find a group of people running into the fight\n");
    printf("You quickly join their ranks as they move through the fight and spot the source of the scream\n");
    printf("It was your brother, Irwin, who was now on the floor unconcious, fountains of blood pouring out of his nose and mouth\n");
    printf("You quickly run to his side but realise it is too late...\n");
    printf("\n");
    printf("\n");
    printf("GAME OVER\n");
  }
}


