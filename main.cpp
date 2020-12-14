#include <iostream>
#include <map>
#include <algorithm>
#include "song.cpp"

using namespace std;

map<string, songs> finalSongList;

  struct Node{
        public:
        string data;
        Node* next;

       Node(string d) 
        { 
            data = d; 
            next = NULL; 
        } 
  };

  Node* head;

void insert(string data){

  if(head == nullptr){
     head = new Node(data);
     head->next = NULL;
    }
      
      else{
            Node* last = head; 
            while (last->next != NULL) { 
                last = last->next; 
            } 
   
            // Insert the new_node at last node 
            last->next = new Node(data);
}

}

void printList() 
    { 
        Node* currNode = head; 

        if(currNode == nullptr){
          cout << "List is empty" <<'\n';
          return;
        }
       cout << "Final list of songs in linked list: " << '\n'; 
   
        // Traverse through the LinkedList 
        while (currNode != NULL) { 
            // Print the data at current node 
           cout << currNode->data + "->" ; 
   
            // Go to next node 
            currNode = currNode->next; 
        } 
          
       cout << '\n'; 
    }

//To delete value from linkedlist based on given value
void deleteValue(string value){
  Node* curr = head;
  Node* prev = NULL;

  if(curr->data == value){
    head = curr->next; // Changed head 
    finalSongList.erase(value);
    // Display the message 
    cout << value << " is deleted" << '\n'; 
    return;
  }

while (curr != nullptr) { 
      if (curr->data == value) { 
        // Since the curr is the required value Unlink currNode from linked list 
                prev->next = curr->next; 
                finalSongList.erase(value);
         // Display the message 
                cout << value << " is deleted" << '\n'; 
                break; 
            } 
            else { 
                // If current value is not the value to be deleted continue to next node 
                prev = curr; 
                curr = curr->next; 
            } 
        } 

         if (curr == nullptr) { 
            // Display the message 
            cout << value << " not found in the linkedlist" << '\n';
        } 

}

//To modify artist name in map
void modifyArtist()
{
        string songName;
        string modifiedArtist;

        cout << "Enter the name of song whose artist you want to modify(case-sensitive)" << '\n';
        cin.ignore();
        getline(cin, songName);

        cout << '\n' << "Enter the new name of artist:" << '\n';
        // cin.ignore();
         getline(cin, modifiedArtist);
        finalSongList.at(songName).setArtist(modifiedArtist);

        cout << '\n' << "The final list is: " << '\n';
        for (const auto& pair: finalSongList) {
		  cout << "{" << pair.first << ": " << pair.second.getArtist()<<"}\n";

      }
}

void songList(){

      string songName;
      string artist;
      
      cout<< "Please enter song name: " <<'\n';
      cin.ignore();
      getline(cin, songName);

      cout<< "Please enter artist name: " <<'\n';
     // cin.ignore();
      getline(cin, artist);
      transform(artist.begin(), artist.end(), artist.begin(), ::tolower); 

      insert(songName);
      finalSongList.insert({songName,songs(songName,artist)});
}


int main()
{
  
  int choice ;
  string wantToContinue = "Yes";

//while loop to prompt user to select a choice. The while loop reset the question once the user is done and continues to run till user want to continue
 while(wantToContinue == "Yes" || wantToContinue == "yes"){

    cout << '\n' << "Create your own playlist. Please type option to continue(1 ? 2 ? 3 ? 4 ? 5)" << '\n';
      cout<< "1. Enter song Information"<<'\n';
      cout<<"2. Show the final song list" << '\n';
      cout<<"3. Show the final song list with artist" << '\n';
      cout<<"4. Modify the artist of any song" << '\n';
      cout<<"5. To delete any song from the list" << '\n' << '\n';
      cin >> choice;

      if(choice == 1){
        songList();

      }

      else if(choice == 2){
        printList();
      }

      else if(choice == 3){
              if(finalSongList.empty()){
                cout << "List is empty" <<'\n';
              }
                for (const auto& pair: finalSongList) {
		            cout << "{" << pair.first << ": " << pair.second.getArtist()<<"}\n";
      }
      }

      else if(choice == 4){
          modifyArtist();
      }

      else if(choice == 5){
        string songName;
        cout << "Enter name of song(case-sensitive)";
        cin.ignore();
        getline(cin,songName);
        deleteValue(songName);
        printList();
      }

      cout <<'\n' <<"Do you want to go back to Options?(Yes ? No)" <<'\n';
      cin >> wantToContinue;
      }
  
 }
  
