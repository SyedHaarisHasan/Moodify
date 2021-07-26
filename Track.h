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
    Track(string _name, string _artist, int _popularity, int _xplicit, int _releaseYear, float _danceability, float _energy, float _valence);

    //accessors
    string getName();
    string getArtist();
    int getPopularity();
    int getExplicit();
    int getReleaseYear();
    float getDanceability();
    float getEnergy();
    float getValence();
};

