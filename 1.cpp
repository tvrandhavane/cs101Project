#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "ezwin.h" 
using namespace std;
#include "bitmap.h"
#include "position.h"
#include "city.h"
#include "company.h"
int z=0,i;
int dice_sum,dice_1,dice_2;
int jail_choice[2];
class player
{
	private:					//can accept and store the name of the player
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
void player::modify_balance(int transaction) 		//transaction may be positive or negative depending on whether player gains or loses money
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
//Declaration Area Begins
	SimpleWindow Game_Board("Game Board",19.5,19.5,Position(4.0,2.0));	
	SimpleWindow Welcome_Screen("Welcome To Monopoly",18.0,12.0,Position(0.0,0.0));
	BitMap Game_Board_Image(Game_Board);
	BitMap Welcome_Image(Welcome_Screen);
	int flag1=0,flag2=0,flag3=0,flag4=0;
	int current_position=0;
	class city cty[20];
	class player plyr[2];
	class company cmpny[6];
	FILE * fp1,*fp2,*fp3;		
//Declaration Area ends
//Welcome Screen
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
		int id, c_rent,hse_rent,htl_rent,t,c_cost,hse_cost,htl_cost,hse_count,htl_count,cty_owner;    //dummy variables for city
		cout<<"Press 1 to display of the details of the cities"<<endl<<" and press any other number to skip"<<endl;
		cin>>flag2;
		while(!feof(fp1))
		{
			fscanf(fp1,"%s %d %d %d %d %d %d %d %d %d %d %			d",str1,&t,&id,&c_cost,&hse_cost,&htl_cost,&c_rent,&hse_rent,&htl_rent,&hse_count,&htl_count,&cty_owner);
			cty[i].set_details_of_city(str1,id, c_rent,hse_rent,htl_rent,t,c_cost,hse_cost,htl_cost,hse_count,htl_count,cty_owner);
			if(flag2==1)
			{	
				cty[i].display_details_of_city();
			}
			i++;
		}
		cout<<endl;
		i=0;
		char str[20], str2[20];
		int p_comp_id,b_rent,p_rent,comp_cost,c_owner;					//dummy variables for company
		cout<<"Press 1 to display of the details of the companies"<<endl<<" and press any other number to skip"<<endl;
		cin>>flag3;
		while(!feof(fp2))
		{
			fscanf(fp2,"%s %s %d %d %d %d %d %d",str,str2,&id,&p_comp_id,&comp_cost,&b_rent,&p_rent,&c_owner);
			cmpny[i].set_details_of_company(str,str2,id,p_comp_id, b_rent, p_rent,comp_cost,c_owner);
			if(flag3==1)
			{			
				cmpny[i].display_details_of_company();
			}
			i++;
		}
		for(i=0;i<2;i++)
		{
			cout<<endl;			
			cout<<"Press any number to start showing the details of player"<<i+1<<endl;
			cin>>flag4;		
			plyr[i].set_details_of_player(i,50000,0,0,0,0,0);     
			plyr[i].display_details_of_player();                                        
		}
		fclose(fp1);
		fclose(fp2);
		int x, y, flag=-1,type_count=0,j,temp;	
		char ch,ch2='n';				//flag=0 denotes city, and flag=1 denotes company
	                                                                      //main algorithm
		/*start:                                                                //LABEL
		Game_Board.Open();	
		Game_Board_Image.Load("Game_Board.xpm");
		Position WindowCenter2=Game_Board.GetCenter();
		Position Game_BoardPosition= WindowCenter+Position(-0.5*Game_Board_Image.GetWidth(),-0.5*Game_Board_Image.GetHeight());
		Game_Board_Image.SetPosition(Game_BoardPosition);
		Game_Board_Image.Draw();
		cin>>i;*/
	
		
//
//
//
//
//		
	}
	return 0;
}
