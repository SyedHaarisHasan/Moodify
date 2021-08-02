#include "HashTable.h"
#include <random>
#include <ctime>
#include <iostream>
using namespace std;
extern const int SIZE = 130003;

int HashTable::hash(string key) { // hash algorithm
    int index = 0;

    for (int i = 1; i <= key.size(); i++)
        index += key[i - 1] * i;

    index = index % 130002;

    if (index < 0) { // if index is invalid, add track to last index
        return 130002;
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
vector<Track> HashTable::findSongName(vector<Track>& playlist, string song)
{
    for (int i = 0; i < SIZE; i++) {
        for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
            if (it->getName() == song) {
                playlist.push_back(*it);
            }
        }
    }
    return playlist;
}
vector<Track> HashTable::findSongArtist(vector<Track>& playlist, string artist)
{
    for (int i = 0; i < SIZE; i++) {
        for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
            if (it->getArtist() == artist) {
                playlist.push_back(*it);
            }
        }
    }
    return playlist;
}
vector<Track> HashTable::findSongPopular(vector<Track>& playlist, bool isPopular)
{
    if (isPopular) {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getPopularity() != 0) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getPopularity() == 0) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    return playlist;
}
vector<Track> HashTable::findSongExplicit(vector<Track>& playlist, bool isExplicit)
{
    if (isExplicit) {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getExplicit() != 0) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getExplicit() != 1) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    return playlist;
}
vector<Track> HashTable::findSongDate(vector<Track>& playlist, int bY, int eY)
{
    int difference = eY - bY;
    if (difference == 0) {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getReleaseYear() == eY) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getReleaseYear() >= bY && it->getReleaseYear() <= eY) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    return playlist;
}
vector<Track> HashTable::findSongDance(vector<Track>& playlist, char c)
{
    if (c == 'A') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getDanceability() > 0 && it->getDanceability() < .33) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else if (c == 'B') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getDanceability() < 0.67 && it->getDanceability() > .33) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else if (c == 'C') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getDanceability() > 0.67) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    return playlist;
}
vector<Track> HashTable::findSongEnergy(vector<Track>& playlist, char c)
{
    if (c == 'A') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getEnergy() > 0 && it->getEnergy() < .33) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else if (c == 'B') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getEnergy() < 0.67 && it->getEnergy() > .33) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else if (c == 'C') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getEnergy() > 0.67) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    return playlist;
}
vector<Track> HashTable::findSongValence(vector<Track>& playlist, char c)
{
    if (c == 'A') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getValence() > 0 && it->getValence() < .33) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else if (c == 'B') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getValence() < 0.67 && it->getValence() > .33) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    else if (c == 'C') {
        for (int i = 0; i < SIZE; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                if (it->getValence() > 0.67) {
                    playlist.push_back(*it);
                }
            }
        }
    }
    return playlist;
}
void HashTable::Print(vector<Track>& playlist)
{
    int finish = 0;
    for (int i = 0; i < SIZE; i++) {
        for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
            if (finish == 5) {
                exit;
            }
            if (it->getName() == "['']") {
                continue;
            }
            else {
                cout << it->getName() << " by " << it->getArtist() << endl;
                finish++;
            }
        }
    }
}
