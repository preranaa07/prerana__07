int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int * trustCount= (int *)calloc(n, sizeof(int));
    for(int i=0; i<trustSize; i++){
        trustCount[trust[i][0]-1]--;
        trustCount[trust[i][1]-1]++;
    }
    for(int i=0 ; i<n; i++){
        if(trustCount[i] == n-1){
            return i+1;
        }
    }
    return -1;
}
