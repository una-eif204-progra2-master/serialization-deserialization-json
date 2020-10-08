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

string serialize(vector<Person> _personList) {
    json _json(_personList);
    string jsonArray = _json.dump();
    return jsonArray;
}

vector<Person> deserialize(string _data) {
    json jsonData = json::parse(_data);
    vector<Person> personList = jsonData;

    return personList;
}

/**
 * Example to Serializing JSON objects
 * @return
 */
int main() {
    vector<Person> personList;
    Person person1 = Person(1, "Mike");
    Person person2 = Person(2, "Carlos");

    personList.push_back(person1);
    personList.push_back(person2);

    cout << "Serialización del Json" << endl;
    cout << serialize(personList);
    // Serialization output: [{"id":1,"name":"Mike"},{"id":2,"name":"Carlos"}]

    vector<Person> personListFromJson;


    cout << "Deserialización del Json" << endl;
    personListFromJson = deserialize(R"([{"id":1,"name":"Mike"},{"id":2,"name":"Carlos"}])");
    for (const Person& person: personListFromJson) {
        std::cout << person.getName() << std::endl;
    }

}