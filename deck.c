#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  //This should print out the contents of a hand.
  //It should print each card, and a space after each card. 
  for (int i = 0;i<hand->n_cards;i++){
    print_card(*(hand->cards[i]));
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  //This function check if a deck contains a particular card or not.
  //If the deck does contain the card, return 1.  Otherwise,return 0.
  for (int i = 0;i<d->n_cards;i++){
    if ((c.value == d->cards[i]->value)&& (c.suit==d->cards[i]->suit)){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  //This function takes in a deck an shuffles it,
  //randomly permuting the order of the cards.

  //Start from last element and swap one by one
  for (int i = d->n_cards - 1; i>0;i--){
    //Pick random index 0 to i
    int j = rand()%(i+1);
    //Swap deck[i] with random index element
    card_t *temp = d->cards[i];
    d->cards[i] = d->cards[j];
    d->cards[j] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  // This function should check that the passed in deck contains ever  valid card exactly once.
  assert(d->n_cards==52);
  for (unsigned i=0; i<d->n_cards;i++){
    assert(deck_contains(d,card_from_num(i))==1);
  } 
}
