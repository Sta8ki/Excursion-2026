#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& person_name, const std::string& person_email);
    virtual ~Person() = default;

    virtual void print_info() const;

    std::string get_name() const;
    std::string get_email() const;

protected:
    std::string name;
    std::string email;
};

#endif