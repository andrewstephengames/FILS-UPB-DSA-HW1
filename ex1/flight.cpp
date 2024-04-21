#include "flight.hpp"

FlightBookingSystem::FlightBookingSystem() {
    first = new Flight;
}

FlightBookingSystem::~FlightBookingSystem() {
    Flight *aux = first;
    while (aux != NULL) {
        Flight *next  = aux->next;
        delete aux;
        aux = next;
    }
}

void FlightBookingSystem::bookSeat(std::string passengerName) {
    Flight *aux = first;
    while (aux->next != NULL)
        if (aux->next->info[SIZE-1] != "")
            aux = aux->next;
        else break;
    if (aux->info[SIZE-1] == "")
        for (int i = 0; i < SIZE; ++i)
            if (aux->info[i] == "") {
                aux->info[i] = passengerName;
                return;
            }
    Flight* flight2 = new Flight;
    flight2->info[0] = passengerName;
    aux->next = flight2;
}

void FlightBookingSystem::cancelBooking(int seatIndex) {
    Flight *aux = first;
    while (aux != NULL) {
        if (seatIndex < SIZE && aux->info[seatIndex] != "") {
            aux->info[seatIndex] = "";
            for (int i = seatIndex+1; i < SIZE; ++i)
                if (aux->info[i] != "") {
                    aux->info[i-1] = aux->info[i];
                    aux->info[i] = "";
                }
            return;
        }
        aux = aux->next;
    }
    std::cout << "No bookings found for seat " << seatIndex << "!\n";
}

void FlightBookingSystem::displaySystem() {
    Flight *aux = first;
    int index = 1;
    while (aux != NULL) {
        std::cout << "###########################\n";
        std::cout << "Flight " << index << std::endl;
        for (int i = 0; i < SIZE; ++i)
            if (aux->info[i] != "")
                std::cout << "Seat " << i << ": " << aux->info[i] << std::endl;
        aux = aux->next;
        index++;
        std::cout << "###########################\n";
    }
}

std::string FlightBookingSystem::getPassenger(int seatIndex) {
    Flight *aux = first;
    while (aux != NULL) {
        if (seatIndex < SIZE && aux->info[seatIndex] != "")
            return aux->info[seatIndex];
        aux = aux->next;
    }
    char buf[20];
    sprintf (buf, "Seat %d is empty", seatIndex);
    std::string result (buf);
    return result;
}
