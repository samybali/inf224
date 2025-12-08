#ifndef film_h
#define film_h

#include "Video.h"
#include <string>


class Film : public Video
{
    private:
        int m_chaptersNb;
        int* m_chapters;

    public:
        Film(std::string name, std::string path, int len, int chaptersNb = 0, int* chapters = nullptr) : Video(name, path, len)
        {

            m_chapters = nullptr;
            m_chaptersNb = 0;

            if (chaptersNb > 0 && chapters != nullptr) {
                setChapters(chaptersNb, chapters);
            }

        }

        Film(const Film& other) : Video(other)
        { 
            m_chaptersNb = other.m_chaptersNb;

            if (other.m_chapters != nullptr)
            {
                m_chapters = new int[m_chaptersNb];
                for (int i = 0; i < m_chaptersNb; ++i)
                {
                    m_chapters[i] = other.m_chapters[i];
                }
            }
            else
            {
            m_chapters = nullptr;
            }
        }

        Film& operator=(const Film& other)
        {
            if (this == &other) return *this;

            Video::operator=(other);

            delete[] m_chapters;

            m_chaptersNb = other.m_chaptersNb;

            if (other.m_chapters != nullptr)
            {
                m_chapters = new int[m_chaptersNb];
                for (int i = 0; i < m_chaptersNb; ++i)
                {
                    m_chapters[i] = other.m_chapters[i];
                }
            }
            else
            {
                m_chapters = nullptr;
            }
        return *this;
        }
        ~Film()
        {
            delete[] m_chapters;
        }
        
        void setChapters(int chaptersNb, int* chapters)
        {
            if (m_chaptersNb > 0 && m_chapters != nullptr)
            {
                delete[] m_chapters;
            }

            m_chaptersNb = chaptersNb;

            if (m_chaptersNb > 0 && chapters != nullptr)
            {
                m_chapters = new int[m_chaptersNb];
            
            for (int i = 0; i < m_chaptersNb; ++i) {
                m_chapters[i] = chapters[i];
            }
            }
            else
            {
                m_chapters = nullptr;
            }
        }

        int getChaptersNb() const { return m_chaptersNb; }

        const int* getChapters() const { return m_chapters; }

        void display(std::ostream & s) const override
        {
            Video::display(s);

            if (m_chaptersNb > 0 && m_chapters != nullptr) 
            {
            for (int i = 0; i < m_chaptersNb; ++i)
            {
                s << "Chapter " << i <<  ": " << m_chapters[i] << std::endl;
            }
            } 
            else
            {
            s << "No chapters" << std::endl;
        }
        }
};

#endif