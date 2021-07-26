#include "HashTable.h"
extern const int SIZE = 580418;

int HashTable::hash(string key) {
    int sum = 0;

    for (int i = 1; i <= key.size(); i++)
        sum += key[i - 1] * i;

    return sum % 2069;
}

void HashTable::insert(Track track) {
    int index = hash(track.getName());
    hashTable[0].push_back(track);
}

int HashTable::getSize() {
    return SIZE;
}

void HashTable::printTable() {
        for (int i = 0; i < SIZE; i++) {
            auto it = hashTable[i].begin();           
            for (; it != hashTable[i].end(); it++) {
                cout << it->getName() << endl;
            }
        }
    }