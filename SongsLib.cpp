#include "SongsLib.h"
#include <iostream>

void SongsLib::addSong(const Song& song)  {
        songlist.push_back(song);

}

void SongsLib::inputSong() {
        std::string title;
        std::string artist;
        std::string album;
        std::string release;

        std::cout << "          Sie koennen nun einen neuen Song mit allen Metadaten angeben.\n";
        std::cout << "          Titel des neuen Songs: ";
        std::cin >> title;

        std::cout << "          Kuenstler des neuen Songs: ";
        std::cin >> artist;

        std::cout << "          Album des neuen Songs: ";
        std::cin >> album;

        std::cout << "          Erscheinungsjahr des neuen Songs: ";
        std::cin >> release;


        Song song(title, artist, album, release);
        addSong(song);

        std::cout << "Der Song wurde hinzugefuegt.\n";
}

void SongsLib::deleteSong(std::string& title) {
        bool exsistenz = false;
        char abfrage;
        std::cout << "Der Song "<< title << " wird geloescht. Sind Sie scher?  (y/n): ";
        std::cin >> abfrage;

        if (abfrage == 'y' || abfrage == 'Y') {

        for (std::vector<Song>::iterator i = songlist.begin(); i != songlist.end();) {
            if ((*i).title == title) {
                i = songlist.erase(i);
            }
            else {
                i++;
            }
        }

        std::cout << "Der Song wurde entfernt\n";

        } else {
            std::cout << "Der Song wurde nicht geloescht.\n";
        }
}
