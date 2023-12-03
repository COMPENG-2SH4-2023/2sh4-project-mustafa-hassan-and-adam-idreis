#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void updatePlayerDir();
        void movePlayer();
        objPosArrayList* getPlayerPosList();
        void setHasEatenFood(bool hasEaten); // Declare this method
        int getScore() const;
        bool checkSelfCollision(const objPos& newHeadPos) const;

        
        

    private:
        objPosArrayList* playerPosList;
        enum Dir myDir;
        bool hasEatenFood;  // Add this member

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        int score;
};

#endif