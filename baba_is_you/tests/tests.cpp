/* **********************************************************
 * Testing the model in the AAA format (Arrange, Act Assert)
 * **********************************************************/

#include <iostream>
#include <cassert>
#include "tests/tests.h"
#include "model/enums.h"
#include "model/board.h"
#include "model/tile.h"
#include "model/component.h"
#include "model/material.h"
#include "model/direction.h"
#include "model/enums.h"

void testBoard()
{
    //arrange
    unsigned int level_number = 0;
    Board board { level_number };

    //act
    unsigned int result1 = board.getNrLevel();
    unsigned int expected1 = level_number;
    //assert
    assert(result1 == expected1 && "getNrLevel() level 0 : test failed");

    //arrange
    Board boardLevel3 { 3 };
    //act
    unsigned int result4 = boardLevel3.getNrLevel();
    unsigned int expected4 = 3;
    //assert
    assert(result4 == expected4 && "getNrLevel() level 3 : test failed");

    //act
    bool result2 = board.isWinReached();
    bool expected2 = false;
    //assert
    assert(result2 == expected2 && "isWinReached() : test failed");

    //act
    bool result3 = board.isYouKilled();
    bool expected3 = false;
    // assert
    assert(result3 == expected3 && "isYouKilled() : test failed");

    //arrange
    Board boardA { 0 };
    //act
    boardA.checkRules();
    //assert
    std::list<Rule> expected5 {
      {MaterialType::BABA, Property::IS_YOU},
      {MaterialType::ROCK, Property::IS_PUSH},
      {MaterialType::FLAG, Property::IS_WIN},
      {MaterialType::WALL, Property::IS_STOP},
    };
    std::list<Rule> result5 = board.getRules();
    //assert
    assert(result5 == expected5 && "checkRules(): test failed");



    std::cout << "All Board tests passed!\n";
}

void testTile()
{
    //arrange
    Tile tile {};
    std::string s = "rock";
    Position p { 1, 1};
    Direction d = Direction::DOWN;
    Material comp1 { s, p, d };
    tile.addComponent(comp1);
    //act
    auto result1 = tile.getComponents();
    auto expectedSize = 1;
    //assert
    assert(result1.size() == expectedSize && "addComponent() 1 : test failed");

    //arrange
    std::string s2 = "wall";
    Position p2 { 1, 1 };
    Direction d2 = Direction::DOWN;
    Material comp2 { s2, p2, d2 };
    tile.addComponent(comp2);
    //act
    auto result2 = tile.getComponents();
    auto expectedSize2 = 2;
    //assert
    assert(result2.size() == expectedSize2 && "addComponent() 2 : test failed");

    //arrange
    std::string s3 = "you";
    Position p3 { 1, 1 };
    Direction d3 = Direction::UP;
    Material comp3 { s3, p3, d3 };
    tile.addComponent(comp3);
    //act
    auto result3 = tile.getComponents();
    auto expectedSize3 = 3;
    //assert
    assert(result3.size() == expectedSize3 && "addComponent() 3 : test failed");

    //act
    auto result4 = tile.getYouComponents();
    auto expectedSize4 = 1;
    //assert
    assert(result4.size() == expectedSize4 && "getYouComponents() 1 : test failed");

    //act
    std::string s4 = "you";
    Position p4 { 1, 1 };
    Direction d4 = Direction::UP;
    Material comp4 { s4, p4, d4 };
    tile.addComponent(comp4);
    std::string s5 = "you";
    Position p5 { 1, 1 };
    Direction d5 = Direction::UP;
    Material comp5 { s5, p5, d5 };
    tile.addComponent(comp5);
    auto result5 = tile.getYouComponents();
    auto expectedSize5 = 3;
    //assert
    assert(result5.size() == expectedSize5 && "getYouComponents() 2 : test failed");



    std::cout << "All Tile tests passed!\n";
}

void testComponent()
{
    //arrange
    std::string s = "rock";
    Position p { 1, 1};
    Direction d = Direction::DOWN;
    Material comp1 { s, p, d };
    //act
    MaterialType result = comp1.getType();
    MaterialType expected = MaterialType::ROCK;
    //assert
    assert(expected == result && "getType() : test failed");

    //arrange
    comp1.addProperty(Property::IS_PUSH);
    //act
    auto result2 = comp1.getProperties().size();
    auto expected2 = 1;
    //assert
    assert(expected2 == result2 && "addProperty() and getProperties() : test failed");

    std::cout << "All Component tests passed!\n";
}

void testing()
{
    testBoard();
    testTile();
    testComponent();
}
