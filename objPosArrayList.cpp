#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() : sizeList(0), sizeArray(200) {
    aList = new objPos[sizeArray];
    for (int i = 0; i < sizeArray; i++) {
        aList[i] = objPos(); // Zero-initialize each element
    }
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos) {
    if (sizeList >= sizeArray) {
        resizeArray(sizeArray * 2); // Double the size
    }
    for (int i = sizeList; i > 0; i--) {
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos) {
    if (sizeList >= sizeArray) {
        resizeArray(sizeArray * 2); // Double the size
    }
    aList[sizeList] = thisPos;
    sizeList++;
}


void objPosArrayList::removeHead() {
    if (sizeList > 0) {
        for (int i = 0; i < sizeList - 1; i++) {
            aList[i] = aList[i + 1];
        }
        sizeList--;
    }
}

void objPosArrayList::removeTail() {
    if (sizeList > 0) {
        sizeList--;
    }
}




void objPosArrayList::getHeadElement(objPos &returnPos) {
    if (sizeList > 0) {
        returnPos = aList[0];
    }
}

void objPosArrayList::getTailElement(objPos &returnPos) {
    if (sizeList > 0) {
        returnPos = aList[sizeList - 1];
    }
}


void objPosArrayList::getElement(objPos &returnPos, int index) {
    if (index >= 0 && index < sizeList) {
        returnPos = aList[index];
    } else {
        returnPos = objPos(); // Return a zero-initialized object for out-of-bound indexes
    }
}

void objPosArrayList::resizeArray(int newCapacity) {
    objPos* newList = new objPos[newCapacity];
    for (int i = 0; i < sizeList; i++) {
        newList[i] = aList[i];
    }
    delete[] aList;
    aList = newList;
    sizeArray = newCapacity;
}
