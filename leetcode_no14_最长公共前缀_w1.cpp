/*------------------------------------------------------------------|
编写一个函数来查找字符串数组中的最长公共前缀。						|
																	|
如果不存在公共前缀，返回空字符串 ""。								|
																	|
示例 1:																|
																	|
输入: ["flower","flow","flight"]									|
输出: "fl"															|
示例 2:																|
																	|
输入: ["dog","racecar","car"]										|
输出: ""															|
解释: 输入不存在公共前缀。											|
说明:																|
																	|
所有输入只包含小写字母 a-z 。										|
																	|
来源：力扣（LeetCode）												|
链接：https://leetcode-cn.com/problems/longest-common-prefix		|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	横向比较法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了91.73%的用户
*	内存消耗：7.1 MB, 在所有 C++ 提交中击败了20.09%的用户
*/
#include <iostream>
#include <vector>

using namespace std;

string match(const string &str1,const string &str2)
{
	int length = min(str1.size(), str2.size());
	 
	int  result = {0};

	while (result < length && str1[result] == str2[result])
	{
		result++;
	}
	return str1.substr(0, result);
}

string longestCommonPrefix(vector<string>& strs) 
{
	int nums = strs.size();

	string result;

	if (nums == 0)
	{
		return result;
	}

	if (nums == 1)
	{
		return strs[0];
	}

	if (nums >= 2)
	{
		result = strs[0];
		for (int i = 1; i < nums; i++)
		{
			result = match(result, strs[i]);
			if (!result.size())
			{
				break;
			}
		}
	}
	
	//if (nums >= 2)														/*	同样的思路，这种写法就比上面的慢一倍	*/
	//{
	//	string common = match(strs[0], strs[1]);

	//	for (int i = 2; i < nums; i++)
	//	{
	//		if (common == "")
	//		{
	//			return common;
	//		}
	//		common = match(common, strs[i]);
	//	}
	//	result = common;
	//}

	return result;
}

int main()
{
	vector<string> strs = { "flower","flow","flight" };

	//

	//

	cout << longestCommonPrefix(strs) << endl;
}