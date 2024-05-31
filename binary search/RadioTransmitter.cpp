#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hackerlandRadioTransmitters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */

int hackerlandRadioTransmitters(vector<int> x, int k) {
    sort(x.begin(),x.end());
    int count=0;
    for(int i=0;i<x.size();){
        int ind=lower_bound(x.begin()+i,x.end(),x[i]+k)-x.begin();
        count++;
        if(ind==x.size()){
            
            break;
        }
        else if(x[ind]>x[i]+k)
            ind--;
        
        int lInd=lower_bound(x.begin()+ind,x.end(),x[ind]+k)-x.begin();
        if(lInd==x.size())
            break;
        else if(x[lInd]>x[ind]+k){
            i=lInd;
        }
        else{
            i=lInd+1;
        }

    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n,k;
    cin>>n>>k;


    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        cin>>x[i];
    }

    int result = hackerlandRadioTransmitters(x, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
