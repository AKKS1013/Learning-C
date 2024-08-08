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
    total = total + card;
    printf("Your card: %i\n", card);
    if (total > 21) {
      printf("Sorry, you BUST!");
      return 0;
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

int dealer(int total) {
  while (total < 16) {
    int cardd = 0;
    printf("The dealer draws:\n");
    cardd = draw();
    printf("%i\n", cardd);
    total = total + cardd;
  }
  return total;
}

int main(int argc, char *argv[]) {
  srandom((unsigned int)time(NULL));

  printf("Welcome to CLI Blackjack");
  printf("------------------------\n");

  int card1 = 0;
  int card2 = 0;
  int dealer_card = 0;
  card1 = draw();
  card2 = draw();
  dealer_card = draw();
  int total = card1 + card2;
  int dealer_total = dealer_card;
  printf("Here are your 2 cards:\n");
  printf("%i and %i\n", card1, card2);
  printf("The dealer has:\n");
  printf("%i\n", dealer_card);
  total = more(total);
  if (total == 0) {
    return EXIT_SUCCESS;
  }
  printf("The dealer reveals: \n");
  dealer_card = draw();
  dealer_total = dealer_total + dealer_card;
  printf("%i\n", dealer_card);
  dealer_total = dealer(dealer_total);
  if (dealer_total > 21) {
    printf("Dealer bust. You WIN!");
  } else if ((21 - dealer_total) > (21 - total)) {
    printf("You are closer to 21. You WIN!");
  } else {
    printf("Dealer is closer to 21. You LOSE!");
  }
  return EXIT_SUCCESS;
}
