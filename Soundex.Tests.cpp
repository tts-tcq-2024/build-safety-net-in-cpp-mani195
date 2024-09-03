#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSymbols) {
    EXPECT_EQ(generateSoundex("~bvv"), "");
}

TEST(SoundexTest, HandlesSingleCharater) {
    EXPECT_EQ(generateSoundex("F"), "F000");
}

TEST(SoundexTest, HandlesSingleLowerCharacter) {
    EXPECT_EQ(generateSoundex("f"), "F000");
}

TEST(SoundexTest, HandlesFirstTwoLettersSame) {
    EXPECT_EQ(generateSoundex("BBert"), "B630");
}

TEST(SoundexTest, HandlesFirstLetterAsNumber) {
    EXPECT_EQ(generateSoundex("6ert"), "6630");
}

TEST(SoundexTest, HandlesTwoVowels) {
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

TEST(SoundexTest, HandleStringWithVowels) {
    EXPECT_EQ(generateSoundex("Aeiou"), "A000");
}

TEST(SoundexTest, HandleStringWithOtherConsonants) {
    EXPECT_EQ(generateSoundex("Chwy"), "C000");
}

TEST(SoundexTest, HandleFirstTwoLetters) {
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

TEST(SoundexTest, HandlesWithSpace) {
    EXPECT_EQ(generateSoundex("6  ert"), "6630");
}

TEST(SoundexTest, HandleSpecialCharater) {
    EXPECT_EQ(generateSoundex("B@ert"), "B630");
}

TEST(SoundexTest, HandleOnlyNumbers) {
    EXPECT_EQ(generateSoundex("6630"), "6000");
}

TEST(SoundexTest, HandleNumber&String) {
    EXPECT_EQ(generateSoundex("6630ff"), "6100");
     EXPECT_EQ(generateSoundex("6630fht"), "6130");
    EXPECT_EQ(generateSoundex("6630aei"), "6000");
    EXPECT_EQ(generateSoundex("6630hwy"), "6000");
    EXPECT_EQ(generateSoundex("6630Aj#$f"), "6210");
    
}
