#ifndef video_h
#define video_h

#include "Multimedia.h"
#include <string>

class Video : public Multimedia
{
    friend class Manager;

    protected:
        int m_length;

        Video(std::string name, std::string path, int len) : Multimedia(name, path), m_length(len) {}

    public:

        int getLength() const { return m_length; }

        void setLength(int len) { m_length = len; }

        virtual void display(std::ostream & s) const override
        {
            Multimedia::display(s);

            s << "Type: Video" << std::endl;
            s << "Length: " << m_length << std::endl;
        }

        void play() const override
        {
            std::string arg = "start " + m_filePath;

            system(arg.data());

        }
} ;

#endif