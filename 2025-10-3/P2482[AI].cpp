// AGENT CODE
// P2482 - [SDOI2010] 猪国杀
// GitHub Copilot - 2025-10-15 00:00:00

/*
 * 完整实现猪国杀游戏模拟
 * 包含所有牌的效果和复杂的AI逻辑
 */

#include<bits/stdc++.h>
using namespace std;

class Game;

class Player
{
public:
    string role;
    int hp;
    deque<string> cards;
    bool hasZhu;
    bool isDead;
    char identity;
    bool isLikeFP;
    int usedKill;
    
    Player() : hp(4), hasZhu(false), isDead(false), identity('N'), isLikeFP(false), usedKill(0) {}
};

class Game
{
public:
    int n, m;
    vector<Player> p;
    deque<string> deck;
    
    Game(int n, int m) : n(n), m(m) { p.resize(n); }
    
    string draw()
    {
        if(deck.empty()) return "";
        string card = deck.front();
        deck.pop_front();
        return card;
    }
    
    bool gameOver()
    {
        if(p[0].isDead) return true;
        for(int i = 1; i < n; i++)
            if(p[i].role == "FP" && !p[i].isDead) return false;
        return true;
    }
    
    void handleDeath(int idx, int src)
    {
        p[idx].isDead = true;
        p[idx].cards.clear();
        p[idx].hasZhu = false;
        
        if(p[idx].role == "FP" && src >= 0 && !p[src].isDead)
        {
            for(int i = 0; i < 3; i++)
            {
                string c = draw();
                if(!c.empty()) p[src].cards.push_back(c);
            }
        }
        else if(p[idx].role == "ZP" && src == 0)
        {
            p[0].cards.clear();
            p[0].hasZhu = false;
        }
    }
    
    void damage(int idx, int dmg, int src)
    {
        p[idx].hp -= dmg;
        while(p[idx].hp <= 0 && !p[idx].isDead)
        {
            bool saved = false;
            for(auto it = p[idx].cards.begin(); it != p[idx].cards.end(); ++it)
            {
                if(*it == "P")
                {
                    p[idx].cards.erase(it);
                    p[idx].hp++;
                    saved = true;
                    break;
                }
            }
            if(!saved) handleDeath(idx, src);
        }
    }
    
    void markIdentity(int actor, int target, bool hostile)
    {
        if(p[actor].identity != 'N') return;
        
        if(p[actor].role == "ZP")
        {
            if((hostile && p[target].identity == 'F') || 
               (!hostile && (target == 0 || p[target].identity == 'Z')))
            {
                p[actor].identity = 'Z';
            }
        }
        else if(p[actor].role == "FP")
        {
            if((hostile && (target == 0 || p[target].identity == 'Z')) || 
               (!hostile && p[target].identity == 'F'))
            {
                p[actor].identity = 'F';
            }
        }
    }
    
    bool askWuXie(int from, int target, bool forGood)
    {
        int curr = from;
        for(int cnt = 0; cnt < n; cnt++)
        {
            if(p[curr].isDead)
            {
                curr = (curr + 1) % n;
                continue;
            }
            
            bool wantUse = false;
            
            // 未表明身份的猪不能对自己用无懈可击
            if(curr == target && p[curr].identity == 'N') 
            {
                curr = (curr + 1) % n;
                continue;
            }
            
            if(p[curr].role == "MP")
            {
                if(forGood && (target == 0 || p[target].identity == 'Z'))
                    wantUse = true;
                else if(!forGood && (p[target].isLikeFP || p[target].identity == 'F'))
                    wantUse = true;
            }
            else if(p[curr].role == "ZP")
            {
                if(forGood && (target == 0 || p[target].identity == 'Z'))
                    wantUse = true;
                else if(!forGood && p[target].identity == 'F')
                    wantUse = true;
            }
            else if(p[curr].role == "FP")
            {
                if(forGood && p[target].identity == 'F')
                    wantUse = true;
                else if(!forGood && (target == 0 || p[target].identity == 'Z'))
                    wantUse = true;
            }
            
            if(wantUse)
            {
                for(auto it = p[curr].cards.begin(); it != p[curr].cards.end(); ++it)
                {
                    if(*it == "J")
                    {
                        p[curr].cards.erase(it);
                        markIdentity(curr, target, !forGood);
                        return !askWuXie(from, target, !forGood);
                    }
                }
            }
            
            curr = (curr + 1) % n;
        }
        return forGood;
    }
    
    void useKill(int from, int to)
    {
        if(p[to].isDead) return;
        markIdentity(from, to, true);
        
        bool dodged = false;
        for(auto it = p[to].cards.begin(); it != p[to].cards.end(); ++it)
        {
            if(*it == "D")
            {
                p[to].cards.erase(it);
                dodged = true;
                break;
            }
        }
        if(!dodged) damage(to, 1, from);
    }
    
    void useDuel(int from, int to)
    {
        if(p[to].isDead) return;
        markIdentity(from, to, true);
        
        if(!askWuXie(from, to, false))
        {
            int turn = to;
            while(true)
            {
                bool hasKill = false;
                bool wantKill = !(p[turn].role == "ZP" && from == 0);
                
                if(wantKill)
                {
                    for(auto it = p[turn].cards.begin(); it != p[turn].cards.end(); ++it)
                    {
                        if(*it == "K")
                        {
                            p[turn].cards.erase(it);
                            hasKill = true;
                            break;
                        }
                    }
                }
                
                if(!hasKill)
                {
                    damage(turn, 1, (turn == to) ? from : to);
                    break;
                }
                turn = (turn == to) ? from : to;
            }
        }
    }
    
    void useNanZhu(int from)
    {
        int curr = (from + 1) % n;
        for(int cnt = 0; cnt < n - 1; cnt++)
        {
            if(gameOver()) return;
            
            int loopGuard = 0;
            while(p[curr].isDead)
            {
                curr = (curr + 1) % n;
                loopGuard++;
                if(loopGuard > n || curr == from) return;
            }
            
            bool needDamage = true;
            if(p[curr].identity != 'N')
            {
                if(askWuXie(from, curr, true)) needDamage = false;
            }
            
            if(needDamage)
            {
                bool hasKill = false;
                for(auto it = p[curr].cards.begin(); it != p[curr].cards.end(); ++it)
                {
                    if(*it == "K")
                    {
                        p[curr].cards.erase(it);
                        hasKill = true;
                        break;
                    }
                }
                if(!hasKill)
                {
                    int hpBefore = p[curr].hp;
                    damage(curr, 1, from);
                    // 主猪受到伤害，标记使用者为类反猪
                    if(curr == 0 && p[from].identity == 'N' && p[curr].hp < hpBefore && !p[curr].isDead)
                    {
                        p[from].isLikeFP = true;
                    }
                }
            }
            curr = (curr + 1) % n;
        }
    }
    
    void useWanJian(int from)
    {
        int curr = (from + 1) % n;
        for(int cnt = 0; cnt < n - 1; cnt++)
        {
            if(gameOver()) return;
            
            int loopGuard = 0;
            while(p[curr].isDead)
            {
                curr = (curr + 1) % n;
                loopGuard++;
                if(loopGuard > n || curr == from) return;
            }
            
            bool needDamage = true;
            if(p[curr].identity != 'N')
            {
                if(askWuXie(from, curr, true)) needDamage = false;
            }
            
            if(needDamage)
            {
                bool hasDodge = false;
                for(auto it = p[curr].cards.begin(); it != p[curr].cards.end(); ++it)
                {
                    if(*it == "D")
                    {
                        p[curr].cards.erase(it);
                        hasDodge = true;
                        break;
                    }
                }
                if(!hasDodge)
                {
                    int hpBefore = p[curr].hp;
                    damage(curr, 1, from);
                    // 主猪受到伤害，标记使用者为类反猪
                    if(curr == 0 && p[from].identity == 'N' && p[curr].hp < hpBefore && !p[curr].isDead)
                    {
                        p[from].isLikeFP = true;
                    }
                }
            }
            curr = (curr + 1) % n;
        }
    }
    
    int findTarget(int idx)
    {
        for(int i = 1; i < n; i++)
        {
            int t = (idx + i) % n;
            if(p[t].isDead) continue;
            
            if(p[idx].role == "MP")
            {
                if(p[t].isLikeFP || p[t].identity == 'F') return t;
            }
            else if(p[idx].role == "ZP")
            {
                if(p[t].identity == 'F') return t;
            }
            else if(p[idx].role == "FP")
            {
                if(t == 0) return 0;
                if(p[t].identity == 'Z') return t;
            }
        }
        return -1;
    }
    
    void turn(int idx)
    {
        if(p[idx].isDead) return;
        p[idx].usedKill = 0;
        
        string c1 = draw(), c2 = draw();
        if(!c1.empty()) p[idx].cards.push_back(c1);
        if(!c2.empty()) p[idx].cards.push_back(c2);
        
        int playCount = 0;
        while(true)
        {
            playCount++;
            if(playCount > 100) return;
            if(gameOver()) return;
            bool played = false;
            
            for(int i = 0; i < p[idx].cards.size(); i++)
            {
                string card = p[idx].cards[i];
                
                if(card == "P" && p[idx].hp < 4)
                {
                    p[idx].cards.erase(p[idx].cards.begin() + i);
                    p[idx].hp++;
                    played = true;
                    break;
                }
                
                if(card == "K" && (p[idx].hasZhu || p[idx].usedKill == 0))
                {
                    int t = findTarget(idx);
                    if(t != -1)
                    {
                        p[idx].cards.erase(p[idx].cards.begin() + i);
                        p[idx].usedKill++;
                        useKill(idx, t);
                        played = true;
                        break;
                    }
                }
                
                if(card == "F")
                {
                    int t = findTarget(idx);
                    if(t != -1)
                    {
                        p[idx].cards.erase(p[idx].cards.begin() + i);
                        useDuel(idx, t);
                        played = true;
                        break;
                    }
                }
                
                if(card == "N")
                {
                    p[idx].cards.erase(p[idx].cards.begin() + i);
                    useNanZhu(idx);
                    played = true;
                    break;
                }
                
                if(card == "W")
                {
                    p[idx].cards.erase(p[idx].cards.begin() + i);
                    useWanJian(idx);
                    played = true;
                    break;
                }
                
                if(card == "Z")
                {
                    p[idx].cards.erase(p[idx].cards.begin() + i);
                    p[idx].hasZhu = true;
                    played = true;
                    break;
                }
            }
            if(!played) break;
        }
    }
    
    void run()
    {
        int roundCount = 0;
        while(!gameOver() && roundCount < 100)
        {
            roundCount++;
            for(int i = 0; i < n; i++)
            {
                turn(i);
                if(gameOver()) break;
            }
        }
    }
    
    void output()
    {
        cout << (p[0].isDead ? "FP" : "MP") << endl;
        for(int i = 0; i < n; i++)
        {
            if(p[i].isDead) cout << "DEAD" << endl;
            else
            {
                for(int j = 0; j < p[i].cards.size(); j++)
                {
                    if(j > 0) cout << " ";
                    cout << p[i].cards[j];
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Game game(n, m);
    
    for(int i = 0; i < n; i++)
    {
        cin >> game.p[i].role;
        for(int j = 0; j < 4; j++)
        {
            string card;
            cin >> card;
            game.p[i].cards.push_back(card);
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        string card;
        cin >> card;
        game.deck.push_back(card);
    }
    
    game.run();
    game.output();
    return 0;
}
