#ifndef GUIDE_H
#define GUIDE_H

#include "Person.h"

class Guide : public Person {
public:
    Guide(int guide_id, const std::string& person_name,
          const std::string& person_phone, const std::string& guide_language);

    void print_info() const override;

    int get_id() const;
    bool is_available() const;
    bool is_busy() const;
    bool is_free() const;

    void refuse();
    void set_busy(bool value);

private:
    int id;
    std::string language;
    bool available;
    bool busy;
};

#endif