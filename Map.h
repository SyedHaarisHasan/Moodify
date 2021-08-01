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
};
