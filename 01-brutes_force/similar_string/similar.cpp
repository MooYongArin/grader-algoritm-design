#include <bits/stdc++.h>

using namespace std;
bool isSimilar(string str1, string str2){
    if(str1 == str2) return true;
    if(str1.size() == 1) {
        if(str1 == str2) return true;
        return false;
    }
    string a1 = "", a2 = "", b1 = "", b2 = "";
    for(int i = 0; i < str1.size() / 2; ++i) {
        a1 += str1[i];
        b1 += str2[i];
    }
    for(int i = str1.size() / 2; i < str1.size(); ++i) {
        a2 += str1[i];
        b2 += str2[i];
    }
    return (isSimilar(a1, b1) && isSimilar(a2, b2)) || (isSimilar(a1, b2) && isSimilar(a2, b1));

}
int main(){
    string str1, str2;

    cin >> str1 >> str2;

    if(isSimilar(str1, str2)) cout << "YES";
    else cout << "NO";
    return 0;   
}