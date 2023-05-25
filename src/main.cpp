#include <iostream>
#include <functional>
#include "headers/Employee.hpp"
#include "headers/Shelf.hpp"
#include "headers/Warehouse.hpp"
#include "headers/instructions.hpp"

int c = 0;
int plus(int a, int b) {
    c++;
    return a + b;
}

int a = 1;
int b = 2;


template<typename Func>
int printInstruction(Func func) {
    std::string func_name = typeid(func).name();//function name
    int result = func(); //execute function
    if (result == -1){
        std::cout << "stop function";
    }
    return result;
}

#define print(func) printInstruction([&]() { return func; })

int main() {

    Warehouse warehouse = Warehouse();

    Pallet pallet1 = Pallet("bananas", 10, 5);
    Pallet pallet2 = Pallet("peaches", 10, 6);
    Pallet pallet3 = Pallet("pork", 10, 10);
    Pallet pallet4 = Pallet();
    Pallet pallet5 = Pallet();
    Pallet pallet6 = Pallet();
    Pallet pallet7 = Pallet("bananas", 10, 3);
    Pallet pallet8 = Pallet();

    Shelf shelf1 = Shelf();
    shelf1.swapPallet(3,4);
    shelf1.name = "test";
    shelf1.pallets = {pallet1, pallet2, pallet3, pallet4};

    Shelf shelf2 = Shelf();
    shelf2.name = "test2";
    shelf2.pallets = {pallet5, pallet6, pallet7, pallet8};

    warehouse.addShelves(shelf1);
    warehouse.addShelves(shelf2);

    Employee employee1 = Employee("test", true);
    Employee employee2 = Employee("test2", false);
    Employee employee3 = Employee("test3", true);
    Employee employee4 = Employee("test4", false);

    warehouse.addEmployee(employee1);
    warehouse.addEmployee(employee2);
    warehouse.addEmployee(employee3);
    warehouse.addEmployee(employee4);

    warehouse.rearrangeShelf(warehouse.Shelves[0]);

    printItems(warehouse);
    std::cout << "\nstock: \t";
    printStock("bananas", warehouse);
    printEmployees(warehouse);

}
