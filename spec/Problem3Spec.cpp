#include "stdafx.h"
#include <stdlib.h>
#include "./../src/Problem3.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem3Spec
	{
	private:
		TestContext^ testContextInstance;
	public:
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes
#pragma endregion 

		struct enode *newENode_spec(char *str)
		{
			struct enode *temp = (struct enode *)malloc(sizeof(struct enode));
			int i = 0;
			while (str[i] != '\0'){
				temp->data[i] = str[i];
				i++;
			}
			temp->data[i] = '\0';
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}

		//If you copy this function ,make sure you remove _spec so It wont be two functions with same name
		struct enode * constructEBinaryTree_spec(char strs[][6], int len){
			struct enode *root = NULL;
			struct enode *nodes[2005];
			for (int i = 0; i < len; i++){
				nodes[i] = newENode_spec(strs[i]);
			}
			int mid = (len / 2);
			for (int i = 0; i < mid; i++){
				struct enode *curnode = nodes[i];
				struct enode *leftnode = nodes[(i * 2) + 1];
				struct enode *rightnode = nodes[(i * 2) + 2];
				if (curnode->data[0] != 'X'){
					if (leftnode->data[0] != 'X'){
						curnode->left = leftnode;
					}
					if (rightnode->data[0] != 'X'){
						curnode->right = rightnode;
					}
				}
			}
			root = nodes[0];
			return root;
		}
		void test_Problem3_spec(char strs[][6], int len,int ans){
			struct enode *root = constructEBinaryTree_spec(strs, len);
			int actual = solve_tree(root);
			Assert::AreEqual(ans, actual, L"Failed sample 0 for NULL case in P1", 1, 2);
		}
		[TestMethod, Timeout(1000)]
		void Sample1_Problem3()
		{
			int check = solve_tree(NULL);
			Assert::AreEqual(-1, check, L"Failed sample 0 for NULL case in P1", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Sample2_Problem3()
		{
			//4+5=9
			char strs[][6] = { "+", "4", "5"};
			int len = 3;
			int ans = 9;
			test_Problem3_spec(strs, len, ans);

		};
		[TestMethod, Timeout(1000)]
		void Sample3_Problem3()
		{
			//(5 + (4*3) ) =17
			char strs[][6] = { "+", "5", "*", "X", "X", "4", "3" };
			int len = 7;
			int ans = 17;
			test_Problem3_spec(strs, len, ans);

		};

	};
}