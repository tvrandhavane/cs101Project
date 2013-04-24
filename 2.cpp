#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "ezwin.h" 
using namespace std;
#include "bitmap.h"
#include "position.h"

int z=0,i;
int dice_sum,dice_1,dice_2;
int jail_choice[2];

class city
{
private:
	char city_name[20];
	int city_id;
	int city_rent, house_rent, hotel_rent;
	int house_count ; //=0;
	int hotel_count;  //=0;
	int owner ;       //=-1;
	int type;
	int city_cost;
	int house_cost;
	int hotel_cost;
public:
	void set_details_of_city(char str[],int id, int c_rent,int hse_rent,int htl_rent,int t,int c_cost,int hse_cost,int htl_cost,int hse_count,int htl_count,int cty_owner);
	void display_details_of_city(void);
	int get_owner();					//get owner is either -1 or 0 or 1. if it is -1, no one owns the city yet.
	void modify_owner(int new_owner);
	void modify_house_count();
	void modify_hotel_count();
	int return_id();
	int return_city_cost();
	int return_house_rent();
	int return_house_cost();
	int return_house_count();
	int return_hotel_rent();
	int return_hotel_cost();
	int return_hotel_count();
	int return_type();
};



void city::set_details_of_city(char str[],int id, int c_rent,int hse_rent,int htl_rent,int t,int c_cost,int hse_cost,int htl_cost,int hse_count,int htl_count,int city_owner)
	{	
		strcpy(city_name,str);
		city_id=id;
		city_rent=c_rent;
		house_rent=hse_rent;
		hotel_rent=htl_rent;
		type=t;
		city_cost=c_cost;
		house_cost=hse_cost;
		hotel_cost=htl_cost;
		house_count=hse_count;
		hotel_count=htl_count;
		owner=city_owner;
	}
void city::display_details_of_city(void)
	 {
		cout<<"\nCity name: "<<city_name;
		cout<<"\nCity type is: "<<type;
		cout<<"\nCost of city: "<<city_cost;
		cout<<"\nRent for "<<city_name<<" : "<<city_rent;
		cout<<"\nRent for each house: "<<house_rent;
		cout<<"\nRent for each hotel: "<<hotel_rent;
		if(owner==0)
		cout<<"\nOwned by : player 1.";
		else if(owner==1)
		cout<<"\nOwned by : player 2.";
		else
		cout<<"\nNo one owns this city yet."; 
		
	}
int city::get_owner(void)
{
	return owner;
}
void city::modify_owner(int new_owner)
{
	owner=new_owner;
}
void city::modify_house_count()
{
	house_count++;
}
void city::modify_hotel_count()
{
	hotel_count++;
} 
int city::return_id(void)
{
	return city_id;
}
int city::return_city_cost(void)
{
	return city_cost;
}
int city::return_house_cost()
{
	return house_cost;
}
int city::return_house_count()
{
	return house_count;
}
int city::return_house_rent()
{
	return house_rent;
}
int city::return_hotel_count()
{
	return hotel_count;
}
int city::return_hotel_cost()
{
	return hotel_cost;
}
int city::return_hotel_rent()
{
	return hotel_rent;
}
int city::return_type()
{
	return type;
}


class company{
private:
	char company_name[20];	
	int company_cost;
	int basic_rent;
	int paired_rent;
	int owner ;     //=-1;
	int company_id;
	int paired_company_id;
	char paired_company_name[20];
public:
	void set_details_of_company(char str[],char str2[],int id,int p_comp_id, int b_rent, int p_rent,int comp_cost,int c_owner);
	
	void display_details_of_company(void);
	int get_owner();
	void modify_owner(int new_ownercout);
	int return_id(); 
	int return_company_cost();
	int return_basic_rent();
	int return_paired_rent();
	int return_paired_company_id();
	
	
};

void company::set_details_of_company(char str[],char str2[],int id,int p_comp_id, int b_rent, int p_rent,int comp_cost,int c_owner)
{
	strcpy(company_name,str);
	strcpy( paired_company_name,str2);
	company_id=id;
	paired_company_id= p_comp_id;
	company_cost=comp_cost;
	basic_rent=b_rent;
	paired_rent=p_rent;
	owner=c_owner;
}
void company::display_details_of_company(void)
{		
	cout<<"\nName of the company: "<<company_name;
	cout<<"\n"<<paired_company_name<<" is paired with this company.";
	cout<<"\nIf one person owns both paired companies, then the rent charged increases.";
	cout<<"\nCost of the company: "<<company_cost;
	cout<<"\nBasic rent of the company: "<<basic_rent;
	cout<<"\nPaired rent of the company: "<<paired_rent;
	cout<<"\n";
	if(owner==0)
	cout<<"\nOwned by : player 1.";
	else if(owner==1)
	cout<<"\nOwned by : player 2.";
	else
	cout<<"\nNo one owns this company yet."; 
}
	
int company::get_owner()
{
	return owner;
}
void company::modify_owner(int new_owner)
{
	owner=new_owner;
}
	
int company::return_id(void)
{
	return company_id;
}

int company::return_company_cost()
{
	return company_cost;
}
int company::return_basic_rent()
{
	return basic_rent;
}
int company::return_paired_rent()
{
	return paired_rent;
}

int company::return_paired_company_id()
{
	return paired_company_id;
}



class player{
private:													//can accept and store the name of the player
	int player_number;
	long int balance;      //=30000; 			
	int house_count;      //=0;
	int hotel_count;     //=0;
	int position;       //=0;
	int city_count;      //=0; 
	int turn;            //=0;
	                                        
public:
	void set_details_of_player(int pn,long int bal,int hse_count,int htl_count,int pos,int cty_count,int p_turn);
	int set_position(int change);
	void modify_balance(int transaction);
	int return_balance(void);      
	void modify_city_count();
	int return_city_count();  
	void jump(int new_position);   
	int return_house_count();
	int return_hotel_count();
	int return_turn();
	int modify_turn(int modification);
	void modify_house_count();
	void modify_hotel_count(); 
	void display_details_of_player();                               //to be made in private
};
void player::display_details_of_player()
{
    cout<<"\nPlayer number:"<<player_number;
    cout<<"\nBalance:"<<balance;
    cout<<"\nNo. of Houses:"<<house_count;
    cout<<"\nNo of hotels:"<<hotel_count;
    cout<<"\nPosition:"<<position;
    cout<<"\nNo. of Cities owned:"<<city_count;
    cout<<"\nTurn:"<<turn;
}
void player::modify_house_count()
{
	house_count++;
}
void player::modify_hotel_count()
{
	hotel_count++;
}
int player::set_position(int change)
{
	position+=change;
	position=position%36;
	return position;
}	
	
void player::modify_balance(int transaction) 			//transaction may be positive or negative depending on whether player gains or loses money
{
	balance+=transaction;
}	
	
void player::set_details_of_player(int pn,long int bal,int hse_count,int htl_count,int pos,int cty_count,int p_turn)
{
	player_number=pn;
	balance=bal;
	house_count=hse_count;
	hotel_count=htl_count;
	position=pos;
	city_count=cty_count;
	turn=p_turn;
}
int player::return_balance()
{
	return balance;
} 	
void player::modify_city_count()
{
	city_count++;
}
int player::return_city_count()
{
	return city_count;
}

void player::jump(int new_position)
{
	position=new_position;
}
int player::return_house_count()
{
	return house_count;
}
int player::return_hotel_count()
{
	return hotel_count;
}
int player::return_turn()
{
	return turn;
}
int player::modify_turn(int modification)
{
	turn+=modification;
}



void dice()
{
	srand(time(0));
	dice_1=rand()%6 + 1;
	
	srand(time(0)+1000); //To be reconsidered
	dice_2=rand()%6 +1;
	dice_sum=dice_1+dice_2;
	cout<<"\nNumber on dice:"<<dice_sum<<"\n";
}



int ApiMain()
{
	SimpleWindow Game_Board("Game Board",19.5,19.5,Position(4.0,2.0));	
	SimpleWindow Welcome_Screen("Welcome To Monopoly",18.0,12.0,Position(0.0,0.0));
	BitMap Game_Board_Image(Game_Board);
	BitMap Welcome_Image(Welcome_Screen);
	int flag1=0,flag2=0,flag3=0,flag4=0;
	int j=0;
	int current_position=0;
	class city cty[20];
	class player plyr[2];
	class company cmpny[6];
	FILE *fp1,*fp2,*fp3;	
	Welcome_Screen.Open();
	Welcome_Image.Load("Welcome.xpm");
	Position WindowCenter=Welcome_Screen.GetCenter();
	Position Welcome_ImagePosition= WindowCenter+Position(-0.5*Welcome_Image.GetWidth(),-0.5*Welcome_Image.GetHeight());
	Welcome_Image.SetPosition(Welcome_ImagePosition);
	Welcome_Image.Draw();
	cin>>flag1;		
	Welcome_Screen.Close();
	if(flag1==2)
	{
		cout<<"Thank You"<<endl;
		return 1;
	}
	if((flag1!=1)&&(flag1!=2))
	{
		cout<<"INVALID INPUT, GAME QUITS"<<endl;
		return 2;
	}
	if(flag1==1)
	{
		cout<<" Let's Start The Game: "<<endl;
//
//
//		
//		
//
		fp1=fopen("city.txt","r");
		fp2=fopen("company.txt","r");								
	
		if(fp1==NULL)
		{
			cout<<"\nCannot open the file city.txt";
			exit(0);
		}
		if(fp2==NULL)
		{
			cout<<"\nCannot open the file company.txt";
			exit(0);
		}
		i=0; 
		char str1[20];												
		int id, c_rent,hse_rent,htl_rent,t,c_cost,hse_cost,htl_cost,hse_count,htl_count,cty_owner;                 //dummy variables for city
		while(!feof(fp1))
		{
			fscanf(fp1,"%s %d %d %d %d %d %d %d %d %d %d %d",str1,&t,&id,&c_cost,&hse_cost,&htl_cost,&c_rent,&hse_rent,&htl_rent,&hse_count,&htl_count,&cty_owner);
			cty[i].set_details_of_city(str1,id, c_rent,hse_rent,htl_rent,t,c_cost,hse_cost,htl_cost,hse_count,htl_count,cty_owner);
			cty[i].display_details_of_city();
			i++;
		}	
		
	}
	return 0;
}
		
