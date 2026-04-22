#include <iostream>
#include <vector>
using namespace std;

// -------- ABSTRACT CLASS --------
class GradingSystem {
protected:
    float marks;

public:
    GradingSystem(float m) : marks(m) {}

    virtual char computeGrade() = 0; // pure virtual
    virtual void display() = 0;

    virtual ~GradingSystem() {}
};

// -------- UNDERGRADUATE --------
class Undergraduate : public GradingSystem {
public:
    Undergraduate(float m) : GradingSystem(m) {}

    char computeGrade() {
        if (marks >= 75) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }

    void display() {
        cout << "UG Marks: " << marks
             << " Grade: " << computeGrade() << endl;
    }
};

// -------- POSTGRADUATE --------
class Postgraduate : public GradingSystem {
public:
    Postgraduate(float m) : GradingSystem(m) {}

    char computeGrade() {
        if (marks >= 80) return 'A';
        else if (marks >= 65) return 'B';
        else if (marks >= 55) return 'C';
        else return 'F';
    }

    void display() {
        cout << "PG Marks: " << marks
             << " Grade: " << computeGrade() << endl;
    }
};

// -------- MAIN --------
int main() {
    vector<GradingSystem*> students;

    students.push_back(new Undergraduate(72));
    students.push_back(new Postgraduate(72));
    students.push_back(new Undergraduate(85));

    cout << "Student Records:\n";
    for (auto s : students) {
        s->display();
    }

    // Cleanup
    for (auto s : students) delete s;

    return 0;
}
