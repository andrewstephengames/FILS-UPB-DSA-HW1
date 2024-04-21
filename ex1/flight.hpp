#ifndef FLIGHT_HPP_
#define FLIGHT_HPP_

#include <iostream>
#include <string>
#include <list>

#define SIZE 5
#define FLIGHT_CAP 5

struct Flight {
    std::string name[SIZE];
};

class FlightBookingSystem {
private:
    std::list<Flight> flights;
    int flightCnt;
public:
    FlightBookingSystem();
    void bookSeat(std::string passengerName);
    void movePassengers();
    void cancelBooking(int seatIndex);
    void displaySystem();
    std::string getPassenger(int seatIndex);
};

#endif // FLIGHT_HPP_
