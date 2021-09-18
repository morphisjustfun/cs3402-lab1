#pragma once
#include "MatcherBase.h"

namespace utec {
namespace compilers {

class NumberMatcher : public MatcherBase {
  //
 public:
  bool match(std::string source) { return false; }
};

}  // namespace compilers
}  // namespace utec