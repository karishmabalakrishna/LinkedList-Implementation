#include <iostream>
#include <string>

using namespace std;


class songs{

 private:
   string songName;
   string artist;

  public:
   songs(string name, string a){
     songName = name;
     artist = a;
   }

   void setName(string n){
     songName = n;
   }

   string getName(){
     return songName;
   }

  void setArtist(string a){
     artist = a;
   }

   string getArtist() const{
     return artist;
   }
};