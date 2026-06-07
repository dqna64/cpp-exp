int main() {
    /**
     * If i try to change a const via a reference, compiler won't let me.
     */
    auto const x = 0;
    auto& xref = x;
    xref++;

    /**
     * But what if I try to change a const via a pointer instead?
     * Compiler won't let me make the pointer in the first place!
     */
    auto const a = 0;
    int* pa = &a;
    *pa = 1;
}