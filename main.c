#include <stdio.h>
#include <stdlib.h>
#include <time.h>

srandom(unsigned int time());

int draw() { return (random() % 13) + 1; }

int main(int argc, char *argv[]) {
  printf("Welcome to CLI Blackjack");
  printf("------------------------");

  int player_total = 0;
  int card1 = 0;
  int card2 = 0;
  card1 = draw();
  card2 = draw();
  printf("Here are your 2 cards\n");
  printf("%i and %i", card1, card2);

  return EXIT_SUCCESS;
}
