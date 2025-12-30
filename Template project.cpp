#include <iostream>
#include <vector>
using namespace std;

/* =========================
   ABSTRACT BASE CLASS
   ========================= */
class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i) : name(n), id(i) {}

    virtual void display() const = 0;  // Pure virtual function
    virtual ~Person() {}
};

/* =========================
   DERIVED CLASS
   ========================= */
class Student : public Person {
private:
    float marks;

public:
    Student(string n, int i, float m)
        : Person(n, i), marks(m) {}

    void display() const override {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Marks: " << marks << endl;
    }
};

/* =========================
   TEMPLATE CLASS
   ========================= */
template <typename T>
class RecordManager {
private:
    vector<T> records;

public:
    void addRecord(const T& obj) {
        records.push_back(obj);
    }

    void displayAll() const {
        for (const auto& record : records) {
            record.display();
        }
    }
};

/* =========================
   MAIN FUNCTION
   ========================= */
int main() {
    RecordManager<Student> studentManager;

    studentManager.addRecord(Student("Rahul", 101, 85.5));
    studentManager.addRecord(Student("Anjali", 102, 92.0));
    studentManager.addRecord(Student("Karan", 103, 78.4));

    cout << "---- Student Records ----" << endl;
    studentManager.displayAll();

    return 0;
}

