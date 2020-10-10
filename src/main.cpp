//
// Created by Maikol Guzman on 9/28/20.
//

// https://github.com/nlohmann/json (Library to handle JSON)

#include <../lib/nlohmann/json.hpp>
#include <iostream>
#include "Person.h"

using namespace std;
using nlohmann::json;

/**
 * Custom to_json method automatically called.
 * @param _json the Json Object
 * @param _person the Model
 */
void to_json(json &_json, const Person &_person) {
    _json = json{
            {"id",   _person.getId()},
            {"name", _person.getName()},
    };
}

/**
 * Custom from_json method automatically called.
 * @param _json  the Json Object
 * @param _person the Model
 */
void from_json(const json &_json, Person &_person) {
    _person.setId(_json.at("id").get<int>());
    _person.setName(_json.at("name").get<std::string>());
}

/**
 * This method will serialize the vector
 * @param _personList
 * @return the string with the json array
 */
string serialize(vector<Person> _personList) {
    json jsonData(_personList);
    string jsonArray = jsonData.dump();
    return jsonArray;
}

/**
 * This method deserialize the string to object
 * @param _data the string json data
 * @return the array of objects
 */
vector<Person> deserialize(string _data) {
    json jsonData = json::parse(_data);
    vector<Person> personList = jsonData;

    return personList;
}

/**
 * Example to Serializing JSON objects
 * @return null
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

    cout << "\n\nDeserialización del Json" << endl;
    personListFromJson = deserialize(R"([{"id":1,"name":"Mike"},{"id":2,"name":"Carlos"}])");
    for (const Person& person: personListFromJson) {
        std::cout << person.toString() << std::endl;
    }
}