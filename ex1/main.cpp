#include "flight.hpp"

int main() {
    FlightBookingSystem *fbs = new FlightBookingSystem();
    fbs->bookSeat("Sergiu");
    fbs->bookSeat("Ana");
    fbs->displaySystem();
    std::cout << "_________________________\n";
    std::cout << "Removing passenger from seat 0: " << fbs->getPassenger(0) << std::endl;
    std::cout << "-------------------------\n";
    fbs->cancelBooking(0);
    fbs->displaySystem();
    delete fbs;
    return 0;
}
