#include "Registration.h"

#include <algorithm>
#include <iostream>
#include <vector>

Registration::Registration(int registration_id, const std::shared_ptr<Conference>& registered_conference,
                           const std::shared_ptr<Participant>& registered_participant)
    : id(registration_id), conference(registered_conference), participant(registered_participant),
      paid_amount(0.0), status(RegistrationStatus::REGISTERED) {
    fee_due = participant->calculate_fee(conference->get_base_fee());
    history.push(status);

    if (fee_due <= 0.0) {
        std::cout << "Participation is free: the payment stage is skipped." << std::endl;
        change_status(RegistrationStatus::PAID);
    }
}

bool Registration::fail(const std::string& message) const {
    std::cout << "Error: " << message << std::endl;
    return false;
}

void Registration::change_status(RegistrationStatus new_status) {
    status = new_status;
    history.push(new_status);
}

bool Registration::pay(double amount) {
    if (status != RegistrationStatus::REGISTERED) {
        return fail("payment is possible only at the REGISTERED stage.");
    }
    if (amount < fee_due) {
        return fail("insufficient amount: " + std::to_string(static_cast<int>(amount)) +
                    " USD paid, " + std::to_string(static_cast<int>(fee_due)) + " USD required.");
    }
    paid_amount = fee_due;
    change_status(RegistrationStatus::PAID);
    std::cout << "Payment of " << paid_amount << " USD accepted." << std::endl;
    if (amount > fee_due) {
        std::cout << "Change returned: " << amount - fee_due << " USD." << std::endl;
    }
    return true;
}

bool Registration::confirm() {
    if (status == RegistrationStatus::REGISTERED) {
        return fail("the registration cannot be confirmed before the payment.");
    }
    if (status != RegistrationStatus::PAID) {
        return fail("confirmation is possible only after the payment.");
    }
    change_status(RegistrationStatus::CONFIRMED);
    std::cout << "Registration #" << id << " is confirmed." << std::endl;
    return true;
}

bool Registration::issue_badge() {
    if (status != RegistrationStatus::CONFIRMED) {
        return fail("the badge can be issued only for a confirmed registration.");
    }
    badge_number = "BADGE-" + std::to_string(conference->get_id()) + "-" + std::to_string(id);
    change_status(RegistrationStatus::BADGE_ISSUED);
    std::cout << "Badge " << badge_number << " issued to " << participant->get_name() << "." << std::endl;
    return true;
}

bool Registration::mark_attended() {
    if (status != RegistrationStatus::BADGE_ISSUED) {
        return fail("attendance can be marked only after the badge is issued.");
    }
    change_status(RegistrationStatus::ATTENDED);
    std::cout << participant->get_name() << " is marked as present." << std::endl;
    return true;
}

bool Registration::issue_certificate() {
    if (status != RegistrationStatus::ATTENDED) {
        return fail("the certificate can be issued only after attendance is marked.");
    }
    change_status(RegistrationStatus::CERTIFIED);
    std::cout << participant->certificate_title() << " issued to "
              << participant->get_name() << "." << std::endl;
    return true;
}