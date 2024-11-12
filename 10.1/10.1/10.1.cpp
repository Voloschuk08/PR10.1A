#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

enum Speciality { CS, IT, MECH, ELECTRONICS, MATH };
wstring specialityStr[] = { L"Комп'ютерні науки", L"Інформаційні технології", L"Механіка", L"Електроніка", L"Математика" };

struct Student {
    wstring surname;
    int course;
    Speciality speciality;
    int physics;
    int math;
    int informatics;
};

void createStudents(Student* students, int N) {
    for (int i = 0; i < N; ++i) {
        wcout << L"Студент №" << i + 1 << L":\n";
        wcout << L"Прізвище: ";
        wcin >> ws;
        getline(wcin, students[i].surname);
        wcout << L"Курс (1-5): ";
        wcin >> students[i].course;
        int specialityIndex;
        wcout << L"Спеціальність (0 - Комп'ютерні науки, 1 - Інформаційні технології, 2 - Механіка, 3 - Електроніка, 4 - Математика): ";
        wcin >> specialityIndex;
        students[i].speciality = static_cast<Speciality>(specialityIndex);
        wcout << L"Оцінка з фізики: ";
        wcin >> students[i].physics;
        wcout << L"Оцінка з математики: ";
        wcin >> students[i].math;
        wcout << L"Оцінка з інформатики: ";
        wcin >> students[i].informatics;
    }
}

void printStudentsTable(Student* students, int N) {
    wcout << L"=====================================================================================================\n";
    wcout << L"| №  | Прізвище                | Курс |         Спеціальність         | Фізика | Математика | Інформатика |\n";
    wcout << L"-----------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < N; ++i) {
        wcout << L"| " << setw(3) << right << i + 1 << L" ";
        wcout << L"| " << setw(20) << left << students[i].surname;
        wcout << L"| " << setw(4) << students[i].course << L" ";
        wcout << L"| " << setw(28) << left << specialityStr[students[i].speciality];
        wcout << L"| " << setw(6) << students[i].physics << L" ";
        wcout << L"| " << setw(10) << students[i].math << L" ";
        wcout << L"| " << setw(11) << students[i].informatics << L" |\n";
    }
    wcout << L"=====================================================================================================\n";
}

void printExcellentStudents(Student* students, int N) {
    bool found = false;
    wcout << L"\nСтуденти, які вчаться на \"відмінно\": ";
    for (int i = 0; i < N; ++i) {
        if (students[i].physics == 5 && students[i].math == 5 && students[i].informatics == 5) {
            if (found) {
                wcout << L", ";
            }
            wcout << students[i].surname;
            found = true;
        }
    }
    if (!found) {
        wcout << L"немає";
    }
    wcout << L"\n";
}

void calculateHighAveragePercentage(Student* students, int N) {
    int countHighAverage = 0;
    for (int i = 0; i < N; ++i) {
        double average = (students[i].physics + students[i].math + students[i].informatics) / 3.0;
        if (average > 4.5) {
            ++countHighAverage;
        }
    }
    double percentage = (static_cast<double>(countHighAverage) / N) * 100;
    wcout << L"Відсоток студентів із середнім балом більшим за 4.5: " << fixed << setprecision(2) << percentage << L"%\n";
}

int main() {
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stdin), _O_WTEXT);

    int N;
    wcout << L"Введіть кількість студентів: ";
    wcin >> N;

    Student* students = new Student[N];

    createStudents(students, N);

    wcout << L"\nТаблиця всіх студентів:\n";
    printStudentsTable(students, N);

    printExcellentStudents(students, N);
    calculateHighAveragePercentage(students, N);

    delete[] students;

    return 0;
}
