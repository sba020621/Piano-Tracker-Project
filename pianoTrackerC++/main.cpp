/*
Author: Shane Arwood
Compiler: GNU GCC
Date: Started 06/18/2021
Purpose of program: The program reads in a file containing the user’s records
of piano practice (name of piece, composer, and minutes practiced). The program
can sort and display the records by minutes practiced or in alphabetical order by
composer or piece name.
*/

#include <iostream>
#include <string>
#include "MusicPiece.h"
#include <fstream>

using namespace std;

// Prototype for function to conduct linear search for a piece the user wants to adjust minutes practiced of
int linearSearch(const MusicPiece *, int, string);

// Prototypes for functions to sort the pieces practiced
void sortByPiece (MusicPiece *, int);
void sortByComposer (MusicPiece *, int);
void sortByMinutes (MusicPiece *, int);

// Main function
int main()
{
    string fileName; // File containing practice records
    ifstream inputFile; // Define file stream object
    int numRecords = 0; // Number of pieces practiced (number of piece records in the file)

    // Information on records read from file, used in the setPieceInformation function to populate
    // the array of MusicPiece objects
    string pieceName;
    string composerName;
    int minutesPracticed;

    int userChoice; // user choice from menu (1, 2, or 3)

    // Variables for when user chooses 3 (add to minutes practiced)
    int minutesChange; // Amount user wants to add to practice time
    int positionOfPiece; // The index where the piece the user wants to alter the practice time of is found
    int newMinutes; // Updated minutes practiced

    // Prompt the user for a file name
    cout << "Enter the file name containing practice records: ";
    cin >> fileName;

    inputFile.open(fileName); // open file
    if (!inputFile) // file could not be opened, exit
    {
        cout << "Could not open file\nExiting\n";
        return 0;
    }
    else // File open successful
    {
        // Read the file to determine number of practice records in the file
        while (inputFile >> pieceName >> composerName >> minutesPracticed)
        {
            // Increment record counter
            numRecords++;
        }
    } // End case file open successful

    // Display number of records read from file
    cout << "\nThere are " << numRecords << " pieces practiced.\n";

    // Dynamically allocate an array of MusicPiece objects
    MusicPiece * piecePtr = new MusicPiece [numRecords];

    // Close and reopen file to reposition read pointer to the beginning of the file
    inputFile.close();
    inputFile.open(fileName);

    // Populate the dynamically allocated array with the items read from the file
    int i = 0;
    while (inputFile >> pieceName >> composerName >> minutesPracticed)
    {
        piecePtr[i].setPieceInformation(pieceName, composerName, minutesPracticed);
        i++;
    }

    // Print the array
    cout << "\nCurrent practice records\n"
            "-----------------------\n";
    for (int i = 0; i < numRecords; i++)
    {
        cout << piecePtr[i].getPieceName() << " by " << piecePtr[i].getComposerName()
             << ", " << piecePtr[i].getMinutesPracticed() << " minutes practiced."
             << endl;
    } // end print the array

    // print menu and prompt user to choose
    cout << "\nMenu\n"
            "----\n"
            "1->Show records in alphabetical order by piece name\n"
            "2->Show records in alphabetical order by composer name\n"
            "3->Show records sorted by minutes practiced\n"
            "4->Add to minutes practiced\n"
            "6->Exit\n";
    cin >> userChoice;

    // PROCESS USER CHOICE

    while ((userChoice == 1) || (userChoice == 2) || userChoice == 3 || userChoice == 4) // user doesn't want to exit program
    {
        if (userChoice == 1) // user chose to show records in alphabetical order by piece name
        {
            // Call function to sort array of music objects alphebetically by piece name
            sortByPiece(piecePtr, numRecords);

            // Show the sorted pieces
            cout << "\nPieces practiced in alphabetical order by piece name\n"
                    "----------------------------------------------------\n";
            for (int i = 0; i < numRecords; i++) {
                cout << piecePtr[i].getPieceName() << " by " << piecePtr[i].getComposerName()
                     << ", " << piecePtr[i].getMinutesPracticed() << " minutes practiced."
                     << endl;
            } // end print the array
        } // end case user chose 1

        else if (userChoice == 2) // user chose to show records in alphabetical order by composer name
        {
            // Call function to sort array of music objects alphebetically by composer name
            sortByComposer(piecePtr, numRecords);

            // Show the sorted pieces
            cout << "\nPieces practiced in alphabetical order by composer name\n"
                    "-------------------------------------------------------\n";
            for (int i = 0; i < numRecords; i++) {
                cout << piecePtr[i].getPieceName() << " by " << piecePtr[i].getComposerName()
                     << ", " << piecePtr[i].getMinutesPracticed() << " minutes practiced."
                     << endl;
            } // end print the array
        } // end case user chose 2

        else if (userChoice == 3) // user chose to show records sorted by minutes practiced
        {
            // Call function to sort array of music objects alphebetically by composer name
            sortByMinutes(piecePtr, numRecords);

            // Show the sorted pieces
            cout << "\nPieces practiced in order by minutes practiced\n"
                    "----------------------------------------------\n";
            for (int i = 0; i < numRecords; i++) {
                cout << piecePtr[i].getPieceName() << " by " << piecePtr[i].getComposerName()
                     << ", " << piecePtr[i].getMinutesPracticed() << " minutes practiced."
                     << endl;
            } // end print the array

        } // end case user chose 3

        else if (userChoice == 4)
        {
            // prompt user for name of the piece they want to add minutes to
            cout << "Enter the piece name: ";
        cin >> pieceName;

        // call function for linear search to find index where the PLU is located
        positionOfPiece = linearSearch(piecePtr, numRecords, pieceName);

        if (positionOfPiece == -1) // no matching plu was found, display error message
            cout << "Piece name not found in the records\n";
        else // a matching plu was found
        {
            // prompt user to enter amount they want to add
            cout << "Enter amount of minutes to add to practice time: ";
            cin >> minutesChange;

            if (minutesChange <= 0) // user entered invalid amount
                cout << "Minutes must be > 0\n";
            else // user input valid amount
            {
                // add minutesChange to the corresponding minutes practiced of the piece they entered
                newMinutes = piecePtr[positionOfPiece].getMinutesPracticed() + minutesChange;
                piecePtr[positionOfPiece].setMinutesPracticed(newMinutes);

                // Display updated records
                cout << "\nUpdated practice records\n"
                        "-----------------------\n";
                for (int i = 0; i < numRecords; i++) {
                    cout << piecePtr[i].getPieceName() << " by " << piecePtr[i].getComposerName()
                         << ", " << piecePtr[i].getMinutesPracticed() << " minutes practiced."
                         << endl;
                } // end print the array
            } // end case user input valid amount to add
        } // end case a matching piece name was found
    } // end case user chose 4

        // print menu and prompt user to choose
        cout << "\nMenu\n"
                "----\n"
                "1->Show records in alphabetical order by piece name\n"
                "2->Show records in alphabetical order by composer name\n"
                "3->Show records sorted by minutes practiced\n"
                "4->Add to minutes practiced\n"
                "5->Exit\n";
        cin >> userChoice;
    } // end loop to process user choice and display menu again

    // user chose 5 (loop was exited), exit program
    inputFile.close(); // close file
    delete [] piecePtr; // delete dynamically allocated memory
    return 0;
} // End function main()

// This function takes the piecePtr, number of records, and the name of the piece the user wants to
// alter the minutes practiced of as arguments, searches for the searchValue (name of the piece) in the array
// of music piece objects and returns the position where the piece was found
int linearSearch(const MusicPiece * piecePtr_, int siz, string searchValue)
{
    int index = 0, position = -1;
    bool notFound = true;
    while (index < siz && notFound)
    {
        if (piecePtr_[index].getPieceName() == searchValue)
        {
            notFound = false;
            position = index;
        }
        index++;
    }
    return position;
} // end function linearSearch

// This function does selection sort on the array of music piece objects.
// It compares the names of the pieces and uses the swap function to
// put the pieces in order, with the piece that comes first in the alphabet
// being first in the sorted array.
void sortByPiece (MusicPiece * piecePtr_, int siz)
{
    int startScan, minIndex;
    string minValue;

    for (startScan = 0; startScan < (siz - 1); startScan++)
    {
        minIndex = startScan;
        minValue = piecePtr_[startScan].getPieceName();
        for (int index = startScan + 1; index < siz; index++)
        {
            if (piecePtr_[index].getPieceName() < minValue)
            {
                minValue = piecePtr_[index].getPieceName();
                minIndex = index;
            }
        }

       swap(piecePtr_[minIndex], piecePtr_[startScan]);
    }
} // End function sortByPiece

// This function does selection sort on the array of music piece objects.
// It compares the composer names of the pieces and uses the swap function to
// put the pieces in order, with the composer that comes first in the alphabet
// being first in the sorted array.
void sortByComposer (MusicPiece * piecePtr_, int siz)
{
    int startScan, minIndex;
    string minValue;

    for (startScan = 0; startScan < (siz - 1); startScan++)
    {
        minIndex = startScan;
        minValue = piecePtr_[startScan].getComposerName();
        for (int index = startScan + 1; index < siz; index++)
        {
            if (piecePtr_[index].getComposerName() < minValue)
            {
                minValue = piecePtr_[index].getComposerName();
                minIndex = index;
            }
        }

        swap(piecePtr_[minIndex], piecePtr_[startScan]);
    }
} // End function sortByComposer

// This function does selection sort on the array of music piece objects.
// It compares the composer names of the pieces and uses the swap function to
// put the pieces in order, with the composer that comes first in the alphabet
// being first in the sorted array.
void sortByMinutes (MusicPiece * piecePtr_, int siz)
{
    int startScan, minIndex;
    int minValue;

    for (startScan = 0; startScan < (siz - 1); startScan++)
    {
        minIndex = startScan;
        minValue = piecePtr_[startScan].getMinutesPracticed();
        for (int index = startScan + 1; index < siz; index++)
        {
            if (piecePtr_[index].getMinutesPracticed() < minValue)
            {
                minValue = piecePtr_[index].getMinutesPracticed();
                minIndex = index;
            }
        }

        swap(piecePtr_[minIndex], piecePtr_[startScan]);
    }
} // End function sortByMinutes