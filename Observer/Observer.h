//
// Created by BusinessB4Pleasure on 1/20/2020.
//

#ifndef DESIGNPATTERNS_OBSERVER_H
#define DESIGNPATTERNS_OBSERVER_H
#include <string>
#include <iostream>
using namespace std;

template <typename T>

class Observer {
public:
    virtual void FieldChanged(T& source, const string& field_name) = 0;
};


#endif //DESIGNPATTERNS_OBSERVER_H
