#ifndef FLIGHT_HPP_
#define FLIGHT_HPP_

#include <iostream>
#include <string>

#define SIZE 5

struct Flight {
    std::string info[SIZE];
    Flight *next;
};

class FlightBookingSystem {
private:
    Flight *first;
public:
    FlightBookingSystem();
    ~FlightBookingSystem();
    void bookSeat(std::string passengerName);
    void cancelBooking(int seatIndex);
    void displaySystem();
    std::string getPassenger(int seatIndex);
};

#endif // FLIGHT_HPP_
