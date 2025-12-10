#ifndef group_h
#define group_h

#include <list>
#include <memory>
#include <string>
#include <iostream>
#include "Multimedia.h"

class Group : public std::list<MultimediaPtr>
{
    private:
        std::string m_name;

    public:
        Group(std::string name) : m_name(name) {}

        std::string getName() const { return m_name; }

        void display(std::ostream & s) const
        {
            s << "Group: " << m_name << " ";

            for (auto it : *this)
            {
                it->display(s);
            }
        }
};

using GroupPtr = std::shared_ptr<Group>;

#endif
