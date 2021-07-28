#include "Track.h"

Track::Track() {
    name = "";
    artist = "";
    popularity = -1;
    xplicit = -1;
    releaseYear = -1;
    danceability = -1;
    energy = -1;
    valence = -1;
}

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
    string a;

    for (int i = 2; i < artist.size(); i++) {
        if (artist[i] == '\'')
            break;
        a += artist[i];
    }

    return a;
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

// bool operator==(Track& lhs, Track& rhs) {
//     if (lhs.name == rhs.name) {
//         if (lhs.artist == rhs.artist) {
//             if (lhs.popularity == rhs.popularity) {
//                 if (lhs.xplicit == rhs.xplicit) {
//                     if (lhs.releaseYear == rhs.releaseYear) {
//                         if (lhs.danceability == rhs.danceability) {
//                             if (lhs.energy == rhs.energy) {
//                                 if (lhs.valence == rhs.valence) {
//                                     return true;
//                                 }
//                             }   
//                         }
//                     }
//                 }              
//             }   
//         }
//     }

//     return false;
// }
