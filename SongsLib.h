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
    void deleteSongSingle(std::string& title);
    bool searchBySong(std::string& title);
    int searchByArtist(std::string& artist);
    int searchByAlbum(std::string& album);
    int searchByRelease(std::string& release);
    void modifyMeta();

    const std::vector<Song>& outputSongs() const;
    int outputSongCount() const;
};
#endif
