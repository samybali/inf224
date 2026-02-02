#ifndef multimedia_h
#define multimedia_h

#include <string>
#include <iostream>
#include <memory>

class Multimedia
{
    protected:
       std::string m_name, m_filePath;
       
    public:
        Multimedia();

        Multimedia(std::string name, std::string path);

        virtual ~Multimedia();

        std::string getName() const;

        std::string getfilePath() const;

        void setName(std::string name);

        void setfilePath(std::string path);

        virtual void display(std::ostream & s) const;

        virtual void play() const = 0;


};

using MultimediaPtr = std::shared_ptr<Multimedia>;

#endif