/*students name:
bayan alqudaihi
sara alosaime
refan alghamdi
ruba almalki
Alshaima  talal
*/

//this program used to calculate currency exchange programmatically

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void printList();

string convertInput();

bool check(string);

double getDataFromFile(string, string, double);

int main()
{

double amount;
string firstCurrency, secoudCurrency;
bool isExist;
 
printList(); //  Call function that will be print message list
 
cout<<"What is the currency you have? ";
 
// will repeat if price is zero
do{ 
  firstCurrency = convertInput();  // call the function that return Uppercase string
  isExist = check(firstCurrency);
  
  if(isExist == false){
   cout<<"Incorrect abbreviation please provide it again"<<endl;
  }
  
}while(isExist == false);
 
cout<<"What is the currency you want to exchange it for? "<<endl;
 
// will repeat if price is zero
do{
  secoudCurrency=convertInput();  // Call the function that return Uppercase string
 
  isExist = check(secoudCurrency);
  
  if(isExist == false){
   cout<<"Incorrect abbreviation please provide it again"<<endl;
  }
  
}while(isExist == false);
 
cout<<"How much money you want to exchange?"<<endl;
cin>>amount; // input amount
  
double total=  getDataFromFile(firstCurrency, secoudCurrency, amount);  // call function to calclate total
 
// Final otput with total
cout<<amount<<" "<<firstCurrency<<" is "<<total<<" "<<secoudCurrency<<endl;
 
return 0;
}

  // Function 1
void printList(){
cout<<"The currencies we have exchange for are:"<<endl;
cout<<"  SAR --> Saudi Arabia Riyal"<<endl;
cout<<"  KWD --> Kuwaiti Dinar"<<endl;
cout<<"  QAR --> Qatar Riyal"<<endl;
cout<<"  AED --> United Arab Emirates Dirham"<<endl;
cout<<"  BHD --> Bahraini Dinar"<<endl;
cout<<"  OMR --> Omani Rial"<<endl;
}
  // Function 2
string convertInput(){
char arr[3]; // array to read inputs 
string upperVlaue=""; // store Uppercase
//  input three char to array
for(int i=0; i<3; i++)
  cin >> arr[i]; // user inputDG
    for (int i=0; i<3; i++)
       upperVlaue+= towupper(arr[i]); // convert array to Uppercase, and store to string valribale 
  
return upperVlaue; // return Uppercase string value
}

bool check(string currency){
ifstream file_("ExchangeRate.txt");  // Source file (.txt), that contain data 
string currencyData;
 
// open file to read data
if(file_.is_open()){
  // read data from file
  while(file_ >> currencyData){
   // check if currency is found Will Return it's price, OR zero 0 if not found
   if(currency == currencyData){
    return true; // return price
   }
  }
}
else{
  // close file
  file_.close();
}
return false;
}
  // Function 3
double getDataFromFile(string firstCurrency, string secoudCurrency, double amount ){
ifstream file_("ExchangeRate.txt");  // Source file (.txt), that contain data 
string currencyData, currencyData2;
double priceData, priceData2;
 
// open file to read data
if(file_.is_open()){
  // read data from file
  while(file_ >> priceData >> currencyData >> priceData2 >> currencyData2){
   // check if currency is found Will Return it's price, OR zero 0 if not found
   if(firstCurrency == currencyData &&  secoudCurrency == currencyData2 ){
    return amount * priceData2; // return price
   }
   else if(secoudCurrency == currencyData && firstCurrency == currencyData2){
    return amount / priceData2; // return price
   }
  }
}
else{
  // close file
  file_.close();
}
// Will Return 0.0 (zero) is not found
return 0.0;
}