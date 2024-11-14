#include "NormalController.h"
#include "Controller.h"
#include "Food.h"
#include <algorithm>

/**
 * ===============================================
 * ========== TODO: Implement this part ==========
 * ===============================================
 * Implement function stackFood
 * 
 * Store a given food object into the refrigerator. 
 * This function should follow the 'Modified Shelf First Fit (Shelf-FF) algorithm, which is given in the PPT slide.
 * Your implemented algorithm should find the proper position of the new food.
 * Hint. you'd better save food objects(its pointers) in both foodList and shelves to handle them easily.
 * 
 * @param name The name of the food to be stored
 * @param size width and height of the food
 * @param exp the expire date of the food
 * @return true if inserting the food for both foodList and shelves has been succeeded
 */
 
bool NormalController::stackFood(string name, intPair size_, int exp) {
	bool stackSuccess = false;
	int x, y;
	for (unsigned int j = 0; j < shelves.size(); j++) {
		for (auto i = 0; i < size.first; i++) {// 냉장고 x축 사이즈
			for (auto k = 0; k < size_.first; k++) {// 음식 x축 크기
				if (storageGrid[6*(j - 1)][i + k] == false) {
					x = i;
					y = 6*(j-1);
					if (foodList.find(name) != foodList.end()) { // 이미 그 음식 이름 존재
						FoodInFridge* new_food = new FoodInFridge(Food(name, size_, exp), x, y);
						foodList[name].push_back(new_food); // foodlist foodptr에 추가
						shelves[j].vec.push_back(new_food); // shelf vector에 추가
						stackSuccess = true;
						break;
					}
					else{ // 그 음식 이름 없을 때
						vector<FoodPtr> vec;
						FoodInFridge* new_food = new FoodInFridge(Food(name, size_, exp), x, y);
						vec.push_back(new_food);
						foodList[name] = vec;
						shelves[j].vec.push_back(new_food);
						stackSuccess = true;
						break;
					}
				}

			}
			
		}
	}
	// true 반환 전 foodlist, shelves에 입력
	// insert food cout 해주기
	if (stackSuccess == true) { // true면 inserting 좌표 적기
		// x, y pos 적기
		cout << "Inserting " << name << " into x: " << x << ", y: " << y << endl;
	}
	return stackSuccess;

}

/**
 * ===============================================
 * ========== TODO: Implement this part ==========
 * ===============================================
 * Implement function popFood
 * 
 * Pop food with shortest expire date from both foodList and shelves.
 * This function does not return the object.
 * The pop process should follows the algorithm in PPT slide.
 * 
 * @param food_name a name of food to be popped
 * @return true if poping the required food for both food_list and shelves has been succeeded
 * 
 * (output example for pop)
 * >> position to pop: x: 12 y: 0
 * >> A food bacon with expire date 3 has been popped
 */

bool NormalController::popFood(string food) {
	cout << "Which food do you want to pop? : ";
	/*
	if () { // 그 음식이 냉장고에 있을 때,pop만


		return true;
	}
	else { // 없으면 예외처리
		cout << food << " is not in Refrigerator" << endl;
		return false;
	}
	*/
	return 0;

}