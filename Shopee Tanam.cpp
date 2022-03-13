#include <iostream>
#include <ctime>
#include <string>
#include <random>
#define SIZE 10 /*size of the 1-D farm is set to 10 it can be increase or decreased by changing the defined value */
#define DAYS 5  /*the number of days the game will run is 5 days it can be increase of devreased by changing the defined vvalue*/

using namespace std;

void setFruit();
void displayFarm();
void selectAction();
void choiceofAction();
void actionTwo();
void actionThree();


int farmcell[SIZE];
int day = 0, health = 80, Actionchoice, Farmchoice;
const char *fruittype[SIZE];

int main() {
    srand(time(NULL)); 
    if (day >= DAYS){
        cout << "Your endgame health is: " << health << endl;
        system("PAUSE");
        }
    while(day < DAYS) 
    {
        day++;
        setFruit();
        selectAction();
        choiceofAction();

    }
    return 0;
}

void choiceofAction() {

    switch(Actionchoice) 
    {
        case 1:
            cout << "Nothing had been done, position is unchanged" << endl;
            system("PAUSE");
            break;
        case 2:
            actionTwo();
            break;
        case 3:
            actionThree();
            break;
        default:
            cout << "\n Invalid input, try again" << endl;
            selectAction();
            break;
    }
    system("cls");
    cout << "Your current health is: " << health << endl;
    system("PAUSE");
    main();
    return;
}

void actionTwo() {
    displayFarm();
    cout << "\n Until which cell you want to walk to? " << endl;
    cout << "You will collect all the fruits along the way: ";
    cin >> Farmchoice;

    for(int k = 0; k <= Farmchoice - 1; k++) {
        health += farmcell[k];
    }

    return;
}

void actionThree() {

    for(int l = 0; l <= SIZE - 1; l++) {
        health += farmcell[l];
    }
}

void selectAction() {
    displayFarm();
    cout << "Please select your action for day: " << day << endl;
    cout << "\nAction Choice" << endl;
    cout << "1. Not crossing the park at all (stay at the current spot)." << endl;
    cout << "2. Walk through the park going through up to selected cells, gathering" << endl;
    cout << "   all the beneficial and poisonous fruits along the way, then" << endl;
    cout << "   the character turns around and goes back to the initial position. " << endl;
    cout << "3. Crossing the park completely, and going to the opposite side of the" << endl;
    cout << "   park collecting all fruits along the way, then the character rests there." << endl;
        
    cout << "\nPlease select your action: ";
    cin >> Actionchoice;
    system("PAUSE");
    system("cls");
}

void setFruit() {
    int randNum;
    
    for(int i; i < SIZE; i++ ) 
    {
        randNum = rand() % 3;
        //the possible outcome of the fruit are only set to 3 where poisonous fruit(-1), benificial fruit(1), neither (0)

        switch(randNum) 
        {
            case 0:
                farmcell[i] = 0; 
                fruittype[i] = "Neutral     ";
                break;
            case 1:
                farmcell[i] = -1;
                fruittype[i] = "Poisonous ";
                break;
            case 2:
                farmcell[i] = 1;
                fruittype[i] = "Benificial  ";
                break;
            default:
                break;
        }
    }
}

void displayFarm() {
    int j;
    system("cls");
    cout << "Current Health: " << health << endl;
    cout << "\nFarm cell No." << "\t\tType of Fruit" << "\t\tChange in Health" << endl;

    for(j = 0; j < SIZE; j++){
        cout << j + 1 << "\t\t\t" << fruittype[j] << "\t\t" << farmcell[j] << endl;
    }
}
