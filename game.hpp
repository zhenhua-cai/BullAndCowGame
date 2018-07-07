//
//  game.hpp
//  TestingProject
//
//  Created by Zhenhua Cai on 7/7/18.
//  Copyright © 2018 Zhenhua Cai. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

class Game{
private:
    enum{TOTAL=10};
    int * secret;
    char * guess;
    int digits[10];
    int bull;
    int cow;

    int count;
    int length;
    bool isRunning;
    
    bool update();
    void printIntro();
    void generateData();
    bool process();
public:
    Game();
    Game(int l);
    bool initGame();
    void runLoop();
    void exit();
    ~Game();
};
#endif /* game_hpp */
