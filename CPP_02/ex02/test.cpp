#include <iostream>

class Fixed {
public:
    Fixed(int value) : _fixedPointValue(value) {}

    // Pre-increment operator returns a reference
    Fixed operator++() {
        ++_fixedPointValue;
        return *this;  // Returning the updated object by reference
    }

    int getValue() const {
        return _fixedPointValue;
    }

private:
    int _fixedPointValue;
};

int main() {
    Fixed obj(0);

    // Chaining multiple increments
    // ++obj; // 1
    ++(++obj); // 2
    //++(++obj);

    std::cout << "Final value: " << obj.getValue() << std::endl;

    return 0;
}

