#pragma once
#include "ofMain.h"
#include "noteList.h"
#include <vector>

class Note {
private:
    ofRectangle* ofRect;
    int coordX;
    int coordY;

public:
    Note(ofRectangle* ofRect, int coordX, int coordY);
    Note();
    ofRectangle* getOfRectangle();
    int getCoordX();
    int getCoordY();
    
    void setUpNote();
    
    //NoteList noteList;
};
