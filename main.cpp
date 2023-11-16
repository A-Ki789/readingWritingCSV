#include <iostream>
#include <fstream>

using namespace std;

struct Movie {
    int id;
    string title;
    int date;
};

int main() {
    fstream file;
    file.open("moviesList.csv", ios::out);
    if (file.is_open()) {
        file << "id,title,date \n"
             << "1, Terminator, 1980 \n"
             << "2, Terminator2, 1990" << endl;
        file.close();
    }

    file.open("moviesList.csv", ios::in);
    if (file.is_open()) {
        string str;
        getline(file, str);
        while (!file.eof()) {
            getline(file, str, ',');
            if (str.empty()) continue;

            Movie movie;
            movie.id = stoi(str);

            getline(file, str, ',');
            movie.title = str;

            getline(file, str);
            movie.date = stoi(str);

            cout << movie.date << endl;

        }
        file.close();
    }

    return 0;
}