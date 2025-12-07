#include <string>
#include <iostream>

class Multimedia {
    private:
       std::string name, filePath;
       
    public:
        Multimedia();
        Multimedia(std::string name, std::string filePath);

        virtual ~Multimedia();

        std::string getName() const;
        std::string getfilePath() const;

        void setName(std::string name);
        void setfilePath(std::string filePath);

        void display(std::ostream & s) const;


};