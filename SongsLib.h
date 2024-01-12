#ifndef SONGSLIB_H
#define SONGSLIB_H

#include <vector>
#include "Song.h"

class SongsLib {
public:
    std::vector<Song> songlist;

    void addSong(const Song& song);
    void inputSong();
    void deleteSong(std::string& title);
    void searchBySong(std::string& title);
    void searchByArtist(std::string& artist);
    void searchByAlbum(std::string& album);
    void searchByRelease(std::string& release);
    void modifyMeta();

    const std::vector<Song>& outputSongs() const;
};
#endif
