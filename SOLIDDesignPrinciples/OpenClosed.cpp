//
// Created by BusinessB4Pleasure on 1/10/2020.
//

//open for extension, closed for modification

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product{
    string name;
    Color color;
    Size size;
};
template <typename T> struct AndSpecification;

template <typename T> struct Specification{
    virtual bool is_satisfied(T* item) = 0;

    AndSpecification<T> operator&&(Specification<T>&& other){
        return AndSpecification<T>(*this, other);
    }
};

template <typename T> struct Filter{
    virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override{
        vector<Product*> result;
        for (auto& item: items)
            if(spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};

struct ColorSpecification : Specification<Product>{
    Color color;

    ColorSpecification (Color color): color(color) {}
    bool is_satisfied(Product *item) override{
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>{
    Size size;
    explicit SizeSpecification(const Size size): size{size}{}

    bool is_satisfied(Product* item) override{
        return item->size == size;
    }
};

template <typename T> struct AndSpecification : Specification<T>{

    Specification<T>& first;
    Specification<T>& second;

    AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {}

    bool is_satisfied(T *item) override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

int main(){
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};
    vector<Product*> items {&apple, &tree, &house};

    BetterFilter bf;
    ColorSpecification green(Color::green);

    for(auto& item: bf.filter(items, green))
        cout<<item->name<< " is green\n";

    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);

    auto spec = ColorSpecification(Color::green) && SizeSpecification(Size::large);

    for(auto& item: bf.filter(items, green_and_large))
        cout <<item->name << " is green and large"<<endl;


    return 0;
}