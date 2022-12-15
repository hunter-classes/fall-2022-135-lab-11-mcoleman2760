#pragma once
#include <iostream>
#include <string>
#include "profile.h"


class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  bool following[MAX_USERS][MAX_USERS];
  int findID (std::string usrn);
  
public:
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
    bool addUser(std::string usrn, std::string dspn);
    bool follow(std::string usrn1, std::string usrn2);
    void printDot();
};
