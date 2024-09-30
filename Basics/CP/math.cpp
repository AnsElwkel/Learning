//Matrix rotate code O(n^2)
vector<vector<int>> rotate(vector<vector<int>> & v){
    vector<vector<int>> ret ;
    ret.assign(v[0].size() , vector<int>(v.size() , 0));
    for(int i = 0 ; i < (int)v.size() ; i++){
        for(int r = 0 ; r < (int)v[0].size() ; r++){
            ret[r][(int)v.size()-i-1] = v[i][r];
        }
    }
    return ret;
}
//Matrix multiplication code O(n^3)
vector<vector<int>> matrix_multiplication(vector<vector<int>> & a , vector<vector<int>> & b){
    vector<vector<int>> ret;
    ret.assign(a.size() , vector<int>(b[0].size() , 0));
    for(int i = 0; i < a.size() ; i++){
        for(int k = 0 ; k < a[0].size() ; k++) {
            for(int j = 0; j < b[0].size() ;j++){
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return ret;
}
