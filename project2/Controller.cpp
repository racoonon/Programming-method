#include "Controller.h"
#include "Food.h"

/**
 * A constructor of the Controller class
 * 
 * The food location is rightEnd of the shelf
 *
 * @param size_ A size of refrigerator
 * @param foodList_ A foodList container
 * @return true if inserting succeed.
 */
Controller::Controller(intPair size_, foodListType &foodList_) : size(size_), foodList(foodList_)
{
    storageGrid = new bool *[size.second]; // y축
    for (int i = 0; i < size.second; i++)
        storageGrid[i] = new bool[size.first]{0}; // x축
}

/**
 * @brief Destroy the Controller:: Controller object
 * 
 * free all allocated memory
 */
Controller::~Controller(){
    for (int i = 0; i < size.second; i++){
        delete[] storageGrid[i];
    }
    delete[] storageGrid;

    for (auto shelf : shelves){
        for (auto fnp : shelf.vec){
            delete fnp;
        }
    }
}


/**
 * Set element of storageGrid in the given range to true
 *
 * @param x The x-axis position of object
 * @param y The y-axis position of object
 * @param w The width of the object
 * @param h The height of the object
 * @return 
 */
void Controller::drawFoodsInStorageGrid(int x, int y, int w, int h)
{
    for (int i = 0; i < w; i++) // x축 좌표
    {
        for (int j = 0; j < h; j++) // x축 좌표
            storageGrid[y + j][x + i] = true;
    }
}

/**
 * Print out the storage state of the refrigerator
 * 
 * @param
 * @return 
 */
void Controller::display()
{
    // Reset storageGrid to false
    for (int i = 0; i < size.second; i++) // y축
    {
        for (int j = 0; j < size.first; j++) // x축
            storageGrid[i][j] = false;
    }

    // Fill out the areas that the object exists
    for (auto it : foodList)
    {
        for (auto fnp : it.second)
            drawFoodsInStorageGrid(fnp->getPos().first, fnp->getPos().second, fnp->getSize().first, fnp->getSize().second);
    }

    // Printout current storage states
    cout << "****************Current storage state*****************" << endl;
    cout << "width: " << size.first << ", height: " << size.second << endl;
    for (int i = 0; i < size.second; i++)
    {
        for (int j = 0; j < size.first; j++)
        {
            if (storageGrid[size.second - i - 1][j] == false) // 음식이 없다
                cout << "ㅁ";
            else // 음식이 차있다
                cout << "\u2B1C";
        }
        cout << endl;
    }
    cout << "****************Current storage state*****************" << endl;
}