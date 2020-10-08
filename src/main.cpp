//
// Created by Maikol Guzman on 9/28/20.
//

#include <../lib/nlohmann/json.hpp>
#include <iostream>
#include "Person.h"

using namespace std;
using nlohmann::json;

void to_json(json &_json, const Person &_person) {
    _json = json{
            {"id",   _person.getId()},
            {"name", _person.getName()},
    };
}

void from_json(const json &_json, Person &_personData) {
    _personData.setId(_json.at("id").get<int>());
    _personData.setName(_json.at("name").get<std::string>());
}

std::string serialize(std::vector<Person> _personData) {
    json _json(_personData);
    std::string jsonArray = _json.dump();
    return jsonArray;
}

int main() {
    std::vector<Person> personList;
    Person person1 = Person(1, "Mike");
    Person person2 = Person(2, "Carlos");

    personList.push_back(person1);
    personList.push_back(person2);

    std::cout << "Hello, Universidad Nacional!" << std::endl;
    std::cout << serialize(personList);
    // Serialization output: [{"id":1,"name":"Mike"},{"id":2,"name":"Carlos"}]
}