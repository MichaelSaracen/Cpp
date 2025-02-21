#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class FileHandler {
public:
    FileHandler(const string& filename);
    ~FileHandler();

    void write(const string& text);
    void read() const;
private:
    ofstream file;
    string m_filename;
};

/**
 * Erwerb
 * @param filename
 */
FileHandler::FileHandler(const string &filename): file(filename), m_filename(filename) {
    if ( !file ) {
        cerr << "Fehler beim Öffnen der Datei!\n";
    } else {
        cout << "Datei geöffnet " << filename << endl;
    }
}

/**
 * Release
 */
FileHandler::~FileHandler() {
    if ( file.is_open() ) {
        cout << "Datei geschlossen\n";
        file.close();
    }
}

/**
 * Schreiben in die Datei
 * @param text
 */
void FileHandler::write(const string &text) {
    if ( file )
        file << text << endl;
}

/**
 * Liest die Datei aus, falls vorhanden.
 */
void FileHandler::read() const {
    std::ifstream inputFile(m_filename);
    if (!inputFile) {
        std::cerr << "Fehler beim Öffnen der Datei zum Lesen!\n";
        return;
    }
    std::cout << "\nInhalt der Datei:\n";
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    inputFile.close();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    FileHandler fh("test.txt");
    fh.write("Hallo, test test test");
    fh.write("Noch eine Zeile!");
    fh.read();
}

/*
Datei geöffnet test.txt
Inhalt der Datei:
Hallo, test test test
Noch eine Zeile!
Datei geschlossen
 */