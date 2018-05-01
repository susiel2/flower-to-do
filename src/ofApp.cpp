#include "ofApp.h"
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

#include <iostream>

void window::setup() {
  ofSetWindowTitle("Flower Productivity");
  ofBackground(230,230,230);
  flower.loadModel("flower.obj");
    current_status = THRIVING;

    typeStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz\n0123456789,:&!?";
}

void window::keyPressed(int key) {

    if (key == 'n') {
//        Status prior = current_status;
      current_status = NEW_NOTE;
        //current_status = prior;
        //checkboxList.mouseInside();
        //checkboxList.mousePressedInside(<#int x#>, <#int y#>, <#int button#>)

//    } else if (key == OF_KEY_F12) {
//      ofToggleFullscreen();
//
//    } else if (current_status == NEW_NOTE) {
//      if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
//      typeStr = typeStr.substr(0, typeStr.length()-1);
//
//      } else if(key == OF_KEY_RETURN ){
//        current_status = THRIVING;
//
//      } else {
//        ofAppendUTF8(typeStr,key);
//      }
    }
}

//Note* window::getNote(int rectangleNum) {
//    for (int i = 0; i < notes.size(); i++) {
//        if (i == rectangleNum) {
//            return notes[i];
//        }
//    }
//}
//
//bool window::mouseInside(int rectangleNum) {
//    int mouseX = ofGetMouseX();
//    int mouseY = ofGetMouseY();
//
//    if (mouseX > rectangleNum * 210 && mouseX < rectangleNum * 210 + 200) {
//        if (mouseY > )
//    }
//
//}

//void window::mousePressed(int x, int y, int button) {
//    if (button == 0) {
//        for (int i = 0; i < notes.size(); i++) {
//
//        }
//    }
//}

void window::mousePressed(int x, int y, int button) {
    cout << noteList.mousePressedInside(x, y, 0);
    if (noteList.mousePressedInside(x, y, 0) != -1) {
        current_status = DELETE_NOTE;
    }
}

void window::draw() {
  flower.setPosition(ofGetWidth()*3/4, (float)ofGetHeight() * 0.75 , 0);
    ofEnableDepthTest();
    ofEnableLighting();
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    glDisable(GL_COLOR_MATERIAL);

    ofPushMatrix();

    flower.enableMaterials();
    flower.drawFaces();

    ofPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_NORMALIZE);
    glDisable(GL_LIGHTING);
    
    noteList.drawNotes();

    if (current_status == NEW_NOTE) {
        noteList.addNote();
        current_status = THRIVING;
    }
    
    else if (current_status == DELETE_NOTE) {
        std::cout << "hi";
        noteList.removeNote(mouseX, mouseY);
        current_status = THRIVING;
    }
}
