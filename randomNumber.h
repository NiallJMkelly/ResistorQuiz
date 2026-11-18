#include <iostream>

#include <random>

class RandomNumberGenerator{
  private:
    int firstBand , secondBand , multiplierBand;

  public:
    RandomNumberGenerator()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<> digitDist(0, 9);  
        std::uniform_int_distribution<> firstDigitDist(1,9); //black isnt normally the first band so the first can be excluded
        std::uniform_int_distribution<> multiplierDist(0, 6); //not going up to 10 because the numbers would be outrageously large

        firstBand = firstDigitDist(gen);
        secondBand= digitDist(gen);
        multiplierBand = multiplierDist(gen);
    }

    int getTotal()
    {
        int value = (firstBand*10) + secondBand; //add the significant values

        for (int i = 0; i < multiplierBand; i++)   // easier in my head to do a for loop after getting a multiplier value between 1 and 6
        {
            //value *= 10; // some change
            value = value * 10;
        }

        return value;
    }

    int getFirstBand()
    {
        return firstBand;
    }

    int getSecondBand()
    {
        return secondBand;
    }

    int getMultiplierBand()
    {
        return multiplierBand;
    }
};

