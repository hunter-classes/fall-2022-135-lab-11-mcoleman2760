#include <iostream>
#include <string>
#include "network.h"

int Network::findID(std::string usrn){

for (int i=0; i<numUsers; i++) {

if (profiles[i].getUsername() == usrn) {

return i;

}

}

return -1;

}

Network::Network(){
  numUsers = 0;
  for (int i = 0; i< MAX_USERS; i++){
    for(int j = 0; j < MAX_USERS; j++){
      following [i][j] == false;
    }
  } 
}





bool Network::addUser(std::string usrn, std::string dspn) {

bool add = true;

for (int i = 0; i < usrn.length(); i++) {
   if (!isalpha(usrn[i]) && !isdigit(usrn[i])){
     return false;
   }
}

if (numUsers < MAX_USERS && findID(usrn) == -1){
  profiles[numUsers] = Profile(usrn, dspn);
  numUsers++;
  return true;

}


return false;

}



bool Network::follow (std::string usrn1, std::string usrn2){
    int us1 = -1;
    int us2 = -1;
    for (int i = 0; i < numUsers; i++){
      if(profiles[i].getUsername() == usrn1){
        us1 = i;
      }
      if(profiles[i].getUsername() == usrn2){
        us2 = i;
      }
    }
    if (us1 != -1 && us2 != -1){
      following[us1][us2] = true;
      return true;
    }
    return false;
}

void Network::printDot(){
  std::cout << "diagraph {\n";
  for (int i = 0; i < numUsers; i++){
    std::cout << " \"@"  << profiles[i].getUsername() <<  "\"" << std::endl;
  }
  std::cout << "\n";
  for (int i=0; i < numUsers; i++){
    for (int j=0; j < numUsers; j++){
      if (following [i][j]){
        std::cout << " \"@ " << profiles[i].getUsername() << "\"" << " -> " << " \"@ " <<profiles[j].getUsername() <<  "\""  << std::endl;  
      }
    }
  }

std::cout << "}" << std::endl;
}
