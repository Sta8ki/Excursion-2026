#ifndef REGISTRATIONSTATUS_H
#define REGISTRATIONSTATUS_H

#include <string>

enum class RegistrationStatus {
    REGISTERED,
    PAID,
    CONFIRMED,
    BADGE_ISSUED,
    ATTENDED,
    CERTIFIED,
    CANCELLED
};

std::string status_to_string(RegistrationStatus status);

#endif
