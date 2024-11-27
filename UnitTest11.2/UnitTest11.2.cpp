#include "pch.h"
#include "CppUnitTest.h"
#include "C:\laboratory works\laboratory11.2\lab11.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest112
{
	TEST_CLASS(UnitTest112)
	{
	public:
		
        TEST_METHOD(TestReplace)
        {
            ofstream inputFile("test_input.txt");
            inputFile << "This is a test (remove this). This is another line (remove)."
                << std::endl << "No parentheses here." << std::endl;
            inputFile.close();

            ofstream outputFile("test_output.txt");

            ifstream t1("test_input.txt");
            if (!t1.is_open()) {
                std::cerr << "Error opening input file!" << std::endl;
                return;
            }

            replace(t1, outputFile);

            t1.close();
            outputFile.close();

            ifstream resultFile("test_output.txt");
            string line;
            string expectedOutput[] = {
                "This is a test . This is another line .",
                "No parentheses here."
            };

            int lineNumber = 0;
            while (getline(resultFile, line)) {
                Assert::AreEqual(expectedOutput[lineNumber].c_str(), line.c_str(), L"Test failed! Output does not match expected.");
                lineNumber++;
            }

            resultFile.close();
            std::cout << "Test passed!" << std::endl;
        }
	};
}
