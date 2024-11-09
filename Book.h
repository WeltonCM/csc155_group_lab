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

        void setIsbn();
        int getIsbn() const;

        void print();

        bool operator==(const Book& other) const {
            return title == other.title;
        }

        bool operator<(const Book& other) const {
            return isbn < other.isbn;
        }

    private: 
        string title;
        string author;
        int isbn;
};

#endif