#include "SpeakerView.h"

// Default Constructor
SpeakerView::SpeakerView(const string& file) : inFile(file){ // Takes in string of file name parameter and initializes file stream
    rowCount = 0; // Set row count to 0
    columnCount = 0; // Set column count to 0
}
// Default Deconstructor
SpeakerView::~SpeakerView(){
    if(inFile.is_open()){ // If file is open
        inFile.close(); // Close file
    }
}
// compareHeights Function
void SpeakerView::compareHeights(){
    countSeats(); // Read file data, counting rows and columns
    for (int i = 0; i < columnCount; i++){ // Iterate for number of columns
        createMStack(i); // Create a Monotonic Stack for each column
    }

}
// countSeats Function
void SpeakerView::countSeats(){
    if(inFile.is_open()){ // If file is open
        while(getline(inFile, line)){ // While getline access line separated by newline from file
            if(line != "BEGIN" && line != "END"){ // If file line isn't BEGIN or END
                stringstream ss(line); // Open string stream for line
                columnCount = 0; // Reset column count to 0 // To only keep the count one row of columns
                while(ss >> num){ // While string stream reads numbers separated by space
                    ++columnCount; // Increase column count by 1
                }
                ++rowCount; // Increase row count by 1
            } 
        }
    } else { // If file is not open
        cout << "Error Reading File." << endl; // Output error statement
    }
}
// createMStack Function
void SpeakerView::createMStack(int nth){ // Parameter: the column/index to access data for
    MonoStack<double> tempStack(rowCount); // Temporary Stack // To temporarily store elements, to pop from and push to new Mono Stack // Ensure elements are in bottom to top order from the file data's order
    MonoStack<double> monoStack(rowCount); // Mono Stack
    int index = 0; // Set index to traverse through file data
    if(inFile.is_open()){ // If file is open
        inFile.clear(); // Clear file stream
        inFile.seekg(0, inFile.beg); // Restart reading file from beginning, to read file a second time
        while(getline(inFile, line)){ // While getline accesses file lines separated by new lines
            if (line != "BEGIN" && line != "END"){ // If the line isn't BEGIN or END
            stringstream ss(line); // Reads string as stream
            while(ss >> num){ // Reads data from string string separated by spaces, storing as a double, num
                if(index == nth){ // If traversed through is equal to the current column 
                    tempStack.push(num, 's'); // Push double, num read onto temporary stack, with s character parameter, to use traditional stack push function
                    break; // Once element of column is found break out of loop, to iterate through next rows line
                }
                ++index; // Increase index by 1 (traversing through row)
            }
            index = 0; // Reset index to 0, before accessing next row line
            }
        }
    } else { // If file is not open
        cout << "Error Reading File." << endl; // Output error statement
    }
    for (int i = 0; i < rowCount; i++){ // Iterate for number of rows (number of elements in column)
        monoStack.push(tempStack.pop(), 'i'); // Push popped element from temporary stack, in increasing Monotonic Stack
    }
    printResults(nth, monoStack); // Output results for current column's Mono Stack with printResults helper function
}
// printResults Function
void SpeakerView::printResults(int col, MonoStack<double> monoStack){ // Parameters: column # for output statement, monoStack object
    cout << "In column " << col << " there are " << monoStack.size() << " who can see. Their heights are "; // Output column number and output statement
    int size = monoStack.size(); // Declare + initialize variable to size of monoStack // Size will change after popping
    for (int i = 0; i < size; i++){ // Iterate size times
        cout << monoStack.pop(); // Output monoStack element to terminal
        if (!monoStack.isEmpty()){ // If the monoStack is not empty
            cout << ", "; // Add a comma after the element outputted
        }
    }
    cout << " inches." << endl; // Output unit, once all in stack/column in increasing order from stage (who can see) are iterated through and outputted
}
