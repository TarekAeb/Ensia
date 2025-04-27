#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
const int Max_col=100;
void MatrixText(string Mat[][Max_col],int Row_size,int &col_size){
    // cout <<"Enter a sentence that contains only alphabitic characters "<<endl;
    string sentence;
    // getline (cin>>ws,sentence);
    bool alpha=false;
    while (!alpha){
        alpha=true;
        for (char c:sentence ){
            if (!isalpha(c) && !isspace(c)){
                alpha =false;
            }
        cout << "enter a valid sentence";
        getline(cin>>ws,sentence);
        }
    }   
    vector<string> words;

    for (int i=0;i<sentence.size();i++){
        int index=0;
        sentence+=' ';
        if (sentence[i]==' '){
            words.push_back(sentence.substr(index,i-index));
        }
        index=i+1;
    }
    for (int i=0; i<words.size();i++){
        Mat[i][col_size]=words[i];
    }
}
void displayMatrix(string Mat[][Max_col],int row_size,int col_size){
    for (int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            cout << Mat[i][j]<<" ";
        }cout << endl;
    }
    }
    string LongestWord(string Mat[][Max_col],int row_size,int col_size){
    string Wmax=Mat[0][0];
    int Smax=Wmax.size();
    for (int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            if(Mat[i][j].size()>Smax){
            Smax=Mat[i][j].size();
            Wmax=Mat[i][j];
            }
    }
    }
    return Wmax;
}
//procedure to lowercase the hole characters of a word
string lower(string &word){
    string nword="";
    for (char c : word){
        nword+=tolower(c);
    }
    word=nword;
    return word;
}
//
// void FrequentWord(string Mat[][Max_col],int row_size,int col_size){
// //to lower all the characters of a word
// for (int i=0;i<row_size;i++){
//     for(int j=0;j<col_size;j++){
//             Mat[i][j]=lower(Mat[i][j]);
//             }
//     }
// vector<string> doublucateWords;
// for (int i=0;i<row_size;i++){
//     for(int j=0;j<col_size;j++){
//         int occurence=0;
//         for (int k=0;k<row_size;k++){
//             for(int l=0;l<col_size;l++){
//                     if (Mat[i][l]==Mat[k][l])
//                         occurence++;
//             }
//     }
//     if(occurence>1){
//         doublucateWords.push_back(Mat[i][j]);
//     }
//             }
//     }
//    cout << "the words that occurate more than one time are: "<<endl;
//    for (int i=0;i<doublucateWords.size();i++){
//     cout << doublucateWords[i]<<", ";
//    }

// }
void FrequentWord(string M[][Max_col],int row_size,int col_size){
    unordered_map<string,int> map;
    
    for (int i=0;i<col_size;i++){
        for (int j=0;j<row_size;j++){
            map[M[i][j]]++;
        }
    }
    cout <<"The word  |  acurence "<<endl;
    for (auto m :map ){
        if (m.second>1){
            cout <<m.first<<" | "<<m.second<<endl;
        }
    }
}


int main()
{
    string Mat[100][Max_col];
    cout << "how many sentence do you want to enter"<<endl;
    int col_size,row_size;
    cin >>col_size;
    for (int i=0;i<col_size;i++){
        cout << "how many words your sentence contains"<<endl;
        cin>>row_size;
        MatrixText(Mat,row_size,col_size);
    }
    displayMatrix(Mat,row_size,col_size);
    LongestWord(Mat,row_size,col_size);
    FrequentWord(Mat,row_size,col_size);

    return 0;
}
