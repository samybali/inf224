//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Manager.h"

const int PORT = 3331;

/*
#ifndef VERSION_1
int main(int argc, char* argv[])
{
  // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client
    response = "RECEIVED: " + request;

    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}
#endif
*/

int main(int argc, char* argv[])
{
  Manager m;

  std::shared_ptr<Group> g = m.createGroup("g");
  std::shared_ptr<Photo> pic = m.createPhoto("pic", "Path_for_pic");
  std::shared_ptr<Video> vid = m.createVideo("vid", "Path_for_vid", 43);
  g->push_back(pic);

  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;
    
    // the response that the server sends back to the client
    std::stringstream os;
    std::stringstream order(request);
    std::string com, name;
    order >> com >> name;

    try {
    if (com == "display") {
        m.findandDisplay(name, os); 
      } 
      else if (com == "play") {
          if (m.play(name)) {
            os << "Playing " << name;
          }
          else {
            os << "Could not play " << name;
          }
      }
      else if (com == "remove") {
        os << "Removing " << name << "... ";
        m.findandRemove(name, os);
      }
      else if (com == "creategroup") {
        os << "Creating group " << name << "... ";
        m.createGroup(name);
      }
      else {
          os << "Unknown command. Use display, play or remove.";
      }
    }
    catch (const MultimediaException& e) {
      os << "Error: " << e.what();
    }

    response = os.str();

    // return false would close the connecytion with the client
    return true;
  });

  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;

}
