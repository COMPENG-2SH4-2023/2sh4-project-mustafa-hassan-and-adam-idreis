#include "Player.h"


Player::Player(GameMechs* thisGMRef) {
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    score = 0;

    // Create an objPos object for the initial position
    int middleX = mainGameMechsRef->getBoardSizeX() / 2;
    int middleY = mainGameMechsRef->getBoardSizeY() / 2;
    objPos initialPos(middleX, middleY, '@'); // '@' as the symbol for the player

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(initialPos); // Pass the created objPos object
    hasEatenFood = false;
}


int Player::getScore() const {
    if (playerPosList != nullptr) {
        return playerPosList->getSize() - 1; // Return size of playerPosList minus one (to exclude head)
    }
    return 0; // Return 0 if playerPosList is null or empty
}


Player::~Player()
{
    delete playerPosList;
}


objPosArrayList* Player::getPlayerPosList() 
{
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();
    switch (input) {
                case 27:  // ESC key
                    mainGameMechsRef->setExitTrue(); // Set the exit flag in GameMechs
                    break;
                case 'd':
                    if (myDir != LEFT)
                    {
                    myDir = RIGHT;
                    }
                    break;
                case 'a':
                    if (myDir != RIGHT)
                    {
                    myDir = LEFT;
                    }
                    break;
                case 's':
                    if (myDir != UP)
                    {
                        myDir = DOWN;
                    }
                    break;
                case 'w':
                     if (myDir != DOWN)
                    {
                        myDir = UP;
                    }
                    break;
                default:
                    break;
            }
        
        mainGameMechsRef->clearInput();
        
}

void Player::movePlayer() {
    objPos newHead; // Create an objPos object to store the new head position
    
    playerPosList->getHeadElement(newHead); // Get the current head position and store in newHead
        // Update new head position based on current direction

    switch (myDir) {
            case UP:
                newHead.y = (newHead.y - 1 + mainGameMechsRef->getBoardSizeY() - 2) % (mainGameMechsRef->getBoardSizeY() - 2);
                break;
            case DOWN:
                newHead.y = (newHead.y + 1) % (mainGameMechsRef->getBoardSizeY() - 2);
                break;
            case LEFT:
                newHead.x = (newHead.x - 1 + mainGameMechsRef->getBoardSizeX() - 2) % (mainGameMechsRef->getBoardSizeX() - 2);
                break;
            case RIGHT:
                newHead.x = (newHead.x + 1) % (mainGameMechsRef->getBoardSizeX() - 2);
                break;
            default:
                break;
        }

    // Adjusting position if snake head goes over the border
    if (newHead.x <= 0) newHead.x += (mainGameMechsRef->getBoardSizeX() - 2);
    if (newHead.y <= 0) newHead.y += (mainGameMechsRef->getBoardSizeY() - 2);

    if (checkSelfCollision(newHead)) {
        mainGameMechsRef->setLoseFlag();
        return;
    }

    playerPosList->insertHead(newHead);

    if (!hasEatenFood) {
        playerPosList->removeTail();
    } else {
        hasEatenFood = false; // Reset the flag after growing
    }

}


void Player::setHasEatenFood(bool hasEaten) {
    hasEatenFood = hasEaten;
}

bool Player::checkSelfCollision(const objPos& newHeadPos) const {
    for (int i = 1; i < playerPosList->getSize(); ++i) {
        objPos segment;
        playerPosList->getElement(segment, i);
        if (segment.x == newHeadPos.x && segment.y == newHeadPos.y) {
            return true; // Collision detected
        }
    }
    return false; // No collision
}
