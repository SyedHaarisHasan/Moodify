#include <iostream>
#include <vector>
#include "Track.h"
using namespace std;
#pragma once

class Map
{
	// public inheritance because a Node is a Track, plus more
	struct Node
	{
		Track track;
		Node* left;
		Node* right;

		Node() {
			left = nullptr;
			right = nullptr;
			track = Track();
		}

		Node(Track _track) {
			track = _track;
			left = nullptr;
			right = nullptr;
		}
	};

public:
	Map();
	Node* root;
	void insert(Track track, Node*& root);
	void printInorder(Node* root, vector<Track>& v);
	void findSongName(Node* root, vector<Track>& playlist, string song);
	void findSongArtist(Node* root, vector<Track>& playlist, string artist);
	void findSongPopular(Node* root, vector<Track>& playlist, bool isPopular);
	void findSongExplicit(Node* root, vector<Track>& playlist, bool isExplicit);
	void findSongDate(Node* root, vector<Track>& playlist, int bY, int eY);
	void findSongDance(Node* root, vector<Track>& playlist, char c);
	void findSongEnergy(Node* root, vector<Track>& playlist, char c);
	void findSongValence(Node* root, vector<Track>& playlist, char c);
};
