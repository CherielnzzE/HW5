#include <iostream>
#include<cstdlib>
#include <string>
using namespace std;

// UniversityStaff class (already defined)

class UniversityStaff {
public:
    UniversityStaff();
    UniversityStaff(string theName);
    UniversityStaff(const UniversityStaff& theObject);
    string getName() const;
    UniversityStaff& operator=(const UniversityStaff& rightSide);
    friend istream& operator>>(istream& instream, UniversityStaff& staffObject);
    friend ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject);

private:
    string name;
};

UniversityStaff::UniversityStaff() {
    name = "";
}

UniversityStaff::UniversityStaff(string theName) {
    name = theName;
}

UniversityStaff::UniversityStaff(const UniversityStaff& theObject) {
    name = theObject.name;
}

string UniversityStaff::getName() const {
    return name;
}

UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rightSide) {
    if (this != &rightSide) {
        name = rightSide.name;
    }
    return *this;
}

istream& operator>>(istream& instream, UniversityStaff& staffObject) {
    instream >> staffObject.name;
    return instream;
}

ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject) {
    outStream << staffObject.name;
    return outStream;
}

// Student class

class Student {
public:
    Student();
    Student(string uniName, int regNum, UniversityStaff proctor);
    Student(const Student& other);
    virtual ~Student();

    string getUniversityName() const;
    int getRegistrationNumber() const;
    UniversityStaff getProctor() const;

    void setUniversityName(string uniName);
    void setRegistrationNumber(int regNum);
    void setProctor(UniversityStaff proctor);

    Student& operator=(const Student& rightSide);

protected:
    string universityName;
    int registrationNumber;
    UniversityStaff proctor;
};

Student::Student() : universityName(""), registrationNumber(0), proctor("") {}

Student::Student(string uniName, int regNum, UniversityStaff proctor)
    : universityName(uniName), registrationNumber(regNum), proctor(proctor) {}

Student::Student(const Student& other)
    : universityName(other.universityName),
    registrationNumber(other.registrationNumber),
    proctor(other.proctor) {}

Student::~Student() {}

string Student::getUniversityName() const {
    return universityName;
}

int Student::getRegistrationNumber() const {
    return registrationNumber;
}

UniversityStaff Student::getProctor() const {
    return proctor;
}

void Student::setUniversityName(string uniName) {
    universityName = uniName;
}

void Student::setRegistrationNumber(int regNum) {
    registrationNumber = regNum;
}

void Student::setProctor(UniversityStaff proctor) {
    this->proctor = proctor;
}

Student& Student::operator=(const Student& rightSide) {
    if (this != &rightSide) {
        universityName = rightSide.universityName;
        registrationNumber = rightSide.registrationNumber;
        proctor = rightSide.proctor;
    }
    return *this;
}

// ScienceStudent class (derived from Student)

class ScienceStudent : public Student {
public:
    ScienceStudent();
    ScienceStudent(string uniName, int regNum, UniversityStaff proctor,
        string scienceDiscipline, string courseType);
    ScienceStudent(const ScienceStudent& other);
    ~ScienceStudent();

    string getScienceDiscipline() const;
    string getCourseType() const;

    void setScienceDiscipline(string scienceDiscipline);
    void setCourseType(string courseType);

    ScienceStudent& operator=(const ScienceStudent& rightSide);

private:
    string scienceDiscipline;
    string courseType;
};

ScienceStudent::ScienceStudent()
    : Student(), scienceDiscipline(""), courseType("") {}

ScienceStudent::ScienceStudent(string uniName, int regNum, UniversityStaff proctor,
    string scienceDiscipline, string courseType)
    : Student(uniName, regNum, proctor),
    scienceDiscipline(scienceDiscipline),
    courseType(courseType) {}

ScienceStudent::ScienceStudent(const ScienceStudent& other)
    : Student(other),
    scienceDiscipline(other.scienceDiscipline),
    courseType(other.courseType) {}

ScienceStudent::~ScienceStudent() {}

string ScienceStudent::getScienceDiscipline() const {
    return scienceDiscipline;
}

string ScienceStudent::getCourseType() const {
    return courseType;
}

void ScienceStudent::setScienceDiscipline(string scienceDiscipline) {
    this->scienceDiscipline = scienceDiscipline;
}

void ScienceStudent::setCourseType(string courseType) {
    this->courseType = courseType;
}

ScienceStudent& ScienceStudent::operator=(const ScienceStudent& rightSide) {
    if (this != &rightSide) {
        Student::operator=(rightSide);
        scienceDiscipline = rightSide.scienceDiscipline;
        courseType = rightSide.courseType;
    }
    return *this;
}

// Driver program to test the classes

int main() {
    // Create a UniversityStaff object
    UniversityStaff proctor("Dr. Smith");

    // Create a Student object
    Student student1("ABC University", 12345, proctor);

    // Test accessors
    cout << "University Name: " << student1.getUniversityName() << endl;
    cout << "Registration Number: " << student1.getRegistrationNumber() << endl;
    cout << "Proctor: " << student1.getProctor().getName() << endl;

    // Test mutators
    student1.setUniversityName("XYZ University");
    student1.setRegistrationNumber(54321);
    student1.setProctor(UniversityStaff("Prof. Johnson"));

    // Display updated information
    cout << "Updated University Name: " << student1.getUniversityName() << endl;
    cout << "Updated Registration Number: " << student1.getRegistrationNumber() << endl;
    cout << "Updated Proctor: " << student1.getProctor().getName() << endl;

    // Create a ScienceStudent object
    ScienceStudent scienceStudent("DEF University", 67890, proctor, "Physics", "Undergraduate");

    // Test accessors specific to ScienceStudent
    cout << "\nScience Discipline: " << scienceStudent.getScienceDiscipline() << endl;
    cout << "Course Type: " << scienceStudent.getCourseType() << endl;

    // Test mutators specific to ScienceStudent
    scienceStudent.setScienceDiscipline("Chemistry");
    scienceStudent.setCourseType("Postgraduate");

    // Display updated information
    cout << "Updated Science Discipline: " << scienceStudent.getScienceDiscipline() << endl;
    cout << "Updated Course Type: " << scienceStudent.getCourseType() << endl;

    return 0;
}
