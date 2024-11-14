#ifndef __CONTROLLER_H_
#define __CONTROLLER_H_
#include "Food.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

typedef FoodInFridge* FoodPtr;
typedef map<string, vector<FoodPtr>> foodListType;

struct Shelf
{
    int height;
    vector<FoodPtr> vec;
    Shelf(int height_) : height(height_){};
};

class Controller
{
public:
    Controller(intPair, foodListType &);
    virtual ~Controller();
    void display();

    /**
     * ===============================================
     * ========== TODO: Implement this part ==========
     * ===============================================
     * Declare two functions used for controller class.
     * 
     * 1) popfood
     * 2) stackfood
     */

    virtual bool stackFood(string name, intPair size, int exp) = 0;
    virtual bool popFood(string food) = 0;

protected:
    intPair size;
    vector<Shelf> shelves;
    foodListType &foodList;
    bool **storageGrid; 
    
private:
    
    void drawFoodsInStorageGrid(int x, int y, int w, int h);
};

#endif
