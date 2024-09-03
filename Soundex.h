#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <cctype>
#include <unordered_map>
#include <iostream>

bool isFirstTwoLettersSame(const std::string& name);

bool isTwoLettersWithSameDigit(std::string& name, std::uint8_t index);

bool isTwoConsecutiveLettersSame(std::string& name, std::uint8_t index);

bool isVowelPresent(char ch);

bool isOtherConsonantPresent(char ch);

void removeCharacterFromString(std::string& name, const char& charToRemove)

void encodeDigit(std::string& soundex, char& currentCode, char& prevCode)

void encodeTwoSameDigitsSeparatedByVowel(const std::string& name, std::size_t& startIndex, std::string& soundex, char& prevCode)

void encodeDigitWithVowelAndOtherConsonant(std::string& name, std::size_t& index, std::string& soundex, char& prevCode)

void processValidAndInvalidCharacter(std::string& name, size_t& i, std::string& soundex)

void processCharacter(std::string& name, size_t& i, std::string& soundex)

std::string processAllCharacter(std::string& name)

std::string generateSoundex(std::string name)

#endif // SOUNDEX_H
