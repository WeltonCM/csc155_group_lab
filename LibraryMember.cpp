/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: Class for the Library Member
*/

#include "LibraryMember.h"
#include <vector>
#include <random>
#include <string>
#include <iostream>


using namespace std;

LibraryMember::LibraryMember(){
    firstName = "";
    lastName = "";
    setId();
}

LibraryMember::LibraryMember(string fName, string lName){
    firstName = fName;
    lastName = lName;
    setId();
}

void LibraryMember::setFirstName(string fName){
    firstName = fName;
}

void LibraryMember::setLastName(string lName){
    lastName = lName;
}

int LibraryMember::getId() const{
    return memberId;
}

string LibraryMember::getFirstName() const {
    return firstName;
}

string LibraryMember::getLastName() const {
    return lastName;
}

void LibraryMember::checkoutBook(Book b) {
    checkedOut.push_back(b);
}

vector<Book> LibraryMember::getCheckedoutBooks() const {
    return checkedOut;
}

void LibraryMember::returnBook(Book b){
    vector<Book>::iterator position = find(checkedOut.begin(), checkedOut.end(), b);
    if(position != checkedOut.end()){
        checkedOut.erase(position);
    }
}

void LibraryMember::print() {
    if(checkedOut.size() < 1){
        printf("Member ID: %d, \nMember Name: %s %s, \nNo Books checked out!", memberId, firstName.c_str(), lastName.c_str());
    } else {
        printf("Member ID: %d, \nMember Name: %s %s, \nBooks checked out: \n", memberId, firstName.c_str(), lastName.c_str());
        for(int i=0; i < checkedOut.size(); i++){
            checkedOut.at(i).print();
            cout << "\n";
        }
    }
}

void LibraryMember::setId(){
    random_device device;
    mt19937 gen(device());
    uniform_int_distribution<> dis(1, 100);
    memberId = dis(gen);
}