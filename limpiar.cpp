#include <bits/stdc++.h>
using namespace std;


bool modificadores[300];//bloqmayus, shif, ctrl, alt, altgr, fn;

void esp(int espacios)
{
    for (int i = 0; i<espacios; ++i)
        cout<<" ";
}

int main()
{    
    freopen("keyloger.in","r", stdin);
    freopen("keyloger.out","w", stdout);


    #include "mapeo.h"

    string s, kicod, evento;
    int num_letra, espacios = 0;
    bool imprimio = false;
    while(getline(cin, s))
    {
        if (not s.size()) continue;        
        stringstream ss(s);
        ss>>kicod;
        if (kicod[1]!='e') continue;

        ss>>num_letra>>evento;

        if (mapa[num_letra] == "")
        {
            printf("%d %c ", num_letra, evento[0]);
            continue;
        }

        imprimio = true;

        if (num_letra == 42 or num_letra == 54 or //shif
            num_letra == 29 or num_letra == 97 or //ctrl
            num_letra == 56 or num_letra == 100 or  //alt
            num_letra == 143 //fn
            )   
        {
            if (evento[0] == 'r')
            {
                cout<<"\n";
                espacios -= 4;
                esp(espacios);
                cout<<mapa[num_letra]<<" levantado\n";
                modificadores[num_letra] = false;  
            }
            else
            {
                if (modificadores[num_letra]) continue;
                cout<<"\n";
                esp(espacios);
                cout<<mapa[num_letra]<<"\n";
                espacios += 4;
                esp(espacios);
                modificadores[num_letra] = true;
            }
        }

        else if (num_letra == 58)
        {
            if (evento[0] == 'r')
            {
                modificadores[num_letra] = not modificadores[num_letra];
                cout<<"\n"<<mapa[num_letra]<<(modificadores[num_letra] ? "\n":" levantado\n");                
            }
        }

        

        else if (evento[0] == 'p')
        {
            if (num_letra == 28)
                cout<<"\n";
            else cout<<mapa[num_letra];
        }
            
    }
    if (imprimio)
        cout<<"---------------------------------\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}