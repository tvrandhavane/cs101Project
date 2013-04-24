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
	void set_details_of_player(int pn);
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
	void modify_hotel_count();                                //to be made in private
};
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
	
void player::set_details_of_player(int pn)
{
	player_number=pn;
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
	cout<<dice_sum<<"\n";
}

