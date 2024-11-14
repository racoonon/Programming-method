#ifndef __RECIPE_H
#define __RECIPE_H

#include <vector>
#include <string>

using namespace std;

typedef pair<string, int> strIntPair;

class Recipe
{
public:
    // Recipe() : name("None"), score(0){};
    Recipe(string, vector<strIntPair>, double);
    string getName() const { return name; }
    vector<strIntPair> getIngredients() const { return ingredients; }
    double getKcal() const { return kcal; }

private:
    string name;
    vector<strIntPair> ingredients;
    double kcal;
};

#endif //__RECIPE_H