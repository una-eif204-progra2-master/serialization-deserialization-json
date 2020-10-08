//
// Created by Maikol Guzman on 10/8/20.
//

#include "Person.h"
#include <utility>
#include <sstream>

Person::Person() = default;

Person::Person(int id, std::string name) : id(id), name(std::move(name)) {}

int Person::getId() const {
    return id;
}

void Person::setId(int id) {
    Person::id = id;
}

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &name) {
    Person::name = name;
}

std::string Person::toString() const {
    std::ostringstream output;
    output << "Person id: " << getId()
           << ", Name: " << getName();

    return output.str();
}

Person::~Person() = default;
