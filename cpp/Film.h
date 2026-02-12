#ifndef film_h
#define film_h

#include "Video.h"
#include <string>

/**
 * @file Film.h
 * @brief Header file for the Film class.
 */

/**
 * @class Film
 * @brief Represents a movie with chapters.
 *
 * The Film class inherits from Video and adds chapter management
 * (duration of each chapter) using a dynamic array of integers.
 * It implements the "Rule of Three" (Copy Constructor, Assignment Operator, Destructor)
 * to ensure proper memory management for the dynamically allocated array.
 */
class Film : public Video
{
    private:
        int m_chaptersNb; ///< Number of chapters
        int* m_chapters;  ///< Dynamic array containing the duration of each chapter

    public:
        /**
         * @brief Constructor for the Film class.
         *
         * @param name The name of the film.
         * @param path The path to the film file.
         * @param len The total duration of the film.
         * @param chaptersNb Number of chapters (default is 0).
         * @param chapters Array of chapter durations (default is nullptr).
         */
        Film(std::string name, std::string path, int len, int chaptersNb = 0, int* chapters = nullptr) : Video(name, path, len)
        {

            m_chapters = nullptr;
            m_chaptersNb = 0;

            if (chaptersNb > 0 && chapters != nullptr) {
                setChapters(chaptersNb, chapters);
            }

        }

        /**
         * @brief Copy constructor.
         *
         * Performs a deep copy of the chapters array to avoid
         * pointer sharing issues between objects.
         *
         * @param other The Film object to copy from.
         */
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

        /**
         * @brief Assignment operator.
         *
         * Performs a deep copy of the chapters array, handling memory reallocation.
         * Checks for self-assignment.
         *
         * @param other The Film object to assign from.
         * @return A reference to the current modified object.
         */
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

        /**
         * @brief Destructor.
         *
         * Frees the memory allocated for the chapters array.
         */
        ~Film()
        {
            delete[] m_chapters;
        }
        
        /**
         * @brief Modifies the chapters of the film.
         *
         * This method handles the reallocation of the internal array.
         *
         * @param chaptersNb The new number of chapters.
         * @param chapters The new array of durations (will be copied).
         */
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

        /**
         * @brief Gets the number of chapters.
         * @return The number of chapters as an integer.
         */
        int getChaptersNb() const { return m_chaptersNb; }

        /**
         * @brief Gets the array of chapter durations.
         *
         * @return A const pointer to the integer array (read-only).
         * Warning: The pointer should not be deleted by the caller.
         */
        const int* getChapters() const { return m_chapters; }

        /**
         * @brief Displays the film's information and its chapters.
         *
         * Prints the base video info followed by the list of chapter durations
         * to the given output stream.
         *
         * @param s The output stream (std::ostream).
         */
        void display(std::ostream & s) const override
        {
            Video::display(s);

            if (m_chaptersNb > 0 && m_chapters != nullptr) 
            {
            for (int i = 0; i < m_chaptersNb; ++i)
            {
                s << "Chapter " << i <<  ": " << m_chapters[i];
            }
            } 
            else
            {
            s << "No chapters";
        }
        }
};

#endif