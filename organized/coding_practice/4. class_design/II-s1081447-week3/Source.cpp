//Classes: A Deeper Look (2 weeks)
//�� ���g�@�ӵ{������B�z���J�P���~�P�P�o�P
//�� �Ӹ`�ѦҪ���
#include "DeckCard.h"

const string Card::suits[4] = { " ���� ", " ��� ", " �®� ", " ���� " };
const string Card::faces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10","J", "Q", "K" };

string Card::toString()
{
   string CardName = suits[suit] + " " + faces[face];

   return CardName;
}

DeckOfCards::DeckOfCards()
{
   
   for (int f = 0; f < 4; f++) {
      for (int s = 0; s < 13; s++) {
         deck.push_back(Card(s, f));
      }
   }
}

void DeckOfCards::shuffle()
{
   srand(time(NULL));
   Card temp(0, 0);
   for (int i = 0; i < 52; i++) {
      temp = deck[i];
      int x = rand() % (52 - i) + i;
      deck[i] = deck[x];
      deck[x] = temp;
   }
}

Card& DeckOfCards::dealCard()
{
   return deck[currentCard];
}

bool DeckOfCards::moreCards()
{
   currentCard++;
   if (currentCard == 52)
      return false;
   return true;
}