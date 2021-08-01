#include "Map.h"

Map::Map() {
	root = nullptr;
}

void Map::insert(Track track, Node*& root) {
	// We are at the loction where we want to insert the new node
	if (root == nullptr) {
		root = new Node(track);
	}
	// Repeat key so just change value
	else if (track.getName() == root->track.getName()) {
		// change value items
		root->track = track;
	}
	// If it's smaller, place it to the left of the current node
	else if (track.getName() < root->track.getName()) {
		insert(track, root->left);
	}
	// If it's larger, place it to the right of the current node
	else if (track.getName() > root->track.getName()) {
		insert(track, root->right);
	}
}

void Map::printInorder(Node* root, vector<Track>& v) {
	// In order traverse the tree (LNR)
	if (root != nullptr) {
		printInorder(root->left, v);
		v.push_back(root->track);
		printInorder(root->right, v);
	}
}
