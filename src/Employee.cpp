
#include "headers/Employee.hpp"

Employee::Employee(std::string name, bool forkLiftCertificate)
: name(name),
forkLiftCertificate(forkLiftCertificate){
    this->busy = false;
}

std::string Employee::getName() {
    return this->name;
}

bool Employee::getBusy() {
    return this->busy;
}

void Employee::setBusy(bool busy) {
    this->busy = busy;
}

bool Employee::getForkLiftCertificate() {
    return this->forkLiftCertificate;
}

bool Employee::setForkLiftCertificate(bool forkLiftCertificate) {
    this->forkLiftCertificate = forkLiftCertificate;
}
