#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "profile.h"
#include "network.h"
#include "doctest.h"


TEST_CASE ("Profile Class"){

Profile prof1("Mike", "michael");
CHECK(prof1.getUsername() == "Mike");
CHECK(prof1.getFullName() == "michael (@Mike)");
prof1.setDisplayName("michael coleman");
CHECK(prof1.getFullName() == "michael coleman (@Mike)");


} 

TEST_CASE ("Network Class") {
    Network nw;
    CHECK(nw.addUser("player1", "Jeff") == true);
    CHECK(nw.addUser("player1", "Jeff") == false);
    CHECK(nw.addUser("#play", "John") == false);
    CHECK(nw.addUser("newcharacter", "Jake") == true);
    CHECK(nw.addUser("lastplayer", "Jamal") == true);

    CHECK(nw.follow("player1", "newcharacter") == true);
    CHECK(nw.follow("player1", "who") == false);
    CHECK(nw.follow("player1" , "lastplayer") == true);



}
