#include "media.h"

void mediaFile() {
    clearScreen();
    cout << "********** Media Players **********" << endl;

    MediaFile* file0 = new MediaFile("Sandisk", 4);
    file0->play();
    MediaFile* file1 = new AudioFile(28, "Sandisk", 4);
    file1->play();
    MediaFile* file2 = new VideoFile(1080, "Sandisk", 4);
    file2->play();
    pauseScreen();
}