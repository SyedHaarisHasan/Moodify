#pragma once
#include "Track.h"
#include <list>
#include <string>
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
    void printTable();

    //accessors
    int getSize();

    //operators
    list<Track> operator[](int index);
};

