#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{

}

GameMechs::GameMechs(int boardX, int boardY) : boardSizeX(boardX), boardSizeY(boardY), input(0), exitFlag(false) {

}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput() {
    if (MacUILib_hasChar() != 0)
        input = MacUILib_getChar();
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::generateFood(objPos *playerPos, objPosArrayList *snakeBody) {
    int newX, newY;
    bool isUniquePos;

    do {
        newX = rand() % boardSizeX;
        newY = rand() % boardSizeY;

        isUniquePos = true;

        // Check against the player position
        if (newX == playerPos->x && newY == playerPos->y) {
            isUniquePos = false;
        }
        
        // Check against the snake body
        for (int i = 0; i < snakeBody->getSize(); ++i) {
            objPos segment;
            snakeBody->getElement(segment, i);
            if (segment.x == newX && segment.y == newY) {
                isUniquePos = false;
                break;
            }
        }
        if (newX == boardSizeX - 1 || newY == boardSizeY - 1) {
            isUniquePos = false;
        }
        else if (newX == 0 || newY == 0) {
            isUniquePos = false;
        }
        // Add more conditions here if necessary, like checking against other game elements

    } while (!isUniquePos);

    foodPos.setObjPos(newX, newY, 'O'); // 'F' for food
}


void GameMechs::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}


