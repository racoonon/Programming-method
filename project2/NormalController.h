#ifndef __NORMALCONTROLLER_H_
#define __NORMALCONTROLLER_H_
#include "Controller.h"
#include <algorithm>

#define MAX_HEIGHT 6
typedef FoodInFridge *FoodPtr;
typedef map<string, vector<FoodPtr>> foodListType;

class NormalController : public Controller
{
public:
    NormalController(intPair size_, foodListType &food_list_) : Controller(size_, food_list_) 
    {
        for (int i =0; i<=3; i++){ //냉장고 30*20에 높이 6이므로 총 4개
            Shelf shelf(6);
            shelves.push_back(shelf); 
        }
    }

    /**
     * ===============================================
     * ========== TODO: Implement this part ==========
     * ===============================================
     * Declare two functions used for controller class.
     * 1) stackFood
     * 2) popFood
     */

    bool stackFood(string name, intPair size, int exp);
    bool popFood(string food);

private:
    int maxHeight = MAX_HEIGHT; // DO NOT CHANGE
};

#endif
