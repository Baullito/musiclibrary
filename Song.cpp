#include "Song.h"

Song::Song(std::string songTitle, std::string songArtist, std::string songAlbum, std::string songRelease) : title(songTitle), artist(songArtist), album(songAlbum), release(songRelease)  {}

const std::string& Song::getTitle() const{
    return title;
}

const std::string& Song::getArtist() const{
    return artist;
}

const std::string& Song::getAlbum() const{
    return album;
}

const std::string& Song::getRelease() const{
    return release;
}
