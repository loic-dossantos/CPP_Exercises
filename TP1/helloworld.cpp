#include <iostream>

int main(int argc, char const* argv[]) {
    // int var;
    // std::cout << "Hello world!" << std::endl;
    std::string var;

    std::cout << "What's your name?" << std::endl;
    std::cin >> var;
    std::cout << "Hello " << var << "!" << std::endl;

    return 0;
}
