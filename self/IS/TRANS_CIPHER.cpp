#include<bits/stdc++.h>
using namespace std;


void PrintMatrix(const vector<vector<char>>& matrix){
  for(int i=0; i<matrix.size(); i++){

    for(int j=0; j<matrix[0].size(); j++){
     cout<<matrix[i][j]<<" ";

    }
    cout<<endl;
  }



}


int main(){
   string pt;
    string key;
    
    cin>>pt;
    cin>>key;

    int row= pt.size()/key.size();
    int col=key.size();


    vector<vector<char>>matrix(row+1, vector<char>(col,'-'));
    int index=0;

    for(int i=0; i<row+1; i++){
        for(int j=0; j<col; j++){
            if(index<pt.size()){
                matrix[i][j]=pt[index++];
            }
            else{
                matrix[i][j]='-';
            }
        }
    }

    cout<<" the plain text matrix is :"<<endl;
      PrintMatrix(matrix);

    string ciphertext;
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row + 1; i++) {
            ciphertext += matrix[i][j];
        }
    }

    // Output ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

      
string decryptedText;
index = 0;
for (int i = 0; i < row+1; i++) { // Loop through columns
    for (int j = 0; j < col; j++) { // Loop through rows

        if (matrix[i][j] != '-') {
            decryptedText += matrix[i][j];
        }
    }
}

// Output decrypted text
cout << "Decrypted Text: " << decryptedText << endl;

return 0;



}