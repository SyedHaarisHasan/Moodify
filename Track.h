#pragma once
#include <string>
using namespace std;

class Track
{
private:
    string name, artist;
    int popularity, xplicit, releaseYear;
    float danceability, energy, valence;
public:
    //constructor
    Track(string _name, string _artist, int _popularity, int _xplicit, int _releaseYear, int _danceability, int _energy, int _valence);

    //accessors
    string getName();
    string getArtist();
    int getPopularity();
    int getExplicit();
    int getReleaseYear();
    int getDanceability();
    int getEnergy();
    int getValence();
};

