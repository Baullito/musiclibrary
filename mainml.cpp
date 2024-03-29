#include <stdio.h>
#include <iostream>
#include <fstream>
#include "SongsLib.h"
#include "json.hpp"

/*INFO: // Inhalt dieser Beispiel JSON Datei ist komplett KI generiert.
Der genutzte prompt für Chat-GPT4 war:
    'Erstelle mir eine formatierte JSON Datei mit 30 Song Beispielen. Es sollen auch mehrere Songs eines Beispielkünstlers vorkommen, sowie Songs eines Besipielkünstlers im gleichen Beispielalbum vorkommen.'

Hinweis! Compilerbefehl: g++ -o mainml mainml.cpp SongsLib.cpp Song.cpp
Ausführen: ./mainml
*/
using json = nlohmann::json;


int main() {

SongsLib musiclibrary;

// Programmstart -> Einlesen JSON-Datei

    std::cout << "++++++ Songbibliothek ++++++\n++++++                ++++++\n\n";
    std::cout << "Geben Sie eine Songdatenbibliothek im JSON-Dateiformat an.\nEs muss der ganze Dateinamen mit der Endung '.json' an.\n\n-> ";

    std::string songfile;
    std::cin >> songfile;

    std::ifstream file(songfile);

    if (file.is_open() == false) {

        std::cout << "*** Fehler! Die Datei kann nicht geöffnet werden.\nDas Programm wird beendet. ***\n\n\n";

        exit(0);

        return 0;
    }

    json inputML;
    file >> inputML;

    //Erstellen von Song-Objekten aus JSON-Datei

    for (auto& element: inputML) {

        std::string title = element["title"];
        std::string artist = element["artist"];
        std::string album = element["album"];
        std::string release = element["release"];

        Song song(title, artist, album, release);
        musiclibrary.addSong(song);
    }

    file.close();

    std::cout << "Einlesen der JSON-Datei erfolgreich.\n\n\n++++++++++++++++++++\n";


    //Menufuehrung

    std::string songtochange;
    std::string searchterm;
    int choiceMain = 0;
    int choiceSub = 0;

    json outputML;
    json songObJson;

    std::ofstream outFile(songfile);


    while (choiceMain != 5)  {
        std::cout << "++++++++++++++++++++\n\n";
        std::cout << "1. Song bearbeiten\n";
        std::cout << "2. Song-Metadaten bearbeiten\n";
        std::cout << "3. Suchen\n";
        std::cout << "4. Playlist/Favoriten(work in progress)\n";
        std::cout << "5. Programm beenden\n";
        std::cout << "Waehlen Sie eine Option: ";

        std::cin >> choiceMain;
        std::cout << "\n";

        //Menuefuehrung -> Eingabefehler Endlosschleife
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "*** Fehler! Ungueltige Option. Bitte erneut vesuchen. ***\n";
        }
        else {

        switch (choiceMain) {
            case 1:     //Menuepunkt 1 -> Song bearbeiten
                std::cout << "          1. Song hinzufügen\n";
                std::cout << "          2. Song entfernen\n";
                std::cout << "          Waehlen Sie eine Option: ";
                std::cin >> choiceSub;
                std::cout << "\n";

                switch (choiceSub) {
                    case 1:
                        musiclibrary.inputSong();

                        break;

                    case 2:
                        std::cout << "          Um einen Song zu entfernen geben Sie den Titel ein: ";
                        std::cin >> songtochange;
                        musiclibrary.deleteSong(songtochange);

                        break;

                    default:
                        std::cout << "*** Fehler! Ungueltige Option. Bitte erneut vesuchen. ***\n\n\n\n++++++++++++++++++++\n";
                        break;

                }

                break;

            case 2:     //Menuepunkt 2 -> Nach Metadaten suchen
                musiclibrary.modifyMeta();

                break;

            case 3:     //Menuepunkt 3 -> Suchfunktion
                std::cout << "          1. Nach Song suchen\n";
                std::cout << "          2. Nach Kuenstler suchen\n";
                std::cout << "          3. Nach Album suchen\n";
                std::cout << "          4. Nach Erscheinungsjahr suchen\n";
                std::cout << "          Waehlen Sie eine Option: ";
                std::cin >> choiceSub;
                std::cout << "\n";

                switch (choiceSub) {
                    case 1:
                        std::cout << "          Um nach einem Song zu suchen geben Sie den Titel ein: ";
                        std::cin >> searchterm;
                        musiclibrary.searchBySong(searchterm);

                        break;

                    case 2:
                        std::cout << "          Um nach einem Kuenstler zu suchen geben Sie den Kuenstlernamen ein: ";
                        std::cin >> searchterm;
                        musiclibrary.searchByArtist(searchterm);

                        break;

                    case 3:
                        std::cout << "          Um nach einem Album zu suchen geben Sie den Albumtitel ein: ";
                        std::cin >> searchterm;
                        musiclibrary.searchByAlbum(searchterm);

                        break;

                    case 4:
                        std::cout << "          Um nach Songs aus einem Erscheinungsjahr zu suchen Jahreszahl eingeben: ";
                        std::cin >> searchterm;
                        musiclibrary.searchByRelease(searchterm);

                        break;

                    default:
                        std::cout << "*** Fehler! Ungueltige Option. Bitte erneut vesuchen. ***\n\n\n\n++++++++++++++++++++\n";
                        break;

                }
                break;


            case 4:     //Menuepunkt 4 -> Playlists/Favoriten

                break;

            case 5:
                std::cout << "Programm wird beendet und JSON-Datei gespeichert.\n";

                for (const Song& songiter : musiclibrary.outputSongs()) {
                    songObJson["title"] = songiter.getTitle();
                    songObJson["artist"] = songiter.getArtist();
                    songObJson["album"] = songiter.getAlbum();
                    songObJson["release"] = songiter.getRelease();

                    outputML.push_back(songObJson);

                }


                outFile << outputML.dump(4);
                outFile.close();

                break;

            default:
                std::cout << "*** Fehler! Ungueltige Option. Bitte erneut vesuchen. ***\n\n";
                break;
        }
        }
    }
    return 0;
}
