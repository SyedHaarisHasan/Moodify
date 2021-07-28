#include "HashTable.h"
#include <random>
#include <ctime>
extern const int SIZE = 580419;

int HashTable::hash(string key) { // hash algorithm
    int index = 0;

    for (int i = 1; i <= key.size(); i++)
        index += key[i - 1] * i;

    index = index % 580471;

    if (index < 0) { // if index is invalid, add track to 0th index
        return 580418;
    }
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

list<Track> HashTable::operator[](int index) { // returns list of Tracks contained at 'index'
    return hashTable[index];
}

void HashTable::printTable() { // prints the table // FOR DEBUGGING PURPOSES
        for (int i = 0; i < SIZE; i++) {         
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                cout << it->getName() << endl;
            }
        }
    }