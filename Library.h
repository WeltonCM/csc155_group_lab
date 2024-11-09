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

struct FindByIsbn {
    int searchIsbn;
    FindByIsbn(int isbn) : searchIsbn(isbn) {}
    bool operator()(const pair<Book, int>& item) {
        return item.first.getIsbn() == searchIsbn;
    }
};

struct FindMemberById {
    int searchId;
    FindMemberById(int id) : searchId(id) {}
    bool operator()(const LibraryMember& member){
        return member.getId() == searchId;
    }
};


class Library {
    public:
        Library();
        Library(string name);
        Library(string name, map<Book, int> books, vector<LibraryMember> users);

        void addMember(LibraryMember m);

        void addBook(Book b, int quantity);
        bool checkoutBook(int isbn, int memberId);
        bool returnBooks(vector<Book> books, int memberId);
        map<Book, int> getTotalInventory() const;
        
        void setName(string name);
        string getName() const;

        void print();
    private:
        vector<LibraryMember> members;
        map<Book, int> inventory;
        string libraryName; 
        LibraryMember& getMemberById(int id);
};
#endif