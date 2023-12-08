/* Type your code here */
#include "PlaylistNode.h"

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

PlaylistNode::PlaylistNode(std::string id, std::string songName, std::string artistName, int songLength)
    : uniqueID(id), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr) {}

string PlaylistNode::GetID() const {
   return uniqueID;   
}

string PlaylistNode::GetSongName() const {
   return songName;   
}

string PlaylistNode::GetArtistName() const {
   return artistName;   
}

int PlaylistNode::GetSongLength() const {
   return songLength;   
}

PlaylistNode* PlaylistNode::GetNext() const {
   return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
   PlaylistNode* tmpNext = nextNodePtr;
   nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = tmpNext;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
   nextNodePtr = nodePtr;   
}

void PlaylistNode::PrintPlaylistNode() const {
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl << endl;
}