#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;




int main (const int argc, const char* const argv[])
{
    
	
	//TO READ INPUT FILE
	freopen("input.txt", "r", stdin);
	
	
	//////////////////////////////////////////////VARIABLES////////////////////////////////////
	//DIFFERENTIATE TEXT LINES IN INPUT
	string uHash;
	string cHash;
	string fHash;
	string wHash;
	string lHash;
	
	//NUMBER OF USERS
	int users;
	
	//NUMBER OF CONTENT
	int content;
	
	//STORING USERS
	cin>>uHash;
	cin>>users;

	//STORING NUMBER OF CONTENT
	cin>>cHash;
	cin>>content;

	
	//SIMILAR SET ARRAY
	bool similar [users][users] = {false};
	
	
	
	
	
	
	
	
	
	
	
	
	
	/////////////////////////START///////////////////////////////////////////////////////////////////////
	/////////////////////////////FRIENDS///////////////////////////////////////////////////////////////
	//TEXT LINE
	cin >> fHash;
	
	//CHECK IF #W APPEARS
	string checkVar;
	
	//TO CHECK HOW MANY FRIENDS ARE THERE
	int counterFriends = 0;
	string friendVar [50];
	
	//COUNTING AND STORING VALUES (FRIENDS)
	for (int i =0; i < 50; i++)
	{
		cin >> checkVar;
		if (checkVar == "#W")
		{
			break;
		}
		else
		{
			friendVar [i] = checkVar;
			counterFriends++;
		}
	}
	
	//STORING ARRAYS
	int array1 [counterFriends] = {0};
	
	//RELATION INPUTS
	int friends [counterFriends][2] = {0};
	
	
	//READ ALL VALUE FROM FRIENDS
	for (int i = 0; i < counterFriends; i ++)
	{
		istringstream convert(friendVar[i]);
		if ( !(convert >> array1[i]) )
		{
			array1[i] = 0;	
		}
    }
	
	//STORING INTO FRIENDS ARRAY
	for (int i = 0; i < counterFriends; i++)
	{
		if (((i % 2) == 0))
		{
			friends [i][0] = array1[i];

		}
		else
		{
			friends [i - 1][1] = array1[i];

		}
		if (array1[i] == 0)
		{
			break;
		}
	}
	

	
	
	/////////////////////////////////CONTENT////////////////////////////
	
	//TO CHECK HOW MANY FRIENDS ARE THERE
	int counterContent = 0;
	string contentVar [50];
	
	//COUNTING AND STORING VALUES 
	for (int i =0; i < 50; i++)
	{
		cin >> checkVar;
		if (checkVar == "#L")
		{
			break;
		}
		else
		{
			contentVar [i] = checkVar;
			counterContent++;
		}
	}
	
	//STORING ARRAYS
	int array2 [counterContent] = {0};
	
	//RELATION INPUTS
	int ownContent [counterContent][2] = {0};
	
	
	//READ ALL VALUE FROM FRIENDS
	for (int i = 0; i < counterContent; i ++)
	{
		istringstream convert(contentVar[i]);
		if ( !(convert >> array2[i]) )
		{
			array2[i] = 0;	
		}  
	}
	
	//STORING INTO FRIENDS ARRAY
	for (int i = 0; i < counterContent; i++)
	{
		if (((i % 2) == 0))
		{
			ownContent [i][0] = array2[i];

		}
		else
		{
			ownContent [i - 1][1] = array2[i];

		}
		if (array2[i] == 0)
		{
			break;
		}

	}
	

	
	///////////////////////////////////////////LIKES/////////////////////////////
	
	//TO CHECK HOW MANY FRIENDS ARE THERE
	int counterLikes = 0;
	int likeVar [50] = {0};
	


	//COUNTING AND STORING VALUES (FRIENDS)
	for (int i =0; i < 50; i++)
	{
		cin >> likeVar [i];
		counterLikes++;
		if (likeVar [i] == 0)
		{
			break;
		}
	}
	
	counterLikes -= 1;
	
	//STORING ARRAYS
	int array3 [counterLikes] = {0};
	
	//RELATION INPUTS
	int likes [counterLikes][2] = {0};
	
	
	//READ ALL VALUE FROM FRIENDS
	for (int i = 0; i < counterLikes; i ++)
	{
		array3[i] = likeVar [i];
    }
	
	//STORING INTO FRIENDS ARRAY
	for (int i = 0; i < counterLikes; i++)
	{
		if (((i % 2) == 0))
		{
			likes [i][0] = array3[i];

		}
		else
		{
			likes [i - 1][1] = array3[i];

		}
		if (array3[i] == 0)
		{
			break;
		}
	}


	
	
	
	
	
	
	
	
	
	
	
	//////////////////////////////OPERATIONS///////////////////////////////////////////////
	
	
	int userLikesThis = 0;
	int thisUserOwns = 0;
	
	//USERS ARE ALREADY FRIENDS OF THEMSELVES. SO ARE SIMILAR AS WELL
	for (int j =0; j < users; j ++)
	{	
		similar [j][j] = true;
	}
	
	//USERS WHO ARE FRIENDS ARE SIMILAR TO EACH OTHER
	for (int j =0; j < counterFriends; j +=2)
	{	
		similar [friends[j][0] - 1][friends[j][1] - 1] = true;
		similar [friends[j][1] - 1][friends[j][0] - 1] = true;
	}
	
	
	//FINDING SIMILAR SETS OF USERS
	for (int i =0 ; i < counterFriends; i+=2)
	{
		for (int j =0; j < counterContent; j +=2)
		{	
			if (likes[i][1] == ownContent [j][1])
			{
				userLikesThis = likes [i][0];
				thisUserOwns = ownContent [j][0];
						
				similar [userLikesThis - 1][thisUserOwns - 1] = true;
			}
		}
	}
	
	
	//OUTPUT DISSIMILAR SETS OF USERS (2)
	for (int i =0 ; i < users; i++)
	{
		for (int j =0; j < users; j ++)
		{	
			if (similar[i][j] == 0)
			{
				cout << "{" << (i + 1) << "} " << "{" << (j + 1) <<"}" << endl;
				
			}
		}
	}
	
	
	//CHECK IF THERE IS A BIG ENOUGH SET
	int counterSet [users] = {0};
	
	//CHECK DISSIMILAR SETS OF USERS
	for (int i =0 ; i < users; i++)
	{
		for (int j =0; j < users; j ++)
		{	
			if (similar[i][j] == 0)
			{
				counterSet[i]++;
			}
		}
	}
	
	
	//OUTPUT DISSIMILAR SETS OF USERS (3)
	for (int k =0; k < users; k++)
	{
		if (counterSet[k] > 1)
		{	
			cout << "{" << (k + 1) << "} " << "{" ;
			for (int j =0; j < users; j ++)
		    {	
				if (similar[k][j] == 0)
				{
					cout << (j + 1)<<","  ;
				}
		    }
		cout << "}";
		cout << endl;

		}	
	}
	
	
	//CHECK IF THERE IS A BIG ENOUGH SET
	int counterSet1 [users] = {0};

	//CHECK DISSIMILAR SETS OF USERS
	for (int i =0 ; i < users; i++)
	{
		for (int j =0; j < users; j ++)
		{	
			if (similar[j][i] == 0)
			{
				counterSet1[i]++;
				
			}
		}
	}
	
	//OUTPUT DISSIMILAR SETS OF USERS (3)
	for (int k =0; k < users; k++)
	{
		if (counterSet1[k] > 1)
		{	
			cout << "{"  ;
			for (int j =0; j < users; j ++)
		    {	
				if (similar[j][k] == 0)
				{
					cout << (j + 1)<<","  ;
				}
		    }
			
		cout << "} {" << (k + 1) << "} " ;
		cout << endl;

		}	
	}
	cout << endl;
	
	
	
	
	
	
	
	
	
	
	
	
	

	//PRINTING SIMILAR ARRAY TO CHECK RESULTS
	for (int i =0 ; i < users; i++)
	{
		for (int j =0; j < users; j ++)
		{	
			cout << similar [i][j] << " ";			
		}
		cout << endl;
	}

	
    return 0;

}