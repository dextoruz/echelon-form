#include <iostream>
#include <fstream>
#include "fraction.h"

using namespace std;


class reducEchelon{
protected:
  unsigned short int row, col;
  fraction **matrix;
  fraction flag;  /// flag = 0;

public:

  bool checkReduc(){
    int p = 0;
  	for(int i = 0; i < col ; i++){
  		if(p == row || p == col) break;
  		if(matrix[p][i] == flag){
  			fraction colsum = flag,restMsum = flag,rowsum = flag;
  			for(int j = p; j < row; j++){
  				for(int k = p; k < col; k++ )
  					restMsum += matrix[j][k];
  			}
  			for(int i = p; i < col; i++)  colsum += matrix[p][i];
  			for(int i = p; i < row; i++)  rowsum += matrix[i][p];
  			if(restMsum == flag && colsum == flag)  return true;
  			if(restMsum != flag && colsum == flag)  return false;
  			if(rowsum != flag)  return false;
  			continue;
  		}
  		if(matrix[p][i] == flag+1){
  			///// downwords check zeros from pivot point
  			for(int j = p+1; j < row; j++)
  				if(matrix[j][i] != flag)
  					return false;

  			//// upwards check zeros from pivot point
  			for(int j = 0; j < p; j++)
  			 	if(matrix[j][i] != flag)
  					return false;
  			p++;
  		}
  		else  return false;
  	}
  	return 1;
  }
  void checkZero(){
    for(int i = 0; i < row-1; i++){
      int count1 = 0, count2 = 0;
        for(int j = 0; j<col; j++){
          if(matrix[i][j] == flag) {  count1++;  }
          else break;
        }
        for(int j = 0; j<col; j++){
          if(matrix[i+1][j] == flag) {  count2++;  }
          else break;
        }
        if (count1 > count2) { swap(matrix[i],matrix[i+1]); }
    }
    return;
  }

  void makeMul(fraction num, fraction arr[], int piv){
    //// take num and multiply by arr
    for(int i = piv; i < col; i++){
        if(arr[i] != flag)
          arr[i] = arr[i] * num;
      }
    return;
  }
  void makeOne(fraction num,fraction arr[]){
    ///// take num = array[0] and divide by array
    for(int i = 0; i < col ; i++){
      if(arr[i] != flag)
       arr[i] = arr[i] / num;
     }
    printMatrix();
    return;
  }
  void makeZero(fraction num, fraction ar1[] ,fraction ar2 [],int piv){
    /// make zeros from pivot point
    fraction temp2[col];
    copy(ar1, ar1+col, temp2);
    makeMul(num,temp2,piv);
    for(int i = 0; i<col; i++)
      ar2[i] = ar2[i] - temp2[i];
    printMatrix();
    return ;
  }

  void ReducedEchelon(){
    int dgl = 0, pivot = 0;
    for(int i = 0; i<col; i++){
      checkZero();
      if(checkReduc() == false){
        makeReducedEchelon(dgl,pivot);
        dgl+=1; pivot+=1;
        if(pivot == col || dgl == row) break;
      }
    }
    cout<< "\nREDUCED ECHELON FORM MATRIX!\n";
    cout<<"----------------------------------";
    return;
  }
  void makeReducedEchelon(int dgl ,int &pivot){

    if(matrix[dgl][pivot] == flag){
       pivot+=1;
       return makeReducedEchelon(dgl,pivot);
     }
    if(matrix[dgl][pivot] != flag){
      makeOne(matrix[dgl][pivot],matrix[dgl]);
      for(int i = dgl; i < row-1 ; i++){
        if(matrix[i+1][pivot] == flag) continue;
        else
          makeZero(matrix[i+1][pivot],matrix[dgl],matrix[i+1],pivot);
      }
      for(int i = 0; i < dgl; i++){
        if(matrix[i][pivot] == flag) continue;
        else
          makeZero(matrix[i][pivot],matrix[dgl],matrix[i],pivot);
      }
    }
    return;
  }


  void setData(){
    int num = 0;
    ifstream in("in2.txt");
    ofstream out("out2.txt");
    if(in.is_open() && out.is_open()){
      in>>num;
      out<<num<<endl;
      for(int i = 0; i < num ; i++){
        in>>row>>col;
        out<<row<<endl<<col<<endl;
        initializeMatrix();
        for(int j = 0 ; j < row; j++ ){
          for(int k = 0; k < col; k++){
            in>>matrix[j][k];
          }
        }
        printMatrix();
        ////// give matrix to a function to check
        if(checkReduc() == true){
          for(int j = 0 ; j < row; j++ ){
            for(int k = 0; k < col; k++)
              out<<matrix[j][k]<<' ';
            out<<endl;
          }
        }
        else{
          ReducedEchelon();
          for(int j = 0 ; j < row; j++ ){
            for(int k = 0; k < col; k++)
              out<<matrix[j][k]<<' ';
            out<<endl;
          }
        }
      }
    }
    else { cout<<"\n\nin.txt and out.txt is not opened\n"; }
    in.close();
    out.close();
  }
  void printMatrix(){
    cout<<endl;
    for(int i = 0; i<row; i++){
      for(int j = 0; j<col; j++) { cout<<"  "<<matrix[i][j]<<"  ";  }
      cout<<endl<<endl;
    }
    return;
  }

  void initializeMatrix(){
    matrix = new fraction*[row];
    for(int i = 0 ; i < row; i++){  matrix[i] =  new fraction[col];  }
    return;
  }
  reducEchelon(){
    row = 0;
    col = 0;
    initializeMatrix();
  }
  ~reducEchelon(){
    delete [] matrix;
    cout<<"\n\nEND!\4";
  }
};


int main()
{
  reducEchelon ech;
  ech.setData();

  return 0;
}
