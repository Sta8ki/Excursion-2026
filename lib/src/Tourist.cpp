#include "Tourist.h"

#include <iostream>

Tourist::Tourist(const std::string& person_name, const std::string& person_phone)
    : Person(person_name, person_phone), arrived(false) {}

void Tourist::print_info() const {
    std::cout << "Tourist: " << name << " (" << phone << ") | "
              << (arrived ? "arrived" : "not arrived yet") << std::endl;
}

void Tourist::mark_arrived() {
    arrived = true;
}

bool Tourist::is_arrived() const {
    return arrived;
}