#include "Person.h"

#include <iostream>

Person::Person(const std::string& person_name, const std::string& person_email)
    : name(person_name), email(person_email) {}

void Person::print_info() const {
    std::cout << name << " (" << email << ")" << std::endl;
}

std::string Person::get_name() const {
    return name;
}

std::string Person::get_email() const {
    return email;
}
