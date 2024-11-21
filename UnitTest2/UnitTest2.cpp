#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\екзу\source\repos\UnitTest2\functionTest\functionTest.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            double x = 10;
            int n = 4;
            double expected = 4;

            double actual = calculateY(x, n);

            Assert::AreEqual(expected, actual); 
        }

    public:
        TEST_METHOD(TestMethod2)
        {
            double x = 7;
            int n = 5;
            double expected = -3;

            double actual = calculateY(x, n);

            Assert::AreEqual(expected, actual); 
        }

    public:
        TEST_METHOD(TestMethod3)
        {
            double x = -10;
            int n = 3;
            double expected = 0; 

            double actual = calculateY(x, n);

            Assert::AreEqual(expected, actual); 
        }

    public:
        TEST_METHOD(TestMethod4_ExceptionCheck)
        {
            int n = -3; // n ok за умовою в функції n <= 0 

            try {
                double x = -8;  // не важливо 
                calculateY(x, n);

                Assert::Fail(L"Parameter 'n' must be greater than zero.");
            }
            catch (...) {
                Assert::IsTrue(true); 
            }
        }
    };
}
