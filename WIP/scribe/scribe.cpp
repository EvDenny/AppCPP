#include "scribe.h"
#include <iostream>
#include <string>

void cout(std::string value) {
    std::cout << value;
}

void endl() {
    std::cout << std::endl;
}

namespace Hang {

void hang() {
    cout('Hanged');
    endl();
}

void hung() {
    cout('Hung IS NOT A WORD');
    endl();
}

}