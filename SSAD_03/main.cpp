#include <iostream>
#include <vector>
using namespace std;
//This abstract class serves as the base class for all data structures in the hierarchy
class DataStructure {
    public:
    virtual void insert(int x);
    virtual void remove();
    virtual void search(int x);
};
//This abstract class inherits from DataStructure
// and introduces functionality specific to sequential data structures
class SequentialDataStructure : public DataStructure {
    virtual void pushBack(int x);
    virtual void pushFront(int x);
    virtual void popBack();
    virtual void popFront();
};
//this abstract class inherits from DataStructure
// and introduces functionality specific to dynamic data structures.
class DynamicDataStructure : public DataStructure{
    virtual void resize(int new_size);
    virtual void clear();

};
//This class represents an implementation of a list data structure that combines characteristics of both sequential and dynamic structures.
class List : public SequentialDataStructure, DynamicDataStructure{
public:
    vector<int> mass;
    List()=default;
    void insert(int x) override{
        mass.push_back(x);
    };
    void remove() override{
        if (mass.size() != 0){
            mass.pop_back();
        }

    };
    void search(int x) override{
        for(int j = 0; j < mass.size(); j++){
            if(mass[j] == x){
                printf("YES\n");
                return;
            }
        }
        printf("NO\n");
    };
    void pushBack(int x) override{
        mass.push_back(x);
    };
    void pushFront(int x) override{
        mass.insert(mass.begin(),x);
    };
    void popBack() override{
        mass.pop_back();
    };
    void popFront() override{
        mass.erase(mass.begin());
    };
    void resize(int new_size) override{
        mass.resize(new_size);
    };
    void clear() override{
        mass.clear();
    };
    void pr(){
        for(int j = 0; j < mass.size(); j++){
            printf("%d ", mass[j]);
        }
    }
    ~List() = default;

};
int main() {
    int n;
    cin >> n;
    int m;
    List someList;
    string comand;
    for (int i = 0; i < n; ++i) {
        //input data
        cin >> comand;
        //choosing the command and call the proper method
        if (comand == "insert"){
                std::cin >> m;
                someList.insert(m);
        }
        if(comand == "remove"){
                someList.remove();
        }
        if (comand == "search") {
            std::cin >> m;
            someList.search(m);
        }
    };
    someList.pr();
    return 0;
};
