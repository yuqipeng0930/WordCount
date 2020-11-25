#include "pch.h"
#include "CppUnitTest.h"
#include"../Project1/wc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(words)
		{
			string file = "D://test1.txt";
			string order = "-w";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(14, wc.words + wc.rows - wc.blankline - wc.commentline);
		}
		TEST_METHOD(sentence)
		{
			string file = "D://test1.txt";
			string order = "-s";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(3, wc.sentence);
		}
		TEST_METHOD(length)
		{
			string file = "D://test1.txt";
			string order = "-c";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(65, wc.length);
		}
		
		TEST_METHOD(rows)
		{
			string file = "D://test1.txt";
			string order = "-tl";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(3, wc.rows);
		}
	};
}
