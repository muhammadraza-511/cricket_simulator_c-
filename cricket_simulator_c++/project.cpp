#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
//Scorecard function if team A wins the toss and bat first
void drawScoreCard_A(string a_player[],string b_player[], int n)
{
	//Declaring all the variables for both teams A and B

    int ball_faced_A[n], ball_bowled_A[n], runs_given_A[n], wicket_taken_A[n],four_A[n],six_A[n],not_out_A[n];
    int total_score_A=0,score,total_score_B=0;
	int ball_faced_B[n], ball_bowled_B[n], runs_given_B[n], wicket_taken_B[n],four_B[n],six_B[n],not_out_B[n];
	float total_balls=0, total_balls_B=0;
	int total_wicket_A=0, total_wicket_B=0;
    float strike_rateB[n], strike_rateA[n], runsA[n], runsB[n], run_rate_A=0, run_rate_B=0;
	float total_over_A, total_over_B;

    srand(time(NULL));

	//Initializing all the variables as zero for both teams A and B

	for (int i = 0; i < n ; i++)
	{
		runsA[i]=0;
		ball_faced_A[i]=0;
		ball_bowled_A[i]=0;
		runs_given_A[i]=0;
		wicket_taken_A[i]=0;
		strike_rateA[i]=0;
		four_A[i]=0;
		six_A[i]=0;
		not_out_A[i]=0;
		runsB[i]=0;
		ball_faced_B[i]=0;
		ball_bowled_B[i]=0;
		runs_given_B[i]=0;
		wicket_taken_B[i]=0;
		strike_rateB[i]=0;
		four_B[i]=0;
		six_B[i]=0;
		not_out_B[i]=0;

	}

	//Reading and storing all the match data from the text file

	ifstream team_file;
	team_file.open("teamA_data.txt",ios::in);

	while (1) {
		for (int i = 0; i < n; i++)
		{
			team_file >>runsA[i]
				    >>ball_faced_A[i]
				    >>ball_bowled_A[i]
				    >>ball_bowled_A[i]
					>>runs_given_A[i]
					>>wicket_taken_A[i]
					>>strike_rateA[i]
					>>four_A[i]
					>>six_A[i]
					>>not_out_A[i]
					>>runsB[i]
				    >>ball_faced_B[i]
				    >>ball_bowled_B[i]
				    >>ball_bowled_B[i]
					>>runs_given_B[i]
					>>wicket_taken_B[i]
					>>strike_rateB[i]
					>>four_B[i]
					>>six_B[i]
					>>not_out_B[i];
		}
		team_file >>total_score_A
		>>total_balls
		>>total_over_A
		>>total_wicket_A
		>>run_rate_A
		>>total_score_B
		>>total_balls_B
		>>total_over_B
		>>total_wicket_B
		>>run_rate_B;

		break;
	
	}
	team_file.close(); //Closing the file

	//Displaying the match summary for 1st innings
	cout<<"\n**************************************************************************\n";
	cout<<"\n\t\t\t\tMATCH SUMMARY\n\n";
	cout<<"\n**************************************************************************\n\t\t\t1st Innings\n";
	cout<<"\n**************************************************************************\n";
	cout<<"NAME\t\tRUNS\t\tBALLS\t\t4s\t\t6s\t\tSTRIKE RATE\n";
	for (int i = 0; i < n ; i++)
	{
		if(runsA[i]>=0 && ball_faced_A[i]>0)
		if(not_out_A[i]==1)
		cout<< a_player[i]<<"\t\t"<<runsA[i]<<"\t\t"<<ball_faced_A[i]<<"\t\t"<<four_A[i]<<"\t\t"<<six_A[i]<<"\t\t"<<strike_rateA[i]<<endl;
		
		else
		cout<< a_player[i]<<"\t\t"<<runsA[i]<<"\t\t"<<ball_faced_A[i]<<"\t\t"<<four_A[i]<<"\t\t"<<six_A[i]<<"\t\t"<<strike_rateA[i]<<endl;

	}
	cout<<"*******************************************************\n";
	cout<<"NAME\t\tRUNS\t\tBALLS\t\tWICKETS\n";
	for (int i = 10; i >5 ; i--)
	{
		cout<< b_player[i]<<"\t\t"<<runs_given_B[i]<<"\t\t"<<ball_bowled_B[i]<<"\t\t"<<wicket_taken_B[i]<<endl;
	}
	

		cout << "Total Runs: "<< total_score_A << "\t\tTotal balls : "<< total_balls <<"\t\tOvers: "<<setprecision(2)<< total_over_A <<"\t\tWickets: "<<total_wicket_A<<"\t\tRun Rate: "<<setprecision(3)<<run_rate_A<< endl;
        cout<<"\n**************************************************************************\n\n";

	//Displaying the match summary for 2nd innings

	cout<<"\t\t\t2nd Innings\n**************************************************************************\n\n";
	cout<<"NAME\t\tRUNS\t\tBALLS\t\t4s\t\t6s\t\tSTRIKE RATE\n";
	for (int i = 0; i < n ; i++)
	{
		if(runsB[i]>=0 && ball_faced_B[i]>0)
		if(not_out_B[i]==1)
		cout<< b_player[i]<<"\t\t"<<runsB[i]<<"\t\t"<<ball_faced_B[i]<<"\t\t"<<four_B[i]<<"\t\t"<<six_B[i]<<"\t\t"<<strike_rateB[i]<<endl;
		
		else
		cout<< b_player[i]<<"*\t\t"<<runsB[i]<<"\t\t"<<ball_faced_B[i]<<"\t\t"<<four_B[i]<<"\t\t"<<six_B[i]<<"\t\t"<<strike_rateB[i]<<endl;
		
	}
	cout<<"*******************************************************\n";
	
	cout<<"NAME\t\tRUNS\t\tBALLS\t\tWICKETS\n";
	for (int i = 10; i > 5 ; i--)
	{
		cout<< a_player[i]<<"\t\t"<<runs_given_A[i]<<"\t\t"<<ball_bowled_A[i]<<"\t\t"<<wicket_taken_A[i]<<endl;
	}

		cout << "Total Runs: "<< total_score_B << "\t\t Total Balls : "<< total_balls_B <<"\t\tOvers: "<<setprecision(2)<<total_over_B<<"\t\tWickets: "<<total_wicket_B<<"\t\tRun Rate: "<<setprecision(3)<<run_rate_B<< endl;
        cout<<"\n\t\t**************************************************************************\n\n";
	
	int win_score = total_score_A - total_score_B;
	int win_wicket = 10-total_wicket_B;

	if (total_score_A > total_score_B)
	{
		cout<<"\t\tTeam A has won the match by "<< win_score<<" runs\n\n";
		cout<<"\n\n\t\t***********************************************************************\n\n";
	}
	if (total_score_B > total_score_A)
	{
		cout<<"\t\tTeam B has won the match by "<< win_wicket<<" wickets\n\n";
		cout<<"\n\n\t\t***********************************************************************\n\n";
	}
	if (total_score_A == total_score_B)
	{
		cout<<"\t\tMatch is drawn\n\n";
		cout<<"\n\n\t\t***********************************************************************\n\n";
	}

    	
}

//Scorecard if team B wins the toss and bat first

void drawScoreCard_B(string a_player[],string b_player[], int n){

	//Declaring all the variables for both teams A and B

	int ball_faced_A[n], ball_bowled_A[n], runs_given_A[n], wicket_taken_A[n],four_A[n],six_A[n],not_out_A[n];
    int total_score_A=0,score,total_score_B=0;
	int ball_faced_B[n], ball_bowled_B[n], runs_given_B[n], wicket_taken_B[n],four_B[n],six_B[n],not_out_B[n];
	float total_balls=0, total_balls_B=0;
	int total_wicket_A=0, total_wicket_B=0;
    float strike_rateB[n], strike_rateA[n], runsA[n], runsB[n], run_rate_A=0, run_rate_B=0;
	float total_over_A, total_over_B;

    srand(time(NULL));

	//Inilializing all the variables as zero for both teams A and B

	for (int i = 0; i < n ; i++)
	{
		runsA[i]=0;
		ball_faced_A[i]=0;
		ball_bowled_A[i]=0;
		runs_given_A[i]=0;
		wicket_taken_A[i]=0;
		strike_rateA[i]=0;
		four_A[i]=0;
		six_A[i]=0;
		not_out_A[i]=0;
		runsB[i]=0;
		ball_faced_B[i]=0;
		ball_bowled_B[i]=0;
		runs_given_B[i]=0;
		wicket_taken_B[i]=0;
		strike_rateB[i]=0;
		four_B[i]=0;
		six_B[i]=0;
		not_out_B[i]=0;

	}

	//Reading and storing all the match data from the text file

	ifstream team_file;
	team_file.open("teamB_data.txt",ios::in);

	while (1) {
		for (int i = 0; i < n; i++)
		{
			team_file >>runsA[i]
				    >>ball_faced_A[i]
				    >>ball_bowled_A[i]
				    >>ball_bowled_A[i]
					>>runs_given_A[i]
					>>wicket_taken_A[i]
					>>strike_rateA[i]
					>>four_A[i]
					>>six_A[i]
					>>not_out_A[i]
					>>runsB[i]
				    >>ball_faced_B[i]
				    >>ball_bowled_B[i]
				    >>ball_bowled_B[i]
					>>runs_given_B[i]
					>>wicket_taken_B[i]
					>>strike_rateB[i]
					>>four_B[i]
					>>six_B[i]
					>>not_out_B[i];
		}
		team_file >>total_score_A
		>>total_balls
		>>total_over_A
		>>total_wicket_A
		>>run_rate_A
		>>total_score_B
		>>total_balls_B
		>>total_over_B
		>>total_wicket_B
		>>run_rate_B;

		break;
	
	}
	team_file.close();

	cout<<"\n\t\t\tMATCH SUMMARY\n\n";
	cout<<"\n**************************************************************************\n\t\t\t1st Innings\n";
	cout<<"\n**************************************************************************\n";
	
	cout<<"NAME\t\tRUNS\t\tBALLS\t\t4s\t\t6s\t\tSTRIKE RATE\n";
	for (int i = 0; i < n ; i++)
	{
		if(runsB[i]>=0 && ball_faced_B[i]>0)
		if(not_out_B[i]==1)
		cout<< b_player[i]<<"\t\t"<<runsB[i]<<"\t\t"<<ball_faced_B[i]<<"\t\t"<<four_B[i]<<"\t\t"<<six_B[i]<<"\t\t"<<strike_rateB[i]<<endl;
		
		else
		cout<< b_player[i]<<"*\t\t"<<runsB[i]<<"\t\t"<<ball_faced_B[i]<<"\t\t"<<four_B[i]<<"\t\t"<<six_B[i]<<"\t\t"<<strike_rateB[i]<<endl;
	}
	cout<<"*******************************************************\n";
	cout<<"NAME\t\tRUNS\t\tBALLS\t\tWICKETS\n";
	for (int i = 10; i > 5 ; i--)
	{
		cout<< a_player[i]<<"\t\t"<<runs_given_A[i]<<"\t\t"<<ball_bowled_A[i]<<"\t\t"<<wicket_taken_A[i]<<endl;
	}

		cout << "Total Runs: "<< total_score_B << "\t\tTotal Balls : "<< total_balls_B <<"\t\tOvers: "<<setprecision(2)<<total_over_B<<"\t\tWickets: "<<total_wicket_B<<"\t\tRun Rate: "<<setprecision(3)<<run_rate_B<< endl;
        cout<<"\n**************************************************************************\n\n";


		cout<<"\t\t\t2nd Innings\n**************************************************************************\n2nd Innings\n";

	cout<<"NAME\t\tRUNS\t\tBALLS\t\t4s\t\t6s\t\tSTRIKE RATE\n";

	for (int i = 0; i < n ; i++)
	{
		if(runsA[i]>=0 && ball_faced_A[i]>0)
		if(not_out_A[i]==1)
		cout<< a_player[i]<<"\t\t"<<runsA[i]<<"\t\t"<<ball_faced_A[i]<<"\t\t"<<four_A[i]<<"\t\t"<<six_A[i]<<"\t\t"<<strike_rateA[i]<<endl;
		
		else
		cout<< a_player[i]<<"*\t\t"<<runsA[i]<<"\t\t"<<ball_faced_A[i]<<"\t\t"<<four_A[i]<<"\t\t"<<six_A[i]<<"\t\t"<<strike_rateA[i]<<endl;
	}
	cout<<"*******************************************************\n";
	cout<<"NAME\t\tRUNS\t\tBALLS\t\tWICKETS\n";
	for (int i = 10; i >5 ; i--)
	{
		cout<< b_player[i]<<"\t\t"<<runs_given_B[i]<<"\t\t"<<ball_bowled_B[i]<<"\t\t"<<wicket_taken_B[i]<<endl;
	}
	

		cout << "Total Runs: "<< total_score_A << "\t\tTotal Balls : "<< total_balls <<"\t\tOvers: "<<setprecision(2)<< total_over_A <<"\t\tWickets: "<<total_wicket_A<<"\t\tRun Rate: "<<setprecision(3)<<run_rate_A<< endl;
        cout<<"\n\t\t**************************************************************************\n\n";
	


		int win_score = total_score_B - total_score_A;
		int win_wicket = 10-total_wicket_A;

		if (total_score_B > total_score_A)
		{
			cout<<"\t\tTeam B has won the match by "<< win_score<<" runs\n\n";
			cout<<"\n\n\t\t***********************************************************************\n\n";
		}
		if (total_score_A > total_score_B)
		{
			cout<<"\t\tTeam A has won the match by "<< win_wicket<<" wickets\n\n";
			cout<<"\n\n\t\t***********************************************************************\n\n";
		}
		if (total_score_A == total_score_B)
		{
			cout<<"\t\tMatch is drawn\n\n";
			cout<<"\n\n\t\t***********************************************************************\n\n";
		}


}

void display(string a_player[], string b_player[], int n){

	//Reading the player names from the file

	fstream player_name;
	player_name.open("teamA.txt");
	int i=0;
	while (i<11) {
	player_name >> a_player[i];
	
	i++;
	}

	player_name.close();

	fstream B_player_name;
	B_player_name.open("teamB.txt");
	int j=0;
	while (j<11) {
	B_player_name >> b_player[j];
	
	j++;
	}

	B_player_name.close();
/*
	for (int i = 0; i < 11; i++)
	{
		cout<<"Name of team A player "<<i+1<<" : ";
		cin>>a_player[i];
	}
	for (int i = 0; i < 11; i++)
	{
		cout<<"Name of team B player "<<i+1<<" : ";
		cin>>b_player[i];
	}
*/

	//Displaying the player Names
	cout<<"\t\t********************************************************************"<<endl;
	cout<<setw(30)<<"[Team A]"<<setw(60)<<"[Team B]"<<endl<<endl;


	for (int i = 0; i < 11; i++)
	{
		cout<<setw(30)<<a_player[i]<<setw(20)<<"||"<<setw(40)<<b_player[i]<<endl;
	}
	cout<<"\t\t********************************************************************"<<endl;

}

void teamA(string a_player[],string b_player[],int n){

	//Declaring all the variables for both teams A and B
	int check, ball_faced_A[n], ball_bowled_A[n], runs_given_A[n], wicket_taken_A[n],four_A[n],six_A[n],not_out_A[n];
    int total_score_A=0,score,total_score_B=0;
	int ball_faced_B[n], ball_bowled_B[n], runs_given_B[n], wicket_taken_B[n],four_B[n],six_B[n],not_out_B[n];
	float total_balls=0, total_balls_B=0;
	int total_wicket_A=0, total_wicket_B=0;
    float strike_rateB[n], strike_rateA[n], runsA[n], runsB[n], run_rate_A=0, run_rate_B=0;;

    srand(time(NULL));
	//Inilializing all the variables zero for both teams A and B
	for (int i = 0; i < n ; i++)
	{
		runsA[i]=0;
		ball_faced_A[i]=0;
		ball_bowled_A[i]=0;
		runs_given_A[i]=0;
		wicket_taken_A[i]=0;
		strike_rateA[i]=0;
		four_A[i]=0;
		six_A[i]=0;
		not_out_A[i]=0;
		runsB[i]=0;
		ball_faced_B[i]=0;
		ball_bowled_B[i]=0;
		runs_given_B[i]=0;
		wicket_taken_B[i]=0;
		strike_rateB[i]=0;
		four_B[i]=0;
		six_B[i]=0;
		not_out_B[i]=0;

	}
	
	//Reading number of over from .txt file
	int N;
	fstream my_file;
	my_file.open("over.txt");

	while (1) {
	my_file >> N;
	if (my_file.eof())
	{
		break;
	}
	
	}

	my_file.close();

	int temp=N*6;    //Total balls
	int over_limit=N/5;  //limit for bowler

	int press;  //To check wether the person wants to play bowl by bowl or skip to the end
	do
	{
		cout<<"\n\t\t========================================================\n\t\t\t\tMENU\n\n\t\t"
		<<"Press 1 to Play ball by ball\n\n\t\tPress 2 to Skip and Play\n\n\t\t";
		cin>> press ;
	} while (press < 1 || press > 2);
	
	
	cout<<endl;

	

		//Declaring temporary varibles and arrays for the loop
        int a[2]= {0,0};
        int b[2]= {0,0};
		int bow[5][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
        int player_name[2] = {0,1};
        bool player = true;
        int play=0;
		int bowler=10;
		int count_bowl=0;
		int bb = 0;
		int out_count = 0;
		int inc = 2;
		bool out = false;
		
		
		
		switch (press)
	{
	case 1:
	{
		//***************** MAIN LOOP **********************
		for (int i = 0; i < temp; i++)
        {
			//To check the probability of the players
            check=(rand()%100)+1;
            
            if(player == true)
                play = player_name[0];
            else
                play = player_name[1];
            
			if (count_bowl > 5)
			{
				count_bowl = 0;
				bb++;
			}
			if(bb > 4)
				bb = 0;
			if(play <= 6 )
			{
					if (check>=10)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			if(play > 6)
			{
					if (check>=50)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			total_balls = i+1;
			if (score==-1)
			{
				total_wicket_A++;
				cout << "****out****" << endl;
                if (player == true)
                {
                    cout << "player out \n"<< a_player[play] <<" \n score : "<<a[0]<< "\n ball faced : "<< a[1]++<<endl;
					//Storing the runs and balls of each player 
                    runsA[play]=a[0];  
                    ball_faced_A[play]=a[1];
					strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
					not_out_A[play]=1;
					
					
					cout << "\n\nplayer out : "<< a_player[play] <<" \n score : "<<runsA[play]<< "\n ball faced : "<< ball_faced_A[play]<<"\t\tfour: "<<four_A[play]<<"\t\tsix: "<<six_A[play]<<"\t\tRate:"<<strike_rateA[play]<<"\n\n"<<endl; 
                    
                    a[0] = 0;
                    a[1] = 0;
                    player_name[0] = inc;
					inc++;
                    
                }
                else
                {
                    cout << "player out : "<< a_player[play] <<" \n score : "<<b[0]<< "\n ball faced : "<< b[1]++<<endl; 
					//Storing the runs and balls of each player
                    runsA[play]=b[0];
                    ball_faced_A[play]=b[1];
					strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
					not_out_A[play]=1;
					
					cout << "\n\nplayer out : "<< a_player[play] <<" \n score : "<<runsA[play]<< "\n ball faced : "<< ball_faced_A[play]<<"\t\tfour: "<<four_A[play]<<"\t\tsix: "<<six_A[play]<<"\t\tRate:"<<strike_rateA[play]<<"\n\n"<<endl; 
                    
                    b[0] = 0;
                    b[1] = 0;
                    player_name[1] = inc;
					inc++;
                    
                }
				out_count++;
				bow[bb][2]++; 
				bow[bb][1]++;
		
				for (int i = 0; i < n ; i++)
				{
					if(runsA[i]>=0 && ball_faced_A[i]>0)
					cout<< a_player[i]<<"\t\t"<<runsA[i]<<"\t\t"<<ball_faced_A[i]<<endl;
				}
				
				cout << "Bowler bowling : "<< b_player[bowler-bb] <<" \n score : "<< bow[bb][0] << "  , balls:  "<< bow[bb][1]<< "    , wickets :  "<<bow[bb][2] <<endl;
				//Stroing the details of bowler
				runs_given_B[bowler-bb]=bow[bb][0];
				ball_bowled_B[bowler-bb]=bow[bb][1];
				wicket_taken_B[bowler-bb]=bow[bb][2];
				

			}
			count_bowl++;

			if(out != true)
			{
				total_score_A += score;
				
				
				if (player == true)
				{
						a[0] += score;
						a[1]++;
						runsA[play]+= score;
                    	ball_faced_A[play]=a[1];
						strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
						if (score==4)
						{
							four_A[play]++;
						}
						if (score==6)
						{
							six_A[play]++;
						}
						bow[bb][0]+=score;  
						bow[bb][1]++;      
				}
				else
				{
						b[0] += score;
						b[1]++;
						runsA[play]+= score;
                    	ball_faced_A[play]=b[1];
						strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
						if (score==4)
						{
							four_A[play]++;
						}
						if (score==6)
						{
							six_A[play]++;
						}
						bow[bb][0]+=score;
						bow[bb][1]++;
				}
				
				cout << "player playing : "<< a_player[play] <<" \n score : "<< score<<endl; 
				cout << "Bowler bowling : "<< b_player[bowler-bb] <<" \n score : "<< bow[bb][0] << "  , balls:  "<< bow[bb][1]<< "    , wickets :  "<<bow[bb][2] <<endl;
				runs_given_B[bowler-bb]=bow[bb][0];
				ball_bowled_B[bowler-bb]=bow[bb][1];
				wicket_taken_B[bowler-bb]=bow[bb][2];

				if (score%2!=0)
				{
					if(player ==true)
						player =false;
					else
						player = true;
				}
				cout << "total runs: "<< total_score_A<<"-"<<total_wicket_A << "\n total balls : "<< total_balls <<endl;
			}
			out = false;
			if (total_wicket_A>=10)
			{
			 	break;
			}
			
			 cin.get();
			 system("cls");
			

        }
		
	
		cout<<"******************END OF 1st INNINGS***********************\n";


		int c[2]= {0,0};
        int d[2]= {0,0};
		int bow_A[5][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
        int player_name_B[2] = {0,1};
        player = true;
        play=0;
		bowler=10;
		count_bowl=0;
		bb = 0;
		out_count = 0;
		inc = 2;
		out = false;
		
        for (int i = 0; i < temp; i++)
        {
            check=(rand()%100)+1;

            if(player == true)
                play = player_name_B[0];
            else
                play = player_name_B[1];
            
			if (count_bowl > 5)
			{
				count_bowl = 0;
				bb++;
			}
			if(bb > 4)
				bb = 0;
			if(play <= 6 )
			{
					if (check>=10)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			if(play > 6)
			{
					if (check>=50)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			total_balls_B = i+1;
			
			if (score==-1)
			{
				total_wicket_B++;
				cout << "****out****" << endl;
                if (player == true)
                {
                    cout << "player out \n"<< b_player[play] <<" \n score : "<<c[0]<< "\n ball faced : "<< c[1]++<<endl; 
                    runsB[play]=c[0];
                    ball_faced_B[play]=c[1];
					strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
					not_out_B[play]=1;
					
					cout << "\n\nplayer out : "<< b_player[play] <<" \n score : "<<runsB[play]<< "\n ball faced : "<< ball_faced_B[play]<<"\t\tfour: "<<four_B[play]<<"\t\tsix: "<<six_B[play]<<"\t\tRate:"<<strike_rateB[play]<<"\n\n"<<endl; 
                    
                    c[0] = 0;
                    c[1] = 0;
                    player_name_B[0] = inc;
					inc++;
                    
                }
                else
                {
                    cout << "player out : "<< b_player[play] <<" \n score : "<<d[0]<< "\n ball faced : "<< d[1]++<<endl; 
                    runsB[play]=d[0];
                    ball_faced_B[play]=d[1];
					strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
					not_out_B[play]=1;
					
					cout << "\n\nplayer out : "<< b_player[play] <<" \n score : "<<runsB[play]<< "\n ball faced : "<< ball_faced_B[play]<<"\t\tfour: "<<four_B[play]<<"\t\tsix: "<<six_B[play]<<"\t\tRate:"<<strike_rateB[play]<<"\n\n"<<endl; 
                
                    d[0] = 0;
                    d[1] = 0;
                    player_name_B[1] = inc;
					inc++;
                    
                }
				out_count++;
				bow_A[bb][2]++; 
				bow_A[bb][1]++;
		
				for (int i = 0; i < n ; i++)
				{
					if(runsB[i]>=0 && ball_faced_B[i]>0)
					cout<< b_player[i]<<"\t\t"<<runsB[i]<<"\t\t"<<ball_faced_B[i]<<endl;
				}
				
				cout << "Bowler bowling : "<< a_player[bowler-bb] <<" \n score : "<< bow_A[bb][0] << "  , balls:  "<< bow_A[bb][1]<< "    , wickets :  "<<bow_A[bb][2] <<endl;
				runs_given_A[bowler-bb]=bow_A[bb][0];
				ball_bowled_A[bowler-bb]=bow_A[bb][1];
				wicket_taken_A[bowler-bb]=bow_A[bb][2];
			
			}
			count_bowl++;

			if(out != true)
			{
				total_score_B += score;
				
				if (player == true)
				{
						c[0] += score;
						c[1]++;
						runsB[play]+= score;
                    	ball_faced_B[play]=c[1];
						strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
						if (score==4)
						{
							four_B[play]++;
						}
						if (score==6)
						{
							six_B[play]++;
						}
						bow_A[bb][0]+=score;  
						bow_A[bb][1]++;      
				}
				else
				{
						d[0] += score;
						d[1]++;
						runsB[play]+= score;
                    	ball_faced_B[play]=d[1];
						strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
						if (score==4)
						{
							four_B[play]++;
						}
						if (score==6)
						{
							six_B[play]++;
						}
						bow_A[bb][0]+=score;
						bow_A[bb][1]++;
				}
				
				cout << "player playing : "<< b_player[play] <<" \n score : "<< score<<endl; 
				cout << "Bowler bowling : "<< a_player[bowler-bb] <<" \n score : "<< bow_A[bb][0] << "  , balls:  "<< bow_A[bb][1]<< "    , wickets :  "<<bow_A[bb][2] <<endl;
				runs_given_A[bowler-bb]=bow_A[bb][0];
				ball_bowled_A[bowler-bb]=bow_A[bb][1];
				wicket_taken_A[bowler-bb]=bow_A[bb][2];
				
				if (score%2!=0)
				{
					if(player ==true)
						player =false;
					else
						player = true;
				}
				cout << "total runs: "<< total_score_B<<"-"<<total_wicket_B << "\n total balls : "<< total_balls_B << endl;
			}
			out = false;
		if (total_score_B > total_score_A)
		{
			break;
		}
		
		if (total_wicket_B>=10)
		{
			break;
		}

		cin.get();
		system("cls");

        }

	
		break;
	}
	case 2:
	{
		for (int i = 0; i < temp; i++)
        {
            check=(rand()%100)+1;
            
            if(player == true)
                play = player_name[0];
            else
                play = player_name[1];
            
			if (count_bowl > 5)
			{
				count_bowl = 0;
				bb++;
			}
			if(bb > 4)
				bb = 0;
			if(play <= 6 )
			{
					if (check>=10)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			if(play > 6)
			{
					if (check>=50)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			total_balls = i+1;
			if (score==-1)
			{
				total_wicket_A++;
				cout << "****out****" << endl;
                if (player == true)
                {
                    cout << "player out \n"<< a_player[play] <<" \n score : "<<a[0]<< "\n ball faced : "<< a[1]++<<endl; 
                    runsA[play]=a[0];
                    ball_faced_A[play]=a[1];
					strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
					not_out_A[play]=1;
					
					cout << "\n\nplayer out : "<< a_player[play] <<" \n score : "<<runsA[play]<< "\n ball faced : "<< ball_faced_A[play]<<"\t\tfour: "<<four_A[play]<<"\t\tsix: "<<six_A[play]<<"\t\tRate:"<<strike_rateA[play]<<"\n\n"<<endl; 
                    
                    a[0] = 0;
                    a[1] = 0;
                    player_name[0] = inc;
					inc++;
                    
                }
                else
                {
                    cout << "player out : "<< a_player[play] <<" \n score : "<<b[0]<< "\n ball faced : "<< b[1]++<<endl; 
                    runsA[play]=b[0];
                    ball_faced_A[play]=b[1];
					strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
					not_out_A[play]=1;
					
					cout << "\n\nplayer out : "<< a_player[play] <<" \n score : "<<runsA[play]<< "\n ball faced : "<< ball_faced_A[play]<<"\t\tfour: "<<four_A[play]<<"\t\tsix: "<<six_A[play]<<"\t\tRate:"<<strike_rateA[play]<<"\n\n"<<endl; 
                    
                    b[0] = 0;
                    b[1] = 0;
                    player_name[1] = inc;
					inc++;
                    
                }
				out_count++;
				bow[bb][2]++; 
				bow[bb][1]++;
		
				for (int i = 0; i < n ; i++)
				{
					if(runsA[i]>=0 && ball_faced_A[i]>0)
					cout<< a_player[i]<<"\t\t"<<runsA[i]<<"\t\t"<<ball_faced_A[i]<<endl;
				}
				
				cout << "Bowler bowling : "<< b_player[bowler-bb] <<" \n score : "<< bow[bb][0] << "  , balls:  "<< bow[bb][1]<< "    , wickets :  "<<bow[bb][2] <<endl;
				runs_given_B[bowler-bb]=bow[bb][0];
				ball_bowled_B[bowler-bb]=bow[bb][1];
				wicket_taken_B[bowler-bb]=bow[bb][2];
				

			}
			count_bowl++;

			if(out != true)
			{
				total_score_A += score;
				
				
				if (player == true)
				{
						a[0] += score;
						a[1]++;
						runsA[play]+= score;
                    	ball_faced_A[play]=a[1];
						strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
						if (score==4)
						{
							four_A[play]++;
						}
						if (score==6)
						{
							six_A[play]++;
						}
						bow[bb][0]+=score;  
						bow[bb][1]++;      
				}
				else
				{
						b[0] += score;
						b[1]++;
						runsA[play]+= score;
                    	ball_faced_A[play]=b[1];
						strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
						if (score==4)
						{
							four_A[play]++;
						}
						if (score==6)
						{
							six_A[play]++;
						}
						bow[bb][0]+=score;
						bow[bb][1]++;
				}
				
				cout << "player playing : "<< a_player[play] <<" \n score : "<< score<<endl; 
				cout << "Bowler bowling : "<< b_player[bowler-bb] <<" \n score : "<< bow[bb][0] << "  , balls:  "<< bow[bb][1]<< "    , wickets :  "<<bow[bb][2] <<endl;
				runs_given_B[bowler-bb]=bow[bb][0];
				ball_bowled_B[bowler-bb]=bow[bb][1];
				wicket_taken_B[bowler-bb]=bow[bb][2];

				if (score%2!=0)
				{
					if(player ==true)
						player =false;
					else
						player = true;
				}
				cout << "total runs: "<< total_score_A << "-"<<total_wicket_A <<"\n total balls : "<< total_balls << endl;
			}
			out = false;
			if (total_wicket_A>=10)
			{
			 	break;
			}
			
			//  cin.get();
			//  system("cls");
			

        }
		
		cout<<"\n\n******************END OF 1st INNINGS***********************\n\n";
	
		


		int c[2]= {0,0};
        int d[2]= {0,0};
		int bow_A[5][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
        int player_name_B[2] = {0,1};
        player = true;
        play=0;
		bowler=10;
		count_bowl=0;
		bb = 0;
		out_count = 0;
		inc = 2;
		out = false;
		
        for (int i = 0; i < temp; i++)
        {
            check=(rand()%100)+1;

            if(player == true)
                play = player_name_B[0];
            else
                play = player_name_B[1];
            
			if (count_bowl > 5)
			{
				count_bowl = 0;
				bb++;
			}
			if(bb > 4)
				bb = 0;
			if(play <= 6 )
			{
					if (check>=10)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			if(play > 6)
			{
					if (check>=50)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			total_balls_B = i+1;
			
			if (score==-1)
			{
				total_wicket_B++;
				cout << "****out****" << endl;
                if (player == true)
                {
                    cout << "player out \n"<< b_player[play] <<" \n score : "<<c[0]<< "\n ball faced : "<< c[1]++<<endl; 
                    runsB[play]=c[0];
                    ball_faced_B[play]=c[1];
					strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
					not_out_B[play]=1;
					
					cout << "\n\nplayer out : "<< b_player[play] <<" \n score : "<<runsB[play]<< "\n ball faced : "<< ball_faced_B[play]<<"\t\tfour: "<<four_B[play]<<"\t\tsix: "<<six_B[play]<<"\t\tRate:"<<strike_rateB[play]<<"\n\n"<<endl; 
                    
                    c[0] = 0;
                    c[1] = 0;
                    player_name_B[0] = inc;
					inc++;
                    
                }
                else
                {
                    cout << "player out : "<< b_player[play] <<" \n score : "<<d[0]<< "\n ball faced : "<< d[1]++<<endl; 
                    runsB[play]=d[0];
                    ball_faced_B[play]=d[1];
					strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
					not_out_B[play]=1;

					cout << "\n\nplayer out : "<< b_player[play] <<" \n score : "<<runsB[play]<< "\n ball faced : "<< ball_faced_B[play]<<"\t\tfour: "<<four_B[play]<<"\t\tsix: "<<six_B[play]<<"\t\tRate:"<<strike_rateB[play]<<"\n\n"<<endl; 
                
                    d[0] = 0;
                    d[1] = 0;
                    player_name_B[1] = inc;
					inc++;
                    
                }
				out_count++;
				bow_A[bb][2]++; 
				bow_A[bb][1]++;
		
				for (int i = 0; i < n ; i++)
				{
					if(runsB[i]>=0 && ball_faced_B[i]>0)
					cout<< b_player[i]<<"\t\t"<<runsB[i]<<"\t\t"<<ball_faced_B[i]<<endl;
				}
				
				cout << "Bowler bowling : "<< a_player[bowler-bb] <<" \n score : "<< bow_A[bb][0] << "  , balls:  "<< bow_A[bb][1]<< "    , wickets :  "<<bow_A[bb][2] <<endl;
				runs_given_A[bowler-bb]=bow_A[bb][0];
				ball_bowled_A[bowler-bb]=bow_A[bb][1];
				wicket_taken_A[bowler-bb]=bow_A[bb][2];
			
			}
			count_bowl++;

			if(out != true)
			{
				total_score_B += score;
				
				if (player == true)
				{
						c[0] += score;
						c[1]++;
						runsB[play]+= score;
                    	ball_faced_B[play]=c[1];
						strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
						if (score==4)
						{
							four_B[play]++;
						}
						if (score==6)
						{
							six_B[play]++;
						}
						bow_A[bb][0]+=score;  
						bow_A[bb][1]++;      
				}
				else
				{
						d[0] += score;
						d[1]++;
						runsB[play]+= score;
                    	ball_faced_B[play]=d[1];
						strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
						if (score==4)
						{
							four_B[play]++;
						}
						if (score==6)
						{
							six_B[play]++;
						}
						bow_A[bb][0]+=score;
						bow_A[bb][1]++;
				}
				
				cout << "player playing : "<< b_player[play] <<" \n score : "<< score<<endl; 
				cout << "Bowler bowling : "<< a_player[bowler-bb] <<" \n score : "<< bow_A[bb][0] << "  , balls:  "<< bow_A[bb][1]<< "    , wickets :  "<<bow_A[bb][2] <<endl;
				runs_given_A[bowler-bb]=bow_A[bb][0];
				ball_bowled_A[bowler-bb]=bow_A[bb][1];
				wicket_taken_A[bowler-bb]=bow_A[bb][2];
				
				if (score%2!=0)
				{
					if(player ==true)
						player =false;
					else
						player = true;
				}
				cout << "total runs: "<< total_score_B <<"-"<<total_wicket_B << "\n total balls : "<< total_balls_B << endl;
			}
			out = false;
		if (total_score_B > total_score_A)
		{
			break;
		}
		
		if (total_wicket_B>=10)
		{
			break;
		}

		// cin.get();
		// system("cls");

        }

		break;
	}
	}

	float total_over_A= total_balls/6;
		

	run_rate_A = total_score_A / total_over_A;
		
	

	float total_over_B= total_balls_B/6;
	
	run_rate_B = total_score_B / total_over_B;

	//Storing the match data in the file
	
	ofstream outfile_A("TeamA_data.txt");
	for (int i = 0; i < n; i++)
	{
		outfile_A << runsA[i]<<endl
				    <<ball_faced_A[i]<<endl
				    <<ball_bowled_A[i]<<endl
				    <<ball_bowled_A[i]<<endl
					<<runs_given_A[i]<<endl
					<<wicket_taken_A[i]<<endl
					<<strike_rateA[i]<<endl
					<<four_A[i]<<endl
					<<six_A[i]<<endl
					<<not_out_A[i]<<endl
					<<runsB[i]<<endl
				    <<ball_faced_B[i]<<endl
				    <<ball_bowled_B[i]<<endl
				    <<ball_bowled_B[i]<<endl
					<<runs_given_B[i]<<endl
					<<wicket_taken_B[i]<<endl
					<<strike_rateB[i]<<endl
					<<four_B[i]<<endl
					<<six_B[i]<<endl
					<<not_out_B[i]<<endl;
	}
		outfile_A <<total_score_A<<endl
		<<total_balls<<endl
		<<total_over_A<<endl
		<<total_wicket_A<<endl
		<<run_rate_A<<endl
		<<total_score_B<<endl
		<<total_balls_B<<endl
		<<total_over_B<<endl
		<<total_wicket_B<<endl
		<<run_rate_B<<endl;

	cout<<"File written\n";
	
}


//_____________________________________________________________________________________________________________________

//if team B wins the toss

void teamB(string b_player[],string a_player[],int n){
	int check, ball_faced_A[n], ball_bowled_A[n], runs_given_A[n], wicket_taken_A[n],four_A[n],six_A[n],not_out_A[n];
    int total_score_A=0,score,total_score_B=0;
	int ball_faced_B[n], ball_bowled_B[n], runs_given_B[n], wicket_taken_B[n],four_B[n],six_B[n],not_out_B[n];
	float total_balls=0, total_balls_B=0;
	int total_wicket_A=0, total_wicket_B=0;
    float strike_rateB[n], strike_rateA[n], runsA[n], runsB[n], run_rate_A=0, run_rate_B=0;;
    srand(time(NULL));

	for (int i = 0; i < n ; i++)
	{
		runsA[i]=0;
		ball_faced_A[i]=0;
		ball_bowled_A[i]=0;
		runs_given_A[i]=0;
		wicket_taken_A[i]=0;
		strike_rateA[i]=0;
		four_A[i]=0;
		six_A[i]=0;
		not_out_A[i]=0;
		runsB[i]=0;
		ball_faced_B[i]=0;
		ball_bowled_B[i]=0;
		runs_given_B[i]=0;
		wicket_taken_B[i]=0;
		strike_rateB[i]=0;
		four_B[i]=0;
		six_B[i]=0;
		not_out_B[i]=0;

	}

	int N;
	fstream my_file;
	my_file.open("over.txt",ios::in);

	while (1) {
	my_file >> N;
	if (my_file.eof())
	{
		break;
	}
	
	}

	my_file.close();

	int temp=N*6;
	int over_limit=N/5;


	int press;
	do
	{
		cout<<"\n\t\t========================================================\n\t\t\t\tMENU\n\n\t\t"
		<<"Press 1 to Play ball by ball\n\n\t\tPress 2 to Skip and Play\n\n\t\t";
		cin>> press ;
	} while (press < 1 || press > 2);
	
	
	cout<<endl;

	switch (press)
	{
	case 1:
		{

			int c[2]= {0,0};
			int d[2]= {0,0};
			int bow_A[5][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
			int player_name_B[2] = {0,1};
			int player = true;
			int play=0;
			int bowler=10;
			int count_bowl=0;
			int bb = 0;
			int out_count = 0;
			int inc = 2;
			int out = false;
		//***************** MAIN LOOP **********************
        for (int i = 0; i < temp; i++)
        {
            check=(rand()%100)+1;

            if(player == true)
                play = player_name_B[0];
            else
                play = player_name_B[1];
            
			if (count_bowl > 5)
			{
				count_bowl = 0;
				bb++;
			}
			if(bb > 4)
				bb = 0;
			if(play <= 6 )
			{
					if (check>=10)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			if(play > 6)
			{
					if (check>=50)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			total_balls_B = i+1;
			
			if (score==-1)
			{
				total_wicket_B++;
				cout << "****out****" << endl;
                if (player == true)
                {
                    cout << "player out \n"<< b_player[play] <<" \n score : "<<c[0]<< "\n ball faced : "<< c[1]++<<endl; 
                    runsB[play]=c[0];
                    ball_faced_B[play]=c[1];
					strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
					not_out_B[play]=1;
					
					cout << "\n\nplayer out : "<< b_player[play] <<" \n score : "<<runsB[play]<< "\n ball faced : "<< ball_faced_B[play]<<"\t\tfour: "<<four_B[play]<<"\t\tsix: "<<six_B[play]<<"\t\tRate:"<<strike_rateB[play]<<"\n\n"<<endl; 
                    
                    c[0] = 0;
                    c[1] = 0;
                    player_name_B[0] = inc;
					inc++;
                    
                }
                else
                {
                    cout << "player out : "<< b_player[play] <<" \n score : "<<d[0]<< "\n ball faced : "<< d[1]++<<endl; 
                    runsB[play]=d[0];
                    ball_faced_B[play]=d[1];
					strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
					not_out_B[play]=1;
					
					cout << "\n\nplayer out : "<< b_player[play] <<" \n score : "<<runsB[play]<< "\n ball faced : "<< ball_faced_B[play]<<"\t\tfour: "<<four_B[play]<<"\t\tsix: "<<six_B[play]<<"\t\tRate:"<<strike_rateB[play]<<"\n\n"<<endl; 
                
                    d[0] = 0;
                    d[1] = 0;
                    player_name_B[1] = inc;
					inc++;
                    
                }
				out_count++;
				bow_A[bb][2]++; 
				bow_A[bb][1]++;
		
				for (int i = 0; i < n ; i++)
				{
					if(runsB[i]>=0 && ball_faced_B[i]>0)
					cout<< b_player[i]<<"\t\t"<<runsB[i]<<"\t\t"<<ball_faced_B[i]<<endl;
				}
				
				cout << "Bowler bowling : "<< a_player[bowler-bb] <<" \n score : "<< bow_A[bb][0] << "  , balls:  "<< bow_A[bb][1]<< "    , wickets :  "<<bow_A[bb][2] <<endl;
				runs_given_A[bowler-bb]=bow_A[bb][0];
				ball_bowled_A[bowler-bb]=bow_A[bb][1];
				wicket_taken_A[bowler-bb]=bow_A[bb][2];
			
			}
			count_bowl++;

			if(out != true)
			{
				total_score_B += score;
				
				if (player == true)
				{
						c[0] += score;
						c[1]++;
						runsB[play]+= score;
                    	ball_faced_B[play]=c[1];
						strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
						if (score==4)
						{
							four_B[play]++;
						}
						if (score==6)
						{
							six_B[play]++;
						}
						bow_A[bb][0]+=score;  
						bow_A[bb][1]++;      
				}
				else
				{
						d[0] += score;
						d[1]++;
						runsB[play]+= score;
                    	ball_faced_B[play]=d[1];
						strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
						if (score==4)
						{
							four_B[play]++;
						}
						if (score==6)
						{
							six_B[play]++;
						}
						bow_A[bb][0]+=score;
						bow_A[bb][1]++;
				}
				
				cout << "player playing : "<< b_player[play] <<" \n score : "<< score<<endl; 
				cout << "Bowler bowling : "<< a_player[bowler-bb] <<" \n score : "<< bow_A[bb][0] << "  , balls:  "<< bow_A[bb][1]<< "    , wickets :  "<<bow_A[bb][2] <<endl;
				runs_given_A[bowler-bb]=bow_A[bb][0];
				ball_bowled_A[bowler-bb]=bow_A[bb][1];
				wicket_taken_A[bowler-bb]=bow_A[bb][2];
				
				if (score%2!=0)
				{
					if(player ==true)
						player =false;
					else
						player = true;
				}
				cout << "total runs: "<< total_score_B <<"-"<<total_wicket_B << "\n total balls : "<< total_balls_B << endl;
			}
			out = false;
		if (total_wicket_B>=10)
		{
			break;
		}

		cin.get();
		system("cls");

        }


		cout<<"\n\n******************END OF 1st INNINGS***********************\n\n";


		int a[2]= {0,0};
		int b[2]= {0,0};
		int bow[5][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
		int player_name[2] = {0,1};
		player = true;
		play=0;
		bowler=10;
		count_bowl=0;
		bb = 0;
		out_count = 0;
		inc = 2;
		out = false;
			
		//***************** MAIN LOOP **********************
        for (int i = 0; i < temp; i++)
        {
            check=(rand()%100)+1;
            
            if(player == true)
                play = player_name[0];
            else
                play = player_name[1];
            
			if (count_bowl > 5)
			{
				count_bowl = 0;
				bb++;
			}
			if(bb > 4)
				bb = 0;
			if(play <= 6 )
			{
					if (check>=10)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			if(play > 6)
			{
					if (check>=50)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			total_balls = i+1;
			if (score==-1)
			{
				total_wicket_A++;
				cout << "****out****" << endl;
                if (player == true)
                {
                    cout << "player out \n"<< a_player[play] <<" \n score : "<<a[0]<< "\n ball faced : "<< a[1]++<<endl; 
                    runsA[play]=a[0];
                    ball_faced_A[play]=a[1];
					strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
					not_out_A[play]=1;
					
					cout << "\n\nplayer out : "<< a_player[play] <<" \n score : "<<runsA[play]<< "\n ball faced : "<< ball_faced_A[play]<<"\t\tfour: "<<four_A[play]<<"\t\tsix: "<<six_A[play]<<"\t\tRate:"<<strike_rateA[play]<<"\n\n"<<endl; 
                    
                    a[0] = 0;
                    a[1] = 0;
                    player_name[0] = inc;
					inc++;
                    
                }
                else
                {
                    cout << "player out : "<< a_player[play] <<" \n score : "<<b[0]<< "\n ball faced : "<< b[1]++<<endl; 
                    runsA[play]=b[0];
                    ball_faced_A[play]=b[1];
					strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
					not_out_A[play]=1;
					
					cout << "\n\nplayer out : "<< a_player[play] <<" \n score : "<<runsA[play]<< "\n ball faced : "<< ball_faced_A[play]<<"\t\tfour: "<<four_A[play]<<"\t\tsix: "<<six_A[play]<<"\t\tRate:"<<strike_rateA[play]<<"\n\n"<<endl; 
                    
                    b[0] = 0;
                    b[1] = 0;
                    player_name[1] = inc;
					inc++;
                    
                }
				out_count++;
				bow[bb][2]++; 
				bow[bb][1]++;
		
				for (int i = 0; i < n ; i++)
				{
					if(runsA[i]>=0 && ball_faced_A[i]>0)
					cout<< a_player[i]<<"\t\t"<<runsA[i]<<"\t\t"<<ball_faced_A[i]<<endl;
				}
				
				cout << "Bowler bowling : "<< b_player[bowler-bb] <<" \n score : "<< bow[bb][0] << "  , balls:  "<< bow[bb][1]<< "    , wickets :  "<<bow[bb][2] <<endl;
				runs_given_B[bowler-bb]=bow[bb][0];
				ball_bowled_B[bowler-bb]=bow[bb][1];
				wicket_taken_B[bowler-bb]=bow[bb][2];
				

			}
			count_bowl++;

			if(out != true)
			{
				total_score_A += score;
				
				
				if (player == true)
				{
						a[0] += score;
						a[1]++;
						runsA[play]+= score;
                    	ball_faced_A[play]=a[1];
						strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
						if (score==4)
						{
							four_A[play]++;
						}
						if (score==6)
						{
							six_A[play]++;
						}
						bow[bb][0]+=score;  
						bow[bb][1]++;      
				}
				else
				{
						b[0] += score;
						b[1]++;
						runsA[play]+= score;
                    	ball_faced_A[play]=b[1];
						strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
						if (score==4)
						{
							four_A[play]++;
						}
						if (score==6)
						{
							six_A[play]++;
						}
						bow[bb][0]+=score;
						bow[bb][1]++;
				}
				
				cout << "player playing : "<< a_player[play] <<" \n score : "<< score<<endl; 
				cout << "Bowler bowling : "<< b_player[bowler-bb] <<" \n score : "<< bow[bb][0] << "  , balls:  "<< bow[bb][1]<< "    , wickets :  "<<bow[bb][2] <<endl;
				runs_given_B[bowler-bb]=bow[bb][0];
				ball_bowled_B[bowler-bb]=bow[bb][1];
				wicket_taken_B[bowler-bb]=bow[bb][2];

				if (score%2!=0)
				{
					if(player ==true)
						player =false;
					else
						player = true;
				}
				cout << "total runs: "<< total_score_A <<"-"<<total_wicket_A << "\n total balls : "<< total_balls << endl;
			}
			out = false;
			if (total_wicket_A>=10)
			{
			 	break;
			}
			if (total_score_A > total_score_B)
			{
				break;
			}
			
			cin.get();
			system("cls");

        }

			break;
	}
	
	case 2:
	{
		int c[2]= {0,0};
			int d[2]= {0,0};
			int bow_A[5][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
			int player_name_B[2] = {0,1};
			int player = true;
			int play=0;
			int bowler=10;
			int count_bowl=0;
			int bb = 0;
			int out_count = 0;
			int inc = 2;
			int out = false;
		
        for (int i = 0; i < temp; i++)
        {
            check=(rand()%100)+1;

            if(player == true)
                play = player_name_B[0];
            else
                play = player_name_B[1];
            
			if (count_bowl > 5)
			{
				count_bowl = 0;
				bb++;
			}
			if(bb > 4)
				bb = 0;
			if(play <= 6 )
			{
					if (check>=10)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			if(play > 6)
			{
					if (check>=50)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			total_balls_B = i+1;
			
			if (score==-1)
			{
				total_wicket_B++;
				cout << "****out****" << endl;
                if (player == true)
                {
                    cout << "player out \n"<< b_player[play] <<" \n score : "<<c[0]<< "\n ball faced : "<< c[1]++<<endl; 
                    runsB[play]=c[0];
                    ball_faced_B[play]=c[1];
					strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
					not_out_B[play]=1;
					
					cout << "\n\nplayer out : "<< b_player[play] <<" \n score : "<<runsB[play]<< "\n ball faced : "<< ball_faced_B[play]<<"\t\tfour: "<<four_B[play]<<"\t\tsix: "<<six_B[play]<<"\t\tRate:"<<strike_rateB[play]<<"\n\n"<<endl; 
                    
                    c[0] = 0;
                    c[1] = 0;
                    player_name_B[0] = inc;
					inc++;
                    
                }
                else
                {
                    cout << "player out : "<< b_player[play] <<" \n score : "<<d[0]<< "\n ball faced : "<< d[1]++<<endl; 
                    runsB[play]=d[0];
                    ball_faced_B[play]=d[1];
					strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
					not_out_B[play]=1;
					
					cout << "\n\nplayer out : "<< b_player[play] <<" \n score : "<<runsB[play]<< "\n ball faced : "<< ball_faced_B[play]<<"\t\tfour: "<<four_B[play]<<"\t\tsix: "<<six_B[play]<<"\t\tRate:"<<strike_rateB[play]<<"\n\n"<<endl; 
                
                    d[0] = 0;
                    d[1] = 0;
                    player_name_B[1] = inc;
					inc++;
                    
                }
				out_count++;
				bow_A[bb][2]++; 
				bow_A[bb][1]++;
		
				for (int i = 0; i < n ; i++)
				{
					if(runsB[i]>=0 && ball_faced_B[i]>0)
					cout<< b_player[i]<<"\t\t"<<runsB[i]<<"\t\t"<<ball_faced_B[i]<<endl;
				}
				
				cout << "Bowler bowling : "<< a_player[bowler-bb] <<" \n score : "<< bow_A[bb][0] << "  , balls:  "<< bow_A[bb][1]<< "    , wickets :  "<<bow_A[bb][2] <<endl;
				runs_given_A[bowler-bb]=bow_A[bb][0];
				ball_bowled_A[bowler-bb]=bow_A[bb][1];
				wicket_taken_A[bowler-bb]=bow_A[bb][2];
			
			}
			count_bowl++;

			if(out != true)
			{
				total_score_B += score;
				
				if (player == true)
				{
						c[0] += score;
						c[1]++;
						runsB[play]+= score;
                    	ball_faced_B[play]=c[1];
						strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
						if (score==4)
						{
							four_B[play]++;
						}
						if (score==6)
						{
							six_B[play]++;
						}
						bow_A[bb][0]+=score;  
						bow_A[bb][1]++;      
				}
				else
				{
						d[0] += score;
						d[1]++;
						runsB[play]+= score;
                    	ball_faced_B[play]=d[1];
						strike_rateB[play]=(runsB[play]/ball_faced_B[play])*100;
						if (score==4)
						{
							four_B[play]++;
						}
						if (score==6)
						{
							six_B[play]++;
						}
						bow_A[bb][0]+=score;
						bow_A[bb][1]++;
				}
				
				cout << "player playing : "<< b_player[play] <<" \n score : "<< score<<endl; 
				cout << "Bowler bowling : "<< a_player[bowler-bb] <<" \n score : "<< bow_A[bb][0] << "  , balls:  "<< bow_A[bb][1]<< "    , wickets :  "<<bow_A[bb][2] <<endl;
				runs_given_A[bowler-bb]=bow_A[bb][0];
				ball_bowled_A[bowler-bb]=bow_A[bb][1];
				wicket_taken_A[bowler-bb]=bow_A[bb][2];
				
				if (score%2!=0)
				{
					if(player ==true)
						player =false;
					else
						player = true;
				}
				cout << "total runs: "<< total_score_B <<"-"<<total_wicket_B << "\n total balls : "<< total_balls_B << endl;
			}
			out = false;
		if (total_wicket_B>=10)
		{
			break;
		}

		// cin.get();
		// system("cls");

        }


		cout<<"\n\n******************END OF 1st INNINGS***********************\n\n";


		int a[2]= {0,0};
		int b[2]= {0,0};
		int bow[5][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
		int player_name[2] = {0,1};
		player = true;
		play=0;
		bowler=10;
		count_bowl=0;
		bb = 0;
		out_count = 0;
		inc = 2;
		out = false;
			
		//***************** MAIN LOOP **********************
        for (int i = 0; i < temp; i++)
        {
            check=(rand()%100)+1;
            
            if(player == true)
                play = player_name[0];
            else
                play = player_name[1];
            
			if (count_bowl > 5)
			{
				count_bowl = 0;
				bb++;
			}
			if(bb > 4)
				bb = 0;
			if(play <= 6 )
			{
					if (check>=10)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			if(play > 6)
			{
					if (check>=50)
					{
						score=(rand()%7);
					}
					else
					{
						score=-1;
						out = true;
					}
			}
			total_balls = i+1;
			if (score==-1)
			{
				total_wicket_A++;
				cout << "****out****" << endl;
                if (player == true)
                {
                    cout << "player out \n"<< a_player[play] <<" \n score : "<<a[0]<< "\n ball faced : "<< a[1]++<<endl; 
                    runsA[play]=a[0];
                    ball_faced_A[play]=a[1];
					strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
					not_out_A[play]=1;
					
					cout << "\n\nplayer out : "<< a_player[play] <<" \n score : "<<runsA[play]<< "\n ball faced : "<< ball_faced_A[play]<<"\t\tfour: "<<four_A[play]<<"\t\tsix: "<<six_A[play]<<"\t\tRate:"<<strike_rateA[play]<<"\n\n"<<endl; 
                    
                    a[0] = 0;
                    a[1] = 0;
                    player_name[0] = inc;
					inc++;
                    
                }
                else
                {
                    cout << "player out : "<< a_player[play] <<" \n score : "<<b[0]<< "\n ball faced : "<< b[1]++<<endl; 
                    runsA[play]=b[0];
                    ball_faced_A[play]=b[1];
					strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
					not_out_A[play]=1;
					
					cout << "\n\nplayer out : "<< a_player[play] <<" \n score : "<<runsA[play]<< "\n ball faced : "<< ball_faced_A[play]<<"\t\tfour: "<<four_A[play]<<"\t\tsix: "<<six_A[play]<<"\t\tRate:"<<strike_rateA[play]<<"\n\n"<<endl; 
                    
                    b[0] = 0;
                    b[1] = 0;
                    player_name[1] = inc;
					inc++;
                    
                }
				out_count++;
				bow[bb][2]++; 
				bow[bb][1]++;
		
				for (int i = 0; i < n ; i++)
				{
					if(runsA[i]>=0 && ball_faced_A[i]>0)
					cout<< a_player[i]<<"\t\t"<<runsA[i]<<"\t\t"<<ball_faced_A[i]<<endl;
				}
				
				cout << "Bowler bowling : "<< b_player[bowler-bb] <<" \n score : "<< bow[bb][0] << "  , balls:  "<< bow[bb][1]<< "    , wickets :  "<<bow[bb][2] <<endl;
				runs_given_B[bowler-bb]=bow[bb][0];
				ball_bowled_B[bowler-bb]=bow[bb][1];
				wicket_taken_B[bowler-bb]=bow[bb][2];
				

			}
			count_bowl++;

			if(out != true)
			{
				total_score_A += score;
				
				
				if (player == true)
				{
						a[0] += score;
						a[1]++;
						runsA[play]+= score;
                    	ball_faced_A[play]=a[1];
						strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
						if (score==4)
						{
							four_A[play]++;
						}
						if (score==6)
						{
							six_A[play]++;
						}
						bow[bb][0]+=score;  
						bow[bb][1]++;      
				}
				else
				{
						b[0] += score;
						b[1]++;
						runsA[play]+= score;
                    	ball_faced_A[play]=b[1];
						strike_rateA[play]=(runsA[play]/ball_faced_A[play])*100;
						if (score==4)
						{
							four_A[play]++;
						}
						if (score==6)
						{
							six_A[play]++;
						}
						bow[bb][0]+=score;
						bow[bb][1]++;
				}
				
				cout << "player playing : "<< a_player[play] <<" \n score : "<< score<<endl; 
				cout << "Bowler bowling : "<< b_player[bowler-bb] <<" \n score : "<< bow[bb][0] << "  , balls:  "<< bow[bb][1]<< "    , wickets :  "<<bow[bb][2] <<endl;
				runs_given_B[bowler-bb]=bow[bb][0];
				ball_bowled_B[bowler-bb]=bow[bb][1];
				wicket_taken_B[bowler-bb]=bow[bb][2];

				if (score%2!=0)
				{
					if(player ==true)
						player =false;
					else
						player = true;
				}
				cout << "total runs: "<< total_score_A <<"-"<<total_wicket_A << "\n total balls : "<< total_balls << endl;
			}
			out = false;
			if (total_wicket_A>=10)
			{
			 	break;
			}
			if (total_score_A > total_score_B)
			{
				break;
			}
			
			// cin.get();
			// system("cls");

        }
		break;
	}
	}


	

	float total_over_B= total_balls_B/6;
	
	run_rate_B = total_score_B / total_over_B;

	 

	float total_over_A= total_balls/6;
		

	run_rate_A = total_score_A / total_over_A;
		
	

	ofstream outfile_A("TeamB_data.txt");
	for (int i = 0; i < n; i++)
	{
		outfile_A << runsA[i]<<endl
				    <<ball_faced_A[i]<<endl
				    <<ball_bowled_A[i]<<endl
				    <<ball_bowled_A[i]<<endl
					<<runs_given_A[i]<<endl
					<<wicket_taken_A[i]<<endl
					<<strike_rateA[i]<<endl
					<<four_A[i]<<endl
					<<six_A[i]<<endl
					<<not_out_A[i]<<endl
					<<runsB[i]<<endl
				    <<ball_faced_B[i]<<endl
				    <<ball_bowled_B[i]<<endl
				    <<ball_bowled_B[i]<<endl
					<<runs_given_B[i]<<endl
					<<wicket_taken_B[i]<<endl
					<<strike_rateB[i]<<endl
					<<four_B[i]<<endl
					<<six_B[i]<<endl
					<<not_out_B[i]<<endl;
	}
		outfile_A <<total_score_A<<endl
		<<total_balls<<endl
		<<total_over_A<<endl
		<<total_wicket_A<<endl
		<<run_rate_A<<endl
		<<total_score_B<<endl
		<<total_balls_B<<endl
		<<total_over_B<<endl
		<<total_wicket_B<<endl
		<<run_rate_B<<endl;

	//cout<<"File written\n";
	
}


	

void over(){
	int N;
	fstream my_file;
	my_file.open("over.txt");

	while (1) {
	my_file >> N;
	if (my_file.eof())
	{
		break;
	}
	
	}

	my_file.close();
	cout<<"**********************************"<<endl;
	cout<<"Match will be played for : "<< N <<" overs\n";
	cout<<"Each bowler will ball : "<< N/5 <<" overs\n"; 
	cout<<"**********************************"<<endl;

}


int toss_function(){
	
	srand(time(NULL));
	int toss;
	cout<<"***********************\n";
	cout<<"ARE YOU READY FOR THE TOSS"<<endl;
	cout<<"***********************\nPRESS ENTER";
	cin.get();
	toss= (rand() % 2)+1;

	switch (toss)
	{
	case 1:
		cout<< "Team A has won the toss and selected to Bat first."<<endl;
		break;
	
	case 2:
		cout<< "Team B has won the toss and selected to Bat first."<<endl;
		break;
	}
	
	return toss;
		
}

int main()
{

	srand(time(NULL));
	int n=11;
	string a_player[n], b_player[n];
	cout<<"\t\t\t*****************************************\n\n";
	cout<<"\t\t\t  WELCOM TO CRICKET MATCH STIMULATOR"<<endl;
	cout<<"\t\t\t*****************************************\n\n";

	cout<<"Press Enter to Play\n";
	cin.get();
	
	over();

	cout<<"Press Enter to Continue Teams details\n";
	cin.get();
	

	display(a_player,b_player,n);

	cout<<"Press Enter to Continue to Toss\n";
	cin.get();

	if(toss_function()==1)
	{
		cin.get();
		teamA(a_player,b_player, n);
		drawScoreCard_A(a_player,b_player, n);
	}
	else 
	{
		cin.get();
		teamB(b_player,a_player, n);
		drawScoreCard_B(a_player,b_player, n);

	}
	

    
	return 0;
}
