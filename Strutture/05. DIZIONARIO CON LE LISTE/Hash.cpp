#include <cstdlib>
#include <iostream>
#include "Hash.h"

using namespace std;

HashValue hash(string str)
    {
        HashValue hash = 5381;
        int l=str.length();
        int c;
        for (int i=0;i<l;i++)
        {
            int c=str[i];
            hash = hash*33 + c; // hash * 33 + c 
        }
        return hash;
    }
