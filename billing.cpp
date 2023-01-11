#include<iostream>
#include<string>
using namespace std;

class Restaurant
{
    public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    float total_tax;
    void getd(int n)
    {
        string x;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter Food Code :"<<endl;
            cin>>food_item_codes[i];
            cout<<"Enter Food Name :"<<endl;
            cin.ignore();
            getline(cin, x);
            food_item_names[i]=x;
            cout<<"Enter Food Price :"<<endl;
            cin>>food_item_prices[i];
        }
    }
    void disd(int n)
    {
        cout<<"\t\t\t"<<"MENU"<<"\t\t\t"<<endl;
        cout<<"\t\t"<<"______________________"<<"\t\t\t"<<endl<<endl<<endl;
        cout<<"item code\t\t"<<"item name\t\t\t\t\t\t"<<"item price\t\t"<<endl<<endl<<endl;
         for(int i=0;i<n;i++)
        {
            cout<<food_item_codes[i]<<"\t\t\t";
            cout<<food_item_names[i]<<"\t\t\t\t\t";
            cout<<food_item_prices[i]<<"\t\t\t";
            cout<<endl;
        }

    }
};

int main()
{
    int tn,noi,itemcode1,itemcode[12],quantity1,quantity[12],price1,price[12],price0,price_indiv[12],v,n;
    float total;
    string itemname[12];
    Restaurant a;
    cout<<"No Of Menu Items :"<<endl;
    cin>>n;
    a.getd(n);
    flag:
    total=0;
    a.disd(n);
    cout<<endl;
    cout<<"Enter Table No :"<<endl;
    cin>>tn;
    cout<<"Enter No Of Items : ";
    cin>>noi;
    for(int i=0;i<noi;i++)
    {
        flag2:    cout<<"Enter item "<<i+1<<" code :"<<endl;
            cin>>itemcode1;
            for(int j=0;j<12;j++)
           {
               if(itemcode1==a.food_item_codes[j])
           {
               v=1;
               itemcode[i]=itemcode1;
               break;
           }
            else
            {
                v=0;
            }
           }
           if(v==0)
           {
               cout<<"Incorrect food code.Enter Again!!"<<endl;
               goto flag2;
           }
           else
           {
            cout<<"Enter item "<<i+1<<" Quantity :"<<endl;
            cin>>quantity1;
            quantity[i]=quantity1;
           }

    }
    for(int i=0;i<noi;i++)
    {
           for(int j=0;j<12;j++)
           {
               if(itemcode[i]==a.food_item_codes[j])
           {
               price0=a.food_item_prices[j];
               price_indiv[i]=price0;
               price1=a.food_item_prices[j]*quantity[i];
               price[i]=price1;
               itemname[i]=a.food_item_names[j];
               total=total+(float)price[i];
               break;
           }
           }
           a.total_tax=((total*5)/100);
    }
    cout<<endl<<endl<<"\t\t\t\t\t"<<"BILL SUMMARY"<<"\t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t"<<"_____________________________"<<"\t\t"<<endl<<endl;
    cout<<"Table NO :"<<tn<<endl<<endl;
    cout<<"Item Code"<<"\t"<<"Item Name"<<"\t\t\t"<<"Item Price"<<"\t"<<"Item Quantity"<<"\t\t"<<"Total Price"<<"\t"<<endl;
     for(int i=0;i<noi;i++)
        {
            cout<<itemcode[i]<<"\t\t";
            cout<<itemname[i]<<"\t\t";
            cout<<price_indiv[i]<<"\t\t";
            cout<<quantity[i]<<"\t\t\t";
            cout<<price[i]<<"\t\t";
            cout<<endl;
        }
cout<<endl<<"TAX\t\t\t\t\t\t\t\t\t\t\t"<<a.total_tax<<endl<<endl;
cout<<"________________________________________________________________________________________________________________________"<<endl;
cout<<"Net Total\t\t\t\t\t\t\t\t\t\t"<<total+a.total_tax<<" Taka"<<endl<<endl;
goto flag;
}
