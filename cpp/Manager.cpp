#include "Manager.h"

Manager::Manager() {}

Manager::~Manager() {}

std::shared_ptr<Photo> Manager::createPhoto(std::string name, std::string path, double lat, double lon)
{
    std::shared_ptr<Photo> photo(new Photo(name, path, lat, lon));

    objectsTab[name] = photo;
    
    return photo;
}

std::shared_ptr<Video> Manager::createVideo(std::string name, std::string path, int len)
{
    std::shared_ptr<Video> vid(new Video(name, path, len));

    objectsTab[name] = vid;
    
    return vid;
}

std::shared_ptr<Film> Manager::createFilm(std::string name, std::string path, int len, int chaptersNb, int* chapters)
{
    std::shared_ptr<Film> film(new Film(name, path, len, chaptersNb, chapters));

    objectsTab[name] = film;

    return film;
}

std::shared_ptr<Group> Manager::createGroup(std::string name)
{
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

void Manager::play(std::string name) const
{
    auto it = objectsTab.find(name);

    if (it != objectsTab.end())
    {
        it->second->play();
    }
    else
    {
        std::cout << name << " not found" << std::endl;
    }


}

void Manager::removeMultimedia(std::string name)
{
    auto it = objectsTab.find(name);

    if (it != objectsTab.end())
    {
        MultimediaPtr ptr = it->second;

        for (auto & group : groupsTab)
        {
            group.second->remove(ptr);
        }
    }

    objectsTab.erase(it);
}

void Manager::removeGroup(std::string name)
{
    groupsTab.erase(name);
}