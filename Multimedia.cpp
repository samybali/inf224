#include "Multimedia.h"


Multimedia::Multimedia() {
    this->name = "";
    this->filePath = "";
}

Multimedia::Multimedia(std::string name, std::string filePath) {

    this->name = name;
    this->filePath = filePath;
}

Multimedia::~Multimedia() {
    
}

std::string Multimedia::getName() const {
    return name;
}

std::string Multimedia::getfilePath() const {
    return filePath;
}

void Multimedia::setName(std::string n) {
    name = n;
}

void Multimedia::setfilePath(std::string nf) {
    filePath = nf;
}

void Multimedia::display(std::ostream & s) const {
    s << name << std::endl;
    s << filePath << std::endl;
}
