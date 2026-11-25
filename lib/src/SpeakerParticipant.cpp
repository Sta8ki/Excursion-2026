#include "SpeakerParticipant.h"

#include <iostream>

SpeakerParticipant::SpeakerParticipant(const std::string& person_name, const std::string& person_email,
                                       const std::string& talk_topic)
    : Participant(person_name, person_email), topic(talk_topic) {}

void SpeakerParticipant::print_info() const {
    std::cout << "[" << get_type() << "] " << name << " (" << email << ") | Talk: "
              << topic << std::endl;
}

std::string SpeakerParticipant::get_type() const {
    return "Speaker";
}

double SpeakerParticipant::calculate_fee(double) const {
    return 0.0;
}

std::string SpeakerParticipant::certificate_title() const {
    return "Speaker Certificate";
}
