#include "headers/Shelf.hpp"

Shelf::Shelf() {}

bool Shelf::swapPallet(int slot, int slot2){
    Pallet temp = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;
    return true;
}

