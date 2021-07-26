#include "Track.h"

Track::Track(string _name, string _artist, int _popularity, int _xplicit, int _releaseYear, float _danceability, float _energy, float _valence) {
    name = _name;
    artist = _artist;
    popularity = _popularity;
    xplicit = _xplicit;
    releaseYear = _releaseYear;
    danceability = _danceability;
    energy = _energy;
    valence = _valence;
}

string Track::getName() {
    return name;
}

string Track::getArtist() {
    return artist;
}

int Track::getPopularity() {
    return popularity;
}

int Track::getExplicit() {
    return xplicit;
}

int Track::getReleaseYear() {
    return releaseYear;
}

float Track::getDanceability() {
    return danceability;
}

float Track::getEnergy() {
    return energy;
}

float Track::getValence() {
    return valence;
}
