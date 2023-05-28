#include "test.hpp"
#include "my_string.hpp"

#include <string>
#include <iostream>

void test_operators()
{
    my_string st = "Hello";

    std::cout << st + " world" << std::endl;

    std::cout  << "world " + st << std::endl;

    my_string st2 = "my_string ";

    std::cout << std::string("sting ") + st2 << std::endl;

    std::cout << st2 + std::string("sting") << std::endl;

}