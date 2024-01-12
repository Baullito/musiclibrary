#ifndef SONG_H
#define SONG_H

#include <string>

//Song Klasse
class Song {
    public:
        std::string title;
        std::string artist;
        std::string album;
        std::string release;

        Song(std::string songTitle, std::string songArtist, std::string songAlbum, std::string songRelease);

        //Getter Methoden
        const std::string& getTitle() const;
        const std::string& getArtist() const;
        const std::string& getAlbum() const;
        const std::string& getRelease() const;

};

#endif


