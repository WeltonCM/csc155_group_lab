/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: Header file for the Library Member
*/

#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H

#include "Book.h"
#include <string>
#include <vector>
using namespace std;

class LibraryMember {
    public:
        LibraryMember();
        LibraryMember(string fName, string lName);
        void setFirstName(string fName);
        void setLastName(string lName);
        int getId() const;
        string getFirstName() const;
        string getLastName() const;
        void print();
        void checkoutBook(Book b);
        vector<Book> getCheckedoutBooks() const;
        void returnBooks();

    private:
        string firstName;
        string lastName;
        int memberId;
        vector<Book> checkedOut;
        void setId();
};
#endif