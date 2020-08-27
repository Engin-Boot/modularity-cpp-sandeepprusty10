#include <iostream>
#include <assert.h>
#include "ColorCoder.h"

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

std::string ToString()
{
    int i;
    int majorcount = TelCoColorCoder::numberOfMajorColors;
    int minorcount = TelCoColorCoder::numberOfMinorColors;
    std::string manualStr = " ";
    for(i = 1; i <= majorcount*minorcount; i++)
    {
        manualStr = manualStr + std::to_string(i) + "---->" + TelCoColorCoder::MajorColorNames[(i-1)/ majorcount] + "   " + TelCoColorCoder::MinorColorNames[(i-1)% minorcount] + "\n" + " ";
    }
    return manualStr;
}
int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    
    ToString();
    
    return 0;
}
