#ifndef video_h
#define video_h

#include "Multimedia.h"
#include <string>

/**
 * @file Video.h
 * @brief Header file for the Video class.
 */

/**
 * @class Video
 * @brief Represents a video object with a duration.
 *
 * This class inherits from Multimedia and adds a length attribute (duration).
 * It overrides the display() and play() methods to handle specific video behaviors.
 *
 * Note: The constructor is protected to enforce the Factory design pattern.
 * Instances of Video should be created via the Manager class.
 */
class Video : public Multimedia
{
    /// Friend class declaration allows Manager to access protected constructors.
    friend class Manager;

    protected:
        int m_length; ///< The duration of the video in seconds.

        /**
         * @brief Protected constructor.
         *
         * Can only be called by the Manager class (factory) or derived classes (like Film).
         *
         * @param name The name of the video.
         * @param path The full path to the video file.
         * @param len The duration of the video.
         */
        Video(std::string name, std::string path, int len) : Multimedia(name, path), m_length(len) {}

    public:

        /**
         * @brief Gets the duration of the video.
         * @return The length as an integer.
         */
        int getLength() const { return m_length; }

        /**
         * @brief Sets the duration of the video.
         * @param len The new length value.
         */
        void setLength(int len) { m_length = len; }

        /**
         * @brief Displays the video's attributes.
         *
         * Calls the base Multimedia::display() first, then prints
         * the type ("Video") and the length.
         *
         * @param s The output stream.
         */
        virtual void display(std::ostream & s) const override
        {
            Multimedia::display(s);

            s << "Type: Video " << "Length: " << m_length << " ";
        }

        /**
         * @brief Plays the video using the default video player.
         *
         * Uses the system command "open" (standard on macOS) followed by the file path.
         * The command is executed in the background (&).
         */
        void play() const override
        {
            std::string arg = "open " + m_filePath + " &";

            system(arg.data());

        }
} ;

#endif