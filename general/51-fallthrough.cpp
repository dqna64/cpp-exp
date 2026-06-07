/**
 * With the -Wimplicit-fallthrough flag,
 * un-annotated switch case fallthroughs will surface a warning.
 *
 * Use [[fallthrough]] to silence.
 */

#include <iostream>

int main() {
    auto a = 0;

    switch (a) {
    case 0: std::cout << "case 0 fallthrough\n";
    case 1: std::cout << "case 1 fallthrough\n"; [[fallthrough]];
    case 2: std::cout << "case 2 fallthrough\n"; [[fallthrough]];
    default: std::cout << "default\n";
    }
}