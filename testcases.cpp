#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "SongsLib.h"
#include "Song.h"
#include "json.hpp"

using json = nlohmann::json;

//Hinweis! Compilerbefehl: g++ -o testProgramm testcases.cpp SongsLib.cpp Song.cpp

TEST_CASE("Laden der Songdaten aus der JSON Datei", "[JSONtoC++]") {
    //Test anhand test JSON Datei
    SongsLib testMusicLibrary;
    std::string testSongFile = "testJSON.json";

    //Test ob Datei öffnet
    std::ifstream file(testSongFile);
    REQUIRE(file.is_open());
    file.close();
}


TEST_CASE("Testen von Hinzufügen eines Songs", "[SongEdit]") {
    SongsLib testMusicLibrary;
    Song testSong("testtitle", "testartist","testalbum","testrelease");
    testMusicLibrary.addSong(testSong);

    REQUIRE(testMusicLibrary.outputSongCount() == 1);
}

TEST_CASE("Testen von Entfernen eines Songs", "[SongEdit]"){
    SongsLib testMusicLibrary;
    std::string testTitle = "testtitle";
    Song testSong(testTitle, "testartist","testalbum","testrelease");
    testMusicLibrary.addSong(testSong);
    REQUIRE(testMusicLibrary.outputSongCount() == 1);

    testMusicLibrary.deleteSongSingle(testTitle);
    REQUIRE(testMusicLibrary.outputSongCount() == 0);

}


TEST_CASE("Testen des Speicherns in die JSON-Datei", "[JSONtoC++]") {
    SongsLib testMusicLibrary;
    Song testSong("testtitle", "testartist", "testalbum", "testrelease");
    testMusicLibrary.addSong(testSong);
    std::string testSongFile = "testSaveJSON.json";

    json outputMLTest;
    json songObJsonTest;
    std::ofstream outFileTest(testSongFile);

    for (const Song& songiter : testMusicLibrary.outputSongs()) {
        songObJsonTest["title"] = songiter.getTitle();
        songObJsonTest["artist"] = songiter.getArtist();
        songObJsonTest["album"] = songiter.getAlbum();
        songObJsonTest["release"] = songiter.getRelease();
        outputMLTest.push_back(songObJsonTest);

    }

        outFileTest << outputMLTest.dump(4);
        outFileTest.close();

        std::ifstream file(testSongFile);
        REQUIRE(file.is_open());
}

TEST_CASE("Testen der Songsuchfunktion", "[Search]") {
    SongsLib testMusicLibrary;
    std::string testTitle = "testtitle";
    Song testSong(testTitle, "testartist","testalbum","testrelease");

    testMusicLibrary.addSong(testSong);
    REQUIRE(testMusicLibrary.searchBySong(testTitle) == true);

    std::string nonexistTestFile = "nonexistent";
    REQUIRE(testMusicLibrary.searchBySong(nonexistTestFile) == false);


}

TEST_CASE("Testen der Künstlersuchfunktion", "[Search]") {
    SongsLib testMusicLibrary;
    std::string testArtist = "testartist";
    Song testSong("testtitle",testArtist,"testalbum","testrelease");

    testMusicLibrary.addSong(testSong);
    REQUIRE(testMusicLibrary.searchByArtist(testArtist) == true);

    std::string nonexistTestFile = "nonexistent";
    REQUIRE(testMusicLibrary.searchByArtist(nonexistTestFile) == false);
}

TEST_CASE("Testen der Albumsuchfunktion", "[Search]") {
    SongsLib testMusicLibrary;
    std::string testAlbum = "testalbum";
    Song testSong("testtitle","testartist",testAlbum,"testrelease");

    testMusicLibrary.addSong(testSong);
    REQUIRE(testMusicLibrary.searchByAlbum(testAlbum) == true);

    std::string nonexistTestFile = "nonexistent";
    REQUIRE(testMusicLibrary.searchByAlbum(nonexistTestFile) == false);
}

TEST_CASE("Testen der Releasesuchfunktion", "[Search]") {
    SongsLib testMusicLibrary;
    std::string testRelease = "testrelease";
    Song testSong("testtitle","testartist","testalbum",testRelease);

    testMusicLibrary.addSong(testSong);
    REQUIRE(testMusicLibrary.searchByRelease(testRelease) == true);

    std::string nonexistTestFile = "nonexistent";
    REQUIRE(testMusicLibrary.searchByRelease(nonexistTestFile) == false);
}
