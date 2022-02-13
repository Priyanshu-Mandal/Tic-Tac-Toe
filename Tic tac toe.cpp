#include <iostream>
using namespace std;

class player{
	public:	
		string name;
		char symb;
		void getname(char n);
		void disp();

};

void player::getname(char n){
	cout<<"Enter the name: ";
	cin>>name;
	cout<<endl;
	symb=n;
}
void player::disp(){
	cout<<"player: "<<name<<endl;
	cout<<"symbol:	"<<symb<<endl<<endl<<"\n";
}

void reset(char a[],int n);
void display(char a[],int n);
char checkwinner(char a[],player p);


int main(){
	int moves=1,pos;
	char a[9];
	reset(a,9);
	display(a,9);
	cout<<endl;
	player p,ob1,ob2;
	ob1.getname('X');
	ob2.getname('O');
	
	while(moves<=9){
		if(moves%2==0){
			do{
				cout<<"\nPlayer2 "<<ob2.name<<" make a move: ";
				cin>>pos;
			}while(a[pos-1]!='-');
			
			a[pos-1]=ob2.symb;
			p=ob2;
		}
		else{
			do{
				cout<<"\nPlayer1 "<<ob1.name<<" make a move: ";
				cin>>pos;
			}while(a[pos-1]!='-');
			
			a[pos-1]=ob1.symb;
			p=ob1;
		}
		
		display(a,9);
		if(moves>=5){
			if(checkwinner(a,p)==ob1.symb){
			cout<<endl<<"Winner"<<endl;
			ob1.disp();
			break;
		}
		else if(checkwinner(a,p)==ob2.symb){
			cout<<endl<<"Winner"<<endl;
			ob2.disp();
			break;
		}
		}
		
		moves++;
	}
	if (checkwinner(a,p)=='f')
	cout<<"Draw";
	
	return 0;
}

void reset(char a[],int n){
	for(int i=0;i<n;i++)
	a[i]='-';
}

void display(char a[],int n){
	for(int i=0;i<n;i++){
		if(i%3==0)
		cout<<endl;
		cout<<a[i]<<"\t";
	}
	cout<<endl<<endl;
}

char checkwinner(char a[],player p){
	if((a[0]==p.symb && a[1]==p.symb && a[2]==p.symb)||
		(a[3]==p.symb && a[4]==p.symb && a[5]==p.symb)||
		(a[6]==p.symb && a[7]==p.symb && a[8]==p.symb)||
		(a[0]==p.symb && a[3]==p.symb && a[6]==p.symb)||
		(a[1]==p.symb && a[4]==p.symb && a[7]==p.symb)||
		(a[2]==p.symb && a[5]==p.symb && a[8]==p.symb)||
		(a[0]==p.symb && a[4]==p.symb && a[8]==p.symb)||
		(a[2]==p.symb && a[4]==p.symb && a[6]==p.symb)
	)
	return  p.symb;
	else
	return 'f';
}
