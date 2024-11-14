#ifndef __SMARTREFRIGERATOR_H_
#define __SMARTREFRIGERATOR_H_
#include "Refrigerator.h"
#include "SmartController.h"
#include "Food.h"
#include "Recipe.h"
// #include "User.h" 
// 치워라치워라
#include <map>

typedef vector<Recipe> recipeVec;

enum Menu{DISPLAY, INSERT_FOOD, POP_FOOD, ADD_RECIPE, SHOW_RECIPE, RECOMMEND, LOGIN, LOGOUT, END};

class SmartRefrigerator : public Refrigerator
{
public:
    SmartRefrigerator();
    int menuSelect();

    /**  
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     * Declare three functions used for class SmartRefrigerator
     * 
     * 1) display
     */
    
    void addRecipeFromFile();
    void showRecipe();
    void recommendMeal();

private:
    recipeVec recipes;
};

#endif
