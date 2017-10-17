#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    status = 0;
    intro.load("opening.mp3");
    intro.setLoop(true);
    intro.setVolume(1.0f);
    battle.load("battle.mp3");
    battle.setLoop(true);
    battle.setVolume(1.0f);
    
    s[START_SCREEN] = new StartScreen();
    s[CHOICE_SCREEN] = new ChoiceScreen();
    s[INTRO_SCREEN_B] = new IntroScreenB();
    s[INTRO_SCREEN_C] = new IntroScreenC();
    s[INTRO_SCREEN_S] = new IntroScreenS();
    s[BATTLE_SCREEN_B] = new BattleScreenB();
    s[BATTLE_SCREEN_C] = new BattleScreenC();
    s[BATTLE_SCREEN_S] = new BattleScreenS();
    s[PAUSE_SCREEN] = new PauseScreen();
    s[WIN_SCREEN] = new WinScreen();
    s[OVER_SCREEN] = new OverScreen();
    
    intro.play();

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    s[status]->display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'p' and status not_eq PAUSE_SCREEN)
    {
        previous = status;
        status = PAUSE_SCREEN;
        return;
    }

    if (status == START_SCREEN)
    {
        status = CHOICE_SCREEN;
    }
    
    if (key == 'b')
    {
        intro.unload();
        battle.play();
        battle.setLoop(true);
        if (status == INTRO_SCREEN_B)
        {
            status = BATTLE_SCREEN_B;
        }
        if (status == INTRO_SCREEN_C)
        {
            status = BATTLE_SCREEN_C;
        }
        if (status == INTRO_SCREEN_S)
        {
            status = BATTLE_SCREEN_S;
        }
    }
    
    if ((status == BATTLE_SCREEN_B or status == BATTLE_SCREEN_C or status == BATTLE_SCREEN_S) && key == 'q')
    {
        s[OVER_SCREEN]->setLosses((s[OVER_SCREEN]->getLosses() + 1));
        s[WIN_SCREEN]->setLosses((s[WIN_SCREEN]->getLosses() + 1));
        status = OVER_SCREEN;
    } else if ((status == BATTLE_SCREEN_B or status == BATTLE_SCREEN_C or status == BATTLE_SCREEN_S) && key == 'w')
    {
        s[WIN_SCREEN]->setWins((s[WIN_SCREEN]->getWins() + 1));
        s[OVER_SCREEN]->setWins((s[OVER_SCREEN]->getWins() + 1));
        status = WIN_SCREEN;
    }
    
    if ((status == OVER_SCREEN or status == WIN_SCREEN) && key == ' ')
    {
        status = START_SCREEN;
    }
    
    if (status == PAUSE_SCREEN && key == 'r')
    {
        status = previous;
        previous = -1;
    }
    
    if (key == 'e')
    {
        for (int i = 0; i < 11; i++)
        {
            delete s[i];
        }
        status = 0;
        std::exit(0);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (status == CHOICE_SCREEN)
    {
        if (100 <= mouseX && mouseX <= 400 && 0 <= mouseY && mouseY <= 215)
        {
            //cout<<"Bulbasaur"<<endl; //cout check
            status = INTRO_SCREEN_B;
            
        }
        else if (100 <= mouseX && mouseX <= 400 && 225 <= mouseY && mouseY <= 440)
        {
            //cout<<"Charmander"<<endl; //cout check
            status = INTRO_SCREEN_C;
        }
        else if (100 <= mouseX && mouseX <= 400 && 450 <= mouseY && mouseY <= 700)
        {
            //cout<<"Squirtle"<<endl; //cout check
            status = INTRO_SCREEN_S;
        } else
        {
            cout<<"Nothing chosen"<<endl;
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
