/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: Header file for the Library class
*/

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "LibraryMember.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class Library {
    public:
        Library();
        Library(string name);
        Library(string name, map<Book, int> books, vector<LibraryMember> users);

        void addMember(LibraryMember m);
        LibraryMember getMember(int id) const;
        vector<LibraryMember> getAllMembers() const;

        void addBook(const Book& b, int quantity);
        Book checkoutBook(int id);
        map<Book, int> getTotalInventory() const;
        
        void setName(string name);
        string getName() const;
    private:
        vector<LibraryMember> members;
        map<Book, int> inventory;\
        string libraryName; 
};
#endif