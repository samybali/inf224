#ifndef manager_h
#define manager_h

#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

/**
 * @file Manager.h
 * @brief Header file for the Manager class.
 */

/**
 * @class MultimediaException
 * @brief Custom exception class for errors occurring within the Manager.
 *
 * Inherits from std::runtime_error. Used to report logical errors
 * (e.g., duplicate names, objects not found) or invalid arguments
 * during the execution of Manager methods.
 */
class MultimediaException : public std::runtime_error {
    public:
        /**
         * @brief Constructor.
         * @param msg The error message describing the exception.
         */
        MultimediaException(const std::string& msg) : std::runtime_error(msg) {}
};

/**
 * @class Manager
 * @brief Central class that manages all Multimedia objects and Groups.
 *
 * The Manager acts as a factory to create objects (Photo, Video, Film, Group)
 * and as a database to store them using std::map containers.
 * It ensures the consistency of the data (e.g., preventing duplicate names)
 * and handles interactions such as displaying, playing, or removing items.
 */
class Manager
{
    private:
        /// Dictionary of Multimedia objects, indexed by their name.
        std::map<std::string, MultimediaPtr> objectsTab;

        /// Dictionary of Groups, indexed by their name.
        std::map<std::string, GroupPtr> groupsTab;

    public:
        /**
         * @brief Default constructor.
         * Initializes the internal maps.
         */
        Manager();

        /**
         * @brief Destructor.
         * Thanks to smart pointers (shared_ptr), the memory of all managed objects
         * is automatically released when the Manager is destroyed.
         */
        virtual ~Manager();

        /**
         * @brief Creates a new Photo and adds it to the manager.
         *
         * @param name The unique name of the photo.
         * @param path The file path of the photo.
         * @param lat The latitude (default 0.0).
         * @param lon The longitude (default 0.0).
         * @return A shared pointer to the created Photo.
         * @throw MultimediaException If the name is invalid or already exists.
         */
        std::shared_ptr<Photo> createPhoto(std::string name, std::string path, double lat = 0.0, double lon = 0.0);

        /**
         * @brief Creates a new Video and adds it to the manager.
         *
         * @param name The unique name of the video.
         * @param path The file path of the video.
         * @param len The duration of the video.
         * @return A shared pointer to the created Video.
         * @throw MultimediaException If the name is invalid or already exists.
         */
        std::shared_ptr<Video> createVideo(std::string name, std::string path, int len);

        /**
         * @brief Creates a new Film and adds it to the manager.
         *
         * @param name The unique name of the film.
         * @param path The file path of the film.
         * @param len The total duration.
         * @param chaptersNb Number of chapters.
         * @param chapters Array of chapter durations.
         * @return A shared pointer to the created Film.
         * @throw MultimediaException If the name is invalid or already exists.
         */
        std::shared_ptr<Film> createFilm(std::string name, std::string path, int len, int chaptersNb, int* chapters);

        /**
         * @brief Creates a new Group and adds it to the manager.
         *
         * @param name The unique name of the group.
         * @return A shared pointer to the created Group.
         * @throw MultimediaException If the name is invalid or already exists.
         */
        std::shared_ptr<Group> createGroup(std::string name);

        /**
         * @brief Searches for a Multimedia object and writes its details to the stream.
         *
         * @param name The name of the object to find.
         * @param s The output stream.
         */
        void displayMultimedia(std::string name, std::ostream & s) const;

        /**
         * @brief Searches for a Group and writes its details to the stream.
         *
         * @param name The name of the group to find.
         * @param s The output stream.
         */
        void displayGroup(std::string name, std::ostream & s) const;

        /**
         * @brief Generic search method.
         *
         * Searches first in the Multimedia objects map, and if not found,
         * searches in the Groups map. Writes the result to the output stream.
         *
         * @param name The name of the element (object or group) to find.
         * @param s The output stream.
         */
        void findandDisplay(std::string name, std::ostream & s) const;

        /**
         * @brief Plays a multimedia object on the server.
         *
         * @param name The name of the object to play.
         * @return true if the object was found and played, false otherwise.
         */
        bool play(std::string name) const;

        /**
         * @brief Removes a Multimedia object from the manager.
         *
         * This method also removes the object from any Groups that contain it
         * to ensure data consistency.
         *
         * @param name The name of the object to remove.
         * @throw MultimediaException If the object is not found.
         */
        void removeMultimedia(std::string name);

        /**
         * @brief Removes a Group from the manager.
         *
         * This does NOT delete the objects contained within the group,
         * only the group container itself.
         *
         * @param name The name of the group to remove.
         * @throw MultimediaException If the group is not found.
         */
        void removeGroup(std::string name);

        /**
         * @brief Generic removal method.
         *
         * Attempts to find and remove an element by name, checking first
         * for Multimedia objects, then for Groups.
         *
         * @param name The name of the element to remove.
         * @param s The output stream to log the result.
         */
        void findandRemove(std::string name, std::ostream & s);
};

#endif