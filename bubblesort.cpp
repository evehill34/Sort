#include <iostream>
#include <limits>
#include <regex>

const std::regex int_pattern_u("[0-9]+");
const std::regex int_pattern("-?[0-9]+");

class CustomArray
{
  public:
    CustomArray();

    void bubbleSort();
    void printArray();

  private:
    int* array;
    int size;
};

void input_nb(const std::string instruction, const std::regex pattern, int* target, const int rank)
{
  std::string s = "";
  std::cout << instruction << std::endl;
  std::cin >> s;
  while (!std::regex_match(s, pattern)) {
    std::cout << "Invalid number!" << std::endl;
    std::cout << instruction << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> s;
  }
  target[rank] = std::stoi(s);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


CustomArray::CustomArray()
{
  input_nb("How much numbers do you need?", int_pattern_u, &(this->size), 0);

  this->array = (int*)malloc(this->size*sizeof(int));

  for (int i = 0; i < this->size; i++) {
    input_nb("Enter a number", int_pattern, this->array, i);
  }

}

// perform bubble sort
void CustomArray::bubbleSort() {

  // loop to access each array element
  for (int step = 0; step < this->size; ++step) {
    // loop to compare array elements
    for (int i = 0; i < this->size - step - 1; ++i) {
      // compare two adjacent elements
      if (this->array[i] > this->array[i + 1]) {
        // swapping elements if elements
        // are not in the intended order
        int temp = this->array[i];
        this->array[i] = this->array[i + 1];
        this->array[i + 1] = temp;
      }
    }
  }
}

// print array
void CustomArray::printArray() {
  for (int i = 0; i < this->size; ++i) {
    std::cout << "  " << this->array[i];
  }
  std::cout << std::endl;
}

int main() {
  CustomArray CA;

  std::cout << "Initial Array:\n";
  CA.printArray();

  CA.bubbleSort();

  std::cout << "Sorted Array in Ascending Order:\n";
  CA.printArray();
}
