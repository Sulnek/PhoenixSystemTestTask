#include "IP_V4.h"

#include <stdio.h>
#include <assert.h>

int main() {
    add(999999, 5);
    assert(check(999999) == 5);
    assert(check(1) == 5);
    assert(add(1, 28) == 0);
    assert(check(1) == 28);
    assert(check(15) == 28);
    assert(del(3, 28) == 0);
    assert(check(15) == 5);
    assert(check(2147483648) == -1);
    assert(add(1, 33) == -1);
    assert(check(1) == 5);
    return 0;
}
