#include "SmartController.h"
#include "Controller.h"
#include "Food.h"

/**
 * ===============================================
 * ========== TODO: Implement this part ==========
 * ===============================================
 * Implement function stackFood
 * 
 * Store a given food object into the refrigerator
 * 
 * This function should follows the 'Shelf First Fit (Shelf-FF) algorithm, which is given in the PPT slide.
 * Your implemented algorithm should find the proper position of the new food.
 * Also, the given food object may in the stack memory. You should save it in the heap memory and reference
 * it from both food_list and shelves.
 * 
 * @param name The name of the food to be stored
 * @param size width and height of the food
 * @param exp the expire date of the food
 * @return true if inserting the food for both food_list and shelves has been succeeded
 * 
 * (output example for )
 * >> Inserting bacon into x: 12 y: 0
 */

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
 * @return true if poping the food for both food_list and shelves has been succeeded
 */

bool SmartController::stackFood(string name, intPair size_, int exp) {
    return 0;
}


bool SmartController::popFood(string food) {
    return 0;
}
