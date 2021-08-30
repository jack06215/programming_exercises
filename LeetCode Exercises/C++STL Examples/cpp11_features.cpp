#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "../prettyprint.h"

int main() {
  auto const owners = std::vector<std::string>{"Ashwin", "Lesley", "Sarah"};
  auto const pets = std::vector<std::string>{"Dog", "Cat", "Dog"};

  auto dog_owners = std::vector<std::string>{};
  std::copy_if(
      owners.cbegin(), 
      owners.cend(), 
      std::back_inserter(dog_owners), 
      [pet = pets.cbegin()](auto const& owner) mutable {
          return *pet++ == "Dog";
      }
  );

  std::cout << dog_owners << std::endl;
}