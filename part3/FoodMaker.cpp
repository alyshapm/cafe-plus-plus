// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// class FoodMaker {
//     public:
//         void prepareFood();
//         void updateOrderStatus();
//         void updateInventory();
// };

#include "FoodMaker.h"
#include "Food.h"
#include <iostream>
#include <chrono>
#include <thread>

void FoodMaker::processItem(const std::shared_ptr<Order>& order) {
    for (auto& item : order->getItems()) {
        if (dynamic_cast<Food*>(item.get())) {
            std::cout << "Preparing food: " << item->getDescription() << std::endl;

            const char* chefArt[] = {
                    "       .--,--.",
                    "       `.  ,.'",
                    "        |___|",
                    "        :o o:    O",
                    "       _`~^~'_   |",
                    "     /'   ^   `\\=)",
                    "   .'  _______ '~|",
                    "   `(<=|     |= /'",
                    "       |     |",
                    "       |_____|",
                    "~~~~~~~ ===== ~~~~~~~~"
            };

            for (auto line : chefArt) {
                        std::cout << line << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay for 500 milliseconds
            }
        }
    }
}
