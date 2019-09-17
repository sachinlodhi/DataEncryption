/* This program encrypt or decrypts file with known extension!!!!*/
#include<fstream>
#include<iostream>
#include<string>
#include<stdlib.h>
int enchoice();

int encALT();
int dechoice();
bool fileCheck(char *);
int content(char *);
int help();
using namespace std;


/////////////////DRIVER CODE\\\\\\\\\\\\\\\\\\\\

int main()
{
  system("clear");
	int choice;
 cout<<"######################## EN-DE-Cryptor ############################";
 cout<<"\n1. Encrypt File\n2. Decrypt File\n3. Help\n4. Exit";
cout<<"\nEnter the selection : ";
cin>>choice;
if(choice==1)
	enchoice();
else if (choice==2)
	dechoice();
else if (choice==3)
	help();
else if(choice==4)
	{
		cout<<"\nAborting!!!! ";
    	}
	else
	{
		cout<<"\nWrong Choice detected!!!! Aborting!!!!";
	}
	return 0;
}


////////ENCRYPTION SECTION OF THE PROGRAM\\\\\\\\\\\\\\\\

int enchoice()
{ int choice,t,b,k;
	cout<<"1. Swapping Character Desired chracter\n2. Swapping the Alphabets and Numbers\nEnter your choice : ";
	cin>>choice;
char c,ch1,ch2;
char fileName[200];
cout<<"Enter the name of file with extension(Enter the full path if file is at other location) : ";
cin>>fileName;
//long t=0, ctr=0,asc=0;
fstream f;
f.open(fileName,ios::in|ios::out|ios::binary);
if(!f.is_open())
{	cout<<"\nFile is not Found!!!!\n\n";
  cout<<"\nPress Any Key to continue";
  cin.get();
  getchar();
  cout<<flush;
  system("clear");
  main();
}
else
{ 
if(choice==1)//if user wants to swap some perticular characters	
{
 cout<<"\nEnter both the character to be swapped in the file: ";
  cin>>ch1>>ch2;
   while(f>>c)
    { 
     if(c==ch1||c==ch2)
       {
		f.seekp(-1,ios::cur);
	     if(c==ch1)
	      f.put(ch2);
           else if(c==ch2)
	        f.put(ch1);
        }    
   }
}

else if (choice==2)//if user chooses to swap the numbers and alphabets with extreme range
{
while(f>>c)
{
  if(c>=65&&c<=90)
  {
t=155-c;
f.seekp(-1,ios::cur);
f.put(t);
  }
  else if(c>=97&&c<=122)
  {
t=219-c;
f.seekp(-1,ios::cur);
f.put(t);
  }
  else if(c>=48&&c<=57)
  {
  t=105-c;
f.seekp(-1,ios::cur);
f.put(t); 
  }}
}
}
if(f.eof())
 {
  cout<<"\nFile : "<<fileName<<" has been encrypted successfully. Want to view the binary code of encrypted file ? : ";
   cin>>ch1;
	if(ch1=='y'||ch1=='Y')
      content(fileName);
       else
        {     
         cout<<"\nAborting";
          return 0;
        }
    f.close();
 }
return 0;
}


///////DECRYPTION SECTION OF THE PROGRAM\\\\\\\\\\\\\\\\\\\\\\

int dechoice()
{
int choice, t,b;
 char c,ch1,ch2;
  char fileName[200];
   
fstream f;
  cout<<"\nDecryption Methods Available:\n1.Swapping the Desired characters.\n2.Swapping the Alphabets and Numbers.\n";
   cout<<"\nChoose the Decryption Method : " ;
   cin>>choice;
   cout<<"Enter the name of file with extension(Enter the full path if file is at other location) : ";
    cin>>fileName;
 f.open(fileName,ios::in|ios::out|ios::binary);


if(!f.is_open())
 {
cout<<"\nFile is not Found!!!!\n\n";
  cout<<"\nPress Any Key to continue";
  cin.get();
  getchar();
  cout<<flush;
  system("clear");

  main();
   }

else
 {
  if (choice==1)
   {
    cout<<"\nEnter both the character to be swapped in the file: ";
     cin>>ch1>>ch2;
      while(f>>c)
       { 

        if(c==ch1||c==ch2)
         {
	      f.seekp(-1,ios::cur);
	       if(c==ch1)
	        f.put(ch2);//ENCRYPTING
             else if(c==ch2)
              f.put(ch1);

         }	
        }
        }

   if(choice==2)
    {
 while(f>>c)
{
  if(c>=65&&c<=90)
  {
t=155-c;
f.seekp(-1,ios::cur);
f.put(t);
  }
  else if(c>=97&&c<=122)
  {
t=219-c;
f.seekp(-1,ios::cur);
f.put(t);
  }


  else if(c>=48&&c<=57)
  {

  t=105-c;
f.seekp(-1,ios::cur);
f.put(t); 
  }
}
}   

if(f.eof())
{
	cout<<"\nFile "<<fileName<<" Decrypted successfully!!!";
	cout<<"\nWant to show the contents of file?(y/n) : ";
	cin>>ch1;
	if(ch1=='y'||ch1=='Y')
     content(fileName);
 else {
 	return 0;
 }
	}
f.close();
}
return 0;
}
///////BINARY VIEW SECTION OF THE FILE\\\\\\\\\\\\

int content(char *filename)//views the contents of the file!!!!
{
char ch;
ifstream fin;
fin.open(filename,ios::in|ios::binary);

while(fin>>ch)
{
	cout<<ch;
}
fin.close();
return 0;
}

///////HELP SECTION OF THE PROGRAM\\\\\\\\\\\\\\\\\\

int help()
{
	cout<<"_______________________________________________HELP______________________________________________";
	cout<<"\nTake note and remember the characters in (same order) you choose to swap during encryption.";
  cout<<"Changing order or attempt to decrypt the file with different pair of character will lead to the twice encryption of the file and you may lose the valuable data permanently.";
  return 0;
}
