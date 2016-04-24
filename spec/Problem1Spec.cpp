#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/Problem1.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem1Spec
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
		struct node *newNode_spec(int key)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->data = key;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}

		struct node * constructBinaryTree_spec(int *arr, int len){
			struct node *root = NULL;
			struct node *nodes[2005];
			for (int i = 0; i < len; i++){
				nodes[i] = newNode_spec(arr[i]);
			}
			int mid = (len / 2);
			for (int i = 0; i < mid; i++){
				struct node *curnode = nodes[i];
				struct node *leftnode = nodes[(i * 2) + 1];
				struct node *rightnode = nodes[(i * 2) + 2];
				if (curnode->data != -999){
					if (leftnode->data != -999){
						curnode->left = leftnode;
					}
					if (rightnode->data != -999){
						curnode->right = rightnode;
					}
				}
			}
			root = nodes[0];
			return root;
		}

		void test_Problem1_spec(int *arr, int len,int actual_len,int ans){
			struct node *root = constructBinaryTree_spec(arr, len);
			int actual = get_missing_value(root, actual_len);
			printf("%d", actual);
			Assert::AreEqual(ans, actual, L"Failed sample 0 for NULL case in P1", 1, 2);
		}
		[TestMethod, Timeout(1000)]
		void Sample1_Problem1()
		{
			int check = get_missing_value(NULL,0);
			Assert::AreEqual(-1, check, L"Failed sample 0 for NULL case in P1", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Sample2_Problem1()
		{
			int arr[] = { -1, -2, -3, -999, 0, -5, 999 };
			int len = 7;
			int actual_len = 5;
			int ans = -4;
			test_Problem1_spec(arr, len,actual_len,ans);

		};


				
	};
}
