typedef vector<int> vi;

class UnionFind {
    private: vi rank, parent;
    int count;

    public:
        UnionFind(int N){
            rank.assign(N,0);
            parent.assign(N,0);
            for(int i=0;i<N;i++)parent[i] = i ;
            count = N;
        }
    
    int findSet(int i) {return i == parent[i]?i:(parent[i] = findSet(parent[i]));}
    int isSameSet(int i,int j) {return findSet(i) == findSet(j);} 
    void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) parent[y] = x;
			else {
				parent[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
            
            count--;
        } }
    int getCount(){
        return count;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        int size = (int)M.size();
        
        UnionFind uf(size);
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(M[i][j] == 1 && i!=j)uf.unionSet(i,j);
            }
        }
        
        return uf.getCount();
    }
};
