#include <iostream>
#include <bits/stdc++.h>
#include<chrono>
#define RANGE 10000
using namespace std;
using namespace std::chrono;
vector<vector<long>> generate_dense_matrix(int rows,int cols){
    vector<vector<long>> matrix(rows);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            matrix[i].push_back(rand()% RANGE);
        }
    }
    /*for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<" "<<matrix[i][j];
        }
        cout<<endl;
    }*/
    return matrix;
}
vector<long> generate_dense_vector(int rows){
    vector<long> vector;
    for(int i=0;i<rows;i++){
            vector.push_back(rand() % RANGE);
    }
    /*for(int j=0;j<rows;j++){
        cout<<" "<<vector[j];
    }*/
    return vector;
}
vector<long> seq_dense_mat_vec_mult(vector<vector<long>> &mat,vector<long> &vec){
    int rows = vec.size();
    int cols = mat[0].size();
    vector<long> res (vec.size(),0);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            res[i]+=mat[i][j] * vec[j];
        }
    }
    return res;
}
int main() {
    // set random seed each time the program is run
    srand(time(NULL));
    //intializing random dense matrix and dense vector
    vector<vector<long>> m = generate_dense_matrix(10,10);
    vector<long> v = generate_dense_vector(10);
    // Get starting timepoint
    auto start = high_resolution_clock::now();
    // do matrix-vector multiplication sequentially
    vector<long >seq_res = seq_dense_mat_vec_mult(m,v);
    // Get starting timepoint
    auto end = high_resolution_clock::now();
    // get duration.
    auto duration = duration_cast<nanoseconds>(end - start);
    // printing results and time taken
    cout<<"Result in sequential: "<<endl;
    for(int i=0;i<seq_res.size();i++){
        cout<<seq_res[i]<<" ";
    }
    cout<<endl<<"Time in nanoseconds = "
    <<duration.count()<<" ns"<<endl;
    return 0;
}
