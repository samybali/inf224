#include "Multimedia.h"
#include <iostream>


int main(int argc, const char* argv[])
{
    Multimedia* m = new Multimedia("Name", "/images/picture.jpg");

    m->display(std::cout);

    delete m;
    return 0;
}
