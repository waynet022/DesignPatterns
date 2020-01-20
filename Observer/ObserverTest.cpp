//
// Created by BusinessB4Pleasure on 1/20/2020.
//
#include <iostream>
#include "Observer.h"
#include "Observable.h"

using namespace std;

class Person: public Observable<Person>{
private:
    int age;
public:
    Person(int age): age(age){}

    int GetAge() const{
        return age;
    }

    void SetAge(int age){
        if (this->age == age)
            return;
        this->age = age;
        Notify(*this, "age");
    }
};


class ConsolePersonObserver : public Observer<Person>{
private:
    void FieldChanged(Person &source, const string &field_name) override {
        cout<<"Person's " <<field_name << " has changed to ";
        if(field_name == "age")
            cout<< source.GetAge();
        cout << "\n";
    }
};

int main(int ac, char* av[]){
    Person person{10};
    ConsolePersonObserver cpo;
    person.Subscribe(cpo);

    person.SetAge(11);
    person.SetAge(12);

    person.Unsubscribe(cpo);
    person.SetAge(13);
}