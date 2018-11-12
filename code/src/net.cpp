#include "net.h"

net::net(string s[], int n)
{
    alpha_v.clear();
    rowSize = n;
    colSize = s[0].size();
    bUsed = (int **)malloc(sizeof(int*)*rowSize);
    for(int i = 0; i < rowSize; i++)
    {
        alpha_v.push_back(s[i]);
        bUsed[i] = (int *)malloc(sizeof(int)*colSize);
        for(int j = 0; j < colSize; j++)
        {
            bUsed[i][j] = 0;
        }
    }
}

net::~net()
{
    if(bUsed)
    {
        for(int i = 0; i < rowSize; i++)
        {
            free(bUsed[i]);
            bUsed[i] = NULL;
        }
        free(bUsed);
        bUsed = NULL;
    }
}

void net::printused()
{
#if 0    
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            printf("%d ",bUsed[i][j]);
        }
        printf("\n");
    }
    printf("\n");
#endif
}

void net::clear(int level)
{
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            if(bUsed[i][j] >= level)
            {
                bUsed[i][j] = 0;
            }
        }
    }
}

bool net::in_net(string &s)
{
    POS nNext = {-1, -1, false};
    POS nFirst = get_first(nNext,s);
    while(nFirst.bValid)
    {
        nNext = get_next(nFirst,s,1);
        if(nNext.bValid)
        {
            printused();
            return true;
        }
        printused();
        clear(1);
        nFirst = get_first(nFirst,s);
    }
    return false;
}

POS net::get_first(POS &start, string &s, int level)
{
    POS nPos = {-1, -1, false};
    bool bValid = false;

    for(int i = 0; i < rowSize; i++)
    {
        if(i < start.nRow)
            continue;

        for(int j = 0; j < colSize; j++)
        {
            if(i == start.nRow && j <= start.nCol)
                continue;

            nPos.nRow = i;
            nPos.nCol = j;

            if(bEqual(nPos.nRow,nPos.nCol,s,level))
            {
                nPos.bValid = true;
                return nPos;
            }
        }
    }
    return nPos;
}

POS net::get_next(POS &start, string &s, int level)
{
    POS nPos = {-1, -1, false};
    int nRows[4] = {-1,0,0,1};
    int nCols[4] = {0,-1,1,0};

    if(level >= s.size())
    {
        nPos.bValid = true;
        return nPos;
    }
    
    for(int i = 0; i < 4; i++)
    {
        nPos.nRow = start.nRow + nRows[i];
        nPos.nCol = start.nCol + nCols[i];

        if(bEqual(nPos.nRow,nPos.nCol,s,level))
        {
            return get_next(nPos, s, level+1);
        }
        else
        {
            clear(level+1);
        }
    }

    return nPos;
}

bool net::bEqual(int nRow, int nCol, string &s, int level)
{
    if(nRow < 0 || nRow >= rowSize || nCol < 0 || nCol >= colSize)
        return false;
    
    if(bUsed[nRow][nCol])
        return false;

    if(alpha_v.at(nRow)[nCol] != s[level])
        return false;
    
    bUsed[nRow][nCol] = level+1;
    return true;
}

