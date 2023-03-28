#include <iostream>

#include "Kitchen.hpp"

int main(int argc, char** argv)
{
    // You can implement whatever you want here!
    if(argv[argc - 1]) {
    }
    auto kitchen = Kitchen {};

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    std::cout << piece_unit.name << std::endl;

    const auto& ml_unit = kitchen.register_unit(Unit { "ml" });
    std::cout << ml_unit.name << std::endl;

    const auto& g_unit = kitchen.register_unit(Unit { "g" });
    std::cout << g_unit.name << std::endl;
    return 0;
}
