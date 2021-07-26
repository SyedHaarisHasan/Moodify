#include "Track.h"

Track::Track(string _name, string _artist, int _popularity, int _xplicit, int _releaseYear, int _danceability, int _energy, int _valence) {
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

int Track::getDanceability() {
    return danceability;
}

int Track::getEnergy() {
    return energy;
}

int Track::getValence() {
    return valence;
}
