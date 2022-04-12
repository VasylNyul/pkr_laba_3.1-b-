#include "pch.h"
#include "CppUnitTest.h"
#include "../pkr_laba_3.1(b)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pkrUnitTest31b
{
	TEST_CLASS(pkrUnitTest31b)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			s[0].prizv = "kvitka";
			s[0].kurs = 2;
			s[0].specialty = ²Ò;
			s[0].physic = 5;
			s[0].math = 5;
			s[0].pedagogika = 5;

			double p = Percent(s, N);
			Assert::AreEqual(p, 100.0);
		}
	};
}
