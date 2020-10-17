//
// Created by Maikol Guzman on 9/28/20.
//

// https://github.com/nlohmann/json (Library to handle JSON)

#include <iostream>
#include "Person.h"
#include "FileManager.h"

using namespace std;

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
    cout << FileManager::serialize(personList);
    // Serialization output: [{"id":1,"name":"Mike"},{"id":2,"name":"Carlos"}]

    vector<Person> personListFromJson;

    cout << "\n\nDeserialización del Json" << endl;
    personListFromJson = FileManager::deserialize(R"([{"id":1,"name":"Mike"},{"id":2,"name":"Carlos"}])");
    for (const Person& person: personListFromJson) {
        std::cout << person.toString() << std::endl;
    }
}