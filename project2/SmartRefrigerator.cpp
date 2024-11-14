#include "SmartRefrigerator.h"
#include "Recipe.h"
#include "Food.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

/**
 * A constructor of the class
 * SmartController should be initialized in this constructor
 */
SmartRefrigerator::SmartRefrigerator()
{
    delete controller;
    controller = new SmartController(size, foodList);
};


/**
 * add recipes from a text file (.txt)
 * This function should add a new recipe object with the given info from the file to the private variable recipe (vector)
 */
void SmartRefrigerator::addRecipeFromFile()
{
    string recipeFile;
    cout << "Enter your file name : ";
    cin >> recipeFile;
    ifstream recipe_list(recipeFile);

    if (!recipe_list)
    {
        cout << "There is no recipe file!" << endl;
        return;
    }

 /**
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     */
     
}


/**
 * @brief Show the current recipes of the smart refrigetrator
 * e.g. recipe name : [food1, # of food1]...[] / Kcal 7
 * if there is no recipe print "There is no recipe yet."
 */
void SmartRefrigerator::showRecipe()
{
     /**
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     */
}

/**
 * @brief Recommend appropriate meals according to the rules in ppt.
 * 
 * 
 *
 * (output example for recommendation)
 * >> 1th meal : vegetableCurry       : [ Min Exp : X   | Kcal : 430 | Cookability : X | Cost : 21 ] | carrot     : 1 | potato     : 1 | onion      : 1 | mushroom   : 2 | currypowder : 1 | milk       : 1
 * 
 * Hint. Refer to the below format
 *         cout << ... << "th meal : " << left << setw(20) << ... << " : ";
 *         cout << "[ Min Exp : " << setw(3) << ...
 *              << " | " << "Kcal : " << ...
 *              << " | " << "Cookability : " << ...
 *              << " | " << "Cost : " << setw(3) << ... << ']';
 *         for(...){
 *              cout << " | " << setw(10) << ... << " : " << ...;
 *          }
 */

void SmartRefrigerator::recommendMeal()
{
    /**
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     * 
     */
}


/**
* ====================================================
* ========== TODO: Implement this part ===============
* ====================================================
* Implement display function
*
* display function is already derived in normal refrigerator.
*
* However, keep in mind that display funciton of Smart refrigerator
* differs from that of normal refrigerator.
* It needs to specify the owner of the food
* 
* (output example for display)
* >> [bacon,5] [ALL:2,junho-lee:1,minji-kim:2] exp date : 3
* The owner of the foods must be printed in lexicographical order.
* e.g. minji-kim:2,junho-lee:1,ALL:2 <- NOT ALLOWED
*/ 




/** 
 * @brief base function of the smart refrigerator
 * User should type a number between 1 and 10 to call a function of the smart regrigerator
 * Then, this function utilizes the other functions of the smart refrigerator as the user's input
 * Below is the list of options that menuSelect should support
 * 1) display
 * 2) insert food
 *    2-1) insert a list of foods from a text file (.txt)
 *    2-2) insert a food directly
 * 3) pop food
 * 4) add recipe
 * 5) show recipe
 * 6) recommend meal
 * 7) login
 * 8) logout
 * 9) topup
 * 10) end program
 * Unless the user ends the program ( 10) end program ),
 * this function does not terminate and keeps requiring the user to type a number
 * @return 0 when the user ends the program by typing 10 else 1
 */
int SmartRefrigerator::menuSelect()
{
    int i;
    while (1)
    {
        /**
         * ====================================================
         * ========== TODO: Implement this part ===============
         * ====================================================
         * Implement a code for printing user info.
         * 
         * (output example if logged in)
         * >> USER : user1
         * (output example if not logged in)
         * >> USER : Not Logged in
         */
        cout << "************************************************************" << endl;
        cout << "************************   Menu   **************************" << endl;
        cout << "************************************************************" << endl;

        cout << "1. display" << endl
             << "2. insert food" << endl
             << "3. pop food" << endl
             << "4. add recipe" << endl
             << "5. show recipe" << endl
             << "6. recommend meal" << endl
             << "7. login" << endl
             << "8. logout" << endl
             << "9. topup" << endl
             << "10. end program" << endl
             << "Select the function you want : ";
        cin >> i;
        if (i < 1 || i > 10){
            cout << "Type an integer from 1 to 10!" << endl;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {break;}
    }
    if (i == 10)
        return 0;
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
            case 4:
                addRecipeFromFile();
                break;
            case 5:
                showRecipe();
                break;
            case 6:
                recommendMeal();
                break;
                /*
            case 7:
                login();
                break;
            case 8:
                logout();
                break;
            case 9:
                topup();
                break;
                */
        }
        return 1;
    }
}

