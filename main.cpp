#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include <iostream>


int main() {
    
    int nb = 3;
    int* durees = new int[nb];
    durees[0] = 10;
    durees[1] = 20;
    durees[2] = 30;

    Film* film = new Film("Titanic", "titanic.mp4", 195);
    
    film->setChapters(nb, durees);

    film->display(std::cout);

    durees[0] = 999;
    
    film->display(std::cout);

    delete[] durees;
    
    film->display(std::cout);

  
    delete film;

    return 0;
}
