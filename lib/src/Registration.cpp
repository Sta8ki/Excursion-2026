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