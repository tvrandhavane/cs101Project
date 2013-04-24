#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
                                											
using namespace std;


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
	        w.RenderText(p1,p2,"city name:",Blue);
	        w.RenderText(p1,p2,city_name,Black);
                
                char array1[50];
	        sprintf(array1,"%d",type);    
	        w.RenderText(p1,p2,"city type:",Blue);
	        w.RenderText(p1,p2,array1,Black);

	        char array2[50];
	        sprintf(array2,"%d",city_cost);    
	        w.RenderText(p1,p2,"cost of city:",Blue);
	        w.RenderText(p1,p2,array2,Black);

		char array3[50];
	        sprintf(array3,"%d",city_rent);    
	        w.RenderText(p1,p2,"rent for",Blue);
                w.RenderText(p1,p2,city_name,Black);
                w.RenderText(p1,p2,":",Blue);
	        w.RenderText(p1,p2,array3,Black);
                
                char array4[50];
	        sprintf(array4,"%d",house_rent);    
	        w.RenderText(p1,p2,"Rent for each house:",Blue);
	        w.RenderText(p1,p2,array4,Black);

		char array5[50];
	        sprintf(array5,"%d",hotel_rent);    
	        w.RenderText(p1,p2,"Rent for each hotel:",Blue);
	        w.RenderText(p1,p2,array5,Black);

		if(owner==0)
                RenderText(p1,p2,"Owned by : player 1.",Black);
		else if(owner==1)
		RenderText(p1,p2,"Owned by : player 2.",Black);
		else
                RenderText(p1,p2,"No one owns this city yet.",Black);
			
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
        char array11[50];
	sprintf(array11,"%d",dice_sum);    
	w.RenderText(p1,p2,"Number on dice:",Blue);
	w.RenderText(p1,p2,array11,Black);

}


			








int main()
{	

	int current_position=0;
	class city cty[20];
	class player plyr[2];
	class company cmpny[6]; 
	
	                                            //used to read the objects of city class
	FILE * fp1,*fp2,*fp3;
	fp1=fopen("city.txt","r");
	fp2=fopen("company.txt","r");								
	
	if(fp1==NULL)
	{
                RenderText(p1,p2,"Cannot open the file city.txt",Black);		
                exit(0);
	}
	if(fp2==NULL)
	{
                RenderText(p1,p2,"Cannot open the file company.txt",Black);
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
	i=0;
	char str[20], str2[20];
	int p_comp_id,b_rent,p_rent,comp_cost,c_owner;
	while(!feof(fp2))
	{
		fscanf(fp2,"%s %s %d %d %d %d %d %d",str,str2,&id,&p_comp_id,&comp_cost,&b_rent,&p_rent,&c_owner);
		cmpny[i].set_details_of_company(str,str2,id,p_comp_id, b_rent, p_rent,comp_cost,c_owner);
		cmpny[i].display_details_of_company();
		i++;
	}
	for(i=0;i<2;i++)
	{
		plyr[i].set_details_of_player(i,50000,0,0,0,0,0);     
		plyr[i].display_details_of_player();                                        
	}
	fclose(fp1);
	fclose(fp2);
	
	
	                                                                       	
	int x, y, flag=-1,type_count=0,j,temp;
	
	char ch,ch2='n';												//flag=0 denotes city, and flag=1 denotes company
	                                                                      //main algorithm
	
	start:                                                                //LABEL
	
	
	
	
	
	while((plyr[0].return_balance()>0)&&(plyr[1].return_balance()>0)&&((ch2=='n')||(ch2=='N')))
	{
	    i=z%2;
            RenderText(p1,p2,"Next player's turn.",Black);
	   
            char array2[15];
            sprintf(array2,"%d",plyr[i].return_balance());
            w.RenderText(p1,p2,"Your current balance:",Blue);
	    w.RenderText(p1,p2,array2,Black)
	    
	    flag=-1;
		z++;
		
		if(plyr[i].return_turn()==0)
		dice(); 
		
		
		main_algorithm_start:                                            //LABEL
		
		
		
		
		
		current_position=plyr[i].set_position(dice_sum);
		
		main_algorithm_start_2:
		
		
		if((current_position==9)&&(plyr[i].return_turn()==0))
		{
		    
			if(plyr[i].return_turn()==0)
			{
                        RenderText(p1,p2,"You've landed in 'JAIL'.Wait for the other player to play.",Black);
			plyr[i].modify_turn(1);
			goto start;
			}
			if(plyr[i].return_turn()>0)
			{	
				if(plyr[i].return_turn()==1)
				{
				 RenderText(p1,p2,"Would you like to pay a fine of Rs. 500, throw three times or miss three turns?",Black);     
                                 RenderText(p1,p2,"Enter 1, 2 or 3 respectively.",Black);
				 cin>>jail_choice[i];
				}
				switch(jail_choice[i])
				{
					case 1:
						plyr[i].modify_balance(-500);
                                                RenderText(p1,p2,"Rs. 500 has been deducted from your bank balance.",Black);
						char array1[50];
	                                        sprintf(array1,"%d",plyr[i].return_balance());    
	                                        w.RenderText(5.0,0.5,"Your current balance :",Blue)
	                                        w.RenderText(p1,p2,array1,Black)
						
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
                                                RenderText(p1,p2,"You've failed to satisfy the condition to be released from 'JAIL'.Hence you've to wait for two more turns.",Black);

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
                                                RenderText(p1,p2,"Invalid input.You've been released from jail and Rs.500 has been deducted from your bank balance.",Black);
						
						plyr[i].modify_balance(-500);
						break; 
				}
			}
		}
		
		
		
		                                                                  //chance 
		
		if (current_position==7 || current_position==20)
		{
			RenderText(p1,p2,"You have landed at 'CHANCE'.",Black);
			switch (dice_sum)
			{
				case 2:				//SYNTAX DOUBTFUL
                                        RenderText(p1,p2,"You have lost Rs. 2000 in the share market.",Black);
					plyr[i].modify_balance(-2000);
					break;
				case 3:
                                        RenderText(p1,p2,"You have won Rs. 2500 in the lottery",Black);
					plyr[i].modify_balance(2500);
					break;
				case 4:
                                        RenderText(p1,p2,"You have been fined Rs. 1500 for driving under influence (DUI)",Black);
					plyr[i].modify_balance(-1500);
					break;
				case 5:
                                        RenderText(p1,p2,"You have won Rs. 1000 in a crossword competition!",Black);
					plyr[i].modify_balance(1000);
					break;
				case 6:
                                        RenderText(p1,p2,"House repairs have cost you Rs. 1500",Black);
					plyr[i].modify_balance(-1500);
					break;
				case 7:
					RenderText(p1,p2,"You have won a jackpot of Rs. 2000!",Black);
					plyr[i].modify_balance(2000);
					break;
				case 8:
					RenderText(p1,p2,"A fire in your godown has caused you a loss of Rs. 3000",Black);
					plyr[i].modify_balance(-3000);
					break;
				case 9:
					if (current_position==7)
					plyr[i].modify_balance(2500);
																	                         //Changed the rules.to be filled.
					break;
				case 10:
					RenderText(p1,p2,"You have been sent to the 'JAIL'.",Black);
					plyr[i].jump(9);
					goto main_algorithm_start_2;
					break;
				case 11:
					RenderText(p1,p2,"You have won Rs. 3000 for best performance in export!",Black);
					plyr[i].modify_balance(3000);
					break;
				case 12:
					RenderText(p1,p2,"You have been sent to the 'REST HOUSE'.",Black);
					plyr[i].jump(27);			                                                        //Changed the rules. Player will NOT miss a turn.
					plyr[i].modify_balance(100);
					break;
			}
		}
		
		
		if((current_position==16)||(current_position==29))                   //community chest
		{
			RenderText(p1,p2,"You have landed at 'CHANCE'.",Black);
			switch (dice_sum)
			{
				case 2:
					RenderText(p1,p2,"It is your birthday.You have received Rs. 500 as gift.",Black);
					plyr[i].modify_balance(500);
					break;	
				case 3:
				        RenderText(p1,p2,"You've been sent to 'JAIL'.",Black);
					plyr[i].jump(9);
					goto main_algorithm_start_2;
					break;
				case 4:
					RenderText(p1,p2,"You've won 1st prize in beauty contest.Rs. 2500 has been awarded to you.",Black);
					plyr[i].modify_balance(2500);
					break;
				case 5:
					RenderText(p1,p2,"You've to pay medical and school fees totaling Rs. 1000.",Black);
					plyr[i].modify_balance(-1000);
					break;
				case 6:
					RenderText(p1,p2,"Income tax refund:You received Rs. 2000.",Black);
					plyr[i].modify_balance(2000);
					break;
				case 7:
					RenderText(p1,p2,"Expenses for marriage celebration are Rs. 2000.",Black);
					plyr[i].modify_balance(-2000);
					break;
				case 8:
					RenderText(p1,p2,"You've been sent to 'REST HOUSE'.",Black);
					plyr[i].jump(27);			                                                        //Changed the rules. Player will NOT miss a turn.
					plyr[i].modify_balance(100);
					break;
				case 9:
					RenderText(p1,p2,"Cost of carrying out general repairs on all your properties is :\n"<<"Rs.50 for each house.\n"<<"Rs.100 for each hotel.",Black);
					plyr[i].modify_balance((-50)*(plyr[i].return_house_count())+(-100)*(plyr[i].return_hotel_count()));
					break;
				case 10:
					RenderText(p1,p2,"You've received interest on shares amounting to Rs. 1500.",Black);
					plyr[i].modify_balance(1500);
					break;
				case 11:
					RenderText(p1,p2,"You've to pay Insurance Premium amounting to Rs. 1500.",Black);
					plyr[i].modify_balance(-1500);
					break;
				case 12:
					RenderText(p1,p2,"You've received Rs. 3000 by selling your stocks.",Black);
					plyr[i].modify_balance(3000);
					break;
			}
		}
		
					
		
		
		
		
		
		if(current_position==18)                                                     //CLUB
		{
			RenderText(p1,p2,"You have landed at CLUB HOUSE.",Black);
			plyr[i].modify_balance(-100);
			RenderText(p1,p2,"Rs. 100 deducted from your bank account.",Black); 
		}
		
		if(current_position==27)                                                 //REST HOUSE
		{
			RenderText(p1,p2,"You have landed at REST HOUSE.",Black);
			plyr[i].modify_balance(100);
			RenderText(p1,p2,"Rs. 100 deposited in your bank account.",Black); 
		}
		
		if(current_position-dice_sum<0)                                         //START
		{
			RenderText(p1,p2,"You have crossed START and Rs. 500 has been deposited in your bank account",Black);
			plyr[i].modify_balance(1500);
		}
		
		
		
		
		
		
		if (current_position==5)				                                    //income tax
		{
			RenderText(p1,p2,"You have landed at 'INCOME TAX'.",Black); 
			if (plyr[i].return_city_count()*(50) >500)
			{
				plyr[i].modify_balance(-500);
				RenderText(p1,p2,"Rs. 500 has been deducted fom your bank account.",Black);
			}
			else
			{
				plyr[i].modify_balance((-50)*(plyr[i].return_city_count()));
                                char array1[50];
	                        sprintf(array1,"%d",plyr[i].return_city_count());    
	                        w.RenderText(p1,p2,"Rs.",Blue);
	                        w.RenderText(p1,p2,(50)*(array1),Black);
                                w.RenderText(p1,p2,"has been deducted from your bank account.",Blue);
			}
		}
		
		if (current_position==31)				                                //wealth tax
		{
			w.RenderText(p1,p2,"You have landed at 'WEALTH TAX'.",Black);
			if ((plyr[i].return_house_count()+(2)*(plyr[i].return_hotel_count()))*(50) > 500)
			{
				plyr[i].modify_balance(-500);
				w.RenderText(p1,p2,"Rs. 500 has been deducted from your bank account.",Black);
			}
			else
			{
				plyr[i].modify_balance((-50)*((plyr[i].return_house_count())+(2)*(plyr[i].return_hotel_count())));
				char array1[50];
                                char array2[50];
	                        sprintf(array1,"%d",plyr[i].return_house_count()); 
                                sprintf(array1,"%d",plyr[i].return_hotel_count());   
	                        w.RenderText(p1,p2,"Rs.",Blue);
	                        w.RenderText(p1,p2,(-50)*(array1)+(2)*(array2)),Black);
                                w.RenderText(p1,p2,"has been deducted from your bank account.",Blue);
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
			w.RenderText(p1,p2,"You have landed on a company.",Black);
			cmpny[x].display_details_of_company();
			if(cmpny[x].get_owner()==-1)
			{
				w.RenderText(p1,p2,"Would you like to buy this company?(y/n)",Black);
				cin>>ch;
				while (!(ch=='y' || ch=='n' || ch=='Y' || ch=='N'))
				{
					w.RenderText(p1,p2,"Invalid input, please type your response again. (y/n)",Black);
					cin>>ch;
				}
				if((ch=='y' || ch=='Y'))
				{
					plyr[i].modify_balance((-1)*cmpny[x].return_company_cost());
					cmpny[x].modify_owner(i);
					w.RenderText(p1,p2,"Congratulations!!You are the owner of this company.",Black);
                                        char array2[15];
                                        sprintf(array2,"%d",cmpny[x].return_company_cost());
                                        w.RenderText(p1,p2," has been deducted from your bank account.",Blue);
	                                w.RenderText(p1,p2,array2,Black)
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
                                        char array2[15];
                                        sprintf(array2,"%d",cmpny[x].return_paired_rent());
                                        w.RenderText(p1,p2," This company is owned by other player.You have to pay a rent of",Blue);
	                                w.RenderText(p1,p2,array2,Black);

					plyr[i].modify_balance((-1)*cmpny[x].return_paired_rent());
                                        char array2[15];
                                        sprintf(array2,"%d",cmpny[x].return_paired_rent());
                                        w.RenderText(p1,p2,"Rs.",Blue);
	                                w.RenderText(p1,p2,array2,Black);
                                        w.RenderText(p1,p2,"has been deducted from your account.",Blue);
				}
				else
				{
                                        char array2[15];
                                        sprintf(array2,"%d",cmpny[x].return_basic_rent());
                                        w.RenderText(p1,p2," This company is owned by other player.You have to pay a rent of",Blue);
	                                w.RenderText(p1,p2,array2,Black);
         
					plyr[i].modify_balance((-1)*cmpny[x].return_basic_rent());
                                        char array2[15];
                                        sprintf(array2,"%d",cmpny[x].return_basic_rent());
                                        w.RenderText(p1,p2,"Rs.",Blue);
	                                w.RenderText(p1,p2,array2,Black);
                                        w.RenderText(p1,p2,"has been deducted from your account.",Blue);
				}
			}	
			else
			{
				w.RenderText(p1,p2,"You are the owner of this company.",Black);
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
			w.RenderText(p1,p2,"You have landed in a city.",Black);
			cty[x].display_details_of_city();
			if (cty[x].get_owner()==-1)
			{
				w.RenderText(p1,p2,"No one owns this city. Would you like to buy it? (y/n)",Black);
				cin>>ch;
				while (!(ch=='y' || ch=='n' || ch=='Y' || ch=='N'))
				{
					w.RenderText(p1,p2,"Invalid input, please type your response again. (y/n)",Black);
					cin>>ch;
				}
				if((ch=='y' || ch=='Y'))
				{
					plyr[i].modify_balance((-1)*cty[x].return_city_cost());
					cty[x].modify_owner(i);
					plyr[i].modify_city_count();
					w.RenderText(p1,p2,"Congratulations!!You are the owner of this city.",Black);
                                        char array2[15];
                                        sprintf(array2,"%d",cty[x].return_city_rent());
                                        w.RenderText(p1,p2,"Rs.",Blue);
	                                w.RenderText(p1,p2,array2,Black);
                                        w.RenderText(p1,p2,"has been deducted from your account.",Blue);
				}
			}
			else if(cty[x].get_owner()!=i)
			{
				if(cty[x].return_house_count()>0)
				{
				plyr[i].modify_balance((-1)*((cty[x].return_house_count())*(cty[x].return_house_rent())+(cty[x].return_hotel_count())*(cty[x].return_hotel_rent())));
				temp=((cty[x].return_house_count())*(cty[x].return_house_rent())+(cty[x].return_hotel_count())*(cty[x].return_hotel_rent()));
                                 char array2[15];
                                 sprintf(array2,"%d",temp);
                                 w.RenderText(p1,p2,"This city is owned by other player.Hence you are required to pay Rs.",Blue);
	                         w.RenderText(p1,p2,array2,Black);
                                 w.RenderText(p1,p2," as rent.",Blue);
				}
				else
				{
					plyr[i].modify_balance((-1)*(cty[x].return_city_cost()));
                                        char array2[15];                                        
                                        sprintf(array2,"%d",cty[x].return_city_cost());
                                        w.RenderText(p1,p2,"This city is owned by other player.Hence you are required to pay Rs.",Blue);
	                                w.RenderText(p1,p2,array2,Black);
                                        w.RenderText(p1,p2," as rent.",Blue);
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
						w.RenderText(p1,p2,"Do you want to a build house in the city ?(y/n)"Black);
						cin>>ch;
						if((ch=='y')||(ch=='Y'))
						{
							cty[x].modify_house_count();
							plyr[i].modify_balance((-1)*(cty[x].return_house_cost()));
							plyr[i].modify_house_count();
							w.RenderText(p1,p2,"Congratulations!!You are the owner of a new house in this city.",Black);
							cout<<"\nRs."<<cty[x].return_house_cost()<<" has been deducted from your bank account.";
						}
					}
					else if(cty[x].return_hotel_count()==0)
					{
						w.RenderText(p1,p2,"Do you want to build a hotel in the city ?(y/n)",Black);
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

	
		
			
			
					
						
					
				
				
				
				
			
			
			
			
			
			
			
			
