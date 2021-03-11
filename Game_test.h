//
// Created by Jared on 3/10/2021.
//
#ifndef FINAL_PROJECT_DMIRZ001_JTANU002_FQUIR007_CWONG165_1_GAME_TEST_H
#define FINAL_PROJECT_DMIRZ001_JTANU002_FQUIR007_CWONG165_1_GAME_TEST_H
#include "gtest/gtest.h"
#include "Game.h"

using namespace std;


TEST(getCoordinates, cornerToCorner) {
    Game chessGame;
    string start = "a1";
    pair<int, int> coordinates;
    coordinates = chessGame.getCoordinates(start);
    EXPECT_EQ(coordinates.first, 7);
    EXPECT_EQ(coordinates.second, 0);
}

TEST(getCoordinates, cornerToCorner2) {
    Game chessGame;
    string end = "h8";
    pair<int, int> coordinates;
    coordinates = chessGame.getCoordinates(end);
    EXPECT_EQ(coordinates.first, 0);
    EXPECT_EQ(coordinates.second, 7);
}

TEST(getCoordinates, cornerToCorner3) {
    Game chessGame;
    string start = "a8";
    pair<int, int> coordinates;
    coordinates = chessGame.getCoordinates(start);
    EXPECT_EQ(coordinates.first, 0);
    EXPECT_EQ(coordinates.second, 0);
}

TEST(getCoordinates, cornerToCorner4) {
    Game chessGame;
    string end = "h1";
    pair<int, int> coordinates;
    coordinates = chessGame.getCoordinates(end);
    EXPECT_EQ(coordinates.first, 7);
    EXPECT_EQ(coordinates.second, 7);
}

TEST(validateInput, validInput1){
    Game chessGame;
    EXPECT_EQ(chessGame.validateInput("e2"), true);
}

TEST(validateInput, validInput2){
    Game chessGame;
    EXPECT_EQ(chessGame.validateInput("h7"), true);
}

TEST(validateInput, validInputCapital){
    Game chessGame;
    EXPECT_EQ(chessGame.validateInput("E4"), true);
}

TEST(validateInput, invalidInputEmpty){
    Game chessGame;
    EXPECT_EQ(chessGame.validateInput(""), false);
}

TEST(validateInput, invalidInput1){
    Game chessGame;
    EXPECT_EQ(chessGame.validateInput("asd;lfkj alsdfka"), false);
}

TEST(validateInput, invalidInput2){
    Game chessGame;
    EXPECT_EQ(chessGame.validateInput("e 2"), false);
}

TEST(validateInput, invalidInput3){
    Game chessGame;
    EXPECT_EQ(chessGame.validateInput("7D"), false);
}

TEST(validateInput, invalidInput4){
    Game chessGame;
    EXPECT_EQ(chessGame.validateInput("\n"), false);
}

#endif //FINAL_PROJECT_DMIRZ001_JTANU002_FQUIR007_CWONG165_1_GAME_TEST_H
