#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int getValue()
{
	while (true)
	{
		cout << "Please input VALLUE";
		cout << '\n';
		int a;
		cin >> a;
		cout << '\n';

		if (cin.fail())
		{
			cin.clear(); // 
			cin.ignore(32767, '\n');
		}
		else return a;

	}

}
double getValueD()
{
	while (true)
	{
		cout << "Please input VALLUE";
		cout << '\n';
		double a;
		cin >> a;
		cout << '\n';

		if (cin.fail())
		{
			cin.clear(); // 
			cin.ignore(32767, '\n');
		}
		else return a;

	}

}
struct tovar
{
	int section;
	string name;
	double price;
	int vallue;
};
void add(tovar store[], int needmas[])
{
	int varible_add;
	cout << "How much do you want add" << endl;
	cin >> varible_add;
	if (needmas[0] == 0)
	{
		int need = 0;
		for (int i = 0; i < varible_add; i++)
		{
			need++;
			cout << "Add section" << endl;
			store[i].section = getValue();
			cout << "Add name" << endl;
			cin >> store[i].name;
			cout << "Add price" << endl;
			 store[i].price=getValueD();
			cout << "Add vallue" << endl;
			store[i].vallue=getValue();
			if (need==2)
			{
				for (int  j = 0; j < need; j++)
				{
					if ((store[i].price == store[j].price)&& (store[i].name == store[j].name))
					{
						store[i].vallue++;
						store[i].section = 0;
						break;

					}
					else {
						needmas[1]++;
					}
				}
			}
			system("cls");
		}
		needmas[1]++;

	}
	else
	{
		int need = 0;
		for (int i = needmas[1] + 1; i < varible_add + needmas[1]; i++)
		{
			need++;
			cout << "Add section" << endl;
			store[i].section = getValue();
			cout << "Add name" << endl;
			cin >> store[i].name;
			cout << "Add price" << endl;
			store[i].price = getValueD();
			cout << "Add vallue" << endl;
			store[i].vallue = getValue();
			if (need == 2)
			{
				for (int j = 0; j < need+needmas[1]; j++)
				{
					if ((store[i].price == store[j].price) && (store[i].name == store[j].name))
					{
						store[i].vallue++;
						store[i].section = 0;
						break;

					}
					else {
						needmas[1]++;
					}
				}
			}
			system("cls");
		}
	}


}
void print(tovar store[], int needmas[])
{
	cout << "Please input name product" << endl;
	string names;
	cin >> names;
	int var_nub=0;
	for (int  i = 0; i < needmas[1]; i++)
	{
		if (store[i].name==names)
		{
			cout << "______________General_Inforamtion______________" << endl;
			cout << " Names production :>>>"<<'\t' << store[i].name << endl;
			cout << "Section is :>>>" << '\t' << store[i].section<<endl;
			cout << "Price product :>>>" << '\t' << store[i].price << endl;
			cout << "Vallue is :>>>" << '\t' << store[i].vallue << endl;
			var_nub++;
			cout << '\n';
			
		}
		if ((i==needmas[1]-1)&&(var_nub==0))
		{
			cout << "No found" << endl;
		}
	}
	 var_nub = 0;
	 system("pause");
	 system("cls");
}
void find_1(tovar store[],int needmas[])
{
	int section_need;
	section_need = getValue();
	int find=0;
	for (int i = 0; i <needmas[1] ; i++)
	{
		if (store[i].section==section_need)
		{
			find++;
		}
	}
	string *names = new string[find];
	for (int  i = 0; i < needmas[1]; i++)
	{
		int need = 0;
		if (store[i].section == section_need)
		{
			names[need] = store[i].name;
			need++;
		}
		
	}
	sort(names, names + find);
	cout << "Find elements" << endl;
	for (int  i = 0; i < find; i++)
	{
		cout << names[i]<<endl;
	}
}
void find_2(tovar store[], int needmas[])
{
	cout << "Please input vallue product" << endl;
	int vallue_products;
	vallue_products = getValue();
	int prover = 0;
	for (int  i = 0; i < needmas[1]; i++)
	{
		
		if (vallue_products>store[i].vallue)
		{
			cout << store[i].name << endl;
			prover++;
		}
		if ((i==needmas[1]-1)&&(prover==0))
		{
			cout << "Not enough any products" << endl;
		}
	}
	 prover = 0;
}
int main()
{
	tovar* store = new tovar[10000];
	int needmas[2];
	needmas[0] = 0;
	needmas[1] = 0;
	int solution = 0;
	while(solution!=5)
	{
		cout << "...............Menu..............." << endl;
		cout << "1-Add new object" << endl;
		cout << "2-Print about object" << endl;
		cout << "3-Find a product by criteria" << endl;
		cout << "4-Find product vallue smaller " << endl;
		cout << "5-End program" << endl;
		cout << "****************" << endl;
		cout << "Wait answer" << endl;
		solution=getValue();
		switch (solution)
		{
		case 1:
			{
			add(store, needmas);
			break;
			}

		case 2: 
			{
				print(store, needmas);
				break;
			}
		
		case 3:
			{
				find_1(store, needmas);
				break;
			}
		
		case 4:
			{
				find_2(store, needmas);
				break;
			}

		case 5:
			{
			solution = 5;
			break;
			}

		}
	}





}