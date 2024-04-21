#ifndef FLIGHT_HPP_
#define FLIGHT_HPP_

#include <string>
#include <list>

#define SIZE 5

struct Flight {
    string name; //[SIZE];
    bool status; //[SIZE];
};

class FlightBookingSystem {
private:
    std::list<std::vector<Flight>> *flightList;
    std::vector<Flight> f;
    int g;
public:
    FlightBookingSystem();
    ~FlightBookingSystem();
    void bookSeat(string passengerName);
    void cancelBooking(int seatIndex);
    void displaySystem();
    string getPassenger(int seatIndex);
};

#endif // FLIGHT_HPP_
