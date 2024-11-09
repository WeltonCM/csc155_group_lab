/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: This class defines the Book objects
*/

#include "Book.h"
#include <string>
#include <random>

using namespace std;

Book::Book(){
    title = "";
    author = "";
    setIsbn();
}

Book::Book(string t, string a){
    title = t;
    author = a;
    setIsbn();
}

void Book::setTitle(string t){
    title = t;
}

string Book::getTitle() const {
    return title;
}

void Book::setAuthor(string a) {
    author = a;
}

string Book::getAuthor() const {
    return author;
}

void Book::setIsbn() {
    random_device device;
    mt19937 gen(device());
    uniform_int_distribution<> dis(1, 100);
    isbn = dis(gen);
}

int Book::getIsbn() const {
    return isbn;
}

void Book::print(){
    printf("%s, by %s", title.c_str(), author.c_str());
}