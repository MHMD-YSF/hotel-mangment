/*hello dr zahi i know this is the best project ever thank you dr
i stell have part b-2 and part 3 i well do it before the persertation
(and i well modifie the filwe to from txt to csv file (ta ekhoud 20 yaane xdddd*/
using namespace std;
#include <iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include <regex> 
#include<cstdlib>
#include<ctime>
#include<fstream>
#include "md5.h"
struct date {
	int day;
	int month;
	int year;
};
struct optionf {
	string option;
	int id;
};
struct room {
	int n;
	string address;
	string type;
	float price;
	optionf* optionn;
	date star_date;
	date end_date;
};
struct client {
	int ID;
	string firstname;
	string lastname;
	string password;
	string email;
	string phonenum;
	room* r;
};
bool datee(date x, date y)
{
	long int sx, sy;
	sx = x.year * 31536000 + x.month * 2592000 + x.day * 86400;
	sy = y.year * 31536000 + y.month * 2592000 + y.day * 86400;

	return ((sx - sy) > 0);
}
int  userroom(client user) {
	int d = 0;
	client junkk;
	fstream  res("reservation.txt", ios::in | ios::out | ios::app);
	while (res)
	{
		res >> junkk.ID >> junkk.firstname >> junkk.lastname;
		getline(res, junkk.password, '\n');

		if ((junkk.firstname == user.firstname) && (junkk.lastname == user.lastname))
		{

			d++;
		}
	}return d;
}
void arrcopy(client user, client* copys,room *M,int size ) {

	ifstream clintrAR("client.txt");
	fstream res("reservation.txt", ios::in | ios::out | ios::app);
	int i = 0;
	int num;
	int s = 0;
	string first, last;
	while (clintrAR)
	{

		i++;
		clintrAR >> copys[i].ID >> copys[i].firstname >> copys[i].lastname >> copys[i].password >> copys[i].email >> copys[i].phonenum;

	}

	client junkk;
	clintrAR.close();
	junkk.r = new room[1];
	for (int j = 0; j < i; j++)
	{
		
		if(userroom(copys[j])>1)
		{
			
			
			
			copys[j].r = new room [userroom(copys[j])-1];
			while (res)
			{
				
				res >> junkk.r[0].n >> junkk.firstname >> junkk.lastname >> junkk.r[0].star_date.day >> junkk.r[0].star_date.month >> junkk.r[0].star_date.year >> junkk.r[0].end_date.day >> junkk.r[0].end_date.month >> junkk.r[0].end_date.year ;
				if ((junkk.firstname == copys[j].firstname) && (junkk.lastname == copys[j].lastname))
				{
					copys[j].r[s].n = junkk.r[0].n;
					copys[j].r[s].star_date.day = junkk.r[0].star_date.day;
					copys[j].r[s].star_date.month = junkk.r[0].star_date.month;
					copys[j].r[s].star_date.year = junkk.r[0].star_date.year;
					copys[j].r[s].end_date.day = junkk.r[0].end_date.day;
					copys[j].r[s].end_date.month = junkk.r[0].end_date.month;
					copys[j].r[s].end_date.year = junkk.r[0].end_date.year;
					for (int q = 0; q < size - 1; q++)
					{
						if (M[q].n== copys[j].r[s].n)
						{
							copys[j].r[s].address = M[q].address;
							copys[j].r[s].price = M[q].price;
							copys[j].r[s].type = M[q].type;
						}
					}
					cout<<'\t' << copys[j].r[s].n;
					cout << '\t' << copys[j].r[s].star_date.day;
					cout << '\t' << copys[j].r[s].star_date.month;
					cout << '\t' << copys[j].r[s].star_date.year;
					cout << '\t' << copys[j].r[s].end_date.day;
					
					cout << '\t' << copys[j].r[s].end_date.month;
					cout << '\t' << copys[j].r[s].end_date.year <<endl;
					


					
					s++;
				}if (s == userroom(copys[j]) - 1)
				{
					break;
				}

					
			}res.close();
		}
	}
	









}
void Reserve(client& user1 ,room*M,int size ,int size2) {

	date st, et;
	fstream res("reservation.txt", ios::in | ios::out | ios::app);
	int roomn;
	cout << "plz enter the starting date ";
	cout << "year   ";
	cin >> st.year;
	cout << endl << " month ";
	cin >> st.month;
	cout << endl << " day ";
	cin >> st.day;
	cout << "plz enter the ending  date ";
	cin >> et.year;
	cout << endl << " month ";
	cin >> et.month;
	cout << endl << " day ";
	cin >> et.day;
	for (int i = 0; i < size - 1; i++)
	{

		if(datee(st,M[i].end_date)||(datee(M[i].star_date,et)))
		{

			cout << endl << M[i].n << "\t" << M[i].address << "\t" << M[i].type << '\t' << M[i].price;
		}
	}
		cout << "enter rhe number of the room you wanet   ";
		cin >> roomn;
		for (int  i = 0; i < size -1; i++)
		{
			if (roomn == M[i].n)
			{
				cout << "rgrrv";
				M[i].star_date.year =st.year;
				M[i].star_date.month = st.month;
				M[i].star_date.day = st.day;
				M[i].end_date.year = et.year;
				M[i].end_date.month = et.month;
				M[i].end_date.day = et.day;
				user1.r = new room[size2 + 1];
				user1.r[size2].star_date.day = st.day;
				user1.r[size2].star_date.month = st.month;
				user1.r[size2].star_date.year = st.year;
				user1.r[size2].end_date.day = et.day;
				user1.r[size2].end_date.month = et.month;
				user1.r[size2].end_date.year = et.year;
				user1.r[size2].n = M[i].n;
				user1.r[size2].address = M[i].address;
				user1.r[size2].price= M[i].price;
				user1.r[size2].type = M[i].type;

				res <<'\n' << M[i].n << '\t' << user1.firstname << '\t' << user1.lastname << '\t' << st.day << ' ' << st.month << ' ' << st.year << '\t' << et.day << ' ' << et.month << ' ' << et.year;
					
					res.close();

			}

		}
	






}
bool roomdontexist(int n) {
	room roomj;
	fstream rooms("room.txt", ios::in | ios::out | ios::app);
	while (rooms) {

		rooms >> roomj.n;
		getline(rooms, roomj.address, '\n');
		if (roomj.n == n) {
			


			return true;


		}
	}rooms.close();
	cout << "This room dos not exist "<<endl;
	return false;
}
int finfRoomN(int size ) {
	ifstream cont("room.txt");
	size = 0;
	string junk;
	while (cont)
	{
		
		getline(cont, junk, '\n');
		size++;
	}
	
	return size;
}
void modify(room*room1,int size )
{
	ifstream adds("add.txt");
	fstream roomdel;

	int n, add, num;
	

	cout << " \n\t enter the  number of the room to modify the  record : ";
	cin >> n;
	while (roomdontexist(n) == false)
	{
		cin >> n;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (n == room1[i].n) {
			cout << " number  " << room1[i].n;
			cin.ignore(INT_MAX, '\n');
			cout << endl << " location  " << room1[i].address;
			getline(cin, room1[i].address);
			cout << endl << " type  " << room1[i].type;
			getline(cin, room1[i].type);
				cout<< endl << " price" << room1[i].price << " $";
				cin>>room1[i].price;
			while (adds)
			{
				adds >> num >> add;
				if (room1[i].n == num) {
					if (add != 0)
					{
						cout << " Additional features ";
						
						for (int j = 0; j <= add; j++)
						{
							cout << room1[i].optionn[j].option << '\t';
							getline(cin, room1[i].optionn[j].option);
						}
					}break;
				}
			}
		}
	}
	roomdel.open("room.txt", ios::out);
	for (int i = 0; i < size - 1; i++)
	{

		roomdel  <<room1[i].n << '\t' << room1[i].address << '\t' << room1[i].type << '\t' << room1[i].price;
		cout << endl << room1[i].n << endl << room1[i].address << endl << room1[i].type << endl << room1[i].price;
		while (adds)
		{


			adds >> num >> add;

			if (room1[i].n == num) {

				if (add != 0)
				{

					for (int j = 0; j <= add; j++)
					{


						roomdel << room1[i].optionn[j].option << '\t';


					}
				}break;
			}
		}
		roomdel << '\n';

	}adds.close();
	roomdel.close();
}
void arrcopyroom(room room1, room* copysr,int size ) {
	ifstream roomco("room.txt");
	ifstream adds("add.txt");
	string first, secend;
	int i = -1;
	int num, add;
	int f;
	while (roomco)
	{
		i++;
	
		if (i == size)
		{
			break;
		}
		
		roomco >> copysr[i].n >> copysr[i].address >> copysr[i].type >> copysr[i].price;
		
		while (adds)
		{


			adds >> num >> add;

			if (copysr[i].n == num) {

				if (add != 0)
				{
					copysr[i].optionn = new optionf[add + 1];
					for (int j = 0; j <= add; j++)
					{


						getline(roomco, copysr[i].optionn[j].option, '\t');
						



					}
				}break;
			}
		}

	}
	roomco.close();
	
	adds.close();
	fstream res("reservation.txt", ios::in | ios::out | ios::app);
	while (res)
	{
		res >> f;
		for (int i = 0; i < size - 1; i++)
		{
			if (f == copysr[i].n)
			{
				res >> first >> secend >> copysr[i].star_date.day >> copysr[i].star_date.month >> copysr[i].star_date.year >> copysr[i].end_date.day >> copysr[i].end_date.month >> copysr[i].end_date.year;
			}
		}
	}

}
bool roomexist(int n) {
	room roomj;
	fstream rooms("room.txt", ios::in | ios::out | ios::app);
	while (rooms) {
		
		rooms >> roomj.n;
		getline(rooms, roomj.address, '\n');
		if (roomj.n == n ){
			cout << "this room we already added" << endl;
			cout << "plz enter the number of the room" << endl;

			
			return false;


		}
	}rooms.close();
	return true;
}
void copyf(fstream& fout, client user) {
	fout.open("client.txt", ios::out | ios::app);
	fout << user.ID << "\t"
		<< user.firstname << "\t"
		<< user.lastname << "\t"
		<< user.password << "\t"
		<< user.email << "\t"
		<< user.phonenum << "\t"
		<< "\n";
	fout.close();


}
void delettft(room* room1, int size) {

	ifstream adds("add.txt");
	fstream roomdel;

	int n,add, num;
	roomdel.open("room.txt", ios::in);
	
	cout << " \n\t enter the  number of the room to delete record : ";
	cin >> n;
	while (roomdontexist(n) == false)
	{
		cin >> n;
	}
	for (int i = 0; i < size - 2; i++)
	{

		if (n == room1[i].n) {
			for (int j = i; j < size - 2; j++)
			{
				room1[j] = room1[j + 1];

			}
		}
	}


	roomdel.close();


	roomdel.open("room.txt", ios::out);
	for (int i = 0; i < size - 2; i++)
	{

		roomdel << room1[i].n << '\t' << room1[i].address << '\t' << room1[i].type << '\t' << room1[i].price ;
		while (adds)
		{


			adds >> num >> add;

			if (room1[i].n == num) {

				if (add != 0)
				{

					for (int j = 0; j <= add; j++)
					{


						roomdel << room1[i].optionn[j].option << '\t';

						
					}
				}break;
			}
		}
		roomdel << '\n';
		
	}adds.close();
}
bool is_valid(string email) {
	string email2;
	bool atFlag = false;
	bool comFlag = false;
	
	int size = email.length();
	for (int c = 0; c < email.length(); c++) {
		if (email[c] == '@') {
			atFlag = true;


			email2 = email.substr(size - (c + 2), size - 2);
			for (int i = 0; i < email2.length(); i++)
			{
				if (email2[i] == '.') {
					comFlag = true;
				}
			}



		}

	}
	if (atFlag && comFlag) {

		return true;

	}
	return false;
}
bool is_valid2(string email) {
	bool t = false;
	ifstream clintr("client.txt");
	client junk;
	while (clintr)
	{
		clintr >> junk.ID >> junk.firstname >> junk.lastname >> junk.password >> junk.email >> junk.phonenum;
		if (email == junk.email) {
		
			return false;
		}
	}
	return true;
}
void passGen2(string& pass) {
	


	short passLeng = 12;
	srand(time(0));
	cout << "enter the length of the password (<8)";
	cin >> passLeng;
	char* p = new char[passLeng + 2];
	for (int i = 0; i < passLeng; i++) {
		p[i] = char(rand() % 95 + 32);
	}
	cout << "\n\n\n\nYour   password is:: \t";
	for (int i = 0; i < passLeng; i++) {
		cout << p[i];
	}
	cout << "\n\n\n\n";


}
void passGen(string& pass) {
	const char alphanum[] = "!@#$%&0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	int string_length = sizeof(alphanum);
	pass = "";
	int passLeng = 0;
	cout << "Enter length of password :";
	cin >> passLeng;
	srand(time(0));
	char* p = new char[passLeng + 2];
	for (int i = 0; i < passLeng; i++) {
		p[i] = char(rand() % 95 + 32);
	}
	cout << "Your  password is::" << endl;
	
	for (int i = 0; i < passLeng; i++) {
		
		
		pass = pass + p[i];
	}
	cout << pass << endl;

}
void strongPass(string& str) {
	int lowcase = 0, upcase = 0, d = 0, s = 0;
	cin.ignore(INT_MAX, '\n');
	getline(cin, str);
	while (str.length() < 8)
	{
		cout << " your pass is short please inter a 8 digits at least ";
		getline(cin, str);
	}
	while (lowcase == 0 || upcase == 0 || d == 0 || s == 0) {

		for (int i = 0; i < str.length(); i++)
		{
			if (islower(str[i]))
				lowcase++;
			if (isupper(str[i]))
				upcase++;
			if (isdigit(str[i]))
				d++;
			if (!isalpha(str[i]) && !isdigit(str[i]))
				s++;
		}
		if (lowcase + upcase + d + s < 8 || (lowcase == 0 || upcase == 0 || d == 0 || s == 0))
		{
			cout << "week password pls enter a password ontaining numbers, letters, and special characters and at least 8 char" << endl;
			getline(cin, str);
		}
		if (lowcase && upcase && d && s && str.length() >= 8)
		{
			break;
		}
	}
}
bool checkPhone(string& pass) {
	if (pass.length() != 8) {
		cout << "the number most be  8 nubers plz enter the number correctly";

		return 0;
	}
	if ((pass[0] == '0' && pass[1] == '3') || (pass[0] == '7 ' && pass[1] == '1') || (pass[0] == '7' && pass[1] == '0') || (pass[0] == '7' && pass[1] == '6') || (pass[0] == '8' && pass[1] == '1')||(pass[0] == '7' && pass[1] == '8') || (pass[0] == '7 ' && pass[1] == '9')) {

		return 1;

	}
	else {
		cout << "plz the nuer most be star with (03,70,71,76,81)";


		return 0;
	}


}
void checkPhone2(client& pass) {
	cout << "plz enter your number ";
	getline(cin, pass.phonenum);
	if (pass.phonenum.length() != 8) {
		cout << "the number most be  8 nubers plz enter the number correctly";
		while (pass.phonenum.length() != 8) {
			cout << "the number most be  8 nubers plz enter the number correctly";
			getline(cin, pass.phonenum);
		}
	}
	else {
		if ((pass.phonenum[0] == '0' && pass.phonenum[1] == '3') || (pass.phonenum[0] == '7 ' && pass.phonenum[1] == '1') || (pass.phonenum[0] == '7' && pass.phonenum[1] == '0') || (pass.phonenum[0] == '7' && pass.phonenum[1] == '6') || (pass.phonenum[0] == '8' && pass.phonenum[1] == '1'))
			return;
		else {
			while (((pass.phonenum[0] == 0 && pass.phonenum[1] == 3) || (pass.phonenum[0] == 7 && pass.phonenum[1] == 1) || (pass.phonenum[0] == 7 && pass.phonenum[1] == 0) || (pass.phonenum[0] == 7 && pass.phonenum[1] == 6) || (pass.phonenum[0] == 8 && pass.phonenum[1] == 1)))
				cout << "plz the nuer most be star with (03,70,71,76,81)";
			getline(cin, pass.phonenum);
		}
	}
}
void hash(client& password) {
	password.password = md5(password.password);
}
void IDgen(client& str1) {
	client junk;
	str1.ID = 1;
	junk.ID = 0;
	ifstream clintr("client.txt");
	while (clintr)
	{
	
		clintr >> junk.ID >> junk.firstname >> junk.lastname >> junk.password >> junk.email >> junk.phonenum;
	}
	str1.ID = junk.ID + 1;
	
	clintr.close();
}
void display(client* user,client user2 ,int size2 )
{
	for (int i = 0; i < size2-1; i++)
	{
	
		cout << user[user2.ID].r[i].n << '\t' << user[user2.ID].r[i].address << '\t' << user[user2.ID].r[i].type << '\t' << user[user2.ID].r[i].price << '\t' << user[user2.ID].r[i].star_date.day << ' ' << user[user2.ID].r[i].star_date.month << ' ' << user[user2.ID].r[i].star_date.year << ' ' << user[user2.ID].r[i].end_date.day << ' ' << user[user2.ID].r[i].end_date.month << user[user2.ID].r[i].end_date.year << endl;
	}
}
void signIn(client& user) {
	IDgen(user);
	
	bool t = false;
	ifstream clintr("client.txt");
	client junk;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cout << "pls enter your first name " << endl;
	getline(cin, user.firstname);
	cout << "pls enter your last name" << endl;
	getline(cin, user.lastname);
	cout << "if you want fill your pass choose 1 and if wont us generate a srong one choose 2"<<endl;
	char   opt[2];
	do
	{
		cin >> opt[0];
	} while (opt[0] != '1' && opt[0] != '2');
	if (opt[0] == '1') {
		strongPass(user.password);
	}
	else {
		passGen(user.password);
		
	}

	user.password = md5(user.password);

	cout << "plz enter your email" << endl;
	getline(cin, user.email);
	while ((is_valid(user.email) == 0) || (is_valid2(user.email) == 0)) {
		while ((is_valid(user.email) == 0))
		{
			cout << "your email is incorect plz enternt correctly" << endl;
			getline(cin, user.email);
		}
		while ((is_valid2(user.email) == 0)) {
			cout << "your email is already exist enter onother onr plz ";
			getline(cin, user.email);
		}
	}

	cout << "plz enter your number ";
	getline(cin, user.phonenum);
	while (checkPhone(user.phonenum) == 0) {
		getline(cin, user.phonenum);
	}

	fstream fout;
	copyf(fout, user);
	
	
}
bool login(client& user) {
	client junk;
	cout << "enter your email and your password plss" << endl;
	cin.ignore(INT_MAX, '\n');

	getline(cin, user.email);
	getline(cin, user.password);
	user.password = md5(user.password);
	
	ifstream clintr("client.txt");
	while (clintr)
	{
		clintr >> junk.ID >> junk.firstname >> junk.lastname >> junk.password >> junk.email >> junk.phonenum;
		
		if ((user.email == junk.email) && (user.password == junk.password)) {
			cout << "log in sussesfull"<<endl;
			user.ID = junk.ID;
			user.firstname = junk.firstname;
			user.lastname = junk.lastname;
			user.phonenum = junk.phonenum;
			return true;
		}
		

	}clintr.close();
	 return false;
}
void clienT(client user) {
	cout <<endl<< "hello Mr." << user.lastname << endl << "You login as client";


}
void AddRoom(room& room1) {

	fstream rooms("room.txt", ios::in | ios::out | ios::app);
	cout << "plz enter the number of the room" << endl;
	cin >> room1.n;
	int add = 0;
	int u = 1;
	bool y = false;

	while (roomexist(room1.n) == false)
	{
		cin >> room1.n;
	}

	cout << "The branches we have" << endl << "1-SHIYEH" << endl << "2-GHBAYREH" << endl << "3-AAIN SAADEH" << endl << "4-HAMRA" << endl;
	cin.ignore(INT_MAX, '\n');
	getline(cin, room1.address);
	
		while ((room1.address[0] != '1') && (room1.address[0] != '2') && (room1.address[0] != '3') && (room1.address[0] != '4'))
		{
			cout << "wrong answer";
			getline(cin, room1.address);
		}
		if (room1.address[0] == '1')
		{
			room1.address = "SHIYEH";
		}
		if (room1.address[0] == '2')
		{
			room1.address = "GHBAYREH";
		}
		if (room1.address[0] == '3')
		{
			room1.address = "AAIN-SAADEH";
		}
		if (room1.address[0] =='4')
		{
			room1.address = "HAMRA";

		}

	cout << "The types  we have " << endl;
	cout << "1-SINGEL ROOM" << endl << "2-DOUBLE ROOM" << endl << "3-SUITE" << endl;
	getline(cin, room1.type);
	while ((room1.type[0] != '1') && (room1.type[0] != '2') && (room1.type[0] != '3'))
	{
		getline(cin, room1.type);
	}
	if (room1.type[0] == '1')
	{
		room1.type = "SINGEL-ROOM";

	}
	if (room1.type[0] == '2')
	{
		room1.type = "DOUBLE-ROOM";
	}
	if (room1.type[0] == '3')
	{
		room1.type = "SUITE";
	}
	if (room1.type == "SINGEL-ROOM") {
		room1.price = 60;
	}
	if (room1.type == "DOUBLE-ROOM") {
		room1.price = 120;
	}
	if (room1.type == "SUITE") {
		room1.price = 120;
	}
	
	int num = 0;
	int num2;
	int Nm = 0;
	int x;
	int size = 10;
	int* p = new int[size];
	fstream option;
	optionf fit[50];

	do {
		option.open("addf.txt", ios::in);
		num = 0;

		while (option) {

			option >> fit[num].id;
			option >> fit[num].option;
			num++;
		}
		option.close();
		num = num - 1;


		cout << "enter (-2) if you dont wand add any features and (-1) if you are done (you can add 5 features max )" << endl << "-2-SKIP" << endl << "-1-FINESH" << endl << "0-ADD NEW FEATURES" << endl;
		add = -1;
		Nm = -1;
		for (int i = 0; i < num; i++)
		{
			cout << fit[i].id << "-" << fit[i].option << endl;
		}

		for (int i = 0; i < 5; i++)
		{
			add++;
			cin >> p[i];
			
			if (p[i] == -1 || p[i] == -2 || p[i] == 0 )
			{
				break;
				
			}
			Nm++;
		}
		
		if (p[add] == -2 ) {
			
			fstream roomss;
			roomss.open("room.txt", ios::out | ios::app);
			roomss << room1.n << "\t"
				<< room1.address << "\t"
				<< room1.type << "\t"
				<< room1.price  << "\t"
				<< "\n";

			roomss.close();
		}
		int s = 0;
		if (p[add] == 0 || p[add] == 0)
		{

			optionf junk;
			fit[0].id = 1;
			junk.id = 0;
			ifstream clintr("addf.txt");
			while (clintr)
			{
				clintr >> junk.id >> junk.option;
				s++;
			}
			fit[s - 1].id = junk.id + 1;
			cin >> fit[s - 1].option;
			clintr.close();
			option.open("addf.txt", ios::out | ios::app);
			if (option.is_open()) {

				option << fit[s - 1].id << "\t";
				option << fit[s - 1].option << "\t" << '\n';
				option.close();

			}
		}
		cout << add;
	} while (p[add] ==0);
	room1.optionn = new optionf[Nm+1];
	int j = 0;
	int temp=0;
	
	
	for (int i = 0; i < Nm+1; i++)
	{
		
	
		
		room1.optionn[i].option = fit[p[i ]-1].option;
		
	}
	if (Nm<=4&&Nm>=0) {
		fstream roomd;
		roomd.open("room.txt", ios::out | ios::app);
		roomd << room1.n << "\t"
			<< room1.address << "\t"
			<< room1.type << "\t"
			<< room1.price  << "\t";
		for (int i = 0; i < Nm+1; i++)
		{

			roomd << room1.optionn[i].option << "\t";

		}
		roomd << "\n";

		roomd.close();
		
	}
	add = Nm + 1;

	fstream add1;
	add1.open("add.txt", ios::out | ios::app);
	add1 << room1.n << "\t" << add << "\n";
	add1.close();
}
bool administrator(client user) {
	
	
	string alyoussf = "alyoussf";
	string AlYoussf = "AlYoussf";
	
	if ((user.lastname == AlYoussf || (user.lastname == alyoussf))) {

		return true;


	}
	else return false;

}
void arrcopyss(client user ,client *copys) {
	
	ifstream clintrAR("client.txt");
	fstream res("reservation.txt", ios::in | ios::out | ios::app);
	int i = 0;
	int num;
	int s = 0;
	string first, last;
	while (clintrAR)
	{
		
		i++;
		clintrAR >> copys[i].ID >> copys[i].firstname >> copys[i].lastname >> copys[i].password >> copys[i].email >> copys[i].phonenum;
		while (res)
		{
			res >> num>>first>>last;
			if(first==copys[i].firstname&&(last==copys[i].lastname))
			{
				
			
			
			}
		}



		
	}

	clintrAR.close();
}
int main() {
	
	client user, junk, arr;
	char  num1[2];
	room room1;
	int var;
	bool ad;
	int size = 0;
	int size2 = 0;

cout << "1- log in" << "2- sign in" << endl;

	do
	{
		cin >> num1;
	} while (num1[0] != '1' && num1[0] != '2');
	if (num1[0] == '1') {
		while ((login(user) == 0) && num1[0] == '1') {
			cout << "your password or your email is incorrect plz try again or create a new account" << endl;
			cout << "1- log in" << "2- sign in" << endl;
			cin >> num1[0];
			if (num1[0] == '2') {
				break;
			}
		}
	}
	if (num1[0] == '2') {
		signIn(user);

	}
	
IDgen(arr);
size = finfRoomN(size);
client* copys = new client[arr.ID+1];
room* M = new room[size];
arrcopyroom(room1, M,size);
arrcopy(arr, copys, M, size);
size = finfRoomN(size);

	size2 = userroom(user);
	user.r = new room[size2];
	

	
	
	
	
	if (administrator(user)) {
		do {
			cout << "hello Mr." << user.lastname << endl << "You login as adminstrator" << endl;
			cout << "1-Add rooms" << endl;
			cout << "2-Delete a room" << endl;
			cout << "3-Modify the data of a room" << endl;
			cin >> var;

		} while ((var != 1) && (var != 2) && (var != 3));
		if (var == 1) {
			AddRoom(room1);
		}if (var == 2) {

			delettft(M,size);
		}if (var == 3) {
			modify(M, size);
		}

	}
	else 
	{
		clienT(user);
		do {
			cout << "1-Reserve a room" << endl;
			cout << "2-Cancel a reservation" << endl;

			cin >> var;


		} while ((var != 1) && (var != 2));
		
		
		if (var == 1)
		{
			Reserve(user, M, size,size2);
        }
		if (var == 2) 
		{
			cout << "the room you reserved"<<endl;
			display(copys,user,size2);
			cout << "enter thre number of the room you want to cancel the reservation" << endl;

		}
		
	
	}
	size = finfRoomN(size);
	
	
	arrcopyroom(room1, M,size);
	

}
