#pragma once
#include "Track.h"
#include <list>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
extern const int SIZE;

class HashTable
{
private:
    list<Track>* hashTable = new list<Track>[SIZE]; // array of lists, each list contains at least one track

public:
    int hash(string key);
    void insert(Track track);
    vector<Track> findSongName(vector<Track>& playlist, string song);
    vector<Track> findSongArtist(vector<Track>& playlist, string artist);
    vector<Track> findSongPopular(vector<Track>& playlist, bool isPopular);
    vector<Track> findSongExplicit(vector<Track>& playlist, bool isExplicit);
    vector<Track> findSongDate(vector<Track>& playlist, int bY, int eY);
    vector<Track> findSongDance(vector<Track>& playlist, char c);
    vector<Track> findSongEnergy(vector<Track>& playlist, char c);
    vector<Track> findSongValence(vector<Track>& playlist, char c);
    void Print(vector<Track>& playlist);

    //accessors
    int getSize();

    //operators
    list<Track> operator[](int index);
};
