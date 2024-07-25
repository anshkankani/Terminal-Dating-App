#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct node
{
	string name, gender, food, persona, DOB, music, quality,pref_gender,no,height;
	struct node* next;
};
void insertend(struct node *&head,struct node n)
{
	struct node*newnode = new struct node;
	struct node *temp=head;
	newnode->name=n.name;
	newnode->no=n.no;
	newnode->gender=n.gender;
	newnode->pref_gender=n.pref_gender;
	newnode->persona=n.persona;
	newnode->DOB=n.DOB;
	newnode->music=n.music;
	newnode->height=n.height;
	newnode->music=n.music;
	newnode->quality=n.quality;
	newnode->food=n.food;
	newnode->next=NULL;
	if (head==0){
		head=newnode;
	}
	else
	{
		while(temp->next!=0)
			temp=temp->next;
		temp->next=newnode;
	}
}
void insertbeg(struct node*&head,struct node n)
{
	struct node* newnode = new struct node;
	newnode->name=n.name;
	newnode->no=n.no;
	newnode->gender=n.gender;
	newnode->pref_gender=n.pref_gender;
	newnode->persona=n.persona;
	newnode->DOB=n.DOB;
	newnode->music=n.music;
	newnode->height=n.height;
	newnode->quality=n.quality;
	newnode->food=n.food;
	newnode->next=head;
	head=newnode;
}
void printlist(struct node* head)
{
	struct node* temp=head;
	if (head==0)
		cout<<"Empty!"<<endl;
	else
	{
		while(temp!=0)
		{
			cout<<temp->name<<endl;
			cout<<temp->no<<endl;
			cout<<temp->gender<<endl;
			cout<<temp->pref_gender<<endl;
			cout<<temp->DOB<<endl;
			cout<<temp->persona<<endl;
			cout<<temp->music<<endl;
			cout<<temp->height<<endl;
			cout<<temp->quality<<endl;
			cout<<temp->food<<endl;
			temp=temp->next;
		}
		cout<<temp->name<<endl;
			cout<<temp->no<<endl;
			cout<<temp->gender<<endl;
			cout<<temp->pref_gender<<endl;
			cout<<temp->DOB<<endl;
			cout<<temp->persona<<endl;
			cout<<temp->music<<endl;
			cout<<temp->height<<endl;
			cout<<temp->quality<<endl;
			cout<<temp->food<<endl;
	}

}
void deleted(struct node*&head,string n)
{
	struct node *temp1=head;
	struct node *temp2=head;
	temp2=temp2->next;
	int f2=0;
	if(temp1->no==n)
	{
		f2=1;
		head=temp2;
	}
	if (f2==0)
	{
		while(temp2->next!=0)
		{
			if (temp2->no==n)
			{
				temp1->next=temp2->next;
				break;
			}
			else
			{
				temp1=temp1->next;
				temp2=temp2->next;
			}
		}
	}
	if (temp2->no==n)
	{
		temp1->next=temp2->next;
	}
}
void stackk(struct node*&head,struct node*&head2,struct node* user){
    int c;
	struct node* temp=head;
	do{
	if (head==0){
		cout<<"No one else left.You have gone through all of them!"<<endl;
		break;}
	else
	{	
		while(temp!=0 ){
			
		if (user->pref_gender==temp->gender && user->gender==temp->pref_gender)
		{	cout<<"\n";
		cout<<"_____________________________________________________________________________________________________________"<<endl;
			cout<<temp->name<<endl;
			cout<<temp->no<<endl;
			cout<<temp->gender<<endl;
			cout<<temp->pref_gender<<endl;
			cout<<temp->DOB<<endl;
			cout<<temp->persona<<endl;
			cout<<temp->music<<endl;
			cout<<temp->height<<endl;
			cout<<temp->quality<<endl;
			cout<<temp->food<<endl;
			cout<<temp->gender<<endl;
			cout<<"_____________________________________________________________________________________________________________"<<endl;
			cout<<"1.)Right Swipe\n2.)Left Swipe\n3.)Exit\nEnter choice:";
			cin>>c;
			if(c==1)
			{
				insertbeg(head2,*temp);
				deleted(head,temp->no);
				temp=temp->next;
			}
			else if (c==2)
			{
			    deleted(head,temp->no);
				temp=temp->next;
			}
			else if (c==3)
			    break;
			else
				cout<<"Invalid"<<endl;
		}
		else {
		deleted(head,temp->no);
		temp=temp->next;
		}
			
	}	
	}
}while(c!=3 && temp->next!=0);
}
void csvtolinkedlist(struct node*&head)
{
    node e; 
    ifstream inFile("form_csv.csv"); //our file
    string line;
    int linenum = 0;
    while (getline (inFile, line))
    {
        istringstream linestream(line);
        string item;
		getline(linestream, item, ',');
		e.name = item;
		getline(linestream, item, ',');
		e.no = item;
		getline(linestream, item, ',');
		e.food = item;
		getline(linestream, item, ',');
		e.gender = item;
		getline(linestream, item, ',');
		e.DOB = item;
		getline(linestream, item, ',');
		e.height = item;
		getline(linestream, item, ',');
		e.persona = item;
		getline(linestream, item, ',');
		e.pref_gender = item;
		getline(linestream, item, ',');
		e.music = item;
		getline(linestream, item, ',');
		e.quality = item;
		linenum++;
		insertend(head,e);
    }
}
struct node* input() 
{
	struct node* Node= new struct node;	
    cout<<"Enter your name:"<<endl;
    getline(cin,Node->name);
    cout<<"Enter your number:"<<endl;
    cin>>Node->no;
    cout<<"Enter your height in cm"<<endl;
    cin>>Node->height;
    cout<<"Your gender :"<<endl;
    cout <<"1. Male"<<endl<<"2. Female"<<endl;
    cin>>Node->gender;
    cout<<"Now, your birthday!"<<endl;
    cout<<"What is your date of birth (enter in dd/mm/yyyy format)"<<endl;
    cin>>Node->DOB;
    cout << "What would be  the gender of your significant other?"<<endl;
    cout <<"1. Male"<<endl<<"2. Female"<<endl;
    cin >> Node->pref_gender;   // Taking input for gender of dating
    cout << "What is your food preference?"<<endl;
    cout <<"1. Veg"<<endl<<"2. Nonveg"<<endl<<"3. Vegan"<<endl;
    cin>>Node->food;   // Taking input for food
    cout << "What type of personality do you think you have?"<<endl;
    cout <<"1. Introvert"<<endl<<"2. Extrovert"<<endl<<"3. Ambivert"<<endl;
    cin.ignore();
    getline(cin,Node->persona);   // Taking input for personality
    cout << "What kind of music do you most vibe to??"<<endl;
    cout <<"1. Pop"<<endl<<"2. Rock"<<endl<<"3. HipHop"<<endl<<"4. Jazz"<<endl<<"5. Country"<<endl<<"6. Classical"<<endl;
    cin>>Node->music;   // Taking input for music
    cout << "What quality would you definitely want your significant other to have?"<<endl;
    cout <<"1. Beautiful Hair"<<endl<<"2. Lovely eyes"<<endl<<"3. Sense of humour"<<endl<<"4. Cheerful smile"<<endl<<"5. Loyalty"<<endl;
    cin.ignore();
    getline(cin,Node->quality);  // Taking input for quality
    return Node;
}
string zodiac_sign(struct node* e)
{
	stringstream ss;
	stringstream ss2;
	string dob=e->DOB;
	string d= dob.substr(0, 2);
	int day;
	ss<< d;
	ss>>day;
	string m= dob.substr(3, 2);
	int month;
	ss2<<m;
	ss2>>month;
    string astro_sign; 
    if (month == 12){      
        if (day < 22)
        astro_sign = "Sagittarius";
        else
        astro_sign ="Capricorn";
    }       
    else if (month == 1){
        if (day < 20)
        astro_sign = "Capricorn";
        else
        astro_sign = "Aquarius";
    }       
    else if (month == 2){
        if (day < 19)
        astro_sign = "Aquarius";
        else
        astro_sign = "Pisces";
    }        
    else if(month == 3){
        if (day < 21)
        astro_sign = "Pisces";
        else
        astro_sign = "Aries";
    }
    else if (month == 4){
        if (day < 20)
        astro_sign = "Aries";
        else
        astro_sign = "Taurus";
    }       
    else if (month == 5){
        if (day < 21)
        astro_sign = "Taurus";
        else
        astro_sign = "Gemini";
    }       
    else if( month == 6){
        if (day < 21)
        astro_sign = "Gemini";
        else
        astro_sign = "Cancer";
    }       
    else if (month == 7){
        if (day < 23)
        astro_sign = "Cancer";
        else
        astro_sign = "Leo";
    }       
    else if( month == 8){
        if (day < 23)
        astro_sign = "Leo";
        else
        astro_sign = "Virgo";
    }       
    else if (month == 9){
        if (day < 23)
        astro_sign = "Virgo";
        else
        astro_sign = "Libra";
    }       
    else if (month == 10){
        if (day < 23)
        {
        astro_sign = "Libra";
    }
        else
        astro_sign = "Scorpio";
    }     
    else if (month == 11){
        if (day < 22)
        astro_sign = "Scorpio";
        else
        astro_sign = "Sagittarius";
    }     
    return astro_sign;
}
double compat(string astrosign,struct node* user,struct node* newNode)
{
	double vibescore=0;
	string z0=zodiac_sign(user);
	string z1=zodiac_sign(newNode);
	string pt0=user->persona;
	string pt1=newNode->persona;
	string mg0=user->music;
	string mg1=newNode->music;
	string sig0=user->quality;
	string sig1=newNode->quality;
	int category[2];          								//zodiac match
	for(int i=0;i<2;i++)
{
	if(z0=="Aries"||z0=="Leo"||z0=="Sagittarius")
	{
		category[0]=1;
	}
	if(z0=="Taurus"||z0=="Virgo"||z0=="Capricorn")
	{	
		category[0]=2;
	}
	if(z0=="Gemini"||z0=="Libra"||z0=="Aquarius")
	{
		category[0]=3;
	}
	if(z0=="Cancer"||z0=="Pisces"||z0=="Scorpio")
	{
		category[0]=4;
	}
	if(z1=="Aries"||z1=="Leo"||z1=="Sagittarius")
	{
		category[1]=1;
	}
	if(z1=="Taurus"||z1=="Virgo"||z1=="Capricorn")
	{	
		category[1]=2;
	}
	if(z1=="Gemini"||z1=="Libra"||z1=="Aquarius")
	{
		category[1]=3;
	}
	if(z1=="Cancer"||z1=="Pisces"||z1=="Scorpio")
	{
		category[1]=4;
	}
}
	if(category[0]==category[1])
	{
		vibescore+=3;
	}
	else {
	if(category[0]==1)
	{
		if(category[1]==3)
		vibescore+=2;
		else
		vibescore+=1;
	}
	if(category[0]==2)
	{
		if(category[1]==4)
		vibescore+=2;
		else
		vibescore+=1;
	}
	if(category[0]==3)
	{
		if(category[1]==1)
		vibescore+=2;
		else
		vibescore+=1;
	}
	if(category[0]==4)
	{
		if(category[1]==2)
		vibescore+=2;
		else
		vibescore+=1;
	}}
	
	if(pt0==pt1)                				          //personality type
	{
		vibescore+=1.5;
	}
	else
	vibescore+=3;	
	if(mg0=="Pop"||mg0=="Rock"||mg0=="Hip hop")			 //music genre
	{
		if(mg1=="Pop"||mg1=="Rock"||mg1=="Hip hop")
		vibescore+=3;
		else
		vibescore+=1.5;
	}
	if(mg0=="Jazz"||mg0=="Country"||mg0=="Classical")
	{
		if(mg1=="Jazz"||mg1=="Country"||mg1=="Classical")
		vibescore+=3;
		else
		vibescore+=1.5;
	}	
	if(sig0==sig1)
	vibescore+=3;
	else
	vibescore+=1.5;	
	vibescore=vibescore/12*100;	
	return vibescore;
}
int main() {
	struct node* head=NULL;
	struct node* head2=NULL;
	cout<<"_____________________________________________________________________________________________________________"<<endl;
	cout<<"\t\t\t\t\t\t\tWelcome!!"<<endl<<"\t\t\t\t\t\t\t*********"<<endl<<" Here is the much awaited dating app!"<<endl<<"Insert your details below to get started"<<endl;
	cout<<"_____________________________________________________________________________________________________________"<<endl;
    struct node*user=input();
    cout<<"_____________________________________________________________________________________________________________"<<endl;
    csvtolinkedlist(head);
    int choice=1;
    while(choice==1||choice==2){
	cout<<"_____________________________________________________________________________________________________________"<<endl;
    cout<<"1.To view people"<<endl<<"2.To view your right swipes:"<<endl<<"3.Any other key to Exit"<<endl;
    cout<<"_____________________________________________________________________________________________________________"<<endl;
    cin>>choice;
    switch(choice){
    	case 1:
    		stackk(head,head2,user);
    		break;
    case 2:
    	struct node* temp=head2;
	if (head2==0){
		cout<<"No Potential Matches!"<<endl;
		break;}
	else
	{	cout <<setw(25)<<"NAME"<<setw(10)<<"VIBESCORE"<< endl;
		while(temp->next!=0 ){
			
			cout <<setw(25)<<temp->name<<setw(10)<< compat(zodiac_sign(user),user,temp)<< endl;
			temp=temp->next;
		}
		cout <<setw(25)<<temp->name<<setw(10)<< compat(zodiac_sign(user),user,temp)<< endl;
		} 	
    	break;
	}
}
    return 0;
}
