//
//  main.cpp
//  TestingProject
//
//  Created by Zhenhua Cai on 7/4/18.
//  Copyright © 2018 Zhenhua Cai. All rights reserved.
//

#include <iostream>
#include "game.hpp"
using namespace std;

int main(int argc, char * argv[]) {
    Game g;
    bool sucess=g.initGame();
    if(sucess){
        g.runLoop();
    }
    g.exit();
    return 0;
}
