#include "Track.h"
#include <list>
#include <string>
using namespace std;

class HashTable {
    private:
    list<Track> hashTable[446475]; // array of lists, each list contains at least one track

    public:
    int hash(string key);
    void insert(string key, Track track);
    list<Track> operator[](int key);
};