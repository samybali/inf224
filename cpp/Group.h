#ifndef group_h
#define group_h

#include <list>
#include <memory>
#include <string>
#include <iostream>
#include "Multimedia.h"

/**
 * @file Group.h
 * @brief Header file for the Group class.
 */

/**
 * @class Group
 * @brief Represents a named group of Multimedia objects.
 *
 * This class inherits from std::list<MultimediaPtr>, which means it acts
 * as a standard container (list) of shared pointers to Multimedia objects.
 * You can use standard list methods (push_back, size, begin, end, etc.) directly.
 * The memory management of the objects contained in the list is handled automatically
 * thanks to smart pointers.
 */
class Group : public std::list<MultimediaPtr>
{
    private:
        std::string m_name; ///< The name of the group.

    public:
        /**
         * @brief Constructor.
         * @param name The name of the group.
         */
        Group(std::string name) : m_name(name) {}

        /**
         * @brief Gets the name of the group.
         * @return The name of the group as a string.
         */
        std::string getName() const { return m_name; }

        /**
         * @brief Displays the attributes of the group and all its members.
         *
         * It iterates through the list and calls the display method of each
         * Multimedia object.
         * The output is formatted with a pipe separator '|' to ensure compatibility
         * with the TCP server protocol (sending the whole group as a single line).
         *
         * @param s The output stream (std::ostream) to write to.
         */
        void display(std::ostream & s) const
        {
            s << "Group: " << m_name;

            for (auto it : *this)
            {
                s << " | ";
                it->display(s);
            }
        }
};

/**
 * @typedef GroupPtr
 * @brief Type alias for a shared pointer to a Group.
 */
using GroupPtr = std::shared_ptr<Group>;

#endif