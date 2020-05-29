#include <iostream>
#include <string>
#include <vector>

enum COLOUR {
    red,
    green,
    blue,
    black,
    white
};

std::string returnColour(COLOUR colour) {
    std::string result;
    switch (colour) {
        case COLOUR::red:
            result = "Red";
        case COLOUR::green:
            result = "Green";
        case COLOUR::blue:
            result = "Blue";
        case COLOUR::black:
            result = "Black";
        case COLOUR::white:
            result = "White";
    }
    return result;
}

enum SIZE {
    small,
    medium,
    large
};

std::string returnSize(SIZE size) {
    std::string result;
    switch (size) {
        case SIZE::small:
            result = "S";
        case SIZE::medium:
            result = "M";
        case SIZE::large:
            result = "L";

            return result;
    }
}

class Clothes {
private:
    std::string name;
    unsigned int prise;
    COLOUR colour;
    SIZE size;
public:
    Clothes(std::string name, unsigned int price, COLOUR colour, SIZE size) {
        this->name = name;
        this->prise = price;
        this->colour = colour;
        this->size = size;
    }

    std::string getName() const {
        return name;
    }

    unsigned int getPrice() const {
        return prise;
    }

    std::string getColour() const {
        return returnColour(colour);
    }

    std::string getSize() const {
        return returnSize(size);
    }

    static Clothes *giveShirtSmallWhite() {
        return new Clothes("Shirt", 1000, white, small);
    }

    static Clothes *giveShirtMediumWhite() {
        return new Clothes("Shirt", 1000, white, medium);
    }

    static Clothes *giveShirtLargeWhite() {
        return new Clothes("Shirt", 1000, white, large);
    }

    static Clothes *giveShirtSmallBlack() {
        return new Clothes("Shirt", 1000, black, small);
    }

    static Clothes *giveShirtMediumBlack() {
        return new Clothes("Shirt", 1000, black, medium);
    }

    static Clothes *giveShirtLargeBlack() {
        return new Clothes("Shirt", 1000, black, large);
    }

    static Clothes *giveTrousersSmallGreen() {
        return new Clothes("Trousers", 1000, green, small);
    }

    static Clothes *giveTrousersMediumBlue() {
        return new Clothes("Trousers", 1000, blue, medium);
    }

    static Clothes *giveTrousersLargeRed() {
        return new Clothes("Trousers", 1000, red, large);
    }

};

class ShoppingList {
private:
    std::vector<const Clothes *> clothes;
public:

    void addObject(Clothes &object) {
        clothes.push_back(&object);
    }

    void printList() {
        unsigned long size = clothes.size();
        if (size == 0) {
            std::cout << "The shopping list is empty!";
        } else {
            for (int i = 0; i < size; i++) {
                std::cout << i << ". " << clothes[i]->getName() << " " << clothes[i]->getColour() << " "
                          << clothes[i]->getSize() << " " << clothes[i]->getPrice();
                std::cout << "\n";
            }
        }
    }
};

int main() {

    ShoppingList shoppingList;

    shoppingList.addObject(*Clothes::giveShirtSmallWhite());
    shoppingList.addObject(*Clothes::giveShirtMediumWhite());
    shoppingList.addObject(*Clothes::giveShirtLargeWhite());
    shoppingList.addObject(*Clothes::giveShirtSmallBlack());
    shoppingList.addObject(*Clothes::giveShirtMediumBlack());
    shoppingList.addObject(*Clothes::giveShirtLargeBlack());
    shoppingList.addObject(*Clothes::giveTrousersSmallGreen());
    shoppingList.addObject(*Clothes::giveTrousersMediumBlue());
    shoppingList.addObject(*Clothes::giveTrousersLargeRed());

    shoppingList.printList();

    return 0;
}