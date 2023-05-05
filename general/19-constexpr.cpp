constexpr int N = 4;
int get_int() { return 5; } // defined elsewhere
constexpr int get_const_int() { return 5; }

bool get_bool() { return true; }
consteval bool get_consteval_bool() { return true; }
constexpr int get_const_int_maybe(const bool b) {
  if (b) {
    return 5;
  } else {
    return 6;
  }
}

int main() {

  const int M = get_int();
  // not OK: M not known until runtime
  //   int arr1[M] = {0};

  // OK: N is a constexpr variable
  int arr2[N] = {0};

  const int P = get_const_int();
  // OK:  is a constexpr variable
  int arr3[P] = {0};

  const int Q = get_const_int_maybe(get_bool());
  // not OK: Q not known until runtime
  //   int arr4[Q] = {0};

  const int R = get_const_int_maybe(get_consteval_bool());
  // OK: R is a constexpr variable
  int arr5[R] = {0};

  return 0;
}
