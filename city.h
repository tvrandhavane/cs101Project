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

