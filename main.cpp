#include <iostream>
#include <string>
#include <fstream>


using namespace std;

string replace(string subject, const string& search, const string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}
int main(int argc, char *argv[])
{
    string filePath(argv[1]);

    string outputFileName;
    outputFileName = filePath.substr(filePath.find_last_of("\\") + 1, filePath.find('.') - filePath.find_last_of("\\") - 1 ) + "_mod" + filePath.substr(filePath.find_last_of('.'), filePath.length() - filePath.find_last_of('.'));

    cout << filePath << endl;
    cout << filePath.find_last_of("\\") + 1 << endl;
    cout << filePath.find('.') << endl;


    cout << outputFileName << endl;

    ifstream inputFile;
    inputFile.open(filePath);

    ofstream outputFile;
    outputFile.open(outputFileName);

    string currentLine;
    string line;

    if(inputFile.is_open() & outputFile.is_open())
    {
        while(getline(inputFile, line))
        {
            currentLine = line;
            outputFile << replace(line, ", ", ",") << '\n';

        }
    }
    inputFile.close();
    outputFile.close();

    int end;
    cin >> end;

    return 0;
}
