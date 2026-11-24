#include "Person.h"
#include <iostream>

Person::Person(const std::string& person_name, const std::string& person_phone)
    : name(person_name), phone(person_phone) {}

    void Person::print_info() const {
        std::cout << name << " (" << phone << ")" << std::endl;
    }

std::string Person::get_name() const {
    return name;
}

std::string Person::get_phone() const {
    return phone;
}