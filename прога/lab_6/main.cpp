#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Plant {
private:
    string name;
    string type;
    double height;
    int age;
    bool isIndoor;

public:
    Plant() : name("No name"), type("unknown"), height(0), age(0), isIndoor(false) {}
    Plant(string n, string t, double h, int a, bool indoor) 
        : name(n), type(t), height(h), age(a), isIndoor(indoor) {}
    
    string getName() const { return name;}
    string getType() const { return type;}
    double getHeight() const { return height;}
    int getAge() const { return age;}
    bool getIsIndoor() const { return isIndoor;}

    // void setHeight(double h) { height = h; }
    // void setAge(int a) { age = a; }

    void print() const {
        cout << "Name: " << name << ", Type: " << type << ", Height: " << height << " cm" << ", Age: " 
        << age << " years" << ", Is Indoor: " << (isIndoor ? "Yes" : "No") << endl;
    }
};

string EstimateLength(const string& s) {
    return s.size() > 10 ? "long" : "short";
}


int main() {
    vector <Plant> plants;
    cout << EstimateLength("five")<< endl;

    plants.push_back(Plant("Cactus", "Succulent", 25, 3, true));
    plants.push_back(Plant("Ficus", "Houseplant", 120, 5, true));
    plants.push_back(Plant("Birch", "Tree", 350, 15, false));
    plants.push_back(Plant("Rose", "Flower", 45, 3, false));
    plants.push_back(Plant("Lavender", "Flower", 30, 1, false));
    plants.push_back(Plant("Orchid", "Flower", 50, 4, true));

    cout << "=== All Plants ===" << endl;
    for (size_t i = 0; i < plants.size(); ++i) {
        plants[i].print();
    }

    double maxH = plants[0].getHeight();
    int tallestIndex = 0;
    for (int i = 1; i < plants.size(); ++i) {
        if (plants[i].getHeight() > maxH) {
            maxH = plants[i].getHeight();
            tallestIndex = i;
        }
    }

    cout << "=== Tallest Plant ===" << endl;
    plants[tallestIndex].print();

    cout << "=== Indoor Plants ===" << endl;
    for (size_t i = 0; i < plants.size(); ++i) {
        if (plants[i].getIsIndoor())
            plants[i].print();
    }

    cout << "=== Only Flower ==="<< endl;
    for (size_t i = 0; i < plants.size(); ++i) {
        if (plants[i].getType() == "Flower") {
            plants[i].print();
    }
}

    return 0;
}
