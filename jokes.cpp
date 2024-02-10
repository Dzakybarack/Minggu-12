#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void membukajoke() 
{
    ifstream file;
    file.open("joke.txt");
    string line;

    cout << "Joke:" <<endl;
    while (getline(file, line)) {
        cout << line <<endl;
    }

    file.close();
}

void membukapunchline() 
{
    ifstream file;
    file.open("punchline.txt");
    string line, lastLine;

    cout << "\nPunchline:" << endl;
    while (getline(file, line))
    {
        if (line.find("garbage") != string::npos) 
        {
            lastLine = line.substr(line.find("garbage") + 8); 
        }
    }

    cout << lastLine << endl;

    file.close();
}

int main() 
{
    membukajoke();
    membukapunchline();

    return 0;
}
