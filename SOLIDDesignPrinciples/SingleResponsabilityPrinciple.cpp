//
// Created by BusinessB4Pleasure on 1/10/2020.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Journal{
    string title;
    vector<string> entries;

    Journal(const string &title ): title(title) {}

    void add_entry(const string& entry){
        static int count = 1;
        count++;
        entries.push_back(count +": "+entry);
    }
};

struct PersistanceManager{
    static void save(const Journal& j, const string& filename){
        ofstream ofs(filename);
        for (auto& e: j.entries)
            ofs <<e << endl;
    }
};

int main(){
    cout<<"Testing single responsability principle"<<endl;

    Journal journal{"first entry"};
    journal.add_entry("The beginning");
    journal.add_entry("second line");

    PersistanceManager journal_manager;
    journal_manager.save(journal, "outputfile.txt");
    return 0;
}