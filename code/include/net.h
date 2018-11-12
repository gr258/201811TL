#ifndef NET_INCLUDE_H
#define NET_INCLUDE_H

#include <string>
#include <vector>
using namespace std;

typedef vector<string> VSTRING;

typedef struct
{
    int     nRow;
    int     nCol;
    bool    bValid;
}POS;

class net
{
public:
    net(string s[], int n);
    ~net();
    bool in_net(string &s);
private:
    POS     get_first(POS &start, string &s, int level = 0);
    POS     get_next(POS &start, string &s, int level);
    bool    bEqual(int nRow, int nCol, string &s, int level);
    void    clear(int level);
    void    printused();
    int     rowSize;
    int     colSize;
    int     **bUsed;
    VSTRING alpha_v;
};

#endif
