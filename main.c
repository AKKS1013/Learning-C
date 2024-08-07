#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int draw() { return (random() % 13) + 1; }

int more(int total) {
  bool hit = true;
  char ans;
  printf("Would you like to (h)it or (s)tand: ");
  scanf(" %c", &ans);

  if (ans == 'h') {
    hit = true;
  } else {
    hit = false;
  }

  while (hit) {
    int card = draw();
    total += card;
    printf("Your card: %i\n", card);
    if (total > 21) {
      printf("Sorry, you BUST!");
      return total;
    }
    printf("Would you like to (h)it or (s)tand: ");
    scanf(" %c", &ans);

    if (ans == 'h') {
      hit = true;
    } else {
      hit = false;
    }
  }
  return total;
}

int main(int argc, char *argv[]) {
  srandom((unsigned int)time(NULL));

  printf("Welcome to CLI Blackjack");
  printf("------------------------");

  int card1 = 0;
  int card2 = 0;
  card1 = draw();
  card2 = draw();
  int total = card1 + card2;
  printf("Here are your 2 cards:\n");
  printf("%i and %i\n", card1, card2);
  total = more(total);

  return EXIT_SUCCESS;
}
