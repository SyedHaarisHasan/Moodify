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

void Map::findSongName(Node* root, vector<Track>& playlist, string song) {
    if (root != nullptr) {
        findSongName(root->left, playlist, song);
        if (root->track.getName() != song) {
            playlist.push_back(root->track);
        }
        findSongName(root->right, playlist, song);
    }
}

void Map::findSongArtist(Node* root, vector<Track>& playlist, string artist) {
    if (root != nullptr) {
        findSongArtist(root->left, playlist, artist);
        if (root->track.getArtist() != artist) {
            playlist.push_back(root->track);
        }
        findSongArtist(root->right, playlist, artist);
    }
}


void Map::findSongPopular(Node* root, vector<Track>& playlist, bool isPopular) {
    if (isPopular) {
        if (root != nullptr) {
            findSongPopular(root->left, playlist, isPopular);
            if (root->track.getPopularity() != 0) {
                playlist.push_back(root->track);
            }
            findSongPopular(root->right, playlist, isPopular);
        }
    }
    else {
        if (root != nullptr) {
            findSongPopular(root->left, playlist, isPopular);
            if (root->track.getPopularity() != 1) {
                playlist.push_back(root->track);
            }
            findSongPopular(root->right, playlist, isPopular);
        }
    }
}


void Map::findSongExplicit(Node* root, vector<Track>& playlist, bool isExplicit) {
    if (isExplicit) {
        if (root != nullptr) {
            findSongExplicit(root->left, playlist, isExplicit);
            if (root->track.getExplicit() != 0) {
                playlist.push_back(root->track);
            }
            findSongExplicit(root->right, playlist, isExplicit);
        }
    }
    else {
        if (root != nullptr) {
            findSongExplicit(root->left, playlist, isExplicit);
            if (root->track.getExplicit() != 1) {
                playlist.push_back(root->track);
            }
            findSongExplicit(root->right, playlist, isExplicit);
        }
    }
}


void Map::findSongDate(Node* root, vector<Track>& playlist, int bY, int eY) {
    int difference = eY - bY;
    if (difference == 0) {
        if (root != nullptr) {
            findSongDate(root->left, playlist, bY, eY);
            if (root->track.getReleaseYear() == eY) {
                playlist.push_back(root->track);
            }
            findSongDate(root->right, playlist, bY, eY);
        }
    }
    else {
        if (root != nullptr) {
            findSongDate(root->left, playlist, bY, eY);
            if (root->track.getReleaseYear() >= bY && root->track.getReleaseYear() <= eY) {
                playlist.push_back(root->track);
            }
            findSongDate(root->right, playlist, bY, eY);
        }
    }
}


void Map::findSongDance(Node* root, vector<Track>& playlist, char c) {
    if (c == 'A') {
        if (root != nullptr) {
            findSongDance(root->left, playlist, c);
            if (root->track.getDanceability() > 0 && root->track.getDanceability() < .33) {
                playlist.push_back(root->track);
            }
            findSongDance(root->right, playlist, c);
        }
    }
    else if (c == 'B') {
        if (root != nullptr) {
            findSongDance(root->left, playlist, c);
            if (root->track.getDanceability() > 0.33 && root->track.getDanceability() < .67) {
                playlist.push_back(root->track);
            }
            findSongDance(root->right, playlist, c);
        }
    }
    else if (c == 'C') {
        if (root != nullptr) {
            findSongDance(root->left, playlist, c);
            if (root->track.getDanceability() > .67) {
                playlist.push_back(root->track);
            }
            findSongDance(root->right, playlist, c);
        }
    }
}


void Map::findSongEnergy(Node* root, vector<Track>& playlist, char c) {
    if (c == 'A') {
        if (root != nullptr) {
            findSongEnergy(root->left, playlist, c);
            if (root->track.getEnergy() > 0 && root->track.getEnergy() < .33) {
                playlist.push_back(root->track);
            }
            findSongEnergy(root->right, playlist, c);
        }
    }
    else if (c == 'B') {
        if (root != nullptr) {
            findSongEnergy(root->left, playlist, c);
            if (root->track.getEnergy() > 0.33 && root->track.getEnergy() < .67) {
                playlist.push_back(root->track);
            }
            findSongEnergy(root->right, playlist, c);
        }
    }
    else if (c == 'C') {
        if (root != nullptr) {
            findSongEnergy(root->left, playlist, c);
            if (root->track.getEnergy() > .67) {
                playlist.push_back(root->track);
            }
            findSongEnergy(root->right, playlist, c);
        }
    }
}


void Map::findSongValence(Node* root, vector<Track>& playlist, char c) {
    if (c == 'A') {
        if (root != nullptr) {
            findSongValence(root->left, playlist, c);
            if (root->track.getValence() > 0 && root->track.getValence() < .33) {
                playlist.push_back(root->track);
            }
            findSongValence(root->right, playlist, c);
        }
    }
    else if (c == 'B') {
        if (root != nullptr) {
            findSongValence(root->left, playlist, c);
            if (root->track.getValence() > 0.33 && root->track.getValence() < .67) {
                playlist.push_back(root->track);
            }
            findSongValence(root->right, playlist, c);
        }
    }
    else if (c == 'C') {
        if (root != nullptr) {
            findSongValence(root->left, playlist, c);
            if (root->track.getValence() > .67) {
                playlist.push_back(root->track);
            }
            findSongValence(root->right, playlist, c);
        }
    }
}
