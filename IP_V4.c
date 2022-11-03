//
// Created by franc on 03.11.2022.
//

#include "IP_V4.h"

#include <stdbool.h>
#include <stdlib.h>

struct maskNode {
    struct maskNode * zero;
    struct maskNode * one;
    struct maskNode * parent;
    bool isRegistered;
    char mask;
};

struct maskNode * newNode(char currMask, struct maskNode * parent) {
    struct maskNode * ret = malloc(sizeof(struct maskNode));
    ret->mask = currMask;
    ret->one = NULL;
    ret->zero = NULL;
    ret->isRegistered = false;
    ret->parent = parent;
}

static struct maskNode * root;

struct maskNode * walkTo(unsigned int base, char mask) {
    struct maskNode * currNode = root;
    unsigned int pow2 = 2147483648; // 2^31
    char currMask = 0;
    while (currMask < mask) {
        if (base / pow2 == 0) {
            if (currNode->zero == NULL) {
                currNode->zero = newNode(currMask + 1, currNode);
            }
            currNode = currNode->zero;
        } else {
            if (currNode->one == NULL) {
                currNode->one = newNode(currMask + 1, currNode);
            }
            currNode = currNode->one;
        }
        currMask++;
        pow2 /= 2;
    }
    return currNode;
}

int add(unsigned int base, char mask) {
    if (root == NULL) {
        root = newNode(0, NULL);
    }
    if (mask < 0 || mask > 32) {
        return -1;
    }

    struct maskNode * currNode = walkTo(base, mask);
    currNode->isRegistered = true;
    return 0;
}

static inline void clearBranch(struct maskNode * currNode) {
    if (currNode == NULL || currNode->parent == NULL) {
        return;
    }

    // jeżeli można wyczyścić:
    while (currNode->zero == NULL &&
           currNode->one == NULL &&
           currNode->isRegistered == false &&
           currNode->parent != NULL) {
        struct maskNode * helper = currNode->parent;
        free(currNode);
        currNode = helper;
    }
}

int del(unsigned int base, char mask) {
    if (root == NULL) {
        root = newNode(0, NULL);
    }
    if (mask < 0 || mask > 32) {
        return -1;
    }

    struct maskNode * currNode = walkTo(base, mask);
    currNode->isRegistered = false;
    clearBranch(currNode);
    return 0;
}

char check(unsigned int ip) {
    if (root == NULL) {
        root = newNode(0, NULL);
    }
    struct maskNode * currNode = root;
    unsigned int pow2 = 2147483648; // 2^31
    bool p = true;
    while (p) {
        if (ip / pow2 == 0) {
            if (currNode->zero == NULL) {
                p = false;
            } else {
                currNode = currNode->zero;
            }
        } else {
            if (currNode->one == NULL) {
                p = false;
            } else {
                currNode = currNode->one;
            }
        }
        pow2 /= 2;
    }
    while (currNode->parent != NULL && currNode->isRegistered == false) {
        currNode = currNode->parent;
    }
    if (!currNode->isRegistered) {
        return -1;
    }
    return currNode->mask;
}
