#include "HashTable.h"

int HashTable::hash(string key) {
    int sum = 0;

    for (int i = 1; i <= key.size(); i++)
       sum += key[i - 1] * i;

    return sum % 2069;
}

void HashTable::insert(string key, Track track) {
    int index = hash(key);
    hashTable[index].push_back(track);
}

list<Track>::iterator HashTable::begin() {
    
}

// Track HashTable::operator[](string key) {
//     for (auto& i : hashTable[hash(key)]) {
//         if (i.name == key)
//             return 
//     }
// }