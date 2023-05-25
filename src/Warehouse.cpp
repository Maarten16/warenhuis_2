#include "headers/Warehouse.hpp"

Warehouse::Warehouse() {}

void Warehouse::addEmployee(Employee employee) {
    this->Employees.push_back(employee);
}

void Warehouse::addShelves(Shelf shelf) {
    this->Shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    for (Employee employee : this->Employees) {
         if(employee.getBusy() == 0 || employee.getForkLiftCertificate() == 1){
             employee.setBusy(1);
             std::vector<int> palletContent;
             for (Pallet pallet : shelf.pallets) {
                 palletContent.push_back(pallet.getItemCount());
             }
                 int i, j, min_idx;
                 for (i = 0; i < palletContent.size() - 1; i++) {
                     min_idx = i;
                     for (j = i + 1; j < palletContent.size(); j++) {
                         if (palletContent[j] < palletContent[min_idx])
                             min_idx = j;
                     }
                     if (min_idx != i)
                         swap(palletContent[min_idx], palletContent[i]);
             }
         }
    }
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    int itemsAvailable = 0;
    for (Shelf shelf : this->Shelves) {
        for (Pallet pallet : shelf.pallets) {
            if(itemName == pallet.getItemName()){
                itemsAvailable += pallet.getItemCount();
            }
        }
    }
    if (itemsAvailable >= itemCount) {
        for (Shelf shelf : this->Shelves) {
            for (Pallet pallet : shelf.pallets) {
                if(pallet.getItemName() == itemName) {
                    while (pallet.getItemCount() > 0 && itemCount > 0) {
                        pallet.takeOne();
                        itemCount -= 1;
                    }
                }
            }
        }
        return true;
    }
    return false;
}