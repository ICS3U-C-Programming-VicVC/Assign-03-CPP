// Copyright (c) 2026 Victor V-C Name All rights reserved.
// .
// Created by: Victor Victor Calixte
// Date: 11/3/26
// This program will determine the type of triangle based on 2 given angles.

#include<iostream>
#include<string>

char const WELCOMING_MSG[] =
("Welcome to angle_to_type.py!"
" This program will determine the type "
"of triangle based on 2 given angles.\n");

char const ERR_MSG[] =
("are not valid Inputs.\n "
"(MUST BE ANGLES [POSITIVE NUMBERS])!\n");

char const IMPBL_MSG[] =
("are not valid Inputs.\n"
" (NOT POSSIBLE FOR A PROPER TRIANGLE!)\n");

char const EQUILATERAL_TRIANGLE[] =
("The angles given must"
" form an Equilateral Triangle!\n");
char const ISOSCELES_TRIANGLE[] =
("The angles given must "
"form an Isosceles Triangle!\n");

char const SCALENE_TRAINGLE[] =
("The angles given must "
"form a Scalene Triangle!\n");

char const RIGHT_TRIANGLE[] =
("The angles given must "
"form a Right Triangle!\n");

const int ANGLE_90 = 90;
const int ANGLE_180 = 180;

int main() {
    std::string angleAStr;
    std::string angleBStr;

    bool isRight = false;
    bool pbl = false;

    std::cout << WELCOMING_MSG;

    std::cout << "Enter an angle: ";
    std::cin >> angleAStr;

    std::cout << "Enter another angle: ";
    std::cin >> angleBStr;


    try {
        float angleA = std::stoi(angleAStr);
        float angleB = std::stoi(angleBStr);

        float remaining = ANGLE_180 - (angleA + angleB);

        if (angleA >= ANGLE_180 || angleB >= ANGLE_180) {
            std::cout
            << "Angle 1: "
            << angleAStr
            << ", or "
            << angleBStr
            << ", "
            << IMPBL_MSG;
        }

        if (angleA <= 0 || angleB <= 0) {
            std::cout
            << "Angle 1: "
            << angleAStr
            << ", or "
            << angleBStr
            << ", "
            << IMPBL_MSG;
        } else {
            pbl = true;
        }

        if (pbl) {
            if (angleA == ANGLE_90 || angleB == ANGLE_90) {
                std::cout << RIGHT_TRIANGLE;
                isRight = true;
            }


            if (!isRight) {
                if (angleA != angleB) {
                    std::cout << SCALENE_TRAINGLE;
                }

                if (angleA == angleB && angleA == remaining) {
                    std::cout << EQUILATERAL_TRIANGLE;
                }

                if (angleA == angleB && angleA != remaining) {
                    std::cout << ISOSCELES_TRIANGLE;
                }
            }
        }
    } catch(std::invalid_argument) {
        std::cout
        << "Angle 1: "
        << angleAStr
        << ", or "
        << angleBStr
        << ", "
        << ERR_MSG;
    }
}
