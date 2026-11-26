#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Conference.h"
#include "Participant.h"
#include "RegistrationStatus.h"

#include <memory>
#include <stack>
#include <string>

class Registration {
public:
    Registration(int registration_id, const std::shared_ptr<Conference>& registered_conference,
                 const std::shared_ptr<Participant>& registered_participant);

    bool pay(double amount);

    bool confirm();

    bool issue_badge();

    bool mark_attended();

    bool issue_certificate();

    bool cancel(const std::string& reason);

    void print_info() const;
    void print_history() const;

    int get_id() const;
    int get_conference_id() const;
    RegistrationStatus get_status() const;
    double get_fee_due() const;
    double get_paid_amount() const;
    std::shared_ptr<Participant> get_participant() const;

private:
    bool fail(const std::string& message) const;
    void change_status(RegistrationStatus new_status);

    int id;
    std::shared_ptr<Conference> conference;
    std::shared_ptr<Participant> participant;
    double fee_due;
    double paid_amount;
    std::string badge_number;
    std::string cancel_reason;
    std::stack<RegistrationStatus> history;
    RegistrationStatus status;
};

#endif
