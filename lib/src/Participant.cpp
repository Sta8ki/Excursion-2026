#include "Participant.h"

#include <iostream>

Participant::Participant(const std::string& person_name, const std::string& person_email)
    : Person(person_name, person_email) {}

void Participant::print_info() const {
    std::cout << "[" << get_type() << "] " << name << " (" << email << ")" << std::endl;
}

std::string Participant::get_type() const {
    return "Regular";
}

double Participant::calculate_fee(double base_fee) const {
    return base_fee;
}

std::string Participant::certificate_title() const {
    return "Certificate of Participation";
}
