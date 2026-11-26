#include "RegistrationStatus.h"

std::string status_to_string(RegistrationStatus status) {
    switch (status) {
        case RegistrationStatus::REGISTERED:   return "REGISTERED";
        case RegistrationStatus::PAID:         return "PAID";
        case RegistrationStatus::CONFIRMED:    return "CONFIRMED";
        case RegistrationStatus::BADGE_ISSUED: return "BADGE_ISSUED";
        case RegistrationStatus::ATTENDED:     return "ATTENDED";
        case RegistrationStatus::CERTIFIED:    return "CERTIFIED";
        case RegistrationStatus::CANCELLED:    return "CANCELLED";
    }
    return "UNKNOWN";
}
