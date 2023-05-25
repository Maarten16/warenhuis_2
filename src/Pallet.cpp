#include "headers/Pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount)
: itemName(itemName),
itemCapacity(itemCapacity),
itemCount(itemCount) {
    if(itemCount > itemCapacity) {
        this->itemCount = itemCapacity;
    }
}

Pallet::Pallet() {
    this->itemName = "";
    this->itemCapacity = 0;
    this->itemCount = 0;}

std::string Pallet::getItemName() {
    return this->itemName;
}

int Pallet::getItemCount() {
    return this->itemCount;
}

int Pallet::getRemainingSpace() {
    return this->itemCapacity - this->itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    return true;
}

bool Pallet::takeOne() {
    if (itemCount > 0){
        itemCount -= 1;
        return true;
    } else {
        return false;
    }
}

bool Pallet::putOne() {
    if (itemCount < itemCapacity){
        itemCount += 1;
        return true;
    } else {
        return false;
    }
}
