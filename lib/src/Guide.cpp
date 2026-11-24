#include "Guide.h"

#include <iostream>

Guide::Guide(int guide_id, const std::string& person_name,
             const std::string& person_phone, const std::string& guide_language)
    : Person(person_name, person_phone), id(guide_id), language(guide_language),
      available(true), busy(false) {}

void Guide::print_info() const {
    std::cout << "Guide #" << id << ": " << name << " (" << phone << ") | Language: "
              << language << " | ";
    if (!available) {
        std::cout << "refused";
    } else if (busy) {
        std::cout << "busy";
    } else {
        std::cout << "free";
    }
    std::cout << std::endl;
}

int Guide::get_id() const {
    return id;
}

bool Guide::is_available() const {
    return available;
}

bool Guide::is_busy() const {
    return busy;
}

bool Guide::is_free() const {
    return available && !busy;
}

void Guide::refuse() {
    available = false;
}

void Guide::set_busy(bool value) {
    busy = value;
}