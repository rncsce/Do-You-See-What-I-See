#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include <fstream>
#include <sstream>
#include <string>
#include "MonoStack.h"

class SpeakerView{
    public:
        // Overloaded Constructor
        SpeakerView(const string& file);
        // Default Decunstructor
        ~SpeakerView();
        // compareHeights Function: reads file data and creates monostack for each column using countSeats and createMStack helper functions
        void compareHeights(); 
    private:
        // inFile: file stream to read file
        ifstream inFile;
        // line: string to store file lines
        string line;
        // num: double to store from string stream // Automatically converted with string stream
        double num;
        // rowCount: number of rows in file read
        int rowCount;
        // columnCount: number of columns in rile read
        int columnCount;
        // countSeats Function: reads file, setting column and row count
        void countSeats();
        // createMStack Function: creates stack 
        void createMStack(int nth);
        // printResults Function: prints out stack elements to terminal
        void printResults(int col, MonoStack<double> monoStack);
};
#endif
