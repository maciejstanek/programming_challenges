#include <iostream>

class A {
  // Fill the class definition so that the provided code will print the message {{{
  public:
  bool operator ==(int q) {
    return (q > 0 && q < 4);
  }
  // }}}
};

int main()
{
  A a;
  if (a == 1 && a == 2 && a == 3)
  {
    std::cout << "message" << std::endl;
  }
}
