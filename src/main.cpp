#include <iostream>
#include "headers/Employee.hpp"
#include "headers/Shelf.hpp"
#include "headers/Warehouse.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Employee employee1 = Employee("John", true);
    Employee employee2 = Employee("Jane", false);

    employee1.setBusy(true);
    employee2.setBusy(false);
    employee1.setForkLiftCertificate(true);
    employee2.setForkLiftCertificate(true);
    std::cout << employee1.getBusy();
    std::cout << employee1.getForkLiftCertificate();
    std::cout << employee1.getName();




    Shelf shelf1 = Shelf();
    Shelf shelf2 = Shelf();

    Warehouse warehouse = Warehouse();

    Pallet pallet1 = Pallet("Pallet1", 10, 10);
    Pallet pallet2 = Pallet("Pallet1", 5, 10);
    return 0;
}
