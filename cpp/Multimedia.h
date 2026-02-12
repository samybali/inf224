#ifndef multimedia_h
#define multimedia_h

#include <string>
#include <iostream>
#include <memory>

/**
 * @file Multimedia.h
 * @brief Header file for the Multimedia class.
 */

/**
 * @class Multimedia
 * @brief Abstract base class representing a generic multimedia object.
 *
 * This class holds the common attributes (name, file path) for all media types.
 * It is an abstract class because the play() method is pure virtual.
 * It provides the interface that specific classes like Photo or Video must implement.
 */
class Multimedia
{
    protected:
       std::string m_name;     ///< The name of the multimedia object.
       std::string m_filePath; ///< The full path to the media file.
       
    public:
        /**
         * @brief Default constructor.
         * Initializes name and path to empty strings.
         */
        Multimedia();

        /**
         * @brief Parameterized constructor.
         * @param name The name of the object.
         * @param path The full path to the file.
         */
        Multimedia(std::string name, std::string path);

        /**
         * @brief Virtual destructor.
         *
         * A virtual destructor is essential for a base class to ensure that
         * the destructor of the derived class is called when an object is
         * deleted through a pointer to the base class.
         */
        virtual ~Multimedia();

        /**
         * @brief Gets the name of the object.
         * @return The name as a string.
         */
        std::string getName() const;

        /**
         * @brief Gets the file path.
         * @return The file path as a string.
         */
        std::string getfilePath() const;

        /**
         * @brief Sets a new name for the object.
         * @param name The new name to set.
         */
        void setName(std::string name);

        /**
         * @brief Sets a new file path for the object.
         * @param path The new path to set.
         */
        void setfilePath(std::string path);

        /**
         * @brief Displays the content of the object.
         *
         * This method writes the object's attributes to the given output stream.
         * It is virtual so it can be overridden by derived classes to display
         * their specific attributes.
         *
         * @param s The output stream (std::ostream) to write to.
         */
        virtual void display(std::ostream & s) const;

        /**
         * @brief Plays the multimedia object.
         *
         * This is a pure virtual method (= 0). It implies that the Multimedia
         * class cannot be instantiated directly. Derived classes (Photo, Video)
         * must implement this method to define the specific playback behavior.
         */
        virtual void play() const = 0;
};

/**
 * @typedef MultimediaPtr
 * @brief Type alias for a shared pointer to a Multimedia object.
 *
 * Using shared_ptr allows for automatic memory management and is used
 * in collections like std::vector or std::list.
 */
using MultimediaPtr = std::shared_ptr<Multimedia>;

#endif