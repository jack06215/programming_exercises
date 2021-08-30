#include <iostream>
#include "../random.hpp"
using Random = effolkronium::random_static;


int main(void) {
    auto random_number = Random::get(1, 9);
    std::cout << random_number << std::endl;
    return 0;
}