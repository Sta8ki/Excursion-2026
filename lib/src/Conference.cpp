#include "Conference.h"

#include <iostream>

Conference::Conference(int conference_id, const std::string& conference_title,
                       const std::string& conference_date, int max_seats, double fee)
    : id(conference_id), title(conference_title), date(conference_date),
      capacity(max_seats), taken_seats(0), base_fee(fee) {}

void Conference::print_info() const {
    std::cout << "Conference #" << id << ": " << title << " | Date: " << date
              << " | Fee: " << base_fee << " USD"
              << " | Seats: " << taken_seats << "/" << capacity
              << " | Waiting: " << waiting_list.size() << std::endl;
}

void Conference::print_waiting_list() const {
    std::cout << "--- Waiting list of \"" << title << "\" ---" << std::endl;
    if (waiting_list.empty()) {
        std::cout << "The waiting list is empty." << std::endl;
        return;
    }
    std::queue<std::shared_ptr<Participant>> copy = waiting_list;
    int position = 1;
    while (!copy.empty()) {
        std::cout << position++ << ". ";
        copy.front()->print_info();
        copy.pop();
    }
}

bool Conference::has_free_seat() const {
    return taken_seats < capacity;
}

void Conference::take_seat() {
    ++taken_seats;
}

void Conference::release_seat() {
    if (taken_seats > 0) {
        --taken_seats;
    }
}

void Conference::add_to_waiting(const std::shared_ptr<Participant>& participant) {
    waiting_list.push(participant);
}

std::shared_ptr<Participant> Conference::pop_waiting() {
    if (waiting_list.empty()) {
        return nullptr;
    }
    std::shared_ptr<Participant> next = waiting_list.front();
    waiting_list.pop();
    return next;
}

int Conference::get_waiting_count() const {
    return static_cast<int>(waiting_list.size());
}

int Conference::get_id() const {
    return id;
}

std::string Conference::get_title() const {
    return title;
}

std::string Conference::get_date() const {
    return date;
}

double Conference::get_base_fee() const {
    return base_fee;
}

int Conference::get_capacity() const {
    return capacity;
}
