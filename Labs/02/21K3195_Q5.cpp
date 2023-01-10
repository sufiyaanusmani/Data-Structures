// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 5

#include <iostream>
using namespace std;

class Students
{
private:
	float **student;
	int studentCount;
	int *courses;

public:
	Students(int studentCount)
	{
		this->studentCount = studentCount;
		student = new float *[studentCount];
		courses = new int[studentCount];
	}

	void input()
	{
		for (int i = 0; i < studentCount; i++)
		{
			cout << "Enter number of courses for student " << i + 1 << ": ";
			cin >> courses[i];
			student[i] = new float[courses[i]];
		}

		cout << endl;
		for (int i = 0; i < studentCount; i++)
		{
			for (int j = 0; j < courses[i]; j++)
			{
				cout << "Enter student " << i + 1 << ", Course " << j + 1 << " marks: ";
				cin >> student[i][j];
			}
			cout << endl;
		}
	}

	void calculateGPA()
	{
		float *gpa = new float[studentCount];
		int creditHours;
		for (int i = 0; i < studentCount; i++)
		{
			gpa[i] = 0.0;
			for (int j = 0; j < courses[i]; j++)
			{
				gpa[i] += (student[i][j] * 3);
			}
			creditHours = courses[i] * 3;
			gpa[i] /= creditHours;
		}

		for (int i = 0; i < studentCount; i++)
		{
			cout << "GPA of student " << i + 1 << ": " << gpa[i] << endl;
		}

		delete[] gpa;
	}

	~Students()
	{
		for (int i = 0; i < studentCount; i++)
		{
			delete[] student[i];
		}
		delete[] student;
		delete[] courses;
	}
};

int main()
{
	int noOfStudents = 5;
	Students student(noOfStudents);

	student.input();
	student.calculateGPA();

	return 0;
}
