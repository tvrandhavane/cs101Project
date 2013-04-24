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
	
