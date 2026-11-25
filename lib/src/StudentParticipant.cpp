#include "StudentParticipant.h"

#include <iostream>

StudentParticipant::StudentParticipant(const std::string& person_name, const std::string& person_email,
                                       const std::string& student_university)
    : Participant(person_name, person_email), university(student_university) {}

void StudentParticipant::print_info() const {
    std::cout << "[" << get_type() << "] " << name << " (" << email << ") | University: "
              << university << std::endl;
}

std::string StudentParticipant::get_type() const {
    return "Student";
}

double StudentParticipant::calculate_fee(double base_fee) const {
    return base_fee * 0.5;
}

std::string StudentParticipant::certificate_title() const {
    return "Student Certificate of Participation";
}
