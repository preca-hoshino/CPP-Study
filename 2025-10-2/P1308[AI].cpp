// AGENT CODE
// P1308 - [NOIP 2011 普及组] 统计单词数
// GitHub Copilot - 2025-10-08 09:00:00
#include<bits/stdc++.h>
using namespace std;

// 转换为小写
string toLower(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

int main()
{
    string word;
    string article;
    
    getline(cin, word);
    getline(cin, article);
    
    // 转换为小写
    word = toLower(word);
    article = toLower(article);
    
    int count = 0;
    int first_pos = -1;
    
    // 在文章前后加空格，方便处理边界
    article = " " + article + " ";
    
    // 遍历文章，查找单词
    int pos = 0;
    while(pos < article.length())
    {
        // 跳过空格
        while(pos < article.length() && article[pos] == ' ')
        {
            pos++;
        }
        
        if(pos >= article.length())
        {
            break;
        }
        
        // 记录单词起始位置（相对于原文章，所以要-1）
        int word_start = pos - 1;
        
        // 提取当前单词
        string current_word = "";
        while(pos < article.length() && article[pos] != ' ')
        {
            current_word += article[pos];
            pos++;
        }
        
        // 检查是否匹配
        if(current_word == word)
        {
            count++;
            if(first_pos == -1)
            {
                first_pos = word_start;
            }
        }
    }
    
    if(count == 0)
    {
        cout << -1;
    }
    else
    {
        cout << count << " " << first_pos;
    }
    
    return 0;
}
