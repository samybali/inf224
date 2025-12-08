#ifndef manager_h
#define manager_h


#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

#include <map>
#include <string>
#include <iostream>

class Manager
{
    private:
        std::map<std::string, MultimediaPtr> objectsTab;
        std::map<std::string, GroupPtr> groupsTab;

    public:
        Manager();

        virtual ~Manager();

        std::shared_ptr<Photo> createPhoto(std::string name, std::string path, double lat = 0.0, double lon = 0.0);
        std::shared_ptr<Video> createVideo(std::string name, std::string path, int len);
        std::shared_ptr<Film> createFilm(std::string name, std::string path, int len, int chaptersNb, int* chapters);
        std::shared_ptr<Group> createGroup(std::string name);

        void displayMultimedia(std::string name, std::ostream & s) const;
        void displayGroup(std::string name, std::ostream & s) const;

        void play(std::string name) const;



};

#endif