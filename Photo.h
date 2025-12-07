#ifndef photo_h
#define photo_h

#include "Multimedia.h"
#include <string>
#include <cstdlib>

class Photo : public Multimedia {
    private:
        double m_latitude, m_longitude;

    public:
        Photo(std::string name, std::string path, double lat, double lon) : Multimedia(name, path), m_latitude(lat), m_longitude(lon) {}

        double getLatitude() const { return m_latitude; }

        double getLongitude() const { return m_longitude; }

        void setLatitude(double lat) {m_latitude = lat; }
        
        void setLongitude(double lon) {m_longitude = lon; }

        void display(std::ostream & s) const override {

            Multimedia::display(s);

            s << "Type: Photo" << std::endl;
            s << "Latitude: " << m_latitude << "Longitude: " << m_longitude << std::endl;
        }

        void play() const override {

            std::string arg = "start " + m_filePath;

            system(arg.data());

        }
};

#endif