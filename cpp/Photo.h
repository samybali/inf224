#ifndef photo_h
#define photo_h

#include "Multimedia.h"
#include <string>
#include <cstdlib>

/**
 * @file Photo.h
 * @brief Header file for the Photo class.
 */

/**
 * @class Photo
 * @brief Represents a photo object with geolocation coordinates.
 *
 * This class inherits from Multimedia and adds latitude and longitude attributes.
 * It overrides the display() and play() methods to handle specific photo behaviors.
 *
 * Note: The constructor is protected to enforce the Factory design pattern.
 * Instances of Photo should be created via the Manager class.
 */
class Photo : public Multimedia
{
    /// Friend class declaration allows Manager to access protected constructors.
    friend class Manager;

    protected:
        double m_latitude;  ///< Latitude coordinate of the photo location.
        double m_longitude; ///< Longitude coordinate of the photo location.

        /**
         * @brief Protected constructor.
         *
         * Can only be called by the Manager class (factory).
         *
         * @param name The name of the photo.
         * @param path The full path to the image file.
         * @param lat The latitude (default 0.0).
         * @param lon The longitude (default 0.0).
         */
        Photo(std::string name, std::string path, double lat = 0.0, double lon = 0.0) : Multimedia(name, path), m_latitude(lat), m_longitude(lon) {}

    public:
        /**
         * @brief Gets the latitude.
         * @return The latitude as a double.
         */
        double getLatitude() const { return m_latitude; }

        /**
         * @brief Gets the longitude.
         * @return The longitude as a double.
         */
        double getLongitude() const { return m_longitude; }

        /**
         * @brief Sets the latitude.
         * @param lat The new latitude value.
         */
        void setLatitude(double lat) {m_latitude = lat; }
        
        /**
         * @brief Sets the longitude.
         * @param lon The new longitude value.
         */
        void setLongitude(double lon) {m_longitude = lon; }

        /**
         * @brief Displays the photo's attributes.
         *
         * Calls the base Multimedia::display() first, then prints
         * the type ("Photo") and the geolocation coordinates.
         *
         * @param s The output stream.
         */
        void display(std::ostream & s) const override
        {
            Multimedia::display(s);

            s << "Type: Photo " << "Latitude: " << m_latitude << " Longitude: " << m_longitude;
        }

        /**
         * @brief Opens the photo using the default image viewer.
         *
         * Uses the system command "open" (standard on macOS) followed by the file path.
         * The command is executed in the background (&).
         */
        void play() const override 
        {
            std::string arg = "open " + m_filePath + " &";

            system(arg.data());
        }
};

#endif