#ifndef __REFRIGERATOR_H_
#define __REFRIGERATOR_H_
#include "Food.h"
#include "NormalController.h"
#include <map>
#include <vector>

using namespace std;

typedef FoodInFridge *FoodPtr; // 냉장고 속 음식 위치 가르킴
typedef map<string, vector<FoodPtr>> foodListType; // 냉장고 속 음식 종류 가르킴 
// key: 음식 이름, vector of foodPtrs

class Refrigerator {
protected:
  intPair size; // 냉장고 크기
  foodListType foodList;
  Controller *controller;

public:
  Refrigerator();
  virtual ~Refrigerator();
  intPair getSize() const { return size; }
    
    /*
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     * Declare three functions used for class refrigerator
     * 
     * 1) popFood
     * 2) InsertFoodFromFile
     * 3) InsertFoodDirectly
     * 4) display
     */
  void popFood();
  void insertFoodFromFile();
  void insertFoodDirectly();
  void display();

  virtual int menuSelect();
};
#endif