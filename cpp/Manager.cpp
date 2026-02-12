#include "Manager.h"

Manager::Manager() {}

Manager::~Manager() {}

std::shared_ptr<Photo> Manager::createPhoto(std::string name, std::string path, double lat, double lon)
{
    if (name.find_first_of("\n\r|") != std::string::npos || name.empty()) {
        throw MultimediaException("Cannot use the name: " + name);
    }

    if (objectsTab.find(name) != objectsTab.end()) {
        throw MultimediaException(name + " already exists");
    }

    std::shared_ptr<Photo> photo(new Photo(name, path, lat, lon));
    objectsTab[name] = photo;
    return photo;
}

std::shared_ptr<Video> Manager::createVideo(std::string name, std::string path, int len)
{
    if (name.find_first_of("\n\r|") != std::string::npos || name.empty()) {
        throw MultimediaException("Cannot use the name: " + name);
    }

    if (objectsTab.find(name) != objectsTab.end()) {
        throw MultimediaException(name + " alreadys exists");
    }

    std::shared_ptr<Video> vid(new Video(name, path, len));
    objectsTab[name] = vid;
    return vid;
}

std::shared_ptr<Film> Manager::createFilm(std::string name, std::string path, int len, int chaptersNb, int* chapters)
{
    if (name.find_first_of("\n\r|") != std::string::npos || name.empty()) {
        throw MultimediaException("Cannot use the name: " + name);
    }

    if (objectsTab.find(name) != objectsTab.end()) {
        throw MultimediaException(name + " alreadys exists");
    }

    std::shared_ptr<Film> film(new Film(name, path, len, chaptersNb, chapters));
    objectsTab[name] = film;
    return film;
}

std::shared_ptr<Group> Manager::createGroup(std::string name)
{
    if (name.find_first_of("\n\r|") != std::string::npos || name.empty()) {
        throw MultimediaException("Cannot use the name: " + name);
    }

    if (groupsTab.find(name) != groupsTab.end()) {
        throw MultimediaException(name + " alreadys exists");
    }

    std::shared_ptr<Group> gr(new Group(name));
    groupsTab[name] = gr;
    return gr;
}

void Manager::displayMultimedia(std::string name, std::ostream & s) const
{
    auto it = objectsTab.find(name);

    if (it != objectsTab.end())
    {
        it->second->display(s);
    }
    else
    {
        s << name << " not found";
    }
}

void Manager::displayGroup(std::string name, std::ostream & s) const
{
    auto it = groupsTab.find(name);

    if (it != groupsTab.end())
    {
        it->second->display(s);
    }
    else
    {
        s << name << " not found";
    }
}

void Manager::findandDisplay(std::string name, std::ostream & s) const {
    auto itM = objectsTab.find(name);
    if (itM != objectsTab.end()) {
        this->displayMultimedia(name, s);
        return;
    }

    auto itG = groupsTab.find(name);
    if (itG != groupsTab.end()) {
        this->displayGroup(name, s);
        return;
    }

    s << name << " not found";
}

bool Manager::play(std::string name) const
{
    auto it = objectsTab.find(name);

    if (it != objectsTab.end())
    {
        it->second->play();
        return true;
    }
    else
    {
        std::cout << name << " not found" << std::endl;
        return false;
    }


}

void Manager::removeMultimedia(std::string name)
{
   auto it = objectsTab.find(name);

    if (it == objectsTab.end()) {
        throw MultimediaException(name + " cannot be found");
    }

    MultimediaPtr ptr = it->second;
    for (auto & group : groupsTab) {
        group.second->remove(ptr);
    }
    objectsTab.erase(it);
}

void Manager::removeGroup(std::string name)
{
    auto it = groupsTab.find(name);
    
    if (it == groupsTab.end()) {
        throw MultimediaException(name + " cannot be found");
    }

    groupsTab.erase(it);
}

void Manager::findandRemove(std::string name, std::ostream & s) {
    auto itM = objectsTab.find(name);
    if (itM != objectsTab.end()) {
        this->removeMultimedia(name);
        return;
    }

    auto itG = groupsTab.find(name);
    if (itG != groupsTab.end()) {
        this->removeGroup(name);
        return;
    }

    s << name << " not found";
}