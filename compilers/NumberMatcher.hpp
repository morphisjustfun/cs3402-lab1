#pragma once
#include "MatcherBase.h"

#include <algorithm>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

bool containsEpsilon(string target, int &tokenIndex) {
  auto findE = target.find("E");
  auto finde = target.find("e");
  if (findE != string::npos || finde != string::npos) {
    if (findE != string::npos && finde != string::npos) {
      return 0;
    }
    if (findE != string::npos) {
      if (findE == target.size() - 1) {
        return 0;
      }
      tokenIndex = findE;
      return 1;
    } else {
      if (finde == target.size() - 1) {
        return 0;
      }
      tokenIndex = finde;
      return 1;
    }
  }
  return 0;
}

bool validInitial(string &target) {
  char firstCharacter = target[0];
  return (firstCharacter == '+' || firstCharacter == '-' ||
          firstCharacter == '.' || isdigit(firstCharacter));
}

bool validEnd(string target) {
  char lastCharacter = target[target.size() - 1];
  return isdigit(lastCharacter);
}

bool isValidNumber(int indexToken, string target) {
  if (indexToken != -1) {
    for (int i = 0; i < target.size(); i++) {
      if (i != indexToken && !isdigit(target[i])) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

/* bool isFloat(string target) { */
/*   int posTokenFloat = -1; */
/*   string testTarget = target; */
/*   return containsEpsilon(testTarget, posTokenFloat) &&
 * validInitial(testTarget) && */
/*          isValidNumber(posTokenFloat, testTarget); */
/* } */

bool isNumber(string test) {
  for (char i : test) {
    if (!isdigit(i)) {
      return 0;
    }
  }
  return 1;
}

bool isFloat(string test) {
  auto tokenDot = test.find('.');
  if (tokenDot == string::npos) {
    return isNumber(test);
  } else {
    string left = test.substr(0, tokenDot);
    string right = test.substr(tokenDot + 1, test.size() - tokenDot);
    return !(right == "" && left == "") && isNumber(left) && isNumber(right);
  }
}

bool validRight(string right) {
  char firstChar = right[0];
  bool startswithSymbol = firstChar == '+' || firstChar == '-';
  if (startswithSymbol) {
    string rightRemoved = right.substr(1, right.size() - 1);
    return isNumber(rightRemoved);
  } else {
    return isNumber(right);
  }
}

bool validLeft(string left) {
  char firstChar = left[0];
  bool startswithSymbol = firstChar == '+' || firstChar == '-';
  if (startswithSymbol) {
    string leftRemoved = left.substr(1, left.size() - 1);
    return isFloat(leftRemoved);
  } else {
    return isFloat(left);
  }
}

bool isFloatExp(string target) {
  int posTokenFloat = -1;
  if (containsEpsilon(target, posTokenFloat)) {
    string leftTarget = target.substr(0, posTokenFloat);
    string rightTarget =
        target.substr(posTokenFloat + 1, target.size() - posTokenFloat);
    if (leftTarget.empty()){
      return false;
    }
    return validRight(rightTarget) && validLeft(leftTarget);
  } else {
    char firstChar = target[0];
    bool startswithSymbol = firstChar == '+' || firstChar == '-';
    if (startswithSymbol) {
      string firstCharRemoved = target.substr(1, target.size() - 1);
      return isFloat(firstCharRemoved);
    } else {
      return isFloat(target);
    }
  }
}

namespace utec {
namespace compilers {

class NumberMatcher : public MatcherBase {
  //
 public:
  bool match(std::string source) { return isFloatExp(source); }
};

}  // namespace compilers
}  // namespace utec
