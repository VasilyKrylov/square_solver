#ifndef SS_OBJECTS_H
#define SS_OBJECTS_H

enum Status {
    STATUS_OK = 0,
    STATUS_INF = 1,
    STATUS_NAN = 2,
    STATUS_NOT_DOUBLE = 3,
    STATUS_WITH_TRASH = 4
};

struct Test {
    double a, b, c;
    double x1, x2;
    int nRoots;
}; // MOVE TO TESTS.H

#endif // SS_OBJECTS_H