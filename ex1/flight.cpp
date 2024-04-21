#include "flight.h"

FlightBookingSystem::FlightBookingSystem() {
    flightCnt = 1;
}

void FlightBookingSystem::bookSeat(std::string passengerName) {
    if (flightCnt <= FLIGHT_CAP) {
        if (!flights.empty()) {
            for (int i = 0; i < SIZE; ++i) {
                if (flights.back().name[i].empty()) {
                    flights.back().name[i] = passengerName;
                    return;
                }
            }
            flightCnt++;
        }
        Flight f;
        f.name[0] = passengerName;
        flights.push_back(f);
    }
}

void FlightBookingSystem::movePassengers() {
    for (std::list<Flight>::iterator f = flights.begin(); f != flights.end(); ++f) {
        for (int i = 0; i < SIZE-1; ++i) {
            if (f->name[i].empty() && !f->name[i+1].empty()) {
                std::string tmp = f->name[i];
                f->name[i] = f->name[i+1];
                f->name[i+1] = tmp;
            }
        }
    }
}

void FlightBookingSystem::cancelBooking(int seatIndex) {
    std::list<Flight>::iterator f;
    if (flights.begin() == flights.end())
        std::cerr << "ERROR: Cannot cancel booking: flight list is empty\n";
    for (f = flights.begin(); f != flights.end(); ++f)
        for (int i = 0; i < SIZE; ++i) {
            if (seatIndex == i) {
                f->name[i].clear();
                movePassengers();
                return;
            }
        }
}

void FlightBookingSystem::displaySystem() {
    int cnt = 1;
    std::list<Flight>::iterator f;
    for (f = flights.begin(); f != flights.end(); ++f) {
        if (cnt > FLIGHT_CAP)
            std::cerr << "ERROR: All flights are full\n";
        else {
            std::cout << "#########################\n";
            std::cout << "Flight " << cnt << std::endl;
            std::cout << "#########################\n";
            for (int i = 0; i < SIZE; ++i)
                if (!f->name[i].empty())
                    std::cout << i+1 << ". " << f->name[i] << std::endl;
            std::cout << "#########################\n";
        }
        cnt++;
    }
}

std::string FlightBookingSystem::getPassenger(int seatIndex) {
    int cnt = 0;
    char buf[64];
    std::list<Flight>::iterator f;
    for (f = flights.begin(); f != flights.end(); ++f)
        for (int i = 0; i < SIZE; ++i) {
            if (seatIndex == cnt && !f->name[i].empty())
                return f->name[i];
            cnt++;
        }
    sprintf (buf, "No passenger at seat %d", seatIndex);
    return buf;
}
