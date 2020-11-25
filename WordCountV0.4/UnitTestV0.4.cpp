#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/wc.h"
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
			WordCount wc(order,file);
			wc.Count();
			Assert::AreEqual(14, wc.words + wc.rows - wc.blankline - wc.commentline);
		}
		TEST_METHOD(sentence)
		{
			string file = "D://test2.txt";
			string order = "-s";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(3, wc.sentence);
		}
		TEST_METHOD(length)
		{
			string file = "D://test2.txt";
			string order = "-c";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(118, wc.length);
		}
		TEST_METHOD(commentline)
		{
			string file = "D://test2.txt";
			string order = "-cl";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(6, wc.commentline);
		}
		TEST_METHOD(blankline)
		{
			string file = "D://test2.txt";
			string order = "-bl";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(2, wc.blankline);
		}
		TEST_METHOD(rows)
		{
			string file = "D://test2.txt";
			string order = "-tl";
			WordCount wc(order, file);
			wc.Count();
			Assert::AreEqual(11, wc.rows);
		}



	};
}
