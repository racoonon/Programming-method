#include "Refrigerator.h"
#include "Food.h"
#include "NormalController.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>

using namespace std;

/**
 * A constructor of the class
 * Controller and User should be initialized in this constructor
 */
Refrigerator::Refrigerator() : size(30, 20)
{
    controller = new NormalController(size, foodList);
}

/**
 * @brief Destroy the Refrigerator:: Refrigerator object
 * free memory allocated for contoller and user
 */

Refrigerator::~Refrigerator(){
    delete controller;
}

/**
 * base function of the refrigerator
 * User should type a number between 1 and 4 to call a function of the refrigerator
 * Then, this function utilizes the other functions of the refrigerator as the user's input
 * Below is the list of options that menuSelect should support
 * 1) display
 * 2) insert food
 *    2-1) insert a list of foods from a text file (.txt)
 *    2-2) insert a food directly
 * 3) pop food
 * 4) end program
 * Unless the user ends the program ( 4) end program ),
 * this function does not terminate and keeps requiring the user to type a number
 * @return 0 when the user ends the program by typing else 1
 */
int Refrigerator::menuSelect()
{
    int i;
    while (1)
    {
        cout << "************************************************************" << endl;
        cout << "************************   Menu   **************************" << endl;
        cout << "************************************************************" << endl;

        cout << "1. display" << endl;
        cout << "2. insert food" << endl;
        cout << "3. pop food" << endl;
        cout << "4. end program" << endl;
        cout << "Select the function you want : ";
        cin >> i;
        if (i < 1 || i > 4)
        {
            cout << "Type an integer from 1 to 4!" << endl;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else
        {
            break;
        }
    }
    if (i == 4)
    {
        return 0;
    }
    else
    {
        switch (i)
        {
            case 1:
                display();
                break;
            case 2:
            {
                int j;
                while (1)
                {
                    cout << "1. Insert a list of foods from a text file" << endl;
                    cout << "2. Insert a food directly" << endl;
                    cout << "Enter how to insert your food : ";
                    cin >> j;
                    if (!(j == 1 or j == 2))
                    {
                        cout << "Type 1 or 2 only" << endl;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if (j == 1)
                    insertFoodFromFile();
                else
                    insertFoodDirectly();
                break;
            }
            case 3:
            {
                popFood();
                break;
            }
        }
        return 1;
    }
}

/**
 * This function print out the storage state and the food lists to the program output window.
 * This function should call the display function of controller first,
 * print outs the foods with the different exp dates
 * e.g. [bacon,2] exp date : 1
 *      [bacon,3] exp date : 3     
 *      [egg,3] exp date : 2
 */
void Refrigerator::display()
{
    // grid display
    controller->display(); // 실제 냉장고 안

    /**
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     */
    // 음식들 list display

    /*
    for (int i=0; i<)
    cout << "["
    */
}

/**
 * Get food informations from user and stack them into refrigerator by calling 
 * the stackFood function in Controller class.
 */
void Refrigerator::insertFoodDirectly()
{

    string foodName;
    intPair foodSize;
    int expDate;
    cout << "Enter food info" << endl;
    cout << "Food name : ";
    cin >> foodName;
    cout << "Food size :";
    cin >> foodSize.first >> foodSize.second;
    cout << "Days left to expiration date : ";
    cin >> expDate;

    /**
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     * Implement a code of inserting the food.
     * Make sure to print a message if the insertion failed
     *
     * (output example for failure)
     * >> Inserting # food failed!
     */

    if (controller->stackFood(foodName, make_pair(foodSize.first, foodSize.second), expDate)) {
        // x, y 좌표 여기다 적을지 Normal controller에 적을지 생각
    }

    else { // 만약 insert 실패
        cout << "Inserting 1 " << foodName << " failed!" << endl;
    }
}

/**
 * Receive a name of text file containing food information lists from user and read it. 
 * Then, get the food informations line by line and stack foods into refrigerator 
 * by calling the `stackFood` function in Controller class.
 */
void Refrigerator::insertFoodFromFile()
{
    string foodFileName;
    cout << "Enter your file name : ";
    cin >> foodFileName;
    /**
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     * Implement a code of inserting the food from textfile.
     * Read the list of foods from txt file and insert it
     * one by one to the refrigerator.
     * Make sure to print a message on both file read failure
     * and insertion failure.
     * 
     * (output example for file read failure)
     * >> There is no food file
     * 
     * (output example for insertion failure )
     * >> Inserting # food failed!
     */

    ifstream file;
    string line;
    file.open(foodFileName);

    if (!file) {
        cout << "There is no food file" << endl;
        return;
    }

    while (getline(file, line)){ // if no line left, return false
        stringstream ss(line); //ss에 line을 잘라서 저장한 문자열 저장 
        string name;
        int width, height, num, exp;
        ss >> name >> width >> height >> num >> exp;
        int cnt = num;
        for (int i = 1; i <= num; i++) {
            if (controller->stackFood(name, make_pair(width, height), exp)) {
                cnt -= 1; // Insert 되었다는 출력 문구는 stackFood 내부에 위치시킴
            }
            else {
                cout << "Inserting " << cnt << " " << name << " failed!" << endl;
                break;
            }
        }
    }

    file.close();
    return;
}

/**
 * Receives a 'foodName' from user and removes it from the refrigerator.
 * You should call the `popFood` function in Controller class.
 * 
 * 
 */
void Refrigerator::popFood()
{
    string foodName;
    cout << "Which food do you want to pop? : ";
    cin >> foodName;
    
    /**
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     * Implement a code of poping the food.
     * Make sure to print a message if the pop has failed
     * 
     * (output example for failure)
     * >> bacon is not in Refrigerator
     */

   

}


