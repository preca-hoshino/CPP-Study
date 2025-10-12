// AGENT CODE
// P9364 - [ICPC 2022 Xi'an R] Perfect Word
// GitHub Copilot - 2025-10-12 00:00:00

/*
 * 题目要求：找到最长的「完美单词」
 * 完美单词定义：该字符串的所有非空子串都必须在给定的字符串集合中出现
 * 
 * 解题思路：
 * 1. 使用 unordered_set 存储所有给定字符串，支持 O(1) 的平均查找时间
 * 2. 按字符串长度从长到短排序，优先检查长字符串
 * 3. 对于每个字符串，枚举其所有子串并检查是否都在集合中
 * 4. 一旦找到完美单词就可以返回（因为已按长度降序排列）
 * 
 * 优化点：
 * - 使用 unordered_set 代替 set，查找时间从 O(logn) 降到 O(1)
 * - 按长度降序排序，找到第一个完美单词即可返回
 * - 使用 find() 代替 count()，语义更清晰
 * 
 * 时间复杂度：O(n*L + n*logn + n*L^3)，其中 n 是字符串数量，L 是最长字符串长度
 * 空间复杂度：O(n * L)
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    // words: 使用 unordered_set 存储所有字符串，O(1) 平均查找时间
    unordered_set<string> words;
    
    // input: 存储所有输入字符串，用于排序和遍历
    vector<string> input;
    
    // 读取所有字符串
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        words.insert(s);
        input.push_back(s);
    }
    
    // 按字符串长度从长到短排序，优先检查长字符串
    // 这样找到的第一个完美单词就是最长的
    sort(input.begin(), input.end(), [](const string& a, const string& b)
    {
        return a.length() > b.length();
    });
    
    // 检查每个字符串是否是完美单词
    for(const string& s : input)
    {
        bool isPerfect = true;
        int len = s.length();
        
        // 枚举当前字符串的所有子串
        // i 是子串的起始位置
        for(int i = 0; i < len && isPerfect; i++)
        {
            // j 是子串的长度
            for(int j = 1; j <= len - i && isPerfect; j++)
            {
                // 提取子串 s[i...i+j-1]，长度为 j
                string sub = s.substr(i, j);
                
                // 检查子串是否在集合中
                if(words.find(sub) == words.end())
                {
                    // 如果有任何一个子串不在集合中，则不是完美单词
                    isPerfect = false;
                }
            }
        }
        
        // 如果找到完美单词，直接输出并返回
        // 因为已按长度降序排列，这就是最长的完美单词
        if(isPerfect)
        {
            cout << len;
            return 0;
        }
    }
    
    // 如果没有找到任何完美单词，输出 0
    cout << 0;
    return 0;
}

/*
 * 示例分析：
 * 输入: a, t, b, ab
 * 
 * 检查 "a"：
 *   - 子串 "a" 在集合中 ✓
 *   - 是完美单词，长度 1
 * 
 * 检查 "t"：
 *   - 子串 "t" 在集合中 ✓
 *   - 是完美单词，长度 1
 * 
 * 检查 "b"：
 *   - 子串 "b" 在集合中 ✓
 *   - 是完美单词，长度 1
 * 
 * 检查 "ab"：
 *   - 子串 "a" 在集合中 ✓
 *   - 子串 "ab" 在集合中 ✓
 *   - 子串 "b" 在集合中 ✓
 *   - 是完美单词，长度 2
 * 
 * 最长完美单词长度为 2
 */
