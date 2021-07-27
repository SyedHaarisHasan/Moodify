#include "HashTable.h"
extern const int SIZE = 580418;

int HashTable::hash(string key) { // hash algorithm
    int index = 0;

    for (int i = 1; i <= key.size(); i++)
        index += key[i - 1] * i;

    index = index % 580471;

    if (index < 0) // if index is invalid, add track to 0th index
        return 0;
    else 
        return index;
}

void HashTable::insert(Track track) { // inserts 'track' at hashed value of 'track's' name
    int index = hash(track.getName());
    hashTable[index].push_back(track);
}

int HashTable::getSize() {
    return SIZE;
}

void HashTable::printTable() {
        for (int i = 0; i < SIZE; i++) {         
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++)
                cout << it->getName() << endl;
        }
    }