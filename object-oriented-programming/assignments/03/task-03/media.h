#include "../main.h"

class MediaFile {
protected:
    string m_fileName;
    int m_duration;
public:
    MediaFile(const string& fileName = "", int duration = 0);
    virtual void play();
};

class AudioFile :public MediaFile {
private:
    int m_bitRate;
public:
    AudioFile(int bitRate = 0, const string& fileName = "", int duration = 0);
    void play() override;
};

class VideoFile :public MediaFile {
private:
    int m_resolution;
public:
    VideoFile(int resolution = 0, const string& fileName = "", int duration = 0);
    void play() override;
};