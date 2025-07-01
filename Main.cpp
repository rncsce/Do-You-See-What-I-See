#include "SpeakerView.h"

int main(int argc, char** argv){

    string inputFile = argv[1];
    SpeakerView SpeakerView(inputFile);
    SpeakerView.compareHeights();

    return 0;
}
