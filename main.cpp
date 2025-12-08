#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include <iostream>


int main(int argc, const char* argv[])
{
    MultimediaPtr ptr1(new Photo("name", "path", 0, 0));

    Group g = Group("g1");

    g.push_back(ptr1);

    ptr1.reset();



    return 0;
}
