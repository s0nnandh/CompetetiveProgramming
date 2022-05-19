/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int Answer;
int n;
vector<string> v;
string best(string &a,string &b){
    int i = (int)a.size() - 1,j = 0;
    string tempA = "",tempB = "";
    while(i >= 0 && j < (int)b.size()){        
        tempA += a[i];
        tempB = b[j] + tempB;
        // if(a == "14123" && b == "234"){
        //     cout << "hell" << tempA << " " << tempB << endl;
        // }
        if(tempA == tempB){
            if(j + 1 < (int)b.size())return a + b.substr(j + 1);
            return a;
        }
        --i;
        ++j;
    }
    return a;
}
int rec(string s,int rem){
    if(rem == 0){
        // dp[s][0] = s.size();
        return (int)s.size();
    }
    int ans = 0;
    for(int i = 0;i < n;++i){
        if(rem&(1 << i)){
            // cout << s << " " << v[i] << " "  << best(s,v[i]) << endl;
            ans = max(rec(best(s,v[i]),rem - (1 << i)),ans);
        }
    }
    return ans;
}
int solve(){    
    cin >> n;
    v.resize(n);
    for(auto &i : v)cin >> i;
    int tot = (1 << n) - 1;
    int ans = 0;
    for(int i = 0;i < n;++i){
        ans = max(ans,rec(v[i],tot - (1 << i)));
    }
    v.clear();
    return ans;
}   

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		Answer = solve();
		// Print the answer to standard output(screen).
		cout << "#" << test_case+1 << " ";
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}