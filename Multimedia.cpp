#include "Multimedia.h"


Multimedia::Multimedia()
{
    this->m_name = "";
    this->m_filePath = "";
}

Multimedia::Multimedia(std::string name, std::string path)
{

    this->m_name = name;
    this->m_filePath = path;
}

Multimedia::~Multimedia() {}

std::string Multimedia::getName() const
{
    return m_name;
}

std::string Multimedia::getfilePath() const
{
    return m_filePath;
}

void Multimedia::setName(std::string name) 
{
    m_name = name;
}

void Multimedia::setfilePath(std::string path)
{
    m_filePath = path;
}

void Multimedia::display(std::ostream & s) const
{
    s << "Name: " << m_name << std::endl;
    s << "Path to file: " << m_filePath << std::endl;
}
