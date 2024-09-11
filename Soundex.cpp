#include "Soundex.h"
#include <string>
#include <cctype>
#include <unordered_map>

char getSoundexCode(char c)
{
  static std::unordered_map<char, char> consonantMap =  //
    {{'b', '1'},
     {'f', '1'},
     {'p', '1'},
     {'v', '1'},  
     {'c', '2'},
     {'g', '2'},
     {'j', '2'},
     {'k', '2'},  
     {'q', '2'},
     {'s', '2'},
     {'x', '2'},
     {'z', '2'},  
     {'d', '3'},
     {'t', '3'},  
     {'l', '4'},
     {'m', '5'},
     {'n', '5'},  
     {'r', '6'}};

  c = std::tolower(c);
  if (consonantMap.find(c) != consonantMap.end())
  {
    return consonantMap[c];
  }
  return '0';  // For A E I O U H W Y
}

bool isStringNotFound(const std::string& name)
{
  if (name.empty() || (ispunct(name[0])))
  {
    return true;
  }
  return false;
}

bool isFirstTwoLettersSame(const std::string& name)
{
  if (name.length() < 2)
  {
    return false;
  }
  return getSoundexCode(name[0]) == getSoundexCode(name[1]);
}

bool isTwoLettersWithSameDigit(std::string& name, std::uint8_t index)
{
  if ((name.length() - index) >= 3)
  {
    if (getSoundexCode(name[index]) == getSoundexCode(name[index + 2]))
    {
      return true;
    }
  }
  return false;
}

bool isTwoConsecutiveLettersSame(std::string& name, std::uint8_t index)
{
  if ((name.length() - index) >= 2)
  {
    if (getSoundexCode(name[index]) == getSoundexCode(name[index + 1]))
    {
      return true;
    }
  }
  return false;
}

bool isVowelPresent(char ch)
{
  std::string vowels = "aeiou";
  for (char vowel : vowels)
  {
    if (tolower(ch) == vowel)
    {
      return true;
    }
  }
  return false;
}

bool isOtherConsonantPresent(char ch)
{
  std::string otherConsonants = "hwy";
  for (char otherConsonant : otherConsonants)
  {
    if (tolower(ch) == otherConsonant)
    {
      return true;
    }
  }
  return false;
}

void removeCharacterFromString(std::string& name, const char& charToRemove)
{
  std::size_t pos = name.find(charToRemove);
  if (pos != std::string::npos)
  {
    name.erase(pos, 1);
  }
}

void encodeDigit(std::string& soundex, char& currentCode, char& prevCode)
{
  soundex += currentCode;
  prevCode = currentCode;
}

void encodeTwoSameDigitsSeparatedByVowel(const std::string& name, std::size_t& startIndex, std::string& soundex, char& prevCode)
{
  for (std::size_t j = 0; j < 3; j++)
  {
    char currentCode = getSoundexCode(name[startIndex + j]);
    if (currentCode != '0')
    {
      encodeDigit(soundex, currentCode, prevCode);
    }
  }
  startIndex += 3;
}

void encodeDigitWithVowelAndOtherConsonant(std::string& name, std::size_t& index, std::string& soundex, char& prevCode)
{
  if (isVowelPresent(name[index + 1]))
  {
    encodeTwoSameDigitsSeparatedByVowel(name, index, soundex, prevCode);
  }
  else if (isOtherConsonantPresent(name[index + 1]))
  {
    removeCharacterFromString(name, index + 1);
  }
}

void processValidAndInvalidCharacter(std::string& name, size_t& i, std::string& soundex)
{
  char currentCode = getSoundexCode(name[i]);
  char prevCode;
  if (isTwoLettersWithSameDigit(name, i))
  {
    encodeDigitWithVowelAndOtherConsonant(name, i, soundex, prevCode);
  }
  else if (currentCode == '0')
  {
    return;
  }
  else
  {
    encodeDigit(soundex, currentCode, prevCode);
  }
}

void processCharacter(std::string& name, size_t& i, std::string& soundex)
{
  if (isTwoConsecutiveLettersSame(name, i))
  {
    removeCharacterFromString(name, i);
  }
  else
  {
    processValidAndInvalidCharacter(name, i, soundex);
  }
}

std::string processAllCharacter(std::string& name)
{
  std::string soundex(1, toupper(name[0]));
  for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i)
  {
    processCharacter(name, i, soundex);
  }

  soundex.resize(4, '0');
  return soundex;
}

std::string generateSoundex(std::string name)
{
  if (isStringNotFound(name))
  {
    return "";
  }

  if (isFirstTwoLettersSame(name))
  {
    removeCharacterFromString(name, name[1]);
  }

  return processAllCharacter(name);
}
