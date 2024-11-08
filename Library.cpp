/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: This class defines the Library
*/

#include "Library.h"
// #include "Book.h"
// #include "LibraryMember.h"
#include <vector>
#include <map>
#include <string>

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

LibraryMember Library::getMember(int id) const {
    for(int i=0; i<members.size(); i++){
        if(members.at(i).getId() == id){
            return members.at(i);
        }
    }
    return LibraryMember();
}

vector<LibraryMember> Library::getAllMembers() const {
    return members;
}

void Library::addBook(const Book& b, int quantity){
    inventory.insert(make_pair(b, quantity));
}

Book Library::checkoutBook(int id){
    map<Book, int>::iterator iterator = find_if(inventory.begin(), inventory.end(), 
    [](const pair<Book, int>& pair){
        return pair.first.getId();
    });


    if(iterator != inventory.end()){
        return iterator -> first;
    } else {
        return Book();
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
