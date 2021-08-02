#include "HashTable.h"
#include "Track.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void loadHashTable(HashTable& table);
void loadMap(Map& map);

int main() {
    cout << "Welcome to Moodify!\nPlease answer the following questions.\n\n";
    int ds = 0;
    clock_t start;
    double duration;

    while (true) { // loops until user inputs valid number    
        if (ds != 1 && ds != 2) {
            cout << "Which data structure would you like to use?\n";
            cout << "1. Map\n2. Hash Table\n";
            cin >> ds;
            cout << endl;
        }
        else
            break;
    }

    if (ds == 1) { // if data structure is map
        Map map;

        start = clock();

        loadMap(map);

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to load Map: " << duration << " seconds." << endl;

        vector<Track> playlist;
        cout << "Is there a specific song you want to listen to? " << endl;
        cout << "A: Yes" << endl;
        cout << "B: No" << endl;
        char c;
        cin >> c;
        if (c == 'A') {
            cout << "What do you want to listen to? " << endl;
            string song;
            cin >> song;

            start = clock();

            map.findSongName(map.root, playlist, song);

            duration = (clock() - start) / (double) CLOCKS_PER_SEC;
            cout << "Time taken to find song: " << duration << " seconds.\n" << endl;
        }

        cout << "Do you want to listen to a popular song?" << endl;
        cout << "A: Yes" << endl;
        cout << "B: No" << endl;
        cin >> c;

        start = clock();

        if (c == 'A') {
            map.findSongPopular(map.root, playlist, true);
        }
        else {
            map.findSongPopular(map.root, playlist, false);
        }

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to find song: " << duration << " seconds.\n" << endl;

        cout << "Are you ok if the song is explicit?" << endl;
        cout << "A: Yes" << endl;
        cout << "B: No" << endl;
        cin >> c;

        start = clock();

        if (c == 'A') {
            map.findSongExplicit(map.root, playlist, true);
        }
        else if (c == 'B') {
            map.findSongExplicit(map.root, playlist, false);
        }

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to find song: " << duration << " seconds.\n" << endl;

        cout << "Is there an artist you want to listen to? " << endl;
        cout << "A: Yes" << endl;
        cout << "B: No" << endl;
        cin >> c;

        if (c == 'A') {
            cout << "Who do you want to listen to? " << endl;
            string name;
            cin >> name;

            start = clock();

            map.findSongArtist(map.root, playlist, name);

            duration = (clock() - start) / (double) CLOCKS_PER_SEC;
            cout << "Time taken to find song: " << duration << " seconds.\n" << endl;
        }

        cout << "How old do you want your song to be" << endl;
        cout << "A: Recent" << endl;
        cout << "B: Old" << endl;
        cout << "C: Ancient" << endl;
        cout << "D: Doesn't matter" << endl;
        cout << "E: Custom year" << endl;
        cin >> c;

        start = clock();

        switch (c) {
        case 'A':
            map.findSongDate(map.root, playlist, 2016, 2021);
            break;
        case 'B':
            map.findSongDate(map.root, playlist, 2000, 2016);
            break;
        case 'C':
            map.findSongDate(map.root, playlist, 1980, 2000);
            break;
        case 'E':
            cout << "What year?" << endl;
            string isYear;
            cin >> isYear;
            map.findSongDate(map.root, playlist, stoi(isYear), stoi(isYear));
            break;
        }

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to find song: " << duration << " seconds.\n" << endl;

        cout << "How danceable do you want your song to be?" << endl;
        cout << "A: not danceable" << endl;
        cout << "B: somewhat danceable" << endl;
        cout << "C: danceable" << endl;
        cin >> c;

        start = clock();

        map.findSongDance(map.root, playlist, c);

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to find song: " << duration << " seconds.\n" << endl;

        cout << "How much energy do you want your song to be?" << endl;
        cout << "A: not much energy" << endl;
        cout << "B: somewhat energy" << endl;
        cout << "C: a lot of energy" << endl;
        cin >> c;

        start = clock();

        map.findSongValence(map.root, playlist, c);

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to find song: " << duration << " seconds.\n" << endl;

        cout << "How valence do you want your song to be?" << endl;
        cout << "A: not much valence" << endl;
        cout << "B: somewhat valent" << endl;
        cout << "C: a lot of valence" << endl;
        cin >> c;

        start = clock();

        map.findSongEnergy(map.root, playlist, c);

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to find song: " << duration << " seconds.\n" << endl;

        cout << "Ok, here are 5 songs that we think you might like" << endl;
        for (int i = 0; i < 5; i++) {
            cout << playlist[i].getName() << ",";
            cout << playlist[i].getArtist() << ",";
            cout << playlist[i].getPopularity() << ",";
            cout << playlist[i].getExplicit() << ",";
            cout << playlist[i].getReleaseYear() << ",";
            cout << playlist[i].getDanceability() << ",";
            cout << playlist[i].getEnergy() << ",";
            cout << playlist[i].getValence() << endl;
        }
    }
    else { // if data structure is hash table
        HashTable table;

        start = clock();

        loadHashTable(table);

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to load Hash Table: " << duration << " seconds.\n" << endl;

        vector<Track> playlist;
        cout << "Is there a specific song you want to listen to? " << endl;
        cout << "A: Yes" << endl;
        cout << "B: No" << endl;
        char c;
        cin >> c;

        if (c == 'A') {
            cout << "What do you want to listen to? " << endl;
            string song;
            cin >> song;

            start = clock();

            playlist = table.findSongName(playlist, song);

            duration = (clock() - start) / (double) CLOCKS_PER_SEC;
            cout << "Time taken to find song: " << duration << " seconds.\n" << endl;
        }
        cout << "Do you want to listen to a popular song?" << endl;
        cout << "A: Yes" << endl;
        cout << "B: No" << endl;
        cin >> c;

        start = clock();

        if (c == 'A') {
            playlist = table.findSongPopular(playlist, true);
        }
        else {
            playlist = table.findSongPopular(playlist, false);
        }

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to refine options: " << duration << " seconds.\n" << endl;

        cout << "Are you ok if the song is explicit?" << endl;
        cout << "A: Yes" << endl;
        cout << "B: No" << endl;
        cin >> c;

        start = clock();

        if (c == 'A') {
            playlist = table.findSongExplicit(playlist, true);
        }
        else if (c == 'B') {
            playlist = table.findSongExplicit(playlist, false);
        }

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to refine options: " << duration << " seconds.\n" << endl;

        cout << "Is there an artist you want to listen to? " << endl;
        cout << "A: Yes" << endl;
        cout << "B: No" << endl;
        cin >> c;
        if (c == 'A') {
            cout << "Who do you want to listen to? " << endl;
            string name;
            cin >> name;
            start = clock();

            playlist = table.findSongArtist(playlist, name);

            duration = (clock() - start) / (double) CLOCKS_PER_SEC;
            cout << "Time taken to refine options: " << duration << " seconds.\n" << endl;
        }
        cout << "How old do you want your song to be" << endl;
        cout << "A: Recent" << endl;
        cout << "B: Old" << endl;
        cout << "C: Ancient" << endl;
        cout << "D: Doesn't matter" << endl;
        cout << "E: Custom year" << endl;
        cin >> c;

        start = clock();

        switch (c) {
        case 'A':
            playlist = table.findSongDate(playlist, 2016, 2021);
            break;
        case 'B':
            playlist = table.findSongDate(playlist, 2000, 2016);
            break;
        case 'C':
            playlist = table.findSongDate(playlist, 1980, 2000);
            break;
        case 'E':
            cout << "What year?" << endl;
            string isYear;
            cin >> isYear;
            playlist = table.findSongDate(playlist, stoi(isYear), stoi(isYear));
            break;
        }

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to refine options: " << duration << " seconds.\n" << endl;

        cout << "How danceable do you want your song to be?" << endl;
        cout << "A: not danceable" << endl;
        cout << "B: somewhat danceable" << endl;
        cout << "C: danceable" << endl;
        cin >> c;

        start = clock();

        playlist = table.findSongDance(playlist, c);

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to refine options: " << duration << " seconds.\n" << endl;

        cout << "How much energy do you want your song to be?" << endl;
        cout << "A: not much energy" << endl;
        cout << "B: somewhat energy" << endl;
        cout << "C: a lot of energy" << endl;
        cin >> c;

        start = clock();

        playlist = table.findSongValence(playlist, c);

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to refine options: " << duration << " seconds.\n" << endl;

        cout << "How valence do you want your song to be?" << endl;
        cout << "A: not much valence" << endl;
        cout << "B: somewhat valent" << endl;
        cout << "C: a lot of valence" << endl;
        cin >> c;

        start = clock();

        playlist = table.findSongEnergy(playlist, c);
    
        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Time taken to refine options: " << duration << " seconds.\n" << endl;

        cout << "Ok, here are 5 songs that we think you might like" << endl;
        table.Print(playlist);
    }

    return 0;
}

void loadHashTable(HashTable& table) {
    ifstream file("data/tracks.csv");
    string name, artist, popularity, xplicit, releaseYear, danceability, energy, valence;

    cout << "Loading..." << endl;

    getline(file, name); // clear header
    while (!file.eof()) { // File I/O
        if (name.size() == 0)
            break;
        getline(file, name, ',');
        getline(file, popularity, ',');
        getline(file, xplicit, ',');
        getline(file, artist, ',');
        getline(file, releaseYear, ',');
        getline(file, danceability, ',');
        getline(file, energy, ',');
        getline(file, valence, '\n');

        for (auto& i : name) { // handle dollar signs in 'name'
            if (i == '$')
                i = ',';
        }

        if (releaseYear.size() != 4)  // update 'releaseYear' if needed 
            releaseYear = releaseYear.substr(releaseYear.size() - 4, 4);

        Track track(name, artist, stoi(popularity), stoi(xplicit), stoi(releaseYear), stof(danceability), stof(energy), stof(valence));
        table.insert(track);
        
    }
}

void loadMap(Map& map) {
    ifstream file("data/tracks.csv");
    string name, artist, artistList, popularity, xplicit, releaseYear, danceability, energy, valence;

    cout << "Loading..." << endl;

    getline(file, name); // clear header
    while (!file.eof()) { // File I/O
        if (name.size() == 0)
            break;
        getline(file, name, ',');
        getline(file, popularity, ',');
        getline(file, xplicit, ',');
        getline(file, artist, ',');
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
        map.insert(track, map.root);    
    }
}
