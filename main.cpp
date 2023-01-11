#include <iostream>
#include<string>
#include<vector>
using namespace std;
class BigDecimalInt
{
public:
    string number;
    BigDecimalInt(){}
    BigDecimalInt(string num)
    {
        number=num;
    }
    BigDecimalInt operator +(BigDecimalInt &t)
    {
        BigDecimalInt n;
        int i=0;
        int y=0;
        int z=0;
        int w=0;
        string m;
        vector<int> arr1(number.length(),-1);
        vector<int> arr2(t.number.length(),-1);
        vector<int> v(number.length()+t.number.length(),-1);
        if(number[0]=='-' )
        {
            for(int i=0; i<number.length()-1; i++)
            {
                arr1[i]=number[i+1]-'0';
            }
        }
        else
        {
            for(int i=0; i<number.length(); i++)
            {
                arr1[i]=number[i]-'0';
            }

        }
        if(t.number[0]=='-' || t.number[0]=='+')
        {
            for(int i=0; i<t.number.length()-1; i++)
            {
                arr2[i]=t.number[i+1]-'0';
            }
        }
        else
        {
            for(int i=0; i<t.number.length(); i++)
            {
                arr2[i]=t.number[i]-'0';
            }
        }
        if(number[0]=='-')
        {
            y=number.length()-2;
        }
        else
        {
            y=number.length()-1;
        }
        if(t.number[0]=='-' || t.number[0]=='+')
        {
            z=t.number.length()-2;
        }
        else
        {
             z=t.number.length()-1;
        }
        w=0;
        for(int i=0;i<arr1.size();i++)
        {
            if(number[0]=='-'&&arr1.back()==-1)
            {
                arr1.pop_back();
            }
        }
        for(int i=0;i<arr2.size();i++)
        {
            if((t.number[0]=='-' || t.number[0]=='+')&&arr2.back()==-1)
            {
                arr2.pop_back();
            }
        }
        i=number.length()+t.number.length()-1;
        if(((number[0]=='-'&&t.number[0]!='-')&&(arr1.size()==arr2.size())) || ((number[0]!='-'&&t.number[0]=='-')&&(arr1.size()==arr2.size())))
        {
            for(int i=0;i<arr1.size();i++)
            {
                if(arr1[i]>arr2[i])
                {
                    m="true";
                    break;
                }
                else if(arr1[i]<arr2[i])
                {
                     m="false";
                    break;
                }
                else
                {
                    m="true1";
                }
            }
        }
        while(true)
        {
            if((number[0]=='-'&&t.number[0]=='-')||(number[0]!='-'&&t.number[0]!='-'))
            {
                if(arr1[y]+arr2[z]+w>=10)
                {
                    v[i]=arr1[y]+arr2[z]+w-10;
                    w=0;
                    w++;
                }
                else
                {
                    v[i]=arr1[y]+arr2[z]+w;
                    w=0;

                }
                if(z==0&&y==0)
                {
                    if(w>0)
                    {
                        v[i-1]=w;
                    }
                    break;
                }
                i--;
                y--;
                z--;
                if(y<0)
                {
                    y=0;
                    arr1[y]=0;
                }
                if(z<0)
                {
                    z=0;
                    arr2[z]=0;
                }
            }
            else if(number[0]=='-'&&t.number[0]!='-')
            {
                if(arr1.size()>arr2.size())
                {
                    if(arr1[y]==arr2[z])
                    {
                        v[i]=arr1[y]-arr2[z];
                    }
                    else if(arr1[y]>arr2[z])
                    {
                        v[i]=arr1[y]-arr2[z];
                    }
                    else if(arr1[y]<arr2[z])
                    {
                        v[i]=arr1[y]+10-arr2[z];
                        arr1[y-1]=arr1[y-1]-1;
                    }
                }
                else if(arr1.size()<arr2.size())
                {
                    if(arr2[z]==arr1[y])
                    {
                        v[i]=arr2[z]-arr1[y];
                    }
                    else if(arr2[z]>arr1[y])
                    {
                        v[i]=arr2[z]-arr1[y];
                    }
                    else if(arr2[z]<arr1[y])
                    {
                        v[i]=arr2[z]+10-arr1[y];
                        arr2[z-1]=arr2[z-1]-1;
                    }
                }
                else
                {
                    if(m=="true")
                    {
                        if(arr1[y]==arr2[z])
                        {
                            v[i]=arr1[y]-arr2[z];
                        }
                        else if(arr1[y]>arr2[z])
                        {
                            v[i]=arr1[y]-arr2[z];
                        }
                        else if(arr1[y]<arr2[z])
                        {
                            v[i]=arr1[y]+10-arr2[z];
                            arr1[y-1]=arr1[y-1]-1;
                        }
                    }
                    else if(m=="false")
                    {
                        if(arr2[z]==arr1[y])
                        {
                            v[i]=arr2[z]-arr1[y];
                        }
                        else if(arr2[z]>arr1[y])
                        {
                            v[i]=arr2[z]-arr1[y];
                        }
                        else if(arr2[z]<arr1[y])
                        {
                            v[i]=arr2[z]+10-arr1[y];
                            arr2[z-1]=arr2[z-1]-1;
                        }
                    }
                    else
                    {
                        v[i]=arr1[y]-arr2[z];
                    }
                }
                if(z==0&&y==0)
                {
                    break;
                }
                i--;
                y--;
                z--;
                if(y<0)
                {
                    y=0;
                    arr1[y]=0;
                }

                if(z<0)
                {
                    z=0;
                    arr2[z]=0;
                }
            }
            else if(number[0]!='-'&&t.number[0]=='-')
            {
                if(arr1.size()>arr2.size())
                {
                    if(arr1[y]==arr2[z])
                    {
                        v[i]=arr1[y]-arr2[z];
                    }
                    else if(arr1[y]>arr2[z])
                    {
                        v[i]=arr1[y]-arr2[z];
                    }
                    else if(arr1[y]<arr2[z])
                    {
                        v[i]=arr1[y]+10-arr2[z];
                        arr1[y-1]=arr1[y-1]-1;
                    }
                }
                else if(arr1.size()<arr2.size())
                {
                    if(arr2[z]==arr1[y])
                    {
                        v[i]=arr2[z]-arr1[y];
                    }
                    else if(arr2[z]>arr1[y])
                    {
                        v[i]=arr2[z]-arr1[y];
                    }
                    else if(arr2[z]<arr1[y])
                    {
                        v[i]=arr2[z]+10-arr1[y];
                        arr2[z-1]=arr2[z-1]-1;
                    }
                }
                else
                {
                    if(m=="true")
                    {
                        if(arr1[y]==arr2[z])
                        {
                            v[i]=arr1[y]-arr2[z];
                        }
                        else if(arr1[y]>arr2[z])
                        {
                            v[i]=arr1[y]-arr2[z];
                        }
                        else if(arr1[y]<arr2[z])
                        {
                            v[i]=arr1[y]+10-arr2[z];
                            arr1[y-1]=arr1[y-1]-1;
                        }
                    }
                    else if(m=="false")
                    {
                        if(arr2[z]==arr1[y])
                        {
                            v[i]=arr2[z]-arr1[y];
                        }
                        else if(arr2[z]>arr1[y])
                        {
                            v[i]=arr2[z]-arr1[y];
                        }
                        else if(arr2[z]<arr1[y])
                        {
                            v[i]=arr2[z]+10-arr1[y];
                            arr2[z-1]=arr2[z-1]-1;
                        }
                    }
                    else
                    {
                        v[i]=arr1[y]-arr2[z];
                    }
                }
                if(z==0&&y==0)
                {
                    break;
                }
                i--;
                y--;
                z--;
                if(y<0)
                {
                    y=0;
                    arr1[y]=0;
                }

                if(z<0)
                {
                    z=0;
                    arr2[z]=0;
                }
            }
        }
        for(int i=0;i<v.size();i++)
        {
              if(v[i]==0&&v[i-1]==-1)
              {
                v[i]=-1;
              }
        }
        if((number[0]=='-'&&t.number[0]=='-')||((number[0]=='-' && t.number[0]!='-') && (arr1.size()>arr2.size() || m=="true")) || ((number[0]!='-'&&t.number[0]=='-')&&(arr2.size()>arr1.size() ||m=="false")))
        {
            n.number[0]='-';
        }
        if(n.number[0]=='-')
        {
            for(int i=1; i<v.size(); i++)
            {
                n.number[i]=v[i]+'0';

            }
        }
        else
        {
            for(int i=0; i<v.size(); i++)
            {
                n.number[i]=v[i]+'0';

            }
        }
        if(m=="true1")
        {
            cout<<"0";
        }
        return n;
    }
    BigDecimalInt operator -(BigDecimalInt &r)
    {
        BigDecimalInt m;
        BigDecimalInt e;
        e.number=number;
        if(r.number[0]!='-')
        {
            r.number='-'+r.number;
        }
        else if(r.number[0]=='-')
        {
            r.number[0]='+';
        }
        return e+r;

    }
     friend ostream&operator<<(ostream&out,BigDecimalInt &p)
     {
       int u=0;
       while(true)
            {
                if((p.number[u]<'0'||p.number[u]>'9')&&p.number[u]!='/'&&p.number[u]!='-')
                {
                    break;
                }
                if(p.number[u]!='/')
                {
                    out<<p.number[u];
                }
                u++;
            }
            return out;
     }

};

int main()
{
    string num1;
    string num2;
    cout<<"please enter first number: ";
    cin>>num1;
    cout<<"please enter second number: ";
    cin>>num2;
    BigDecimalInt N1(num1);
    BigDecimalInt N2(num2);
    int choice;
    do
    {
        cout<<"[1] +" << endl<<"[2] -"<<endl;
        cin>>choice;
    }while(choice<=0 || choice>2);
    switch(choice)
    {
    case 1:
        {
            BigDecimalInt N3=N1+N2;
            cout<<N3;
            break;
        }
    case 2:
        {
            BigDecimalInt N3=N1-N2;
            cout<<N3;
            break;
        }
    }
    return 0;
}
