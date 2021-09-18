#pragma once
#include <string>

namespace utec {
namespace compilers {

class MatcherBase {
 public:
  virtual bool match(std::string source) = 0;
};

}  // namespace compilers
}  // namespace utec