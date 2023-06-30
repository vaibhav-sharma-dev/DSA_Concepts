#include <iostream>
#include <ctime>
#include <math.h> // int_max, int_min, pow ke lie
#include <algorithm> // max, min, sort, search ke lie
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>

using namespace std;

static void removeChar (char *str, char c)
{
    int j, n = strlen(str);
    for (int i=j=0; i<n; i++)
    {
        if (str[i]!=c)
            str[j++] = str[i];
    }

    str[j] = '\0';
}

static void cutMultipleUnderscoresToOne(char* str) {
    int j, n = strlen(str);
    for(int i = j = 0 ; i < n ; i++) {
        if(str[i] == '_') {
            while((i+1) < n && str[i+1] == '_') {
                i++;
            }
        }
        str[j++] = str[i];
    }
    str[j] = '\0';

    // int n = strlen(str);
    // string s = "";

    // for (int i=0; i<n; i++)
    // {
    //     if (str[i]!=str[i+1])
    //         s = s + str[i];
    // }

    // s.push_back(str[n-1]);
    // s.push_back('\0');

    // for (int i=0; i<s.length(); i++)
    //     str[i] = s[i];
    
}

static void replaceUnderscoresBwDigitsWithHash(char* str) {
    int n = strlen(str);
    for(int i = 0 ; i < n ; i++) {
        if(isdigit(str[i]) and (i+1) < n and str[i+1] == '_' and (i+2) < n and isdigit(str[i+2]))
            str[i+1] = '#';
    }
}

void applyDefaultPinNameChangingRules(std::string &pin) {
    if(pin.empty()) return;

    char* pin_name = strdup(pin.c_str());

    // Rule 1 - Remove \ and whitespace
    int j, n = strlen(pin_name); 
    for (int i = j = 0; i < n; i++) {
        switch (pin_name[i]) {
            case '\\':
            case ' ':
                //do nothing
                break;
            default:
                pin_name[j++] = pin_name[i];
        }
    }
    pin_name[j] = '\0';

    //Rule 2 - Replace /.[]() with _
    for(int i = 0 ; i < n ; i++) {
        char ch = pin_name[i];
        switch(ch) {
            case '/':
            case '.':
            case '(':
            case ')':
            case '[':
            case ']':
            {
                pin_name[i] = '_';
                break;
            }
            default:
                //do nothing
                break;
        }
    }

    //Rule 3
    cutMultipleUnderscoresToOne(pin_name);

    //Rule 4
    replaceUnderscoresBwDigitsWithHash(pin_name);

    //Rule 5
    removeChar(pin_name, '_');

    pin = pin_name;
    free(pin_name);
}

void new_op(string &str)
{
    int n = str.length();
    int j = 0;

    for (int i=0; i<n; i++)
    {
        if (str[i]==' ' || str[i]=='\\')
        {
            str.erase(i, 1);
            i--;
            j++;
        }

        else if (str[i]=='/' || str[i]=='.' || str[i]=='(' || str[i]==')' || str[i]=='[' || str[i]==']')
        {
            if (i>0 && isdigit(str[i-1]) && i<n && isdigit(str[i+1]))
                str[i] = '#';

            else
            {
                str.erase(i, 1);
                i--;
                j++;
            }
        }
    }
    str[n-j+1] = '\0';
}

void new_medhavi(string &s)
{
    int n = s.length();
     if(n==0)
        return;
    string result;
    int j=0,i=0;
    for(i=0;i<n;i++)
    {
        if(s[i]!=' ' && s[i]!= '\\' )
        {
            s[j++]=s[i];
        }
    }
    s=s.substr(0,j);
    // cout<<s<<endl;
   
    j=0;
    for(i=0;i<s.length();i++)
    {
        // cout<<"THE VALUE OF S IS "<<s<<endl;
     if(s[i]=='/' || s[i]=='.' || s[i]=='(' || s[i]==')' || s[i]=='[' || s[i]==']' || s[i]=='_')
        {
            for(;i<s.length();i++)
              {
                  if(isdigit(s[i]))
                  {
                     s[j++]='#';
                     s[j++]=s[i];
                     break;
                  }
                  else if(i==s.length()-1)
                  {
                     s[j++]='_';  
                  }
              }
        }
        else
            s[j++]=s[i];
       
    }
    s=s.substr(0,j);
    // cout<<"\n The result is : "<<s<<endl;
}

int main()
{
    string str = "ab\\cd e1/.2h[]i)(((";
    // string str = "0085 \\/._6/_";
    // clock_t c;

    // c = clock();
    // for (int i=0; i<200000; i++)
    //     applyDefaultPinNameChangingRules(str);

    // c = clock() - c;
    // cout << (float)c/CLOCKS_PER_SEC << endl;

    // c = clock();
    // for (int i=0; i<200000; i++)
    //     new_op(str);

    // c = clock() - c;
    // cout << (float)c/CLOCKS_PER_SEC << endl;

    // c = clock();
    // for (int i=0; i<200000; i++)
    //     new_medhavi(str);

    // c = clock() - c;
    // cout << (float)c/CLOCKS_PER_SEC << endl;

    applyDefaultPinNameChangingRules(str);
    cout << str;
}