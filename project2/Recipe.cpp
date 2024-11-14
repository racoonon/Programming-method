#include "Recipe.h"
#include <iostream>

using namespace std;

/**
 * A constructor of the class
 * @param name_ the name of the recipe
 * @param foods a vector that contains the pairs of food name and the number of the foods required. e.g. (bacon, 2)
 */
Recipe::Recipe(string name_, vector<strIntPair> ingredients_, double kcal_) : name(name_), ingredients(ingredients_), kcal(kcal_)
{
    if (kcal_ < 0)
    {
        cout << "The kcal of recipe must be positive value";
        exit(0);
    }
}
