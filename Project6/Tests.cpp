#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Admin\Desktop\1\Project6\Project6\logika.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MyTests
{
    TEST_CLASS(MyTests)
    {
    public:

        TEST_METHOD(TestNormalValues)
        {
            float x = 1.0f;
            float y = 1.0f;
            float S = 0.0f;
            float R = 0.0f;
            float C = 0.0f;

            float expected_S = 0.5f;

            Calculate(x, y, S, R, C);

            Assert::AreEqual(expected_R, R, 0.001f, L"R is incorrect");
            Assert::AreEqual(expected_S, S, 0.001f, L"S is incorrect");

            Assert::AreEqual(expected_R, C, 0.001f, L"C is incorrect");
        }

        TEST_METHOD(TestDivisionByZero) {
            float x = 0.0f;
            float y = 7.0f;
            float S = 0.0f;
            float R = 0.0f;
            float C = 0.0f;

            auto func = [&] { Calculate(x, y, S, R, C); };

            Assert::ExpectException<std::invalid_argument>(func, L"x должен быть > 0");
        }

        TEST_METHOD(TestNegativeX) {
            float x = -2.0f;
            float y = 5.0f;
            float S = 0.0f;
            float R = 0.0f;
            float C = 0.0f;

            auto func = [&] { Calculate(x, y, S, R, C); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestXEqualsY) {
            float x = 2.0f;
            float y = 2.0f;
            float S = 0.0f;
            float R = 0.0f;
            float C = 0.0f;


            float expected_R = 3.0f;
            float expected_S = 0.0f;

            Calculate(x, y, S, R, C);

            Assert::AreEqual(expected_R, R, 0.001f, L"R for x=y is incorrect");
            Assert::AreEqual(expected_S, S, 0.001f, L"S for x=2 is incorrect");
            // C = max(3.0, 0) = 3.0
            Assert::AreEqual(expected_R, C, 0.001f, L"C for x=y is incorrect");
        }

        TEST_METHOD(TestYZero) {
            float x = 3.0f;
            float y = 0.0f;
            float S = 0.0f;
            float R = 0.0f;
            float C = 0.0f;


            float expected_R = 3.0f;

            Calculate(x, y, S, R, C);

            Assert::AreEqual(expected_R, R, 0.001f, L"R with y=0 is incorrect");

        }
    };
}