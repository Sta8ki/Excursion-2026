#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "Participant.h"

#include <memory>
#include <queue>
#include <string>

class Conference {
public:
    Conference(int conference_id, const std::string& conference_title,
               const std::string& conference_date, int max_seats, double fee);

    void print_info() const;
    void print_waiting_list() const;

    bool has_free_seat() const;
    void take_seat();
    void release_seat();

    void add_to_waiting(const std::shared_ptr<Participant>& participant);
    std::shared_ptr<Participant> pop_waiting();
    int get_waiting_count() const;

    int get_id() const;
    std::string get_title() const;
    std::string get_date() const;
    double get_base_fee() const;
    int get_capacity() const;

private:
    int id;
    std::string title;
    std::string date;
    int capacity;
    int taken_seats;
    double base_fee;
    std::queue<std::shared_ptr<Participant>> waiting_list;
};

#endif
