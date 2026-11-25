#ifndef STUDENTPARTICIPANT_H
#define STUDENTPARTICIPANT_H

#include "Participant.h"

class StudentParticipant : public Participant {
public:
    StudentParticipant(const std::string& person_name, const std::string& person_email,
                       const std::string& student_university);

    void print_info() const override;

    std::string get_type() const override;
    double calculate_fee(double base_fee) const override;
    std::string certificate_title() const override;

private:
    std::string university;
};

#endif
