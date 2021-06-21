#include <iostream>
#include "Tests/runTests.h"
#include "UI/UI.h"
using namespace std;

int main() {

    runAll();
    UI ui = UI();
    ui.console();

    return 0;
}
