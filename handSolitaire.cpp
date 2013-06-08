/*
 * This code is property of KyJay LLC and is being
 * provided to you through GitHub
 * Author: Jayden Navarro
 * Date: 6/7/2013
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;


bool prompt();
void feedDeck(int [52][2]);
int playDeck(int [52][2], int [52][2]);
void printOut(int [52][2], int [52][2], int);


int main() {
    std::srand(time(NULL));

    bool forward = prompt();
    int array1[52][2];
    int array2[52][2];
    int length = 1;

    if (forward) {
        feedDeck(array1);
        length = playDeck(array1, array2);
    } else {
        while (length != 0) {
            feedDeck(array1);
            length = playDeck(array1, array2);
        }
    }
    printOut(array1, array2, length);


    std::cin.clear();
    std::cin.get();
    std::cin.get();
    return 0;
}

bool prompt() {
    char input = 'i';
    while (input != 'R' && input != 'r'
            && input != 'W' && input != 'w') {
        cout << "Would you like a winning deck or random?\n";
        cout << "R for random W for winning: ";
        cin >> input;
        cout << endl;
    }
    if (input == 'R' || input == 'r')
        return true;
    else
        return false;
}

void feedDeck(int A1[52][2]) {
    for (int i = 0; i < 52; i++) {
        A1[i][0] = 0;
        A1[i][1] = 0;
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            bool repeat = true;
            while (repeat) {
                int random = std::rand() % 52;
                if (A1[random][0] == 0) {
                    A1[random][0] = j;
                    A1[random][1] = i;
                    repeat = false;
                }
            }
        }
    }
}

int playDeck(int A1[52][2], int A2[52][2]) {
    int height = 0;
    int maxHeight = 0; //For maxheight addition to game uncomment
    for (int i = 0; i < 52; i++) {
        A2[i][0] = 0;
        A2[i][1] = 0;
    }
    for (int i = 51; i >= 0;) {
        if (height < 3) {
            for (; height < 4; height++) {
                if (i >= 0) {
                    A2[height][0] = A1[i][0];
                    A2[height][1] = A1[i][1];
                    i--;
                }
            }
        } else {
            A2[height][0] = A1[i][0];
            A2[height][1] = A1[i][1];
            height++;
            i--;
        }
        bool test = false;
        if (height > 3) {
            while (!test) {
                if (A2[height-1][0] == A2[height-4][0]) {
                    for (int j = 1; j <= 4; j++) {
                        A2[height-j][0] = 0;
                        A2[height-j][1] = 0;
                    }
                    height -= 4;
                } else if (A2[height-1][1] == A2[height-4][1]) {
                    for (int j = 2; j <= 3; j++) {
                        A2[height-j][0] = 0;
                        A2[height-j][1] = 0;
                    }
                    A2[height-3][0] = A2[height-1][0];
                    A2[height-3][1] = A2[height-1][1];
                    A2[height-1][0] = 0;
                    A2[height-1][1] = 0;
                    height -= 2;
                } else {
                    test = true;
                }
            }
        }
        if (height > maxHeight) //Comment out
            maxHeight = height; //Comment out
   }
   if (maxHeight < 29 && height == 0) //Comment out
       height = 1; //Comment out
   return height;
}

void printOut(int A1[52][2], int A2[52][2], int height) {
    cout << "There are " << height << " final cards\n";
    if ((height) != 0) {
        for (int i = 0; i < height; i++) {
            int number = A2[i][0];
            if (number < 11 && number != 1)
                cout << A2[i][0];
            else if (number == 11)
                cout << "Jack";
            else if (number == 12)
                cout << "Queen";
            else if (number == 13)
                cout << "King";
            else if (number == 1)
                cout << "Ace";


            int suite = A2[i][1];
            if (suite == 1)
                cout << " of spades" << endl;
            else if (suite == 2)
                cout << " of hearts" << endl;
            else if (suite == 3)
                cout << " of clubs" << endl;
            else if (suite == 4)
                cout << " of diamonds" << endl;
            else
                cout << " ERROR" << endl;
        }
    }
    cout << "The deck was as follows\n";
    for (int i = 0; i < 52; i++) {
        cout << i+1 << "...";
        int number = A1[i][0];
        if (number < 11 && number != 1)
            cout << A1[i][0];
        else if (number == 11)
            cout << "Jack";
        else if (number == 12)
            cout << "Queen";
        else if (number == 13)
            cout << "King";
        else if (number == 1)
            cout << "Ace";


        int suite = A1[i][1];
        if (suite == 1)
            cout << " of spades" << endl;
        else if (suite == 2)
            cout << " of hearts" << endl;
        else if (suite == 3)
            cout << " of clubs" << endl;
        else if (suite == 4)
            cout << " of diamonds" << endl;
        else
            cout << " ERROR" << endl;
    }
}







