#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Person.h"

// Regular participant pays the full fee
class Participant : public Person {
public:
    Participant(const std::string& person_name, const std::string& person_email);

    void print_info() const override;

    virtual std::string get_type() const;
    virtual double calculate_fee(double base_fee) const;
    virtual std::string certificate_title() const;
};

#endif