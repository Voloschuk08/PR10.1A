#include "pch.h"
#include "CppUnitTest.h"
#include "../10.1/10.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101
{
	TEST_CLASS(UnitTest101)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Student students[3] = {
               { L"Волощук", 1, IT, 5, 5, 5 },
               { L"Савчук", 2, ELECTRONICS, 4, 5, 5 },
               { L"Грицак", 2, CS, 5, 4, 5 }
            };

            // Очікувана кількість студентів із оцінками 5
            int expectedCount = 1;
            int actualCount = 0;

            for (int i = 0; i < 3; ++i) {
                if (students[i].physics == 5 && students[i].math == 5 && students[i].informatics == 5) {
                    ++actualCount;
                }
            }

            Assert::AreEqual(expectedCount, actualCount, L"Перевірка кількості студентів, які вчаться на \"відмінно\"");

		}
	};
}
