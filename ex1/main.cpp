#include "flight.hpp"

int main () {
    FlightBookingSystem *fbs = new FlightBookingSystem();
    fbs->bookSeat ("Sergiu");
    fbs->bookSeat ("Ana");
    fbs->bookSeat ("Ted");
    fbs->bookSeat ("Andrew");
    fbs->bookSeat ("Jane");
    fbs->bookSeat ("Jonathan");
    fbs->bookSeat ("Jonathan");
    fbs->bookSeat ("Jonathan");
    fbs->bookSeat ("Jonathan");
    fbs->bookSeat ("Jonathan");
    fbs->displaySystem();
    //std::cout << "\nAfter booking 3 was cancelled\n\n";
    delete fbs;
    return 0;
}
