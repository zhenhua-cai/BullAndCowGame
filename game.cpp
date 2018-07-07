//
//  game.cpp
//  TestingProject
//
//  Created by Zhenhua Cai on 7/7/18.
//  Copyright © 2018 Zhenhua Cai. All rights reserved.
//

#include "game.hpp"
#include<iostream>
#include<cstdlib>

Game::Game():length(4),isRunning(true),count(0){
    srand(static_cast<int>(time(0)));
    secret=new int[length];
    guess=new char[length+1];
}
void Game::printIntro(){
    std::cout<<"Welcome to Bulls and Cows, a fun number game.\n";
    std::cout<<std::endl;
    std::cout<<"Can you guess the "<<length;
    std::cout<<" digits?(No duplicate!)\n";
    std::cout<<std::endl;
}

void Game::generateData(){
    for(int i=0;i<length;i++){
        int digit=std::rand()%10;
        while(digits[digit]!=0){
            digit=std::rand()%10;
        }
        secret[i]=digit;
        digits[digit]++;
    }
}
bool Game::initGame(){
    for(int &i:digits)
        i=0;
    generateData();
    count=0;
    return true;
}
void Game::runLoop(){
    while(isRunning){
        printIntro();
        initGame();
        if(!update()){
            isRunning=false;
            std::copy(secret,secret+length,std::ostream_iterator<int,char>(std::cout," "));
            break;
        }
        std::cout<<"The digits are: ";
        std::copy(secret,secret+length,std::ostream_iterator<int,char>(std::cout," "));
        std::cout<<"\nDo you want to play again?(Y/N)";
        char again;
        std::cin.get(again);
        again=tolower(again);
        if(again=='n')
            isRunning=false;
        while(std::cin.get()!='\n');
    }
}
void Game::exit(){
    std::cout<<"Have a nice day!"<<std::endl;
}
bool Game::process(){
    bull=cow=0;
    int size=(int)strlen(guess);
    for(int i=0;i<size;i++){
        int digit=guess[i]-48;
        if(digits[digit]){
            if(secret[i]==digit)
                bull++;
            else
                cow++;
        }
    }
    while(std::cin.get()!='\n');
    if(bull==length) return true;
    return false;
}
bool Game::update(){
    while(count<TOTAL){
        std::cout<<"Enter your "<<++count<<" guess(q to quit): ";
        std::cin.get(guess,length+1);
        
        if(tolower(guess[0])=='q') return false;
        if(process()){
            std::cout<<"You win!\n";
            break;
        }
        std::cout<<"Bull: "<<bull<<"\tCow: "<<cow<<std::endl;
    }
    return true;
}
Game::~Game(){
    delete[] guess;
    delete[] secret;
}
