//
// Created by Shane Arwood on 11/22/21.
//

#ifndef PIANOTRACKER_MUSICPIECE_H
#define PIANOTRACKER_MUSICPIECE_H

#endif //PIANOTRACKER_MUSICPIECE_H

#include <iostream>
#include <string>

using namespace std;

class MusicPiece
{
private:
    string pieceName;
    string composerName;
    int minutesPracticed;
public:
    void setPieceInformation(string, string, int);
    void setMinutesPracticed(int);
    string getPieceName() const;
    string getComposerName() const;
    int getMinutesPracticed() const;
};