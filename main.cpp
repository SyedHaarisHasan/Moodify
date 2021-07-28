#include "HashTable.h"
#include "Track.h"
#include <iostream>
#include <fstream>
using namespace std;

void loadHashTable(HashTable& table);

int main() { 
    cout << "Welcome to Moodify!\nPlease answer the following questions.\n\n"; // menu TO-FIX
    cout << "Question #1\n\n";
    cout << "Question #2\n\n"; 
    cout << "Question #3\n\n"; 
    cout << "Question #4\n\n";   

    int ds = 0;
    
    while (true) { // loops until user inputs valid number    
        if (ds != 1 && ds != 2) {
            cout << "Which data structure would you like to use?\n";
            cout << "1. Map\n2. Hash Table\n\n";
            cin >> ds;
            cout << endl;
        }
        else
            break;
    }

    if (ds == 1) { // if data structure is map
        // declare map
        // load map

        // INSERT SONG FUNCTIONALITY HERE
    }
    else { // if data structure is hash table
        HashTable table;
        loadHashTable(table);

        // INSERT SONG FUNCTIONALITY HERE
    }

    return 0;
}

void loadHashTable(HashTable& table) {
    ifstream file("data/tracks.csv");
    string name, artist, artistList, popularity, xplicit, releaseYear, danceability, energy, valence;

    cout << "Loading..." << endl;

    getline(file, name); // clear header
    while (!file.eof()) { // File I/O
        getline(file, name, ',');
        getline(file, popularity, ',');
        getline(file, xplicit, ',');
        getline(file, artistList, ',');
        getline(file, releaseYear, ',');
        getline(file, danceability, ',');
        getline(file, energy, ',');
        getline(file, valence, '\n');

        for (auto& i : name) { // handle dollar signs in 'name'
            if (i == '$')
                i = ',';
        }
        
        if (releaseYear.size() != 4) // update 'releaseYear' if needed
            releaseYear = releaseYear.substr(releaseYear.size() - 4, 4);

        Track track(name, artist, stoi(popularity), stoi(xplicit), stoi(releaseYear), stof(danceability), stof(energy), stof(valence));
        table.insert(track);
    } 
}