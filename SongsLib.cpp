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

        std::cout << "          Sie koennen nun einen neuen Song mit allen Metadaten angeben.\n\n";
        std::cout << "          + Titel des neuen Songs: ";
        std::cin >> title;

        std::cout << "          + Kuenstler des neuen Songs: ";
        std::cin >> artist;

        std::cout << "          + Album des neuen Songs: ";
        std::cin >> album;

        std::cout << "          + Erscheinungsjahr des neuen Songs: ";
        std::cin >> release;


        Song song(title, artist, album, release);
        addSong(song);

        std::cout << "\n          Der Song wurde hinzugefuegt.\n";
}

void SongsLib::deleteSong(std::string& title) {
        bool exsistenz = false;
        char abfrage;
        std::cout << "          Der Song "<< title << " wird geloescht. Sind Sie sicher?  (y/n): ";
        std::cin >> abfrage;

        if (abfrage == 'y' || abfrage == 'Y') {

            for (std::vector<Song>::iterator i = songlist.begin(); i != songlist.end();) {
                if ((*i).title == title) {
                    i = songlist.erase(i);
                    exsistenz = true;

                }else {
                    i++;
                }
            }

            if (exsistenz) {
                std::cout << "\n          Der Song wurde entfernt.\n";
            } else {
                std::cout << "\n          Der Song wurde nicht gefunden.\n";
            }

        } else {
            std::cout << "\n          Der Song wurde nicht geloescht.\n";
        }
}

void SongsLib::searchBySong(std::string& title) {
    bool existence = false;

    for (const Song& song : songlist) {
        if (song.title == title) {
            existence = true;

            std::cout << "\n          -> Song gefunden! Suchergebnisse: \n\n";
            std::cout << "      +++++++\n          Titel: " << song.title << "\n";
            std::cout << "          Kuenstler: " << song.artist << "\n";
            std::cout << "          Album: " << song.album<< "\n";
            std::cout << "          Erscheinungsjahr: " << song.release << "\n\n";
            break;
        }
    }

    if (existence == false) {
        std::cout << "          Der Song konnte nicht gefunden werden.\n";
    }

}

void SongsLib::searchByArtist(std::string& artist) {
    bool existence = false;
    bool InfoPrinted = false;

    for (const Song& song : songlist) {
        if (song.artist == artist) {
            existence = true;
            if (InfoPrinted == false) {
                std::cout << "\n          -> Kuenstler gefunden! Es werden alle Songs des Kuenstlers als Suchergebnis angezeigt: \n\n";
                InfoPrinted = true;
            }

            std::cout << "      +++++++\n          Titel: " << song.title << "\n";
            std::cout << "          Kuenstler: " << song.artist << "\n";
            std::cout << "          Album: " << song.album<< "\n";
            std::cout << "          Erscheinungsjahr: " << song.release << "\n\n";

        }
    }

    if (existence == false) {
        std::cout << "          Der Kuenstler konnte nicht gefunden werden.\n";
    }

}

void SongsLib::searchByAlbum(std::string& album) {
    bool existence = false;
    bool InfoPrinted = false;

    for (const Song& song : songlist) {
        if (song.album == album) {
            existence = true;
            if (InfoPrinted == false) {
                std::cout << "\n          -> Album gefunden! Es werden alle Songs des Albums als Suchergebnis angezeigt: \n\n";
                InfoPrinted = true;
            }

            std::cout << "      +++++++\n          Titel: " << song.title << "\n";
            std::cout << "          Kuenstler: " << song.artist << "\n";
            std::cout << "          Album: " << song.album<< "\n";
            std::cout << "          Erscheinungsjahr: " << song.release << "\n\n";

        }
    }

    if (existence == false) {
        std::cout << "          Das Album konnte nicht gefunden werden.\n";
    }

}

void SongsLib::searchByRelease(std::string& release) {
    bool existence = false;
    bool InfoPrinted = false;

    for (const Song& song : songlist) {
        if (song.release == release) {
            existence = true;
            if (InfoPrinted == false) {
                std::cout << "\n          -> Songs aus diesem Erscheinungsjahr gefunden! Es werden alle Songs aus diesem Jahr als Suchergebnis angezeigt: \n\n";
                InfoPrinted = true;
            }

            std::cout << "      +++++++\n          Titel: " << song.title << "\n";
            std::cout << "          Kuenstler: " << song.artist << "\n";
            std::cout << "          Album: " << song.album<< "\n";
            std::cout << "          Erscheinungsjahr: " << song.release << "\n\n";

        }
    }

    if (existence == false) {
        std::cout << "          Es konnten keine Songs aus diesem Jahr gefunden werden.\n";
    }

}

void SongsLib::modifyMeta() {
    std::string title;
    std::cout << "          Geben Sie den Titel des Songs ein, den Sie bearbeiten möchten: ";
    std::cin >> title;

    for (Song& song : songlist) {
        if (song.title == title) {
            std::cout << "\n          Song gefunden! Geben Sie die neuen Metadaten ein.\n";

            std::cout << "          + Neuer Kuenstler: ";
            std::cin >> song.artist;

            std::cout << "          + Neues Album: ";
            std::cin >> song.album;

            std::cout << "          + Neues Erscheinungsjahr: ";
            std::cin >> song.release;

            std::cout << "\n          Die Songdaten wurden erfolgreich aktualisiert.\n\n";
            return;
        }
    }

    std::cout << "          Der Song konnte nicht gefunden werden.\n\n";
}

const std::vector<Song>& SongsLib::outputSongs() const {
    return songlist;
}
