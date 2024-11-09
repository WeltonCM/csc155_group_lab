/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: This class defines the Library
*/

#include "Library.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

Library::Library(){
    libraryName = "";
    vector<LibraryMember> members;
    map<Book, int> inventory;
}

Library::Library(string name){
    libraryName = name;
    vector<LibraryMember> members;
    map<Book, int> inventory;
}

Library::Library(string name, map<Book, int> books, vector<LibraryMember> users){
    libraryName = name;
    vector<LibraryMember> members = users;
    map<Book, int> inventory = books;
}

void Library::addMember(LibraryMember m){
    members.push_back(m);
}

void Library::addBook(Book b, int quantity){
    inventory.insert(make_pair(b, quantity));
}

bool Library::checkoutBook(int isbn, int memberId){
    try {
        LibraryMember& foundMember = getMemberById(memberId);
        map<Book, int>::iterator it = find_if(inventory.begin(), inventory.end(), FindByIsbn(isbn));
        if(it != inventory.end()) {
            if(it->second > 0){
                it -> second --;
                cout << foundMember.getFirstName() << " " << foundMember.getLastName();
                cout << " checked out " << it->first.getTitle().c_str() << "!" << endl;
                return true;
            } else {
                cout << "All copies of " << it->first.getTitle().c_str() << " are checked out." << endl;
                return false;
            }
        } else {
            throw runtime_error("Book with ISBN: " + to_string(isbn) + " is not in our inventory. Please talk with a librarian." );
        }
    } catch (const runtime_error& e) {
        cerr << "Error checking out book: " << e.what() << endl;
        return false;
    }
}

bool Library::returnBooks(vector<Book> books, int memberId) {
    try {
        LibraryMember& foundMember = getMemberById(memberId);
        for(int i=0; i< books.size(); i++){
            int isbn = books[i].getIsbn();
            map<Book, int>::iterator it;
            it = find_if(inventory.begin(), inventory.end(), FindByIsbn(isbn));

            if(it == inventory.end()) {
                throw runtime_error("Book ISBN " + to_string(isbn) + " not found.");
            } 
            cout << "\n"
            << foundMember.getFirstName().c_str() 
            << " "
            << foundMember.getLastName().c_str()
            <<  " successfully returned " 
            << books[i].getTitle().c_str() 
            << "."
            << endl;
            it -> second ++;
    }
    return true;
    } catch (const runtime_error& e) {
        cerr << "Error returning books: " << e.what() << endl;
        return false;
    }
    
}

map<Book, int> Library::getTotalInventory() const {
    return inventory;
}

void Library::setName(string n){
    libraryName = n;
}

string Library::getName() const {
    return libraryName;
}

LibraryMember& Library::getMemberById(int memberId) {
    LibraryMember foundMember;
    vector<LibraryMember>::iterator library_it = find_if(members.begin(), members.end(), FindMemberById(memberId));
    if(library_it != members.end()){
        return *library_it;
    } else {
        throw runtime_error("Member with ID: " + to_string(memberId) + " could not be found.");
    }
}

void Library::print() {
    printf("\nWelcom to %s! \n", libraryName.c_str());
    cout << "We have " << members.size() << " members at this location." << endl;
    cout << "Here are the books we have in stock: " << endl;
    map<Book, int>::iterator it;
    for(it = inventory.begin(); it != inventory.end(); it++){
        cout << it->first.getTitle().c_str()
            << ", by "
            << it -> first.getAuthor().c_str()
            << " | Quantity: "
            << it->second
            <<endl;
    }
    cout << "\n";
}
