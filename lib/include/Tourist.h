#ifndef TOURIST_H
#define TOURIST_H

#include "Person.h"

class Tourist : public Person {
public:
    Tourist(const std::string& person_name, const std::string& person_phone);

    void print_info() const override;

    void mark_arrived();
    bool is_arrived() const;

private:
    bool arrived;
};

#endif