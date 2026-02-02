#ifndef photo_h
#define photo_h

#include "Multimedia.h"
#include <string>
#include <cstdlib>

class Photo : public Multimedia
{
    friend class Manager;

    protected:
        double m_latitude, m_longitude;

        Photo(std::string name, std::string path, double lat = 0.0, double lon = 0.0) : Multimedia(name, path), m_latitude(lat), m_longitude(lon) {}

    public:
        double getLatitude() const { return m_latitude; }

        double getLongitude() const { return m_longitude; }

        void setLatitude(double lat) {m_latitude = lat; }
        
        void setLongitude(double lon) {m_longitude = lon; }

        void display(std::ostream & s) const override
        {
            Multimedia::display(s);

            s << "Type: Photo " << "Latitude: " << m_latitude << " Longitude: " << m_longitude;
        }

        void play() const override 
        {
            std::string arg = "start " + m_filePath;

            system(arg.data());
        }
};

#endif