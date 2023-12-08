#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl << endl;
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   PlaylistNode* newSong = nullptr;
   
   switch(option) {
      case 'a': {
         //add song
         string uniqueID;
         string songName;
         string artistName;
         int songLength;
         
         cout << "ADD SONG" << endl;
         
         cout << "Enter song's unique ID:" << endl;
         getline(cin, uniqueID);
         
         cout << "Enter song's name:" << endl;
         getline(cin, songName);
         
         cout << "Enter artist's name:" << endl;
         getline(cin, artistName);
         
         cout << "Enter song's length (in seconds):" << endl << endl;
         cin >> songLength;
         
         newSong = new PlaylistNode(uniqueID, songName, artistName, songLength);

         
         if(headNode == nullptr) {
            headNode = newSong;  
         } else {
            PlaylistNode* current = headNode;
            while(current->GetNext() != nullptr) {
               current = current->GetNext();  
            }
           
            current->InsertAfter(newSong);
         }
         
         break;
      }
      case 'd': {
         //remove song
         string targetID;
         
         cout << "REMOVE SONG" << endl;
         
         cout << "Enter song's unique ID:" << endl;
         getline(cin, targetID);
         
         PlaylistNode* current = headNode;
         PlaylistNode* prev = nullptr;
         PlaylistNode* removedNode = nullptr;
         
         while(current != nullptr && current->GetID() != targetID) {
            prev = current;
            current = current->GetNext();
         }
         
         if(prev == nullptr) {
            headNode = current->GetNext();  
         } else {
            prev->SetNext(current->GetNext());  
         }
         
         removedNode = current;
         delete current;
         cout << "\"" << removedNode->GetSongName() << "\" removed." << endl << endl;
         
         
         break;
      }
      case 'c': {
         int currentPosition;
         int newPosition;
         
         cout << "CHANGE POSITION OF SONG" << endl;
         
         cout << "Enter song's current position:" << endl;
         cin >> currentPosition;
         
         cout << "Enter new position for song:" << endl;
         cin >> newPosition;
         
         if(newPosition < 1) {
            newPosition = 1;  
         }
         
         PlaylistNode* current = headNode;
         PlaylistNode* prev = nullptr;
         int currentPosCounter = 1;
         
         while(current != nullptr && currentPosCounter < currentPosition) {
            prev = current;
            current = current->GetNext();
            currentPosCounter++;
         }
         
         if(prev == nullptr) {
            headNode = current->GetNext();  
         } else {
            prev->SetNext(current->GetNext());  
         }
         
         if(newPosition == 1) {
            current->SetNext(headNode);
            headNode = current;
         } else {
            PlaylistNode* newPrev = nullptr;
            PlaylistNode* newCurrent = headNode;
            int newPosCounter = 1;
           
            while(newCurrent != nullptr && newPosCounter < newPosition) {
               newPrev = newCurrent;
               newCurrent = newCurrent->GetNext();
               newPosCounter++;
            }
           
            if(newPrev != nullptr) {
               newPrev->InsertAfter(current);  
            } else {
               current->SetNext(headNode);
               headNode = current;
            }
         }
         
         cout << "\"" << current->GetSongName() << "\" moved to position " << newPosition << endl << endl;
         
         break;
      }
      case 's': {
         string artistToSearch;
         int position = 1;
         PlaylistNode* current = headNode;
         
         cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
         cout << "Enter artist's name:" << endl << endl;
         getline(cin, artistToSearch);
         
         while(current != nullptr) {
            if(current->GetArtistName() == artistToSearch) {
               cout << position << "." << endl;
               current->PrintPlaylistNode();
            }
           
            current = current->GetNext();
            position++;
         }
         
         break;
      }
      case 't': {
         //output total time of playlist
         int totalTime = 0;
         PlaylistNode* current = headNode;
         
         while(current != nullptr) {
            totalTime += current->GetSongLength();
            current = current->GetNext();
         }
         
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
         cout << "Total time: " << totalTime << " seconds" << endl << endl;

         break;
      }
      case 'o': {
         if(headNode == nullptr) {
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            cout << "Playlist is empty" << endl << endl;  
         } else {
            int position = 1;
            PlaylistNode* current = headNode;
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            while(current != nullptr) {
               cout << position << "." << endl;
               current->PrintPlaylistNode();
               current = current->GetNext();
               position++;
            }
         }
         
         break;
      }
      case 'q': {
         //Quit
         break;
      }
     
   }
   
   return headNode;
}

int main() {
   string playlistTitle;
   char option;
   
   cout << "Enter playlist's title:" << endl << endl;
   getline(cin, playlistTitle);
   
   PlaylistNode* headNode = nullptr;
   
   do {
      PrintMenu(playlistTitle);
      cout << "Choose an option:" << endl;
      cin >> option;
      cin.ignore();
   
      headNode = ExecuteMenu(option, playlistTitle, headNode);
   } while(option != 'q');
   
   return 0;
}