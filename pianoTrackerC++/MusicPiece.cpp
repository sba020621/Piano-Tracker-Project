/*
Author: Shane Arwood
Compiler: GNU GCC
Date: Started 06/18/2021
This file contains the function description of all the MusicPiece member functions
 */

#include "MusicPiece.h"
#include <string>

using namespace std;

// This function takes the piece name, composer name, and minutes practiced members as arguments and assigns values to them
void MusicPiece::setPieceInformation(string piece_, string composer_, int minutes_)
{
    pieceName = piece_;
    composerName = composer_;
    minutesPracticed = minutes_;
} // end function setProductAttributes

// This function returns the content in the piece name member
string MusicPiece::getPieceName() const
{
    return pieceName;
} // End function getPieceName()

// This function returns the content in the composer name member
string MusicPiece::getComposerName() const
{
    return composerName;
} // end function getComposerName()

// This function returns the value in the minutes practiced member
int MusicPiece::getMinutesPracticed() const
{
    return minutesPracticed;
} // end function getMinutesPracticed()

void MusicPiece::setMinutesPracticed(int minutes_)
{
    minutesPracticed = minutes_;
} // end function setMinutesPracticed