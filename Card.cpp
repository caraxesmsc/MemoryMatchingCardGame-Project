#include "Card.h"
#include <string>
using namespace std;


Card::Card() : isShown(false) {}

Card::Card(string x) : CardName(x), isShown(false) {}

Card::Card(int value) : isShown(false) {

    // Assume that values range from 1 to 13 (representing Ace to King)
    if (value >= 1 && value <= 13) {
        switch (value) {
        case 1:
            CardName = "A";
            break;
        case 11:
            CardName = "J";
            break;
        case 12:
            CardName = "Q";
            break;
        case 13:
            CardName = "K";
            break;
        default:
            CardName = std::to_string(value);
            break;
        }
    }


}

void Card::setShown(bool booleanVar) {
    isShown = booleanVar;
}
