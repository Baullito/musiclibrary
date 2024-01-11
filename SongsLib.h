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


};
#endif
