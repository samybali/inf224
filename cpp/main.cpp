#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Manager.h"
#include <iostream>


int main(int argc, const char* argv[])
{
    Manager m;

    try {
        std::shared_ptr<Group> g = m.createGroup("g");
        std::shared_ptr<Photo> pic = m.createPhoto("pic", "path");

        g->push_back(pic);
        g->push_back(m.createVideo("vid", "pathvid", 43));

        g->display(std::cout);
        pic->display(std::cout);

        m.removeMultimedia("pic");
        m.displayGroup("g", std::cout);

        m.removeMultimedia("pic");
    }
    catch (const MultimediaException& e) {
        std::cout << "Error: " << e.what();
    }

    return 0;
}
