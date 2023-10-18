#include "stringtrimmer.hpp"

int main() {
    try {
        dwt::testTrimRight();
        std::cout << "All the tests have passed successfully" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "The test has failed with id: " << e.what() << std::endl;
    }
}