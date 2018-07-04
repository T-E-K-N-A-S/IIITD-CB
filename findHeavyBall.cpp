// code to find the position of the 'biggest' ball from the sequence using weighing scale 
// or in this case by calculating the left and right sums of seq.
// this is a cpp file and not a c file.
// 
// Author : teknas
// Date : 05/07/2018
//
// ps. do not plagiarize or DO plagiarize i want to see what happens 

#include<iostream>
using namespace std;



int solve(int size, int p[11],int a,int b) {
	
	int sumL=0, sumR=0,mid=0,end=0,is_odd;

	cout <<"\n current size: "<< size<<endl;
	if (size == 2)
	{
		if (p[a] > p[a + 1])//this is also case 2
		{
			cout << "case2 sums: " << p[a] << "&" << p[a + 1] << endl;
			return a;
		}
		else // this is also case 3
		{
			cout << "case3 sums: " << p[a] << "&" << p[a + 1] << endl;
			return a + 1;
		}
	}
	if (size == 1)return b; // case 1


	if (size % 2 == 0) // check for even
	{
		end = size-1 - 2;	// remove last 2 elements 
		//note: 'size' is count of elements and 'size-1' is position of last element of array
		mid = end/2;
		is_odd = 0;	// not odd
	}
	else
	{
		end = size - 1 - 1;	//	remove last ele
		mid = end / 2;
		is_odd = 1; // odd
	}
	cout <<"left range"<< a<<" to "<< a + mid<<endl;
	for (int i = a; i <= a+mid; i++)// cal left sum
	{
		sumL += p[i];
	}
	cout << "right range" << a + mid + 1 << " " << a + end << endl;
		
	for (int i = a+mid +1 ; i <= a+end; i++)// cal right sum
	{
		sumR += p[i];
	}

		if (sumL == sumR) // case 1: sL = sR, then process last two or one elements
		{
			cout << "case1 " <<sumL<<"&"<<sumR<< endl;
			return solve(size-end-1,p, a + end, b);

		}

		else if (sumL > sumR) // case 2: sL > sR, process left set of elements
		{
			cout << "case2 " << sumL << "&" << sumR << endl;
			return solve(mid+1,p, a, a + mid);
		}
		else // case 3: sL < sR, process right set of elements
		{
			cout << "case3 " << sumL << "&" << sumR << endl;
			return solve(mid+1,p, a + mid+1, a + end);
		}
	
	
}

int main() {
	int p[] = { 2,2,2,2,2,2,2,2,2,2,2 }; // array of same weight balls
	int size=11; // update size yourself  
	
	int pos; 
	cout << "entr position to hide 'big' ball";
	cin >> pos;
	p[pos] = 7; //	a "big" number 

	int sumL, sumR;
	int sol;

	sol = solve(size,p,0,10); // calls the 'solve' function

	// output
	cout << "\nfound on pos: " << sol << " and val is: "<<p[sol] ;
	cin >> sol;

	return 0;
}