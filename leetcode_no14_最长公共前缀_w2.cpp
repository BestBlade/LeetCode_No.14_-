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

/*	纵向比较法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了91.73%的用户
*	内存消耗：6.9 MB, 在所有 C++ 提交中击败了54.79%的用户
*/
#include <iostream>
#include <vector>

using namespace std;

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
		int length = strs[0].size();
		for (int i = 0; i < length; i++)
		{
			char c = strs[0][i];
			for (int j = 0;j < nums; j++)
			{
				if (i == strs[j].size()|| strs[j][i] != c)											/*	匹配不上的情况肯定是比匹配的上的情况少的，因此判断匹配不上的情况更好一些	*/
				{
					return strs[0].substr(0, i);
				}
			}
		}
	}
	return strs[0];
}


int main()
{
	vector<string> strs = { "flower","flow","flight" };

	cout << longestCommonPrefix(strs) << endl;
}