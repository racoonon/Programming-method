#ifndef __SMARTCONTROLLER_H_
#define __SMARTCONTROLLER_H_
#include "Controller.h"

class SmartController : public Controller
{
public:
    SmartController(intPair size_, foodListType &food_list_) : Controller(size_, food_list_) {}

    /*
     * ====================================================
     * ========== TODO: Implement this part ===============
     * ====================================================
     * Declare three functions used for class SmartController
     * 
     * 1) stackFood
     * 2) popFood
     */
    // 재정의하기 
    bool stackFood(string name, intPair size, int exp);
    bool popFood(string food);
    

private:
    int maxHeight(Shelf &);
    
};

#endif
