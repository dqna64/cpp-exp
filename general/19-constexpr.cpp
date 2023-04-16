constexpr int N = 4;
int get_int() { return 5; }                 // defined elsewhere
constexpr int get_const_int() { return 5; } // defined elsewhere

int main() {

  const int M = get_int();
  // not OK: M not known until runtime
  //   int arr1[M] = {0};

  // OK: N is a constexpr variable
  int arr2[N] = {0};

  const int P = get_const_int();
  // OK:  is a constexpr variable
  int arr3[P] = {0};
}
