#include <stdio.h>
#include <iostream>
#include <fstream>
#include "json.hpp"


using json = nlohmann::json;

//Song Klasse
    class Song {
    public:
        std::string title;
        std::string artist;
        std::string album;
        std::string release;

        Song(std::string songTitle, std::string songArtist, std::string songAlbum, std::string songRelease) : title(songTitle), artist(songArtist), album(songAlbum), release(songRelease)  {}



    };


// Song Bibliothek

class SongsLib {
public:
    std::vector<Song> songlist;


    void addSong(const Song& song)  {
        songlist.push_back(song);
    }

    void inputSong() {
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


    void deleteSong(std::string& title) {
        for (std::vector<Song>::iterator i = songlist.begin(); i != songlist.end();) {
            if ((*i).title == title) {
                i = songlist.erase(i);
            }
            else {
                i++;
            }
        }

        std::cout << "Der Song wurde entfernt\n";
    }

};

int main() {

SongsLib musiclibrary;

// Programmstart -> Einlesen JSON-Datei

    std::cout << "++++++ Songbibliothek ++++++\n++++++                ++++++\n\n";
    std::cout << "Geben Sie eine Songdatenbibliothek im JSON-Dateiformat an.\nEs muss der ganze Dateinamen mit der Endung '.json' an.\n\n-> ";

    std::string songfile;
    std::cin >> songfile;

    std::ifstream file(songfile);

    if (!file.is_open()) {

        std::cout << "*** Fehler! Die Datei kann nicht geöffnet werden.\nDas Programm wird beendet. ***\n\n\n";

        exit(0);

        return 1;
    }

    json ml;
    file >> ml;

    //Erstellen von Song-Objekten aus JSON-Datei

    for (auto& element: ml) {

        std::string title = element["title"];
        std::string artist = element["artist"];
        std::string album = element["album"];
        std::string release = element["release"];

        Song song(title, artist, album, release);
    }

    file.close();

    std::cout << "Einlesen der JSON-Datei erfolgreich.\n\n\n++++++++++++++++++++\n";


    //Menufuehrung
    std::string songtoremove;
    int choice = 0;
    int choiceu1 = 0;
    while (choice != 5)  {
        std::cout << "++++++++++++++++++++\n\n";
        std::cout << "1. Song bearbeiten\n";
        std::cout << "2. Song-Metadaten bearbeiten\n";
        std::cout << "3. Suchen\n";
        std::cout << "4. Playlist/Favoriten\n";
        std::cout << "5. Programm beenden\n";
        std::cout << "Waehlen Sie eine Option: ";

        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
            case 1:
                std::cout << "          1. Song hinzufügen\n";
                std::cout << "          2. Song entfernen\n";
                std::cout << "          Waehlen Sie eine Option: ";
                std::cin >> choiceu1;
                std::cout << "\n";

                switch (choiceu1) {
                    case 1:
                        musiclibrary.inputSong();

                        break;

                    case 2:
                        std::cout << "Um einen Song zu entfernen geben Sie den Title ein: ";
                        std::cin >> songtoremove;
                        musiclibrary.deleteSong(songtoremove);

                        break;

                    default:
                        std::cout << "*** Fehler! Ungueltige Option. Bitte erneut vesuchen. ***\n\n\n\n++++++++++++++++++++\n";
                        break;

                }

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:
                std::cout << "Programm wird beendet und JSON-Datei gespeichert.\n";
                break;

            default:
                std::cout << "*** Fehler! Ungueltige Option. Bitte erneut vesuchen. ***\n\n";
                break;
        }
    }
    return 0;
}
