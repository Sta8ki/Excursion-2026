#ifndef SPEAKERPARTICIPANT_H
#define SPEAKERPARTICIPANT_H

#include "Participant.h"

class SpeakerParticipant : public Participant {
public:
    SpeakerParticipant(const std::string& person_name, const std::string& person_email,
                       const std::string& talk_topic);

    void print_info() const override;

    std::string get_type() const override;
    double calculate_fee(double base_fee) const override;
    std::string certificate_title() const override;

private:
    std::string topic;
};

#endif
