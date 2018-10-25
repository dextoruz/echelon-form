#include <iostream>
#include <fstream>

using namespace std;


class checkEchelon
{
protected:
  int row, col;
  int **matrix;

  void checkZero()
  {
    for(int i = 0; i < row-1; i++)
    {
      int count1 = 0, count2 = 0;
        for(int j = 0; j<col; j++)
        {
          if(matrix[i][j] == 0) {  count1++;  }
          else break;
        }
        for(int j = 0; j<col; j++)
        {
          if(matrix[i+1][j] == 0) {  count2++;  }
          else break;
        }
        if (count1 > count2) { swap(matrix[i],matrix[i+1]); }
    }
    return;
  }
public:

  bool checkReduc(){
    // checkZero();
    // printMatrix();
    int p = 0;
  	for(int i = 0; i < col ; i++){

      cout<<"p = "<<p<<" i = "<<i<<endl;
      if(p == row || p == col) { cout<<"break\n";  break;}
      if(matrix[p][i] == 0){
        int colsum = 0,restMsum = 0,rowsum = 0;
        for(int j = p; j<row; j++)
        {
          for(int k = p; k<col; k++ )
          {
            restMsum += matrix[j][k];
          }
        }
        for(int i = p; i<col; i++) { colsum += matrix[p][i]; }
        for(int i = p; i<row; i++) { rowsum += matrix[i][p]; }
        if(restMsum == 0 && colsum == 0) { cout<<"true-1\n"; return true; }
        if(restMsum != 0 && colsum == 0) { cout<<"false-4\n"; return false; }
        if(rowsum != 0) { cout<<"false-5\n"; return false; }
        cout<<"continue\n";continue;
      }
  		if(matrix[p][i] == 1)
  		{
        ///// downwords check zeros from pivot point

        for(int j = p+1; j < row; j++){
          // cout<<"downward"
          cout<<j<<'x'<<i<<" "<<matrix[j][i]<<endl;
          if(matrix[j][i] != 0) {
             cout<<"false-1\n";
              return false;
            }
          }

        cout<<"____________\n";
        //// upwards check zeros from pivot point

        for(int j = 0; j < p; j++) {
          cout<<j<<'x'<<i<<" "<<matrix[j][i]<<endl;
          if(matrix[j][i] != 0){
            cout<<"false-2\n";
            return false;
          }
        }
        cout<<"*******\n";
    		p++;
  		}
  		else	{ cout<<"false-3\n"; return false; }
  	}
    cout<<"true\n";
    return true;
  }

  bool checkEche(){
    int p = 0;
    for(int i = 0; i < col ; i++){
      if(p == row || p == col) break;
      if(matrix[p][i] == 0){
        int colsum = 0,restMsum = 0;
        for(int j = p; j<row; j++){
          for(int k = p; k<col; k++ )
            restMsum += matrix[j][k];
        }
        for(int i = p; i<col; i++) { colsum += matrix[p][i]; }
        if(restMsum == 0 && colsum == 0) { return true; }
        if(restMsum != 0 && colsum == 0) { return false; }
        continue;
      }
      if(matrix[p][i] != 0){
        ///// downwords check zeros from pivot point
        for(int j = p+1; j < row; j++)
          if(matrix[j][i] != 0)
            return false;
        p++;
      }
      else  return false;
    }
    return 1;
  }
  void setData(){
    int num = 0;
    ifstream in("in2.txt");
    if(in.is_open())
    {
      in>>num;
      for(int i = 0; i < num ; i++)
      {
        in>>row>>col;
        // cout<<m<<'x'<<n<<endl;
        initializeMatrix();
        for(int j = 0 ; j < row; j++ )
        {
          for(int k = 0; k < col; k++)
          {
            in>>matrix[j][k];
          }
        }
        printMatrix();
        ////// give matrix to a function to check
        checkReduc();
      }
    }
    else { cout<<"\n\nin.txt is not opened\n"; }
    in.close();
  }

  void printMatrix()
  {
    cout<<endl;
    for(int i = 0; i<row; i++)
    {
      for(int j = 0; j<col; j++) { cout<<"  "<<matrix[i][j]<<"  ";  }
      cout<<endl<<endl;
    }
    return;
  }

  void initializeMatrix()
  {
    matrix = new int*[row];
    for(int i = 0 ; i < row; i++){  matrix[i] =  new int[col];  }
    return;
  }

  checkEchelon()
  {
    row = 0;
    col = 0;
    initializeMatrix();
  }
  ~checkEchelon()
  {
    delete [] matrix;
    cout<<"\n\nEND!\4";
  }

};


int main()
{
  checkEchelon ech;
  ech.setData();

  return 0;
}
