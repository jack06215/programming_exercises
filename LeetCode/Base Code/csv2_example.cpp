#include "../csv2.hpp"

int main() {
  csv2::Reader<csv2::delimiter<','>, 
               csv2::quote_character<'"'>, 
               csv2::first_row_is_header<true>,
               csv2::trim_policy::trim_whitespace> csv;
               
  if (csv.mmap("Daily-base.csv")) {
    const auto header = csv.header();
    for (const auto row: csv) {
      for (const auto cell: row) {
        // Do something with cell value
        std::string value;
        cell.read_value(value);
        std::cout << value << std::endl;
      }
    }
  }
}
