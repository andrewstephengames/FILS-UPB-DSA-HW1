#include "flight.hpp"

FlightBookingSystem::FlightBookingSystem() {
    flightList = new std::list<std::vector<Flight>>();
    g = 0;
}

FlightBookingSystem::~FlightBookingSystem() {
    delete flightList;
}

void FlightBookingSystem::bookSeat (string passengerName) {
    f.push_back({passengerName, true});
    g++;
    if (f.size == 5) {
        f.clear();
        flightList->pop_back();
        flightList->push_back(f);
    } else {
        flightList->pop_back();
        flightList->push_back(f);
    }
}
