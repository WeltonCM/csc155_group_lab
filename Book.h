/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: Header file for the Book class
*/

#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
    public: 
        Book();
        Book(string title, string author);

        void setTitle(string title);
        string getTitle() const;

        void setAuthor(string author);
        string getAuthor() const;

        void setId();
        int getId() const;

        void print();

        bool operator==(const Book& other) const {
            return title == other.title;
        }

        bool operator<(const Book& other) const {
            return id < other.id;
        }

    private: 
        string title;
        string author;
        int id;
};

#endif