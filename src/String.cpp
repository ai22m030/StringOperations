//
// Created by Adnan Vatric User on 17.09.22.
//

#include "../include/String.h"
#include <iostream>

String::String() {
    string_ = new char [1];
    string_[0] = '\0';
}

String::String(const char * string) {
    length_ = 0;

    while (string[length_] != '\0') {
        length_++;
    }

    string_ = new char [length_ + 1];
    int i = 0;

    while (string[i] != '\0') {
        string_[i] = string[i];
        i++;
    }
}

String& String::operator=(const String& string) {
    if(this != &string) {
        delete [] string_;

        length_ = 0;

        while (string.string_[length_] != '\0') {
            length_++;
        }

        string_ = new char [length_ + 1];

        int i = 0;

        while (string.string_[i] != '\0') {
            string_[i] = string.string_[i];
            i++;
        }

    }

    return *this;
}

String& String::operator=(String&& string) noexcept {
    if (this != &string) {
        string_ = string.string_;
        length_ = string.length_;
        string.length_ = 0;
    }

    return *this;
}

String& String::operator+=(const String& string) {
    this->append(string);
    return *this;
}

void String::append(const char *string) {

}

void String::append(const String &string) {
    int length = this->length_ + string.length_;

    char * new_string = new char [length];

    int i = 0;

    while (this->string_[i] != '\0') {
        new_string[i] = this->string_[i];
        i++;
    }

    i = 0;

    while (string.string_[i] != '\0') {
        new_string[this->length_ + i] = string.string_[i];
        i++;
    }

    delete [] this->string_;

    this->string_ = new_string;
}

void String::print() const{
    std::cout << string_ << std::endl;
}