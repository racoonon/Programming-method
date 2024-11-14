#ifndef __FOOD_H_
#define __FOOD_H_
#include <string>
using namespace std;

typedef pair<int, int> intPair;
/**
 * TODO: You must modify this file.
 * 
 */
class Food {
public:
    Food() : name("null"), size(0, 0), exp(0){}
    Food(string name_, intPair size_, int exp_);
    int getExp() const { return exp; }
    string &getName() { return name; }
    intPair getSize() const { return size; }

protected:
    string name;
    intPair size;
    int exp;
};

class FoodInFridge : public Food {
public:
    FoodInFridge(Food food, int x, int y) : Food(food) { pos = make_pair(x, y); }
    intPair getPos() { return pos; }
    void setPos(intPair &pos_) { pos = pos_; }

private:
    intPair pos; // 모든 재료들의 좌측 하단 좌표
};

#endif