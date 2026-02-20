#include "media.h"

MediaFile::MediaFile(const string& fileName, int duration) :m_fileName(fileName), m_duration(duration) {}

void MediaFile::play() {
    cout << "Media File" << endl;
}

//_________________________________________________________________________________________

AudioFile::AudioFile(int bitrate, const string& fileName, int duration) : MediaFile(fileName, duration), m_bitRate(bitrate) {}

void AudioFile::play() {
    cout << "Audio File" << endl;
}

//_________________________________________________________________________________________

VideoFile::VideoFile(int resolution, const string& fileName, int duration) : MediaFile(fileName, duration), m_resolution(resolution) {}

void VideoFile::play() {
    cout << "Video File" << endl;
}