#pragma once
#include <iostream>
#include <vector>
#include "Employee.hpp"
#include "Shelf.hpp"

class Warehouse {
public:
    std::vector <Employee> Employees;
    std::vector <Shelf> Shelves;

    Warehouse();
    void addEmployee(Employee employee);
    void addShelves(Shelf shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickItems(std::string itemName, int itemCount);
};

