#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& person_name, const std::string& person_phone);
    virtual ~Person() = default;

    virtual void print_info() const;

    std::string get_name() const;
    std::string get_phone() const;

protected:
    std::string name;
    std::string phone;
};

#endif