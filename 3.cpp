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

SimpleWindow Monopoly("Monopoly",25.0,19.5,Position(0.0,0.0));

BitMap Dice_text(Monopoly);
BitMap Dice_Image(Monopoly);
BitMap Dice_1(Monopoly);
BitMap Dice_2(Monopoly);
BitMap Dice_3(Monopoly);
BitMap Dice_4(Monopoly);
BitMap Dice_5(Monopoly);
BitMap Dice_6(Monopoly);

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
	cout<<"\nNumber on dice 1:"<<dice_1;
	cout<<"\nNumber on dice 2:"<<dice_2;
	cout<<"\nDice Sum:"<<dice_sum<<"\n";
}
int MouseClickEvent1(const Position &MousePosition)
{
	if(Dice_Image.IsInside(MousePosition))
	{
		Dice_Image.Erase();
		switch(dice_1)
		{
			case 1:
				Dice_1.Load("diceno1");
			case 2:
				Dice_1.Load("diceno2");
			case 3:
				Dice_1.Load("diceno3");
			case 4:
				Dice_1.Load("diceno4");
			case 5:
				Dice_1.Load("diceno5");
			case 6:
				Dice_1.Load("diceno6");
		}
		switch(dice_2)
		{
			case 1:
				Dice_2.Load("diceno1");
			case 2:
				Dice_2.Load("diceno2");
			case 3:
				Dice_2.Load("diceno3");
			case 4:
				Dice_2.Load("diceno4");
			case 5:
				Dice_2.Load("diceno5");
			case 6:
				Dice_2.Load("diceno6");
		}
		Dice_text.Erase();
		Dice_text.Load("df.xpm");  
		Dice_text.SetPosition(Dice_textPosition);
		Dice_text.Draw();
		Dice_1.SetPosition(Dice_1Position);
		Dice_2.SetPosition(Dice_2Position);
		Dice_1.Draw();
		Dice_2.Draw();
	}
	return 1;
}
			
			
int ApiMain()
{	
	//SimpleWindow Game_Board("Game Board",19.5,19.5,Position(4.0,2.0));	
	//SimpleWindow Welcome_Screen("Welcome To Monopoly",18.0,12.0,Position(0.0,0.0));
	//SimpleWindow Roll_Dice("Roll Dice",25.0,18.0,Position(4.0,2.0));

	/*BitMap Dice_Image(Roll_Dice);
	BitMap Dice_1(Roll_Dice);
	BitMap Dice_2(Roll_Dice);
	BitMap Dice_3(Roll_Dice);
	BitMap Dice_4(Roll_Dice);
	BitMap Dice_5(Roll_Dice);
	BitMap Dice_6(Roll_Dice);
	BitMap Dice_text(Roll_Dice);
	BitMap Game_Board_Image(Game_Board);*/
	BitMap Welcome_Image(Welcome_Screen);
	

	int current_position=0;
	int flag1=0;

	class city cty[20];
	class player plyr[2];
	class company cmpny[6]; 
					
	Monopoly.Open();
	Welcome_Image.Load("Welcome.xpm");
	Position WindowCenter=Monopoly.GetCenter();
	Position Welcome_ImagePosition= WindowCenter+Position(-0.5*Welcome_Image.GetWidth(),-0.5*Welcome_Image.GetHeight());
	Welcome_Image.SetPosition(Welcome_ImagePosition);
	Welcome_Image.Draw();
	cin>>flag1;
	
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
	                                            
		FILE *fp1,*fp2,*fp3;
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
		int id, c_rent , hse_rent, htl_rent, t, c_cost, hse_cost, htl_cost, hse_count, htl_count; 			int cty_owner;                 //dummy variables for city
		while(!feof(fp1))
		{
			fscanf(fp1,"%s %d %d %d %d %d %d %d %d %d %d %d",str1,&t,&id,&c_cost,&hse_cost,&htl_cost,&c_rent,&hse_rent,&htl_rent,&hse_count,&htl_count,&cty_owner);
			cty[i].set_details_of_city(str1,id, c_rent,hse_rent,htl_rent,t,c_cost,hse_cost,htl_cost,hse_count,htl_count,cty_owner);
			cty[i].display_details_of_city();
			i++;
			cout<<endl;
		}
		cout<<endl;	
		i=0;
		char str[20], str2[20];
		int p_comp_id,b_rent,p_rent,comp_cost,c_owner;
		while(!feof(fp2))
		{
			fscanf(fp2,"%s %s %d %d %d %d %d %d",str,str2,&id,&p_comp_id,&comp_cost,&b_rent,&p_rent,&c_owner);
			cmpny[i].set_details_of_company(str,str2,id,p_comp_id, b_rent, p_rent,comp_cost,c_owner);
			cmpny[i].display_details_of_company();
			i++;
			cout<<endl;
		}
		for(i=0;i<2;i++)
		{
			plyr[i].set_details_of_player(i,50000,0,0,0,0,0);     
			plyr[i].display_details_of_player();
			cout<<endl;                                        
		}
		fclose(fp1);
		fclose(fp2);	                                                                       	
		int x,y,flag=-1,type_count=0,j,temp;	
		char ch,ch2='n'; 			//flag=0 denotes city, and flag=1 denotes company
//main algorithm	
		start:                                                                //LABEL	
		while((plyr[0].return_balance()>0)&&(plyr[1].return_balance()>0)&&((ch2=='n')||(ch2=='N')))
		{
	    		i=z%2;
	    		cout<<"\nNext player's turn.";
	    		cout<<"\nYour current balance:"<<plyr[i].return_balance();
	    		flag=-1;
			z++;
			/*Roll_Dice.Open();
			
			Position WindowCenter1=Roll_Dice.GetCenter();
				
			
			Dice_text.SetPosition(Dice_textPosition);
			Dice_text.Draw();
			Dice_Image.SetPosition(Dice_ImagePosition);
			Dice_Image.Draw();*/
			Welcome_Image.Erase();
			Dice_Image.Load("dice.xpm");
			Dice_text.Load("df.xpm");
			Dice_1.Load("diceno1.xpm");
			Dice_2.Load("diceno2.xpm");
			Dice_3.Load("diceno3.xpm");
			Dice_4.Load("diceno4.xpm");
			Dice_5.Load("diceno5.xpm");
			Dice_6.Load("diceno6.xpm");
			Position Dice_textPosition=WindowCenter+Position(-0.5*Dice_text.GetWidth(),-0.5*Dice_text.GetHeight());
			Position Dice_ImagePosition= Position(12.0+Exit_Button.GetWidth(),17-Exit_Button.GetHeight());
			Position Dice_1Position= WindowCenter+Position(3.0-0.5*Welcome.GetWidth(),4.0-0.5*Welcome.GetHeight());
			Position Dice_2Position= Dice_1Position+Position(3.0,0.0);
			Dice_text.SetPosition(Dice_textPosition);
			Dice_text.Draw();
			Dice_Image.SetPosition(Dice_ImagePosition);
			Dice_Image.Draw();			
			if(plyr[i].return_turn()==0)
			{
				dice();
			}
			Monopoly.SetMouseClickCallback(MouseClickEvent1);
				
			
			
		
		main_algorithm_start:                                            //LABEL
		
		
		
		
		
		current_position=plyr[i].set_position(dice_sum);
		
		main_algorithm_start_2:
		
		
		if((current_position==9)&&(plyr[i].return_turn()==0))
		{
		    
			if(plyr[i].return_turn()==0)
			{
			cout<<"\nYou've landed in 'JAIL'.Wait for the other player to play.";
			plyr[i].modify_turn(1);
			goto start;
			}
			if(plyr[i].return_turn()>0)
			{	
				if(plyr[i].return_turn()==1)
				{
				cout<<"\nWould you like to pay a fine of Rs. 500, throw three times or miss three turns?";
				cout<<"\nEnter 1, 2 or 3 respectively.";
				cin>>jail_choice[i];
				}
				switch(jail_choice[i])
				{
					case 1:
						plyr[i].modify_balance(-500);
						cout<<"\nRs. 500 has been deducted from your bank balance.";
						cout<<"\nYour current balance : "<<plyr[i].return_balance();
						plyr[i].modify_turn((-1)*(plyr[i].return_turn()));
						dice();
                        plyr[i].set_position(dice_sum);					
						break;		
					case 2:
						int d_sum[3];
						for(j=0;j<3;j++)
						{
							dice();
							if(dice_1==dice_2)
							{
								plyr[i].modify_turn((-1)*(plyr[i].return_turn()));
								goto main_algorithm_start;
							}
							d_sum[j]=dice_sum;
						}
						if((d_sum[0]==d_sum[1])&&(d_sum[1]==d_sum[2]))
						{
							plyr[i].modify_turn((-1)*(plyr[i].return_turn()));
							goto main_algorithm_start;
						}
						cout<<"\nYou've failed to satisfy the condition to be released from 'JAIL'.Hence you've to wait for two more turns.";
					case 3:
						if(plyr[i].return_turn()<3)
						{
							plyr[i].modify_turn(1);
							goto start;
						}
						if(plyr[i].return_turn()==3)
						{
							plyr[i].modify_turn((-1)*(plyr[i].return_turn()));
							goto start;
						}
						break;
					default:
						cout<<"\nInvalid input.You've been released from jail and Rs.500 has been deducted from your bank balance.";
						plyr[i].modify_balance(-500);
						break; 
				}
			}
		}
		
		
		
		                                                                  //chance 
		
		if (current_position==7 || current_position==20)
		{
			cout<<"\nYou have landed at 'CHANCE'.";
			switch (dice_sum)
			{
				case 2:				//SYNTAX DOUBTFUL
					cout<<"\nYou have lost Rs. 2000 in the share market.";
					plyr[i].modify_balance(-2000);
					break;
				case 3:
					cout<<"\nYou have won Rs. 2500 in the lottery!";
					plyr[i].modify_balance(2500);
					break;
				case 4:
					cout<<"\nYou have been fined Rs. 1500 for driving under influence (DUI)";
					plyr[i].modify_balance(-1500);
					break;
				case 5:
					cout<<"\nYou have won Rs. 1000 in a crossword competition!";
					plyr[i].modify_balance(1000);
					break;
				case 6:
					cout<<"\nHouse repairs have cost you Rs. 1500";
					plyr[i].modify_balance(-1500);
					break;
				case 7:
					cout<<"\nYou have won a jackpot of Rs. 2000!";
					plyr[i].modify_balance(2000);
					break;
				case 8:
					cout<<"\nA fire in your godown has caused you a loss of Rs. 3000";
					plyr[i].modify_balance(-3000);
					break;
				case 9:
					if (current_position==7)
					plyr[i].modify_balance(2500);
																	                         //Changed the rules.to be filled.
					break;
				case 10:
					cout<<"\nYou have been sent to the 'JAIL'.";
					plyr[i].jump(9);
					goto main_algorithm_start_2;
					break;
				case 11:
					cout<<"\nYou have won Rs. 3000 for best performance in export!";
					plyr[i].modify_balance(3000);
					break;
				case 12:
					cout<<"\nYou have been sent to the 'REST HOUSE'.";
					plyr[i].jump(27);			                                                        //Changed the rules. Player will NOT miss a turn.
					plyr[i].modify_balance(100);
					break;
			}
		}
		
		
		if((current_position==16)||(current_position==29))                   //community chest
		{
			cout<<"\nYou have landed at 'CHANCE'.";
			switch (dice_sum)
			{
				case 2:
					cout<<"\nIt is your birthday.You have received Rs. 500 as gift.";
					plyr[i].modify_balance(500);
					break;	
				case 3:
				    cout<<"\nYou've been sent to 'JAIL'.";
					plyr[i].jump(9);
					goto main_algorithm_start_2;
					break;
				case 4:
					cout<<"\nYou've won 1st prize in beauty contest.Rs. 2500 has been awarded to you.";
					plyr[i].modify_balance(2500);
					break;
				case 5:
					cout<<"\nYou've to pay medical and school fees totaling Rs. 1000.";
					plyr[i].modify_balance(-1000);
					break;
				case 6:
					cout<<"\nIncome tax refund:You received Rs. 2000.";
					plyr[i].modify_balance(2000);
					break;
				case 7:
					cout<<"\nExpenses for marriage celebration are Rs. 2000.";
					plyr[i].modify_balance(-2000);
					break;
				case 8:
					cout<<"\nYou've been sent to 'REST HOUSE'.";
					plyr[i].jump(27);			                                                        //Changed the rules. Player will NOT miss a turn.
					plyr[i].modify_balance(100);
					break;
				case 9:
					cout<<"\nCost of carrying out general repairs on all your properties is :\n"<<"Rs.50 for each house.\n"<<"Rs.100 for each hotel.";
					plyr[i].modify_balance((-50)*(plyr[i].return_house_count())+(-100)*(plyr[i].return_hotel_count()));
					break;
				case 10:
					cout<<"\nYou've received interest on shares amounting to Rs. 1500.";
					plyr[i].modify_balance(1500);
					break;
				case 11:
					cout<<"\nYou've to pay Insurance Premium amounting to Rs. 1500.";
					plyr[i].modify_balance(-1500);
					break;
				case 12:
					cout<<"\nYou've received Rs. 3000 by selling your stocks.";
					plyr[i].modify_balance(3000);
					break;
			}
		}
		
					
		
		
		
		
		
		if(current_position==18)                                                     //CLUB
		{
			cout<<"\nYou have landed at CLUB HOUSE.";
			plyr[i].modify_balance(-100);
			cout<<"\nRs. 100 deducted from your bank account."; 
		}
		
		if(current_position==27)                                                 //REST HOUSE
		{
			cout<<"\nYou have landed at REST HOUSE.";
			plyr[i].modify_balance(100);
			cout<<"\nRs. 100 deposited in your bank account."; 
		}
		
		if(current_position-dice_sum<0)                                         //START
		{
			cout<<"\nYou have crossed START and Rs. 500 has been deposited in your bank account";
			plyr[i].modify_balance(1500);
		}
		
		
		
		
		
		
		if (current_position==5)				                                    //income tax
		{
			cout<<"\nYou have landed at 'INCOME TAX'."; 
			if (plyr[i].return_city_count()*(50) >500)
			{
				plyr[i].modify_balance(-500);
				cout<<"\nRs. 500 has been deducted fom your bank account.";
			}
			else
			{
				plyr[i].modify_balance((-50)*(plyr[i].return_city_count()));
				cout<<"\nRs. "<<(50)*(plyr[i].return_city_count())<<" has been deducted from your bank account.";
			}
		}
		
		if (current_position==31)				                                //wealth tax
		{
			cout<<"\nYou have landed at 'WEALTH TAX'.";
			if ((plyr[i].return_house_count()+(2)*(plyr[i].return_hotel_count()))*(50) > 500)
			{
				plyr[i].modify_balance(-500);
				cout<<"\nRs. 500 has been deducted from your bank account.";
			}
			else
			{
				plyr[i].modify_balance((-50)*((plyr[i].return_house_count())+(2)*(plyr[i].return_hotel_count())));
				cout<<"\nRs. "<<(-50)*((plyr[i].return_house_count())+(2)*(plyr[i].return_hotel_count()))<<" has been deducted from your bank account.";
			}
		}
		
		
		
				
		
		//city and company
		
		
		
		x=0;				                                            //flag=0 denotes city, and flag=1 denotes company
		for(x=0;x<6;x++)
		{
			if(cmpny[x].return_id()==current_position)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"\nYou have landed on a company.";
			cmpny[x].display_details_of_company();
			if(cmpny[x].get_owner()==-1)
			{
				cout<<"\nWould you like to buy this company?(y/n)";
				cin>>ch;
				while (!(ch=='y' || ch=='n' || ch=='Y' || ch=='N'))
				{
					cout<<"\nInvalid input, please type your response again. (y/n)";
					cin>>ch;
				}
				if((ch=='y' || ch=='Y'))
				{
					plyr[i].modify_balance((-1)*cmpny[x].return_company_cost());
					cmpny[x].modify_owner(i);
					cout<<"\nCongratulations!!You are the owner of this company.";
					cout<<"\n"<<cmpny[x].return_company_cost()<<" has been deducted from your bank account.";
				}
			}
			else if(cmpny[x].get_owner()!=i)
			{
				for(y=0;y<6;y++)
				{
					if(cmpny[y].return_id()==cmpny[x].return_paired_company_id())
					break;
				}
				if(cmpny[y].get_owner()==cmpny[x].get_owner())
				{
					cout<<"\nThis company is owned by other player.You have to pay a rent of "<<cmpny[x].return_paired_rent();
					plyr[i].modify_balance((-1)*cmpny[x].return_paired_rent());
					cout<<"\nRs."<<cmpny[x].return_paired_rent()<<" has been deducted from your account.";
				}
				else
				{
					cout<<"\nThis company is owned by other player.You have to pay a rent of "<<cmpny[x].return_basic_rent();
					plyr[i].modify_balance((-1)*cmpny[x].return_basic_rent());
					cout<<"\nRs."<<cmpny[x].return_basic_rent()<<" has been deducted from your account."; 
				}
			}	
			else
			{
				cout<<"\nYou are the owner of this company.";
			}
		}
		
		
		for (x=0;x<20;x++)
		{
			if (cty[x].return_id()==current_position)
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{	
			cout<<"\nYou have landed in a city.";
			cty[x].display_details_of_city();
			if (cty[x].get_owner()==-1)
			{
				cout<<"\nNo one owns this city. Would you like to buy it? (y/n)";
				cin>>ch;
				while (!(ch=='y' || ch=='n' || ch=='Y' || ch=='N'))
				{
					cout<<"\nInvalid input, please type your response again. (y/n)";
					cin>>ch;
				}
				if((ch=='y' || ch=='Y'))
				{
					plyr[i].modify_balance((-1)*cty[x].return_city_cost());
					cty[x].modify_owner(i);
					plyr[i].modify_city_count();
					cout<<"\nCongratulations!!You are the owner of this city.";
					cout<<"\n"<<cty[x].return_city_cost()<<" has been deducted from your bank account.";
				}
			}
			else if(cty[x].get_owner()!=i)
			{
				if(cty[x].return_house_count()>0)
				{
				plyr[i].modify_balance((-1)*((cty[x].return_house_count())*(cty[x].return_house_rent())+(cty[x].return_hotel_count())*(cty[x].return_hotel_rent())));
				temp=((cty[x].return_house_count())*(cty[x].return_house_rent())+(cty[x].return_hotel_count())*(cty[x].return_hotel_rent()));
				cout<<"\nThis city is owned by other player.Hence you are required to pay Rs."<<temp<<" as rent.";
				}
				else
				{
					plyr[i].modify_balance((-1)*(cty[x].return_city_cost()));
					cout<<"\nThis city is owned by other player.Hence you are required to pay Rs."<<(cty[x].return_city_cost())<<" as rent.";
				}
			}
			else
			{
				type_count=0;
				for(y=0;y<20;y++)
				{
					if((cty[y].get_owner()==cty[x].get_owner())&&(cty[y].return_type()==cty[x].return_type()))
					type_count++;
				}
				if(type_count==3)
				{
					if(cty[x].return_house_count()<3)
					{
						cout<<"\nDo you want to a build house in the city ?(y/n)";
						cin>>ch;
						if((ch=='y')||(ch=='Y'))
						{
							cty[x].modify_house_count();
							plyr[i].modify_balance((-1)*(cty[x].return_house_cost()));
							plyr[i].modify_house_count();
							cout<<"\nCongratulations!!You are the owner of a new house in this city.";
							cout<<"\nRs."<<cty[x].return_house_cost()<<" has been deducted from your bank account.";
						}
					}
					else if(cty[x].return_hotel_count()==0)
					{
						cout<<"\nDo you want to build a hotel in the city ?(y/n)";
						cin>>ch;
						if((ch=='y')||(ch=='Y'))
						{
							cty[x].modify_hotel_count();
							plyr[i].modify_hotel_count();
							plyr[i].modify_balance((-1)*(cty[x].return_hotel_cost()));
							cout<<"\nCongratulations!!You are the owner of a new hotel in this city.";
							cout<<"\nRs."<<cty[x].return_hotel_cost()<<" has been deducted from your bank account.";
						}
					}
				}
			}
		}
		cout<<"\nDo you want to quit?(y/n)";
	    cin>>ch2;
	}
	if((ch=='n')||(ch=='N'))
	{
	    if(i==0)
	    cout<<"\nHENCE PLAYER 2 IS THE UNDISPUTED WINNER OF THIS GAME!!!";
	    else
	    cout<<"\nHENCE PLAYER 1 IS THE UNDISPUTED WINNER OF THIS GAME!!!";
	}
	else
	{
	    cout<<"\nPlayer "<<i+1<<" has been 'BANKRUPT'.";
	    cout<<"\nHence he MUST MORTGAGE ALL HIS PROPERTY WITH THE BANK IN RETURN FOR THE MORTGAGE VALUE OF ALL THE PROPERTIES";
	    cout<<" SO AS TO CONTINUE IN THE GAME.";
	    for(x=0;x<20;x++)
	    {
	     if(cty[x].get_owner()==i)
	        {
	         cty[x].modify_owner(-1);
	         plyr[i].modify_balance((cty[x].return_city_cost())/2);
	     }
	    }
	    for(x=0;x<6;x++)
	    {
	        if(cmpny[x].get_owner()==i)
	        {
	            cmpny[x].modify_owner(-1);
	            plyr[i].modify_balance((cmpny[x].return_company_cost())/2);
	       }
	    }
	    if(plyr[i].return_balance()<=0)
	    {
	       cout<<"\nEven after mortgaging all his properties he has NOT BEEN ABLE TO REPAY ALL THE DEBTS.";
	       if(i==0)
	        cout<<"\nHENCE PLAYER 2 IS THE UNDISPUTED WINNER OF THIS GAME!!!";
	        else
	        cout<<"\nHENCE PLAYER 1 IS THE UNDISPUTED WINNER OF THIS GAME!!!";
	    }
	}
return 0;
}

	
		
			
			
					
						
					
				
				
				
				
			
			
			
			
			
			
			
			
			
			
			
			
			
										
				
				
		
		
		
		







	
	
