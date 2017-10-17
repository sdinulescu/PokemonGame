#pragma once

#include "ofMain.h"
#include "Screen.hpp"

class ofApp : public ofBaseApp{
    
public:
    const int START_SCREEN = 0;
    const int CHOICE_SCREEN = 1;
    const int INTRO_SCREEN_B = 2;
    const int INTRO_SCREEN_C = 3;
    const int INTRO_SCREEN_S = 4;
    const int BATTLE_SCREEN_B = 5;
    const int BATTLE_SCREEN_C = 6;
    const int BATTLE_SCREEN_S = 7;
    const int PAUSE_SCREEN = 8;
    const int WIN_SCREEN = 9;
    const int OVER_SCREEN = 10;
    
    ofImage bulbasaurImage;
    ofImage charmanderImage;
    ofImage squirtleImage;
    ofImage professor;
    ofTrueTypeFont font;
    
    ofSoundPlayer intro;
    ofSoundPlayer battle;

    int status;

    int previous = -1;
    Screen *s[11];

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};
