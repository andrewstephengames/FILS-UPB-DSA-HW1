#include <fstream>

std::ifstream in ("journey_input.txt");
std::ofstream out ("journey_output.txt");

int main (void) {
    std::string oasis;
    in >> oasis;
    for (int i = 0; i < oasis.length(); ++i) {
        if (oasis.at(i) >= '0' && oasis.at(i) <= '9')
            out << oasis.at(i) << " ";
    }
    return 0;
}
