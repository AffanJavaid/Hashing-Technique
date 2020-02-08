#include<iostream>
#include<string.h>
/* u2017230 Muhammad Affan Javaid 
   u2017103 Eisha Jawad */
using namespace std;
typedef unsigned int unit;
unit table_size;
char Disk[64];
struct fNode 
{
	string File;  //file name
	string Extn;
	short fSize;
	short fstart;
	fNode *next;
}; 
short end;
short start; 	
typedef fNode * LIST;
fNode* head;
short Contiguous_Allocation(short size)
{	
   Disk[size];
   start=end;
   end=end+size;
   cout<<"  Start : "<<start<<endl;
   cout<<" End : "<<end<<endl;
   if (start<= 63)
   {
   for (short i=start ;i<end; i++)
   {
   if (Disk[i]== 'E')
   {
   	Disk[i]='O';
   }
   }
   }
   else if (start>= 63)
   {
   	cout<<" Disk is Full  :\n";
   	for (int i=0; i<64; i++)
   	{
   		if (Disk[i]=='E')
   		{
   			cout<< " Empty locations are : "<<i<<endl;
		}
	}
   }
   return start;
}
short endD;
void Empty_Disk(short size,short startD)
{	
   Disk[size];
   endD=startD+size;
   for (short i=startD ;i<endD; i++)
   {
   if (Disk[i]== 'O')
   {
   	Disk[i]='E';
   }
   else 
   {
   	cout<<" Disk already empty : \n";
   }
   }
   cout<<"  Disk empty from "<<startD<< " to "<<endD<<endl;
}
unit hash(string key) { // Hash function which give index number
	unit hash_value = 0;
	int i;
	for ( i=0; key[i]!='\0'; i++ ) {   // add ASCII of all the chracters
		hash_value=(hash_value<<5)+key[i];
	}
	unit index=hash_value%table_size;
	return (index);
}
//OPEN HASHING
struct hash_tbl {
	unit table_size;
	fNode **the_list;     // it will have the add of whole fNode struct
};
hash_tbl * H;
void intialize_table() {               //function to make hash table
	H= new hash_tbl;
	H->table_size = table_size ;              // table size is equal to number of elements
	H->the_list = new LIST[H->table_size];   // making dynamic array of the list
	for(unit i=0; i<H->table_size; i++ ) {    //making array of hashtable
		H->the_list[i] =new fNode;
		(H->the_list[i])->next = NULL;
		(H->the_list[i])->File =" empty ";
		(H->the_list[i])->Extn =" empty ";
		(H->the_list[i])->fSize =0;
		(H->the_list[i])->fstart =0;
	}
	cout<<" Table Size : "<<H->table_size<<endl;
}
void Insert( string name) { // insert at end
	unit index;
	short size;
	index = hash(name);
	cout<<" Index : "<<index<<endl;
	if ((H->the_list[index])->File ==" empty " ) 
	{
		(H->the_list[index])->File=name;
		cout<<" Wrtie File Extension : ";
		cin>>(H->the_list[index])->Extn;
		cout<<" Wrtie File Size : ";
		cin>>(H->the_list[index])->fSize;
        H->the_list[index]->fstart=Contiguous_Allocation((H->the_list[index])->fSize);
        (H->the_list[index])->next=NULL;
	} 
	else 
	{
		fNode * ptr = H->the_list[index];
		fNode *new_cell = new fNode;
		new_cell->File = name ;
		cout<<" Wrtie File Extension : \n";
		cin>>new_cell->Extn;
		cout<<" Wrtie File Size : \n";
		cin>>new_cell->fSize;
		while ( ptr->next != NULL) 
		{
			ptr = ptr->next;
		}
		ptr->next = new_cell;
		new_cell->fstart=Contiguous_Allocation(new_cell->fSize);		
	}
}
// find
void find( string name ) { // function of structure datatype
	//  H->the_list[index]  will be our head node.
	fNode *ptr;
	unit index = hash(name);
	cout<<" Index : "<<index<<endl;
	head=H->the_list[index];
	for ( ptr =head; ptr!=NULL; ptr=ptr->next)
	{
		if (ptr->File  == name ) 
		{
			cout<<" File : "<<ptr->File<<" . "<<ptr->Extn<<" "<<ptr->fSize<<endl;
		}
	}
}
void Delete( string name ) { // function of structure datatype
	unit index = hash(name);
	cout<<" Index : "<<index<<endl;
	head=H->the_list[index];
	fNode *prev=head;
	fNode *ptr;
	if(head->File=="empty")
	{
		cout<<" Empty : \n";
	}
	else if (head->File==name && head->next==NULL)  // if there is only one heead node in hashtable
	{
		cout<<" File to delete: "<<head->File<<" . "<<head->Extn<<" "<<head->fSize<<endl;
		Empty_Disk(head->fSize, head->fstart);
		head->File="empty";
	   	head->Extn="empty";
	   	head->fSize=0;
	}
	else 
	{
	for(ptr=prev->next; ptr!=NULL; ptr=ptr->next)
	{
	   if(ptr->File == name) 
	   {
	   	cout<<" File to delete: "<<ptr->File<<" . "<<ptr->Extn<<endl;
	   	Empty_Disk(head->fSize, head->fstart);
	   	ptr->File="empty";
	   	ptr->Extn="empty";
	   	ptr->fSize=0;
	    prev->next=ptr->next; 
	   }
	    prev=prev->next;
	}
	
	}
}

void Display()  // function of structure datatype 
{ 
   //  H->the_list[index]  will be our head node.
    fNode *ptr;
    for (int i=0; i<table_size; i++)
    {
    for ( ptr =H->the_list[i]; ptr!=NULL; ptr=ptr->next)
    {
      cout<<" HashTable ["<<i<<"]"<<" | ->";
	  cout<<" File : "<<ptr->File<<" . "<<ptr->Extn<<" "<<ptr->fSize<<" -> ";
    }
    cout<<" NULL "<<endl;
    }
}
void Display_Memory()
{
	cout<<" Disk Memory : "<<endl;
	for (int i=0; i<64; i++)  // making disk of 64 size
	{
		cout<<Disk[i]<< "   ";
	
	}
}
int main() {
	unit n;
	fNode *f;
	string name;
		for (int i=0; i<64; i++)  // making disk of 64 size
	{
		Disk[i]='E';
	}
	cout<<"Write the size of HashTable : ";
	cin>>table_size;
	intialize_table();
	int c=0;
	do {
		cout<<" \n\nto Exit Press 0: \n";
		cout<<" To insert file Press 1: \n";
		cout<<" To find Press 2: \n";
		cout<<" To Delete Press 3: \n";
		cout<<"  Display Hash table 4 : \n";
		cout<<"  Display Memory 5 : \n";
		cin>>c;
		if (c==1) {
			cout<<" Write the name of file : ";
			cin>>name;
			Insert(name);
		} else if (c==2) {
			cout<<"Write name of file to find : ";
			cin>>name;
			find(name);
		} else if (c==3) {
			cout<<"Write name of file to Delete : ";
			cin>>name;
			Delete(name);
		} else if (c==4) {
			Display();
		}
		else if (c==5) {
			Display_Memory();
		}
	} while (c!=0);
	cout<<" Thanks For Using our Program : "<<endl;
}
