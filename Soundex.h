#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <cctype>
#include <unordered_map>
#include <iostream>

/*!
 * @brief check the first two letters are same
 * @param[in] name string name to test
 * @return true when code is available
 */
bool isFirstTwoLettersSame(const std::string& name);

/*!
 * @brief check the first two letters are same
 * @param[in] name string name to test
 * @param[in] index
 * @return true when code is available
 */
bool isTwoLettersWithSameDigit(std::string& name, std::uint8_t index);

/*!
 * @brief check the first two letters are same
 * @param[in] name string name to test
 * @param[in] index
 * @return true when code is available
 */
bool isTwoConsecutiveLettersSame(std::string& name, std::uint8_t index);

/*!
 * @brief check the vowels are present "a,e,i,o,u"
 * @param[in] ch string name to test
 * @return true when code is available
 */
bool isVowelPresent(char ch);

/*!
 * @brief check the other Consonant are present "h,w,y"
 * @param[in] ch string name to test
 * @return true when code is available
 */
bool isOtherConsonantPresent(char ch);

/*!
 * @brief sets diagnosis code lower
 * @param[in] setValue value to set
 */
void removeCharacterFromString(std::string& name, const char& charToRemove)

void encodeDigit(std::string& soundex, char& currentCode, char& prevCode)

void encodeTwoSameDigitsSeparatedByVowel(const std::string& name, std::size_t& startIndex, std::string& soundex, char& prevCode)

void encodeDigitWithVowelAndOtherConsonant(std::string& name, std::size_t& index, std::string& soundex, char& prevCode)

void processValidAndInvalidCharacter(std::string& name, size_t& i, std::string& soundex)

void processCharacter(std::string& name, size_t& i, std::string& soundex)

std::string processAllCharacter(std::string& name)

std::string generateSoundex(std::string name)


#endif // SOUNDEX_H
