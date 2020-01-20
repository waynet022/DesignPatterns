//
// Created by BusinessB4Pleasure on 1/20/2020.
//

#ifndef DESIGNPATTERNS_OBSERVABLE_H
#define DESIGNPATTERNS_OBSERVABLE_H

#include <string>
#include <vector>
using namespace std;

template <typename> class Observer;
template <typename T>

class Observable {
    vector<Observer<T>*> observers;
public:
    void Notify(T& source, const string& field_name){
        for (auto observer: observers)
            observer->FieldChanged(source, field_name);
    }

    void Subscribe(Observer<T>& observer){
        observers.push_back(&observer);
    }

    void Unsubscribe(Observer<T>& observer){
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }
};


#endif //DESIGNPATTERNS_OBSERVABLE_H
